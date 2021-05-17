#include "CommandEventObject.h"

CCommandEventObject::CCommandEventObject( const char* strCommand /*= ""*/ ):
	 m_bExclusive(true)
{
	memset(m_strCommadBuffer, '\0', sizeof(char) * 256);
	strcat_s(m_strCommadBuffer, strCommand);

}

CCommandEventObject::~CCommandEventObject()
{

}

void CCommandEventObject::SetCommand( const char* strCmd )
{
	memset(m_strCommadBuffer, '\0', sizeof(char) * 256);
	strcat_s(m_strCommadBuffer, strCmd);
}

void * CCommandEventObject::GetCommand()
{
	return &m_strCommadBuffer;
}

const char* CCommandEventObject::GetCommand() const
{
	return m_strCommadBuffer;
}

CEventObject* CCommandEventObject::Clone() const
{
	CCommandEventObject *pCommandEventObject = new CCommandEventObject(m_strCommadBuffer);
	pCommandEventObject->SetExclusive(m_bExclusive);
	return pCommandEventObject;
}

void CCommandEventObject::SetExclusive( bool bExclusive )
{
	m_bExclusive = bExclusive;
}

bool CCommandEventObject::IsExclusive() const
{
	return m_bExclusive;
}
