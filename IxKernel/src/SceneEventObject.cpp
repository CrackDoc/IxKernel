#include "SceneEventObject.h"

CSceneEventObject::CSceneEventObject()
{

}

CSceneEventObject::~CSceneEventObject()
{

}

CEventObject* CSceneEventObject::Clone() const
{
	CSceneEventObject *pEventObject = new CSceneEventObject;
	pEventObject->SetObjectID(m_nObjectID);
	pEventObject->SetEventScene(m_eEventScene);
	return pEventObject;
}

void CSceneEventObject::SetObjectID( int nId )
{
	m_nObjectID = nId;
}

int CSceneEventObject::GetObjectID() const
{
	return m_nObjectID;
}

void CSceneEventObject::SetEventScene( E_EVENT_SCENE eEventScene )
{
	m_eEventScene = eEventScene;
}

CSceneEventObject::E_EVENT_SCENE CSceneEventObject::GetEventScene() const
{
	return m_eEventScene;
}
