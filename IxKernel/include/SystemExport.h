#ifndef _SYSTEM_EXPORT_H_
#define _SYSTEM_EXPORT_H_

#include "SystemConfig.h"

#if defined(WIN32) 

#	if defined (SYSTEM_BUILD_DLL)	//�����̵�DLL����
#		define SYSTEM_EXPORT //__declspec(dllexport)
#	else
#		define SYSTEM_EXPORT //__declspec(dllimport)
#	endif

#else
#	define SYSTEM_EXPORT
#endif

#ifdef _MSC_VER
#	pragma warning (disable:4251)
#	pragma warning (disable:4275)
#	if defined(_MSC_VER) && _MSC_VER==1200//vc6.0
#		pragma warning (disable:4311)
#		pragma warning (disable:4786)
#		pragma warning (disable:4005)
#	elif defined(_MSC_VER) && _MSC_VER==1310//vc7.1
#		pragma warning (disable:4311)
#	elif defined(_MSC_VER) && _MSC_VER>=1400//vc8.0�Ժ�汾
#		pragma warning (disable:4311)
#		pragma warning (disable:4996)
#	endif
#endif

#endif
