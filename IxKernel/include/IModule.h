/***********************************************************************
* Module:  IModule.h
* Author:  Administrator
* Modified: 2015年12月9日 14:35:50
* Purpose: Declaration of the class IModule
* Comment: 所有模块的基类
***********************************************************************/

#ifndef IModule_h__
#define IModule_h__
#include "IObject.h"

class KERNEL_EXPORT IModule : public IObject
{
public:
	virtual ~IModule(){}

	virtual const char* GetName(void) = 0;
};
template <typename T>
inline std::string SymbolizeClassNameOfType()
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
    for (; i < strClassName.length(); ++i)
    {
        if (strClassName[i] >= 'A' && strClassName[i] <= 'z')
        {
            break;
        }
    }
    strClassName = strClassName.substr(i);
    std::cout << "class name is >>>>>> " << strClassName << std::endl;
#endif
    return strClassName;
}

#endif // IModule_h__
