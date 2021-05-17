/**
* @file      Library.h
* @brief     ���ڼ��ض�̬�⣬ע����__linux__�±��붯̬��ʱ����Ҫ��-fPICѡ����ܱ���̬����
*          
* @note      ������windows��linux��vxworks
*          
* @author    Crack Xie
* @date      2020-05-26
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include "SystemExport.h"

#ifdef WIN32
#	include <windows.h>
	typedef HMODULE LibraryHandle;
#elif defined __linux__
#	include <dlfcn.h>
	typedef void* LibraryHandle;
#elif defined VXWORKS
#	ifdef REWORKS
#		include "symtbl.h"
#	else
#		include "moduleLib.h"
#	endif
	typedef MODULE_ID LibraryHandle;
#endif

/**
* @class CLibrary
* @brief ��̬�⶯̬������
* @note  
*/
class SYSTEM_EXPORT CLibrary
{
public:
	/**
	 * @fn       CLibrary(const std::string& strFileName)   
	 * @brief    ���캯��   
	 * @param    const std::string& strFileName ��̬����ļ��������Դ������·��            
	*/
	CLibrary(const char* strFileName = "");
	~CLibrary();

public:
	/**
	 * @fn       bool Load()   
	 * @brief    ���ض�̬��        
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	bool Load();

	/**
	 * @fn       bool Unload()   
	 * @brief    ж�ض�̬��       
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	bool Unload();

	/**
	 * @fn       void* Resolve(const std::string& strSymbol)   
	 * @brief    ��ȡ��̬���еĺ�����ַ   
	 * @param    const std::string& strSymbol ��������           
	 * @return   void*	������ַ       
	*/
	void* Resolve(const char* strSymbol);

	/**
	 * @fn       bool IsLoaded()   
	 * @brief    �Ƿ��Ѿ�����        
	 * @return   bool	�Ѽ��ط���true�����򷵻�false       
	*/
	bool IsLoaded();

	/**
	 * @fn       bool SetFileName(const std::string& strFileName)   
	 * @brief    ����Ҫ���ص��ļ���������ļ�������һ�ε��ļ�����һ��������ж����һ���Ѿ����صĶ�̬��   
	 * @param    const std::string& strFileName  �ļ���         
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	bool SetFileName(const char* strFileName);

	/**
	 * @fn       std::string& GetFilePath()   
	 * @brief    ��ȡ��̬��ľ���·��       
	 * @return   std::string&	��̬��ľ���·��       
	*/
	const char* GetFilePath();

	/**
	 * @fn       void* Resolve(const std::string& strFileName,const std::string& strSymbol)   
	 * @brief    ��ȡָ���ļ����Ķ�̬���еĺ�����ַ   
	 * @param    const std::string& strFileName  �ļ���     
	 * @param    const std::string& strSymbol  ��������          
	 * @return   void*	������ַ       
	*/
	static void* Resolve(const char* strFileName,const char* strSymbol);

	/**
	 * @fn       CLibrary *Clone() 
	 * @brief    ��¡ԭʼ�ļ�  
	 * @param    const std::string& strFileName  �ļ���           
	 * @return   void*	������ַ       
	*/
	CLibrary *Clone();
private:
	LibraryHandle m_hHandle;		///<���ؿ�ľ��

	char m_strFileName[52];
	//std::string m_strFileName;		///<�û�������ļ����������Ǵ����·�����ļ��� �����������ΪUTF-8 ����·��
	char m_strFilePath[256];
	//std::string m_strFilePath;		///<�ļ�������·��

	bool m_IsSucc;				// load�ɹ���־

};
#endif
