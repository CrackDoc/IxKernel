#include "StateEventObject.h"
#include "ThreadEvent.h"

CStateEventObject::CStateEventObject()
{

}

CStateEventObject::~CStateEventObject()
{

}

CEventObject* CStateEventObject::Clone() const
{
	//CEventObject *pObject = new CEventObject;
	//pObject->SetSenderName(this->GetSender());
	//pObject->SetReceiver(this->GetReceiver());

	//pObject->SGetSafeEvent();
	//pObject->m_bBlock = IsBlock()

	//pObject->m_nStateType = GetStateType();
	//pObject->m_vCurrentStateValue = GetCurrentStateValue();
	//pObject->m_vOldStateValue = GetOldStateValue();

	return NULL;
}
void CStateEventObject::SetSender( void* pSender )
{
	m_pSender = pSender;
}

void* CStateEventObject::GetSender() const
{
	return m_pSender;
}

void CStateEventObject::SetReceiver( void* pReceiver )
{
	m_pReceiver = pReceiver;
}

void* CStateEventObject::GetReceiver() const
{
	return m_pReceiver;
}

void CStateEventObject::SetBlock( bool bBlock )
{
	m_bBlock = bBlock;
}

bool CStateEventObject::IsBlock() const
{
	return m_bBlock;
}

void CStateEventObject::SetStateType( int nStateType )
{
	m_nStateType = nStateType;
}

int CStateEventObject::GetStateType() const
{
	return m_nStateType;
}

void CStateEventObject::SetCurrentStateValue( Variant rValue )
{
	m_vCurrentStateValue = rValue;
}

Variant& CStateEventObject::GetCurrentStateValue()
{
	return m_vCurrentStateValue;
}

Variant CStateEventObject::GetCurrentStateValue() const
{
	return m_vCurrentStateValue;
}

void CStateEventObject::SetOldStateValue( Variant vValue ) 
{
	m_vOldStateValue = vValue;
}

Variant& CStateEventObject::GetOldStateValue()
{
	return m_vOldStateValue;
}

Variant CStateEventObject::GetOldStateValue() const
{
	return m_vOldStateValue;
}

void CStateEventObject::SetSafeEvent( CThreadEvent* pEvent )
{
	m_pSafeEvent = pEvent;
}

CThreadEvent* CStateEventObject::GetSafeEvent() const
{
	return m_pSafeEvent;
}

bool GenerStateEventObj( const char* strCommand,CStateEventObject& objOut )
{
	return true;
}
