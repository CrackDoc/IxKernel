/***********************************************************************
* Module:  CEventDataObj.h
* Author:  Administrator
* Modified: 2015��12��9�� 14:48:46
* Purpose: Declaration of the class CEventObject
***********************************************************************/
#ifndef EventObject_h__
#define EventObject_h__

#include "KernelExport.h"
#include "ThreadEvent.h"

class KERNEL_EXPORT CEventObject
{
public:
	enum E_EVNT_TYPE
	{
		E_EVENT_TYPE_MOUSE = 0,		//����¼�
		E_EVENT_TYPE_KEYBORAD = 1,	//�����¼�
		E_EVENT_TYPE_COMMAND = 2,	//�����¼�
		E_EVENT_TYPE_FRAME = 3,		//֡�����¼�
		E_EVENT_TYPE_DATAGRAM = 4,	//���ݱ����¼�[����ģ��]
		E_EVENT_TYPE_SCENE = 5,		//���������¼�[������2D|3D]
		E_EVENT_TYPE_STATE = 6,		//״̬�¼�
		E_EVENT_TYPE_DROP = 7,		//��ק�¼�
		E_EVENT_TYPE_WINDOW = 8,	//�����¼�
		E_EVENT_TYPE_USER = 20,		//�û��¼�
	};
public:
	CEventObject(CThreadEvent *pThreadEvent = NULL);

	virtual ~CEventObject();

	void SetEventType(int nEvtType);

	void SetEventCode(int nEvtCode);

	int GetEventType() const;

	int GetEventCode() const;

	void SetSendID(const char* nSendId);

	void SetDestID(const char* nDstId);

	const char* GetSendID() const;

	const char* GetDestID() const;

	void SetSenderName(const char* strName);

	const char* GetSenderName() const;

	//�ýӿڷ���һ����¡�Ķ���,�������ʵ��
	virtual CEventObject* Clone() const;

	bool IsBroadcastEvent() const;

	void SetBroadcastEvent(bool bBrodcast);

	double GetDelayTime() const;

	void SetDelayTime(double dDelayTime) ;

	void TimeElapsed(double dElapsedTime);

	CThreadEvent *GetThreadEvent();

	void SetThreadEvent(CThreadEvent *pThreadEvent);

	void SetSendContent(const char* strContent);

	void * GetSendContent() const;

	size_t GetContentLength() const;

protected:
	int m_nEventType;
	int m_nEventCode;

	char m_nSendID[32];
	//std::string m_nSendID;
	//std::string m_nDestID;
	char m_nDestID[32];
	double m_dDelayTime;	//�������Ϣ����������Ҫ��ʱ��
	char m_SenderName[32];
	//std::string m_SenderName;
	bool m_bBroadcastEvent;
	void* m_strSendContent;
	size_t m_ContentLength;
	//std::string m_strSendContent; // ���͵���Ϣ����

private:
	CThreadEvent *m_pThreadEvent;	
};

#endif // EventObject_h__
