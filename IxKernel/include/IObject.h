/***********************************************************************
* Module:  IObject.h
* Author:  Administrator
* Modified: 2015年12月9日 14:43:17
* Purpose: Declaration of the class IObject
* Comment: 基类
***********************************************************************/
#ifndef IObject_h__
#define IObject_h__
#include <string>
#include "IxKernelExport.h"

#define CAS_META_OBJECT() \
public:\
	virtual const char* GetClassType() const {return m_strClassType;}\
	virtual void SetClassType(const char* strClassType) {memset(m_strClassType,'\0',sizeof(char)*128);strcat_s(m_strClassType,strClassType);}\
protected: \
	char m_strClassType[128];

// IOject类作为所有CAS对象的基类 [5/25/2016 CETC]
class KERNEL_EXPORT IObject
{
	CAS_META_OBJECT()

public:
	virtual ~IObject(){}

	virtual int GetID() = 0;
};

template <typename T>
bool IsKindOf(IObject* pObject)
{
	return (NULL != dynamic_cast<T*>(pObject));
}
	
#endif // IObject_h__
