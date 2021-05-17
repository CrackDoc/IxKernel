#include "ObjectCreator.h"
#include <map>
#include <set>

CObjectCreator::CObjectCreator(void)
	:m_ObjectTypes(new std::map<std::string, CObjectRegisterAgent*>())
	, m_ObserversSet(new std::set<CObjectCreatorObserver*>())
{

}

CObjectCreator::~CObjectCreator()
{

}

bool CObjectCreator::RegisterType( const char* strTypeName, CObjectRegisterAgent* pObjectAngent )
{
	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);
	std::map< std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.find(strTypeName);
	if(it == ObjectTypes.end())
	{
		ObjectTypes.insert(std::map<const std::string, CObjectRegisterAgent*>::value_type(strTypeName,pObjectAngent));
		return true;
	}
	return false;
}

CObjectRegisterAgent* CObjectCreator::UnregisterType( const char* strTypeName )
{
	CObjectRegisterAgent *pCObjectRegisterAgent = NULL;
	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);

	std::map<const std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.find(strTypeName);
	if(it == ObjectTypes.end())
	{
		pCObjectRegisterAgent = it->second;
		std::set<CObjectCreatorObserver*>& ObserversSet = *static_cast<std::set<CObjectCreatorObserver*>*>(m_ObserversSet);
		if(!ObserversSet.empty())
		{
			NotifyObjectTypeUnregister(strTypeName,pCObjectRegisterAgent);
		}
		ObjectTypes.erase(it);
	}
	return pCObjectRegisterAgent;
}

void CObjectCreator::UnRegisterAllType()
{
	CObjectRegisterAgent *pCObjectRegisterAgent = NULL;
	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);
	std::map< std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.begin();

	for(;it != ObjectTypes.end();++it)
	{
		CObjectRegisterAgent *pCObjectRegisterAgent = it->second;
		std::set<CObjectCreatorObserver*>& ObserversSet = *static_cast<std::set<CObjectCreatorObserver*>*>(m_ObserversSet);

		if(!ObserversSet.empty())
		{
			NotifyObjectTypeUnregister(it->first.c_str(),pCObjectRegisterAgent);
		}
		ObjectTypes.erase(it);

		delete pCObjectRegisterAgent;

		pCObjectRegisterAgent = NULL;
	}
}

IObject* CObjectCreator::CreateObject(const char* strTypeName )
{
	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);
	std::map< std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.begin();
	IObject *pIObject = NULL;
	if(it != ObjectTypes.end())
	{
		pIObject = it->second->Create();
		pIObject->SetClassType(strTypeName);
	}
	return pIObject;
}

void CObjectCreator::DestroyObject( IObject* pObject )
{
	std::string strClassName = pObject->GetClassType();

	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);
	std::map<const std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.find(strClassName);

	if(it == ObjectTypes.end())
	{
		CObjectRegisterAgent *pCObjectRegisterAgent = it->second;
		ObjectTypes.erase(it);

		delete pCObjectRegisterAgent;

		pCObjectRegisterAgent = NULL;
	}
}

CObjectRegisterAgent* CObjectCreator::LookupAgent(const char* strTypeName)
{
	CObjectRegisterAgent *pAgent = NULL;
	return pAgent;

}

bool  CObjectCreator::GetAllAgent(void* input)
{
	input = m_ObjectTypes;
	return true;
}
void CObjectCreator::Travel( CObjectRegisterAgentVisitor& rVisitor )
{
	std::map< std::string, CObjectRegisterAgent*>& ObjectTypes = *static_cast<std::map< std::string, CObjectRegisterAgent*>*>(m_ObjectTypes);
	std::map<const std::string, CObjectRegisterAgent*>::iterator it = ObjectTypes.begin();

	for(;it != ObjectTypes.end();++it)
	{
		CObjectRegisterAgent *pCObjectRegisterAgent = it->second;
		bool bContinues = rVisitor.Apply(it->first.c_str(),pCObjectRegisterAgent);
		if(!bContinues)
		{
			break;
		}
	}
}

void CObjectCreator::RegisterObserver( CObjectCreatorObserver* pOb )
{
	std::set<CObjectCreatorObserver*>& ObserversSet = *static_cast<std::set<CObjectCreatorObserver*>*>(m_ObserversSet);
	ObserversSet.insert(pOb);

}

void CObjectCreator::UnregisterObserver( CObjectCreatorObserver* pOb )
{
	std::set<CObjectCreatorObserver*>& ObserversSet = *static_cast<std::set<CObjectCreatorObserver*>*>(m_ObserversSet); 
	ObserversSet.erase(pOb);
}

void CObjectCreator::NotifyObjectTypeUnregister(const char* strType, CObjectRegisterAgent* pAngent )
{
	std::set<CObjectCreatorObserver*>& ObserversSet = *static_cast<std::set<CObjectCreatorObserver*>*>(m_ObserversSet);

	std::set<CObjectCreatorObserver*>::iterator it = ObserversSet.begin();
	for(;it != ObserversSet.end();++it)
	{
		CObjectCreatorObserver *pCObjectCreatorObserver = *it;
		pCObjectCreatorObserver->OnUnregisterObjectType(strType,pAngent);
	}

}
IMPLEMENT_SINGLETON_CLASS(CObjectCreatorSingleton);