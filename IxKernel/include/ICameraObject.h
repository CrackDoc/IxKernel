#ifndef ICameraObject_h__
#define ICameraObject_h__

#include "IObject.h"
#include "KernelConstant.h"

class ICameraObject : public IObject
{
public:
	virtual ~ICameraObject(){}

	virtual CVector3D GetEyesightVector() = 0;
};
#endif // ICameraObject_h__
