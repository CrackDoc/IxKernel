#ifndef FrameEventObject_h__
#define FrameEventObject_h__

#include "EventObject.h"

class KERNEL_EXPORT CFrameEventObject : public CEventObject
{
public:
	CFrameEventObject();
	~CFrameEventObject();

	CEventObject* Clone() const;

	void SetElapsedTime(double dElapsedTime);

	double GetElapsedTime();
protected:
	double m_dElapsedTime;
};
#endif // FrameEventObject_h__
