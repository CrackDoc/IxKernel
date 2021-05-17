/**
* @file      Library.h
* @brief     用于加载动态库，注意在__linux__下编译动态库时，需要加-fPIC选项才能被动态加载
*          
* @note      适用于windows、linux、vxworks
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
* @brief 动态库动态加载类
* @note  
*/
class SYSTEM_EXPORT CLibrary
{
public:
	/**
	 * @fn       CLibrary(const std::string& strFileName)   
	 * @brief    构造函数   
	 * @param    const std::string& strFileName 动态库的文件名，可以带上相对路径            
	*/
	CLibrary(const char* strFileName = "");
	~CLibrary();

public:
	/**
	 * @fn       bool Load()   
	 * @brief    加载动态库        
	 * @return   bool	成功返回true，失败返回false       
	*/
	bool Load();

	/**
	 * @fn       bool Unload()   
	 * @brief    卸载动态库       
	 * @return   bool	成功返回true，失败返回false       
	*/
	bool Unload();

	/**
	 * @fn       void* Resolve(const std::string& strSymbol)   
	 * @brief    获取动态库中的函数地址   
	 * @param    const std::string& strSymbol 函数名称           
	 * @return   void*	函数地址       
	*/
	void* Resolve(const char* strSymbol);

	/**
	 * @fn       bool IsLoaded()   
	 * @brief    是否已经加载        
	 * @return   bool	已加载返回true，否则返回false       
	*/
	bool IsLoaded();

	/**
	 * @fn       bool SetFileName(const std::string& strFileName)   
	 * @brief    设置要加载的文件名，如果文件名和上一次的文件名不一样，则先卸载上一次已经加载的动态库   
	 * @param    const std::string& strFileName  文件名         
	 * @return   bool	成功返回true，失败返回false       
	*/
	bool SetFileName(const char* strFileName);

	/**
	 * @fn       std::string& GetFilePath()   
	 * @brief    获取动态库的绝对路径       
	 * @return   std::string&	动态库的绝对路径       
	*/
	const char* GetFilePath();

	/**
	 * @fn       void* Resolve(const std::string& strFileName,const std::string& strSymbol)   
	 * @brief    获取指定文件名的动态库中的函数地址   
	 * @param    const std::string& strFileName  文件名     
	 * @param    const std::string& strSymbol  函数名称          
	 * @return   void*	函数地址       
	*/
	static void* Resolve(const char* strFileName,const char* strSymbol);

	/**
	 * @fn       CLibrary *Clone() 
	 * @brief    克隆原始文件  
	 * @param    const std::string& strFileName  文件名           
	 * @return   void*	函数地址       
	*/
	CLibrary *Clone();
private:
	LibraryHandle m_hHandle;		///<加载库的句柄

	char m_strFileName[52];
	//std::string m_strFileName;		///<用户输入的文件名，可能是带相对路径的文件名 输入参数必须为UTF-8 编码路径
	char m_strFilePath[256];
	//std::string m_strFilePath;		///<文件的真正路径

	bool m_IsSucc;				// load成功标志

};
#endif
