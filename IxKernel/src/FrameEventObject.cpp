#include "FrameEventObject.h"

CFrameEventObject::CFrameEventObject()
{

}

CFrameEventObject::~CFrameEventObject()
{

}

CEventObject* CFrameEventObject::Clone() const
{
	CFrameEventObject *pCEventObject = new CFrameEventObject();
	pCEventObject->SetElapsedTime(m_dElapsedTime);
	return pCEventObject;
}

void CFrameEventObject::SetElapsedTime( double dElapsedTime )
{
	m_dElapsedTime = dElapsedTime;
}

double CFrameEventObject::GetElapsedTime()
{
	return m_dElapsedTime;
}

