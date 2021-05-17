#ifndef ObjectCreator_h__
#define ObjectCreator_h__
#include <string>
#include "IObject.h"
#include "PublicMarco.h"
#include <iostream>

class CThreadMutex;

template <typename T> std::string ClassNameOfType();

class CObjectRegisterAgent
{
public:
	virtual ~CObjectRegisterAgent(){}

	virtual IObject* Create() = 0;
};

template <typename T> 
class CObjectRegisterAgentT : public CObjectRegisterAgent
{
public:
	CObjectRegisterAgentT(){}
	~CObjectRegisterAgentT(){}

	IObject* Create()
	{
		return new T;
	}

	T* Cast(IObject* pObject) const
	{
		T* pCastObject = dynamic_cast<T*>(pObject);
		return pCastObject;
	}
};

//ObjectCreator观察者
class CObjectCreatorObserver
{
public:
	virtual ~CObjectCreatorObserver(){}

	virtual void OnUnregisterObjectType(const char* strType, CObjectRegisterAgent* pAngent) = 0;
};

//注册器
//class CThreadMutex;
class CObjectRegisterAgentVisitor
{
public:
	virtual ~CObjectRegisterAgentVisitor(){}

	// Brief:返回值表示是否继续, true表示继续 [2017/4/24 CETC] 
	virtual bool Apply(const char* strType, CObjectRegisterAgent* pAgent) = 0;
};

// Brief:Object创建器[虚拟工厂] [2016/1/4 SCHX] 
class KERNEL_EXPORT CObjectCreator
{
public:
	CObjectCreator();
	virtual ~CObjectCreator();

	bool RegisterType(const char* strTypeName, CObjectRegisterAgent* pObjectAngent);

	CObjectRegisterAgent* UnregisterType(const char* strTypeName);

	IObject* CreateObject(const char* strTypeName);

	virtual void DestroyObject(IObject* pObject);

	CObjectRegisterAgent* LookupAgent(const char* strTypeName);

	bool GetAllAgent(void* input);

	void Travel(CObjectRegisterAgentVisitor& rVisitor);

public:	//关于观察者

	void RegisterObserver(CObjectCreatorObserver* pOb);

	void UnregisterObserver(CObjectCreatorObserver* pOb);

	//浅拷贝出去的数据不能删除
	void NotifyObjectTypeUnregister(const char* strType, CObjectRegisterAgent* pAngent);

public:	//模板方法
	template <typename T>
	bool RegisterType()
	{
		CObjectRegisterAgentT<T>* pAngent = new CObjectRegisterAgentT<T>(); 
		std::string strClassName = ClassNameOfType<T>();
		bool bRet = RegisterType(strClassName.c_str(), pAngent);
		return bRet;
	}

	template <typename T>
	void UnregisterType()
	{
		std::string strClassName = ClassNameOfType<T>();
		CObjectRegisterAgent* pAngent = UnregisterType(strClassName);
		if (NULL != pAngent)
		{
			delete pAngent;
			pAngent = NULL;
		}
	}

protected:
	void UnRegisterAllType();
protected:
	void* m_ObjectTypes;
	//CThreadMutex* m_pObjectTypesLock;
	//std::map<const std::string, CObjectRegisterAgent*> m_ObjectTypes;
	//CThreadMutex* m_pObserversSetLock;
	void* m_ObserversSet;
	//std::set<CObjectCreatorObserver*> m_ObserversSet;
};

//提供一个全局的对象创建器
DECLARE_SINGLETON_CLASS(CObjectCreator, CObjectCreatorSingleton, KERNEL_EXPORT)

//获取类名
template <typename T>
std::string ClassNameOfType()
{
	std::string strClassName = typeid(T).name();
#ifdef WIN32
	const std::string STR_TOKEN = "class ";
	int nPos = strClassName.find_first_of(STR_TOKEN);
	nPos += STR_TOKEN.length();
	if (nPos >= STR_TOKEN.length())
	{
		strClassName = strClassName.substr(nPos);
	}
#elif __linux__
	int i = 0;
	for(; i < strClassName.length(); ++i)
	{
		if(strClassName[i] >= 'A' && strClassName[i] <= 'z')
		{
			break;
		}
	}
	strClassName = strClassName.substr(i);
	std::cout << "class name is >>>>>> " << strClassName << std::endl;
#endif
	return strClassName;
}

//提供一个比较方便的函数
template <typename T> bool RegisterObjectType()
{
	CObjectCreator* pCreator = CObjectCreatorSingleton::GetInstance();
	return pCreator->RegisterType<T>();
}

template <typename T> void UnregisterObjectType()
{
	CObjectCreatorSingleton::GetInstance()->UnregisterType<T>();
}


//=======================================
//PART-II.自动注册部分
template <typename T>
class CObjectAutoRegisterHelper : public CObjectCreatorObserver
{
public:
	CObjectAutoRegisterHelper(const std::string& strTypeName, CObjectCreator* pCreator = NULL)
		: m_pObjectCreator(pCreator)
		, m_strTypeName(strTypeName)
	{
		if (NULL == m_pObjectCreator)
		{
			m_pObjectCreator = CObjectCreatorSingleton::GetInstance();
		}

		if (NULL == m_pObjectCreator)
		{
			return;
		}

		m_pObjectCreator->RegisterObserver(this);

		//TODO:
		m_pObjectCreator->RegisterType<T>();
	}

	~CObjectAutoRegisterHelper()
	{
		if (NULL == m_pObjectCreator)
		{
			return;
		}

		m_pObjectCreator->UnregisterObserver(this);

		m_pObjectCreator->UnregisterType<T>();
	}

	void OnUnregisterObjectType(const std::string& strType, CObjectRegisterAgent* pAngent)
	{
		//这里需要把m_pObjectCreator==NULL
		if (strType != m_strTypeName)
		{
			return;
		}

		if (NULL != m_pObjectCreator)
		{
			m_pObjectCreator->UnregisterObserver(this);
			m_pObjectCreator = NULL;
		}
	}

protected:
	CObjectCreator* m_pObjectCreator;
	std::string m_strTypeName;
};

#define AUTO_REGISTER_OBJECT_NS_TYPE(objCreator, className, ns) \
	static CObjectAutoRegisterHelper<ns::className> g_##className##ObjectAutoRegister(std::string(#ns) + std::string("::") + std::string(#className), objCreator);

#define AUTO_REGISTER_OBJECT_TYPE(objCreator, className) \
	static CObjectAutoRegisterHelper<className> g_##className##ObjectAutoRegister(std::string(#className), objCreator);

//-----------------------------------------------------

#endif // ObjectCreator_h__
