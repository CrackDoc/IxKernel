#ifndef SceneEventObject_h__
#define SceneEventObject_h__

#include "EventObject.h"

class KERNEL_EXPORT CSceneEventObject : public CEventObject
{
public:
	enum E_EVENT_SCENE
	{
		E_EVENT_OBJECT_NONE = 0,
		E_EVENT_OBJECT_DRAG = 1,
		E_EVENT_OBJECT_PICK = 2,
		E_EVENT_OBJECT_UNPICK = 3,
		E_EVENT_OBJECT_HOVER = 4,
		E_EVENT_OBJECT_LEAVE = 5,
		E_EVENT_OBJECT_MOVE = 6,
		E_EVENT_OBJECT_INVOKE = 7,
		E_EVENT_OBJECT_SHOW = 8,
		E_EVENT_OBJECT_HIDE = 9,
		E_EVENT_OBJECT_HIGHLIGHT = 10,
		E_EVENT_LABEL_DRAG = 20,
		E_EVENT_LABEL_MOVE = 21,
		E_EVENT_LABEL_PICK = 22,
		E_EVENT_LABEL_HOVER = 23,
		E_EVENT_LABEL_LEAVE = 24,
		E_EVENT_LABEL_SHOW = 25,
		E_EVENT_LABEL_HIDE = 26,
	};
public:
	CSceneEventObject();
	~CSceneEventObject();

	CEventObject* Clone() const;

	void SetObjectID(int nId);

	int GetObjectID() const;

	void SetEventScene(E_EVENT_SCENE eEventScene);

	E_EVENT_SCENE GetEventScene() const;
	
protected:
	int m_nObjectID;			//≥°æ∞ŒÔÃÂID
	E_EVENT_SCENE m_eEventScene;
};
#endif // SceneEventObject_h__
