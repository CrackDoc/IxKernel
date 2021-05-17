#ifndef MouseEventObject_h__
#define MouseEventObject_h__

#include "EventObject.h"
//#include "qnamespace.h"

class KERNEL_EXPORT CMouseEventObject : public CEventObject
{
public:
	enum E_MOUSE_BUTTON
	{
		E_MOUSE_BUTTON_NONE = 0,	// Û±Í“∆∂Ø
		E_MOUSE_BUTTON_LEFT = 1,
		E_MOUSE_BUTTON_RIGHT = 2,
		E_MOUSE_BUTTON_MIDDLE = 3,
	};

	enum E_MOUSE_EVENT_TYPE
	{
		E_MOUSE_EVENT_TYPE_NONE = 0,
		E_MOUSE_EVENT_TYPE_PUSH = 1,
		E_MOUSE_EVENT_TYPE_RELEASE = 2,
		E_MOUSE_EVENT_TYPE_DOUBLECLICK = 3,
		E_MOUSE_EVENT_TYPE_MOVE = 4,
		E_MOUSE_EVENT_TYPE_DRAG = 5,
		E_MOUSE_EVENT_TYPE_SCROLL = 6,
		E_MOUSE_EVENT_TYPE_CLICKED = 7,
	};
public:
	CMouseEventObject();
	~CMouseEventObject();

	CEventObject* Clone() const;

	void SetMouseButton(E_MOUSE_BUTTON eMouseButton);

	E_MOUSE_BUTTON GetMouseButton() const;

	void SetMouseEventType(E_MOUSE_EVENT_TYPE eMouseEventType);

	E_MOUSE_EVENT_TYPE GetMouseEventType() const;

	void SetScreenXY(int x, int y);

	int GetScreenX() const;

	int GetScreenY() const;

	void SetMouseScroll(float fX, float fY);

	float GetScrollX()const;

	float GetScrollY()const;

	static E_MOUSE_BUTTON ConvertOsgMouseButton(int nOsgButton);

	//static E_MOUSE_BUTTON ConvertQtMouseButton(Qt::MouseButton eQtButton);

protected:
	E_MOUSE_BUTTON m_eMouseButton;
	E_MOUSE_EVENT_TYPE m_eMouseEventType;
	int m_nScreenX;
	int m_nScreenY;
	float m_fScrollX;
	float m_fScrollY;
};
#endif // MouseEventObject_h__
