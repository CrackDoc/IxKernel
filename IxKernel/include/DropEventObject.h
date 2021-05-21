//////////////////////////////////////////////////////////////////////////
//	@File		:	DropEventObject.h
//	@Data		:	2016-6-14 14:28
//	@Author		:	ZC
//	@Brief		:	拖拽的事件对象。目前在拖拽的时候，没有把QT的事件进行克隆，因此
//					这里存储的事件指针是临时的。事件必须是直接调用。
//////////////////////////////////////////////////////////////////////////
#pragma once
//#include <QEvent>
//#include "EventObject.h"
//#include "IxKernelExport.h"
//
//class KERNEL_EXPORT CDropEventObject : public CEventObject
//{
//public:
//	CDropEventObject(QEvent* pEvent)
//		: m_pEvent(pEvent)
//	{
//		SetEventType(E_EVENT_TYPE_DROP);
//	}
//	virtual ~CDropEventObject(){};
//	QEvent* GetEvent(){ return m_pEvent; };
//
//private:
//	virtual CEventObject* Clone() const { return NULL; };
//	CDropEventObject(const CDropEventObject& rParam){};
//	CDropEventObject& operator=(const CDropEventObject& rParam){ return *this; };
//	
//protected:
//	QEvent *m_pEvent;
//};
