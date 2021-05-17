#ifndef StateEventObject_h__
#define StateEventObject_h__

#include "EventObject.h"
#include "Variant.h"

class CThreadEvent;

// 该消息支持阻塞式,且支持点对点发送 [8/7/2019 kyske]
class KERNEL_EXPORT CStateEventObject : public CEventObject
{
public:
	enum
	{
		E_STATE_TYPE_2D3DSWAP = 0,		//2D,3D场景切换
		E_STATE_TYPE_FULLSCREEN = 1,	//全屏状态切换
		E_STATE_TYPE_NAVIMAP = 2,		//导航图开关切换
		E_STATE_TYPE_SCALEBAR = 6,		//比例尺开关
		E_STATE_TYPE_USERLOGIN = 3,		//用户登录
		E_STATE_TYPE_RETURN_LOGIN = 4,	//返回用户登录
		E_STATE_TYPE_LIGHTONOFF	= 5,	//光照开关
		E_STATE_TYPE_PADHOME    = 6,    //PAD Home按键
		E_STATE_TYPE_PADPAGE_CHANGED = 7, //PAD底部窗口页面切换

		E_STATE_TYPE_USER_DEF = 0x0100,	//用户定义
	};
public:
	CStateEventObject();
	~CStateEventObject();

	CEventObject* Clone() const;

	void SetSender(void* pSender);

	void* GetSender() const;

	void SetReceiver(void* pReceiver);

	void* GetReceiver() const;

	void SetBlock(bool bBlock);

	bool IsBlock() const;

	//消息类型
	void SetStateType(int nStateType);

	int GetStateType() const;

	//新的状态值
	void SetCurrentStateValue(Variant rValue);

	Variant& GetCurrentStateValue();

	Variant GetCurrentStateValue() const;

	//旧的状态值
	void SetOldStateValue(Variant vValue);


	Variant& GetOldStateValue();

	Variant GetOldStateValue() const;

	void SetSafeEvent(CThreadEvent* pEvent);

	CThreadEvent* GetSafeEvent() const;

protected:
	mutable void* m_pSender;
	mutable void* m_pReceiver;
	mutable CThreadEvent* m_pSafeEvent;
	mutable bool m_bBlock;

	mutable int m_nStateType;
	mutable Variant m_vCurrentStateValue; 
	mutable Variant m_vOldStateValue;
};

//根据命令生成状态信息
extern bool KERNEL_EXPORT GenerStateEventObj(const char* strCommand,CStateEventObject& objOut);

#endif // StateEventObject_h__
