#include "WindowEventObject.h"

CWindowEventObject::CWindowEventObject()
{

}

CWindowEventObject::~CWindowEventObject()
{

}

CEventObject* CWindowEventObject::Clone() const
{
	CWindowEventObject *pObject = new CWindowEventObject;
	pObject->SetWindowEventType(GetWindowEventType());
	pObject->SetMousePosition(GetMousePosition());
	pObject->SetWindowSize(GetWindowSize());
	pObject->SetAppendData(GetAppendData());

	return pObject;
}

void CWindowEventObject::SetWindowEventType( E_WINDOW_EVENT_TYPE eWindowEventType )
{
	m_eWindowEventType = eWindowEventType;
}

CWindowEventObject::E_WINDOW_EVENT_TYPE CWindowEventObject::GetWindowEventType() const
{
	return m_eWindowEventType;
}

void CWindowEventObject::SetMousePosition( const CVector2D& rPosition )
{
	m_vMousePosition = rPosition;
}

CVector2D CWindowEventObject::GetMousePosition() const
{
	return m_vMousePosition;
}

void CWindowEventObject::SetWindowPosition( const CVector2D& rPosition )
{
	m_vWindowPosition = rPosition;
}

CVector2D CWindowEventObject::GetWindowPosition() const
{
	return m_vWindowPosition;
}

void CWindowEventObject::SetWindowSize( const CVector2D& rSize )
{
	m_vWindowSize = rSize;
}

CVector2D CWindowEventObject::GetWindowSize() const
{
	return m_vWindowSize;
}

void CWindowEventObject::SetAppendData( const Variant& rData )
{
	m_vAppendData = rData;
}

Variant& CWindowEventObject::GetAppendData()
{
	return m_vAppendData;
}

const Variant& CWindowEventObject::GetAppendData() const
{
	return m_vAppendData;
}

