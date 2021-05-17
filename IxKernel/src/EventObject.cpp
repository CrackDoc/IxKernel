#include "EventObject.h"
#include <string>
CEventObject::CEventObject(CThreadEvent *pThreadEvent):
	  m_pThreadEvent(pThreadEvent)
	, m_bBroadcastEvent(false)
	, m_nEventType(-1)
	, m_nEventCode(-1)
	, m_dDelayTime(0.0)
	, m_strSendContent(nullptr)
	, m_ContentLength(0)
{
	memset(m_nSendID, '\0', sizeof(char) * 32);
	memset(m_nDestID, '\0', sizeof(char) * 32);
	memset(m_SenderName, '\0', sizeof(char) * 32);
}
CEventObject::~CEventObject()
{
	if (!m_strSendContent)
	{
		delete[] m_strSendContent;
		m_strSendContent = nullptr;
	}
}

void CEventObject::SetEventType( int nEvtType )
{
	m_nEventType = nEvtType;
}

void CEventObject::SetEventCode( int nEvtCode )
{
	m_nEventCode = nEvtCode;
}

int CEventObject::GetEventType() const
{
	return m_nEventType;
}

int CEventObject::GetEventCode() const
{
	return m_nEventCode;
}

void CEventObject::SetSendID( const char* nSendId )
{
	memset(m_nSendID, '\0', sizeof(char) * 32);
	strcat_s(m_nSendID, nSendId);
}

void CEventObject::SetDestID( const char* nDstId )
{
	memset(m_nDestID, '\0', sizeof(char) * 32);
	strcat_s(m_nDestID, nDstId);
}

const char* CEventObject::GetSendID() const
{
	return m_nSendID;
}

const char* CEventObject::GetDestID() const
{
	return m_nDestID;
}

void CEventObject::SetSenderName( const char* strName )
{
	memset(m_SenderName, '\0', sizeof(char) * 32);

	strcat_s(m_SenderName, strName);
}

const char* CEventObject::GetSenderName() const
{
	return m_SenderName;
}

CEventObject* CEventObject::Clone() const
{
	CEventObject *pClone = new CEventObject;

	pClone->SetDelayTime(m_dDelayTime);
	pClone->SetSendID(m_nSendID);
	pClone->SetDestID(m_nDestID);
	pClone->SetEventCode(m_nEventCode);
	pClone->SetEventType(m_nEventType);
	pClone->SetSenderName(m_SenderName);

	return pClone;
}

bool CEventObject::IsBroadcastEvent() const
{
	return m_bBroadcastEvent;
}

void CEventObject::SetBroadcastEvent( bool bBrodcast )
{
	m_bBroadcastEvent = bBrodcast;
}

double CEventObject::GetDelayTime() const
{
	return m_dDelayTime;
}

void CEventObject::SetDelayTime( double dDelayTime )
{
	m_dDelayTime = dDelayTime;
}

void CEventObject::TimeElapsed( double dElapsedTime )
{
	m_dDelayTime = dElapsedTime - dElapsedTime;
}

CThreadEvent * CEventObject::GetThreadEvent()
{
	return m_pThreadEvent;
}

void CEventObject::SetThreadEvent( CThreadEvent *pThreadEvent )
{
	if(m_pThreadEvent != NULL)
	{
		delete m_pThreadEvent;
		m_pThreadEvent = NULL;
	}
	m_pThreadEvent = pThreadEvent;
}

void CEventObject::SetSendContent(const char* strContent)
{
	m_ContentLength = strlen(strContent);
	char* pContent = new char[m_ContentLength];
	strcat(pContent, strContent);
	m_strSendContent = pContent;
}

void* CEventObject::GetSendContent() const
{
	return m_strSendContent;
}

size_t CEventObject::GetContentLength() const
{
	return m_ContentLength;
}

