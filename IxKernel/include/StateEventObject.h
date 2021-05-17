#ifndef StateEventObject_h__
#define StateEventObject_h__

#include "EventObject.h"
#include "Variant.h"

class CThreadEvent;

// ����Ϣ֧������ʽ,��֧�ֵ�Ե㷢�� [8/7/2019 kyske]
class KERNEL_EXPORT CStateEventObject : public CEventObject
{
public:
	enum
	{
		E_STATE_TYPE_2D3DSWAP = 0,		//2D,3D�����л�
		E_STATE_TYPE_FULLSCREEN = 1,	//ȫ��״̬�л�
		E_STATE_TYPE_NAVIMAP = 2,		//����ͼ�����л�
		E_STATE_TYPE_SCALEBAR = 6,		//�����߿���
		E_STATE_TYPE_USERLOGIN = 3,		//�û���¼
		E_STATE_TYPE_RETURN_LOGIN = 4,	//�����û���¼
		E_STATE_TYPE_LIGHTONOFF	= 5,	//���տ���
		E_STATE_TYPE_PADHOME    = 6,    //PAD Home����
		E_STATE_TYPE_PADPAGE_CHANGED = 7, //PAD�ײ�����ҳ���л�

		E_STATE_TYPE_USER_DEF = 0x0100,	//�û�����
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

	//��Ϣ����
	void SetStateType(int nStateType);

	int GetStateType() const;

	//�µ�״ֵ̬
	void SetCurrentStateValue(Variant rValue);

	Variant& GetCurrentStateValue();

	Variant GetCurrentStateValue() const;

	//�ɵ�״ֵ̬
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

//������������״̬��Ϣ
extern bool KERNEL_EXPORT GenerStateEventObj(const char* strCommand,CStateEventObject& objOut);

#endif // StateEventObject_h__
