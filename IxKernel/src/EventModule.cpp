#include "EventModule.h"
#include "ThreadMutex.h"
#include "Task.h"
#include "NullScriptFunctionAnalyse.h"

#include <algorithm>
#include "EventObject.h"
#include "Guid.h"
#include <map>
#include <list>
CEventModule::CEventModule(void):
	m_pCommandEventMutex(new CThreadMutex)
	,m_bRunning(true)
	, m_MapCommandEventObserver(new std::map<std::string, ICommandEventObserver*>())
	, m_ListCommandObject(new std::list<CEventObject*>())
{
}

CEventModule::~CEventModule(void)
{
	if(m_pCommandEventMutex != NULL)
	{
		delete m_pCommandEventMutex;
		m_pCommandEventMutex = NULL;
	}
	if (!m_MapCommandEventObserver)
	{
		delete m_MapCommandEventObserver;
	}
	if (m_ListCommandObject)
	{
		delete m_ListCommandObject;
	}
	Quit();
	Wait();
}
void CEventModule::Initialize(bool isQueue)
{
	//�����߳�
	if(isQueue)
	{
		Activate();
	}
}

void CEventModule::UnInitialize()
{
	m_bRunning = false;
}

void CEventModule::RegisterMouseEventObserver( IMouseEventObserver* pMouseOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pMouseOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterMouseEventObserver( IMouseEventObserver* pMouseOb )
{

}

void CEventModule::RegisterCommandEventObserver( ICommandEventObserver* pCommandOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pCommandOb->SetObServerId(strUuid);

	m_pCommandEventMutex->Acquire();

	std::map<std::string,ICommandEventObserver*> &MapCommandEventObserver = *static_cast<std::map<std::string, ICommandEventObserver*>*>(m_MapCommandEventObserver);
	MapCommandEventObserver.insert(std::map<std::string,ICommandEventObserver*>::value_type(strUuid,pCommandOb));
	m_pCommandEventMutex->Release();
	
}

void CEventModule::UnregisterCommandEventObserver( ICommandEventObserver* pCommandOb )
{
	m_pCommandEventMutex->Acquire();
	std::map<std::string, ICommandEventObserver*>& MapCommandEventObserver = *static_cast<std::map<std::string, ICommandEventObserver*>*>(m_MapCommandEventObserver);

	std::map<std::string,ICommandEventObserver*>::iterator it0 = MapCommandEventObserver.find(pCommandOb->GetObServerId());
	if(it0 != MapCommandEventObserver.end())
	{
		MapCommandEventObserver.erase(it0);
		delete pCommandOb;
		pCommandOb = NULL;
	}
	m_pCommandEventMutex->Release();
}

void CEventModule::RegisterKeyboardEventObserver( IKeyboadEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterKeyboardEventObserver( IKeyboadEventObserver* pOb )
{

}

void CEventModule::RegisterFrameEventObserver( IFrameEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterFrameEventObserver( IFrameEventObserver* pOb )
{

}

void CEventModule::RegisterDatagramEventObserver( IDatagramEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterDatagramEventObserver( IDatagramEventObserver* pOb )
{

}

void CEventModule::RegisterSceneEventObserver( ISceneEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterSceneEventObserver( ISceneEventObserver* pOb )
{

}

void CEventModule::RegisterStateEventObserver( IStateEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterStateEventObserver( IStateEventObserver* pOb )
{

}

void CEventModule::RegisterDropEventObserver( IDropEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterDropEventObserver( IDropEventObserver* pOb )
{

}

void CEventModule::RegisterWindowEventObserver( IWindowEventObserver* pOb )
{
	std::string strUuid = CGuid::GenerateGuid().toString();
	pOb->SetObServerId(strUuid);
}

void CEventModule::UnregisterWindwoEventObserver( IWindowEventObserver* pOb )
{

}

CTask::E_TASK_STATE CEventModule::OnRunTask()
{
	while(m_bRunning)
	{
		CTask *pTask = this;
		IMPLEMENT_TASK_CRITICAL(pTask);
		m_pCommandEventMutex->Acquire();

		std::list<CEventObject*>& ListCommandObject = *static_cast<std::list<CEventObject*>*>(m_ListCommandObject);

		std::list<CEventObject*>::iterator it0 = ListCommandObject.begin();
		for (;it0 != ListCommandObject.end();++it0)
		{
			CEventObject *object = *it0;
			//�ȴ�1ms ��,������ź��ѷ���
			bool bAcquire = object->GetThreadEvent()->Wait(0);
			if(bAcquire)
			{
				std::map<std::string, ICommandEventObserver*>& MapCommandEventObserver = *static_cast<std::map<std::string, ICommandEventObserver*>*>(m_MapCommandEventObserver);

				std::map<std::string,ICommandEventObserver*>::iterator it0 = MapCommandEventObserver.begin();

				for(;it0 != MapCommandEventObserver.end();++it0)
				{
					ICommandEventObserver *pObserver = it0->second;

					CNullScriptFunctionAnalyse *pCNullScriptFunctionAnalyse = new CNullScriptFunctionAnalyse;
					pCNullScriptFunctionAnalyse->Load((char*)object->GetSendContent(), object->GetContentLength());
					pObserver->OnCommand(pCNullScriptFunctionAnalyse,object);
					delete pCNullScriptFunctionAnalyse;
					pCNullScriptFunctionAnalyse = NULL;
					MapCommandEventObserver.erase(it0);
				}
			}
		}
		m_pCommandEventMutex->Release();

	}
	return CTask::E_COMPLETED;
}

void CEventModule::OnRecycleThreadQuit()
{

}
//�¼����ͳ�ȥ�������̴߳���������ô��
bool CEventModule::SendEvent( CEventObject* pEvent, bool bPost /*= false*/ )
{
	CEventObject::E_EVNT_TYPE cmdType = (CEventObject::E_EVNT_TYPE)pEvent->GetEventType();

	// ����Ϣ������Ϣ������,
	switch(cmdType)
	{
		case CEventObject::E_EVENT_TYPE_MOUSE:	//����¼�
			{

			}
			break;
		case CEventObject::E_EVENT_TYPE_KEYBORAD://�����¼�
			{

			}
			break;
		case CEventObject::E_EVENT_TYPE_COMMAND://�����¼�
			{
				m_pCommandEventMutex->Acquire();
				if(bPost)
				{
					std::map<std::string, ICommandEventObserver*>& MapCommandEventObserver = *static_cast<std::map<std::string, ICommandEventObserver*>*>(m_MapCommandEventObserver);

					std::map<std::string,ICommandEventObserver*>::iterator it0 = MapCommandEventObserver.begin();

					for(;it0 != MapCommandEventObserver.end();++it0)
					{
						ICommandEventObserver *pObserver = it0->second;

						//CNullScriptFunctionAnalyse *pCNullScriptFunctionAnalyse = new CNullScriptFunctionAnalyse;
						//pCNullScriptFunctionAnalyse->Load((char*)pObserver->GetSendContent(), object->GetContentLength());
						//pObserver->OnCommand(pCNullScriptFunctionAnalyse);
						//delete pCNullScriptFunctionAnalyse;
						//pCNullScriptFunctionAnalyse = NULL;

						MapCommandEventObserver.erase(it0);
					}
				}
				else
				{
					if(!IsRunning())
					{
						this->Activate();
					}
					std::list<CEventObject*>& ListCommandObject = *static_cast<std::list<CEventObject*>*>(m_ListCommandObject);

					ListCommandObject.push_back(pEvent);
					pEvent->GetThreadEvent()->Signal();
				}
				m_pCommandEventMutex->Release();
			}	
			break;
		case CEventObject::E_EVENT_TYPE_FRAME://֡�����¼�
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_DATAGRAM: //���ݱ����¼�[����ģ��]
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_SCENE: //���������¼�[������2D|3D]
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_STATE: //״̬�¼�
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_DROP://��ק�¼�
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_WINDOW://�����¼�
			{

			}	
			break;
		case CEventObject::E_EVENT_TYPE_USER://�û��¼�
			{

			}
			break;
	}
	return false;
}
