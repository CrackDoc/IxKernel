#include "KeyboardEventObject.h"

CKeyboardEventObject::CKeyboardEventObject()
{

}

CKeyboardEventObject::~CKeyboardEventObject()
{

}

CEventObject* CKeyboardEventObject::Clone() const
{
	CKeyboardEventObject *pEventObject = new CKeyboardEventObject;
	pEventObject->SetKey(m_eKey);
	pEventObject->SetKeyEventType(m_eKeyEventType);
	pEventObject->SetModifier(m_eModifier);
	return pEventObject;
}

void CKeyboardEventObject::SetKey( E_KEY eKey )
{
	m_eKey = eKey;

}

CKeyboardEventObject::E_KEY CKeyboardEventObject::GetKey()
{
	return m_eKey;
}

void CKeyboardEventObject::SetModifier( E_MOD_KEY eModifier )
{
	m_eModifier = eModifier;
}

CKeyboardEventObject::E_MOD_KEY CKeyboardEventObject::GetModifier()
{
	return m_eModifier;
}

CKeyboardEventObject::E_KEY_EVENT_TYPE CKeyboardEventObject::GetKeyEventType()
{
	return m_eKeyEventType;
}

void CKeyboardEventObject::SetKeyEventType( E_KEY_EVENT_TYPE eKeyEventType )
{
	m_eKeyEventType = eKeyEventType;
}

