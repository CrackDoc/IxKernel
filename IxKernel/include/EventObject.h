/***********************************************************************
* Module:  CEventDataObj.h
* Author:  Administrator
* Modified: 2015年12月9日 14:48:46
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
		E_EVENT_TYPE_MOUSE = 0,		//鼠标事件
		E_EVENT_TYPE_KEYBORAD = 1,	//键盘事件
		E_EVENT_TYPE_COMMAND = 2,	//命令事件
		E_EVENT_TYPE_FRAME = 3,		//帧更新事件
		E_EVENT_TYPE_DATAGRAM = 4,	//数据报文事件[网络模块]
		E_EVENT_TYPE_SCENE = 5,		//场景产生事件[不区分2D|3D]
		E_EVENT_TYPE_STATE = 6,		//状态事件
		E_EVENT_TYPE_DROP = 7,		//拖拽事件
		E_EVENT_TYPE_WINDOW = 8,	//窗口事件
		E_EVENT_TYPE_USER = 20,		//用户事件
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

	//该接口返回一个克隆的对象,子类必须实现
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
	double m_dDelayTime;	//距离该消息触发，还需要的时间
	char m_SenderName[32];
	//std::string m_SenderName;
	bool m_bBroadcastEvent;
	void* m_strSendContent;
	size_t m_ContentLength;
	//std::string m_strSendContent; // 发送的消息内容

private:
	CThreadEvent *m_pThreadEvent;	
};

#endif // EventObject_h__
