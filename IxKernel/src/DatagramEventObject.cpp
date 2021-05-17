#include "DatagramEventObject.h"

CDatagramEventObject::CDatagramEventObject()
{
	memset(m_strDescription, '\0', sizeof(char) * 256);
}

CDatagramEventObject::~CDatagramEventObject()
{

}

CEventObject* CDatagramEventObject::Clone() const
{
	CDatagramEventObject *pCEventObject = new CDatagramEventObject;
	pCEventObject->SetCache(m_Cache);
	pCEventObject->SetDescription(m_strDescription);
	pCEventObject->SetEventFormat(m_eEventFormat);
	pCEventObject->SetIdentityCode(m_nIdentityCode);
	pCEventObject->SetUserData1(m_pUserData1);
	pCEventObject->SetUserData2(m_pUserData2);
	return pCEventObject;
}

void CDatagramEventObject::SetEventFormat( E_EVENT_FORMAT eEventFormat )
{
	m_eEventFormat = eEventFormat;
}

CDatagramEventObject::E_EVENT_FORMAT CDatagramEventObject::GetEventFormat() const
{
	return m_eEventFormat;
}

void CDatagramEventObject::SetDescription( const char* strDescription )
{
	memset(m_strDescription, '\0', sizeof(char) * 256);
	strcat_s(m_strDescription, strDescription);
}

const char* CDatagramEventObject::GetDescription() const
{
	return m_strDescription;
}

void CDatagramEventObject::SetCache( const CCache& rhs )
{
	m_Cache = rhs;
}

void CDatagramEventObject::SetCache( unsigned char* pBufferLen, int nLen )
{
	m_Cache = CCache(pBufferLen,nLen);
}

CCache& CDatagramEventObject::GetCache()
{
	return m_Cache;
}

const CCache& CDatagramEventObject::GetCache() const
{
	return m_Cache;
}

void CDatagramEventObject::SetUserData1( void* pUserData )
{
	m_pUserData1 = pUserData;
}

void* CDatagramEventObject::GetUserData1() const
{
	return m_pUserData1;
}

void CDatagramEventObject::SetUserData2( void* pUserData )
{
	m_pUserData2 = pUserData;
}

void* CDatagramEventObject::GetUserData2() const
{
	return m_pUserData2;
}

void CDatagramEventObject::SetIdentityCode( int nID )
{
	m_nIdentityCode = nID;
}

int CDatagramEventObject::GetIdentityCode() const
{
	return m_nIdentityCode;
}

