#ifndef IPluginModule_h__
#define IPluginModule_h__

#include "IModule.h"
#include "KernelExport.h"

class IPlugin;
class CLibrary;

// ����һ���ṹ�� PluginInfo 
class KERNEL_EXPORT CPluginInfo
{
public:
	CPluginInfo():
		  m_pPlugin(nullptr)
		, m_pLibrary(nullptr)
	{
		memset(m_strBelong, '\0', sizeof(char) * 128);
		memset(m_strDuty, '\0', sizeof(char) * 128);
	}

	~CPluginInfo()
	{

	}

public:
	IPlugin* m_pPlugin;			//���ʵ��
	CLibrary* m_pLibrary;		//���DLL��Ϣ
	char m_strBelong[128];	    //�������
	char m_strDuty[128];		//���ְ��
};
/**
* @class CPluginModuleObserver
* @brief ���ģ��۲���
* @note  
*/
class KERNEL_EXPORT CPluginModuleObserver
{
public:
	virtual ~CPluginModuleObserver(){}

	virtual bool OnPluginLoad(const char* strModulePath, const char* strConfigPluginPath, IPlugin* pPlugin, const char* strDuty) = 0;

	virtual bool OnPluginUnload(IPlugin* pPlugin, const char* strDuty) = 0;
};

class KERNEL_EXPORT PluginInfoVisitor
{
public:
	virtual ~PluginInfoVisitor(){}

	/**
		* @fn  Visit			
		* @brief �������ӿ�  
		* @param const std::string & strName: �����ʲ����
		* @param const CPluginInfo & rPluginInfo: �����ʲ����Ϣ
		* @return void
		*/
	virtual void Visit(const char* strName,CPluginInfo *pluginInfo)  = 0;
};
class  KERNEL_EXPORT IPluginModule : public IModule
{
public:
	virtual ~IPluginModule(){}

	/**
	 * @fn  LoadPlugin        
	 * @brief ͨ�������,���·��,���ͼ�����Ϣ,���ز��  
	 * @param const std::string & strName:		�����
	 * @param const std::string & strDllPath:	���·��
	 * @param const std::string & strIconPath:	ͼ��·��
	 * @param const std::string & strDuty:		ְ����Ϣ,Ĭ��Ϊsystem,[�ջ���'system'����Ϊ������ְ��system]
	 * @return bool �����Ƿ�ɹ�
	 */
	virtual bool LoadPlugin(const char* strName, 
			const char *strDllPath, 
			const char* strIconPath = "", 
			const char* strDuty = "system") = 0;

	/**
	 * @fn  LoadPluginsFromFile        
	 * @brief �������ļ����ز��  
	 * @param const std::string & strPath: �����ļ�·��
	 * @return bool �����Ƿ�ɹ�
	 */
	virtual bool LoadPluginsFromFile(const char* strPath, const char* strDuty) = 0;

	/**
	 * @fn  UnloadPlugin  [����]      
	 * @brief   ͨ�������(����������IPlugin::GetName())ж�ز��
	 * @param const std::string & strName: �����
	 * @param bool bForceUnload: ǿ��ж��
	 * @return bool 
	 */
	virtual bool UnloadPlugin(const char* strName, bool bForceUnload = false) = 0;

	/**
	 * @fn  UnloadPlugin        
	 * @brief   ͨ�����,ж�ز��
	 * @param IPlugin * pPlugin: ���ָ��
	 * @param bool bForceUnload: ǿ��ж��
	 * @return bool
	 */
	virtual bool UnloadPlugin(IPlugin* pPlugin, bool bForceUnload = false) = 0;

	/**
	 * @fn  UnloadPluginByDllPath        
	 * @brief   ͨ�����·��ж�ز��(����ƥ��·��)
	 * @param const std::string & strDllPath: �������·��,����Ͳ�������ļ���һ��
	 * @param bool bForceUnload: ǿ��ж��
	 * @return bool �����Ƿ�ɹ�
	 */
	virtual bool UnloadPluginByDllPath(const char* strDllPath, bool bForceUnload = false) = 0;

	/**
	 * @fn  UnloadPluginsFromFile        
	 * @brief ͨ�������ļ�ж�ز��  
	 * @param const std::string & strPath: �����ļ�·��
	 * @param bool bForceUnload: ǿ��ж��
	 * @return void
	 */
	virtual void UnloadPluginsFromFile(const char* strPath, bool bForceUnload = false) = 0;

	/**
	 * @fn  UnloadPluginsByDuty        
	 * @brief ���ղ��ְ��ж�ز��  
	 * @param const std::string & strDuty: ְ��
	 * @param bool bForceUnload: ǿ��ж��
	 * @return void
	 */
	virtual bool UnloadPluginsByDuty(const char* strDuty, bool bForceUnload = false) = 0;

	/**
	 * @fn  UnloadAllPlugins        
	 * @brief ж�����в��  
	 * @return void
	 */
	virtual void UnloadAllPlugins() = 0;

	/**
	 * @fn  RegisterObserver        
	 * @brief ע����ģ��Ĺ۲���,���Դ��������غ�ж�ص��¼�֪ͨ  
	 * @param CPluginModuleObserver * pObserver: ���ģ��۲���
	 * @return bool �����Ƿ�ע��ɹ�
	 */
	virtual bool RegisterObserver(CPluginModuleObserver* pObserver) = 0;

	/**
	 * @fn  UnregisterObserver        
	 * @brief ȡ�����ģ��Ĺ۲���ע��,  
	 * @param CPluginModuleObserver * pObserver: ��Ҫȡ��ע��Ĺ۲���
	 * @return void
	 */
	virtual void UnregisterObserver(CPluginModuleObserver* pObserver) = 0;

	/**
	 * @fn  Travel        
	 * @brief �������в��  
	 * @param PluginInfoVisitor & rVisitor: 
	 * @return void
	 */
	virtual void Travel(PluginInfoVisitor& rVisitor) = 0;

	/**
	 * @fn  IsPluginLoaded        
	 * @brief ����ĳ������Ƿ����
	 * @param const std::string& strPluginName: 
	 * @return bool
	 */
	virtual bool IsPluginLoaded(const char* strPluginName) = 0;

public:
	/**
	 * @fn  NotifyPluginLoad        
	 * @brief ֪ͨ���ע��  
	 * @param const std::string & strPluginPath: 
	 * @param IPlugin * pPlugin: 
	 * @return void
	 */
	virtual void NotifyPluginLoad(const char*strModulePath, const char* strPluginPath, IPlugin* pPlugin, const char* strDuty) = 0;

	/**
	 * @fn  NotifyPluginUnload        
	 * @brief ֪ͨ���ж��  
	 * @param IPlugin * pPlugin: 
	 * @return void
	 */
	virtual void NotifyPluginUnload(IPlugin* pPlugin, const char* strDuty) = 0;
};

#endif // IPluginModule_h__
