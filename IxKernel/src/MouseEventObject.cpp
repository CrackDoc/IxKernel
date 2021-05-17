#include "MouseEventObject.h"

CMouseEventObject::CMouseEventObject()
{

}

CMouseEventObject::~CMouseEventObject()
{

}

CEventObject* CMouseEventObject::Clone() const
{
	CMouseEventObject *pObject = new CMouseEventObject;

	pObject->SetMouseButton(m_eMouseButton);
	pObject->SetMouseEventType(m_eMouseEventType);
	pObject->SetScreenXY(GetScreenX(),GetScreenY());
	pObject->SetMouseScroll(GetScrollX(),GetScrollY());

	return pObject;
}

void CMouseEventObject::SetMouseButton(E_MOUSE_BUTTON eMouseButton)
{
	m_eMouseButton = eMouseButton;
}

CMouseEventObject::E_MOUSE_BUTTON CMouseEventObject::GetMouseButton() const
{
	return m_eMouseButton;
}

void CMouseEventObject::SetMouseEventType(E_MOUSE_EVENT_TYPE eMouseEventType)
{
	m_eMouseEventType = eMouseEventType;
}

CMouseEventObject::E_MOUSE_EVENT_TYPE CMouseEventObject::GetMouseEventType() const
{
	return m_eMouseEventType;
}

void CMouseEventObject::SetScreenXY(int x, int y)
{
	m_nScreenX = x;
	m_nScreenY = y;
}

int CMouseEventObject::GetScreenX() const
{
	return m_nScreenX;
}

int CMouseEventObject::GetScreenY() const
{
	return m_nScreenY;
}

void CMouseEventObject::SetMouseScroll(float fX, float fY)
{
	m_fScrollX = fX;
	m_fScrollY = fY;

}

float CMouseEventObject::GetScrollX()const
{
	return m_fScrollX;
}

float CMouseEventObject::GetScrollY()const
{
	return m_fScrollY;
}

CMouseEventObject::E_MOUSE_BUTTON CMouseEventObject::ConvertOsgMouseButton(int nOsgButton)
{
	return E_MOUSE_BUTTON_NONE;
}
