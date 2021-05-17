#ifndef WindowEventObject_h__
#define WindowEventObject_h__

#include "EventObject.h"
#include "Variant.h"
#include "Vector2D.h"

class KERNEL_EXPORT CWindowEventObject : public CEventObject
{
public:
	
	enum E_WINDOW_EVENT_TYPE
	{
		E_WINDOW_EVENT_TYPE_NONE = 0,
		E_WINDOW_EVENT_TYPE_DROP = 1,
		E_WINDOW_EVENT_TYPE_RESIZE = 2,	
	};

public:
	CWindowEventObject();
	~CWindowEventObject();

	CEventObject* Clone() const;

	//消息类型
	void SetWindowEventType(E_WINDOW_EVENT_TYPE eWindowEventType);

	E_WINDOW_EVENT_TYPE GetWindowEventType() const;

	void SetMousePosition(const CVector2D& rPosition);

	CVector2D GetMousePosition() const;

	void SetWindowPosition(const CVector2D& rPosition);

	CVector2D GetWindowPosition() const;

	void SetWindowSize(const CVector2D& rSize);

	CVector2D GetWindowSize() const;

	void SetAppendData(const Variant& rData);

	Variant& GetAppendData();

	const Variant& GetAppendData() const;

protected:
	E_WINDOW_EVENT_TYPE m_eWindowEventType;
	CVector2D m_vWindowSize;
	CVector2D m_vMousePosition;
	CVector2D m_vWindowPosition;
	Variant m_vAppendData;
};

#endif // WindowEventObject_h__
