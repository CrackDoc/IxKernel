#pragma once
#ifndef EventModule_h__
#define EventModule_h__
#include "IEventModule.h"
#include "Task.h"

class CThreadMutex;

class CEventModule : public IEventModule,public CTask
{
public:
	CEventModule(void);
	virtual ~CEventModule(void);

	/**
	 * @fn  Initialize        
	 * @brief  
	 * @param 
	 * @return void
	 */
	void Initialize(bool isQueue = false);
	/**
	 * @fn   UnInitialize();    
	 * @brief
	 * @param
	 * @return void
	 */
	void UnInitialize();
	/**
	 * @fn  RegisterMouseEventObserver        
	 * @brief   @interface ע������¼��۲��߽ӿ�
	 * @param IMouseEventObserver * pMouseOb: ����¼��۲���
	 * @return void
	 */
	virtual void RegisterMouseEventObserver(IMouseEventObserver* pMouseOb);

	/**
	 * @fn  UnregisterMouseEventObserver        
	 * @brief   @interface ȡ������¼��۲���ע��ӿ�
	 * @param IMouseEventObserver * pMouseOb: ����¼��۲���
	 * @return void
	 */
	virtual void UnregisterMouseEventObserver(IMouseEventObserver* pMouseOb);

	/**
	 * @fn  RegisterCommandEventObserver        
	 * @brief  @interface ע�������¼��۲��߽ӿ�
	 * @param ICommandEventObserver * pCommandOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterCommandEventObserver(ICommandEventObserver* pCommandOb);

	/**
	 * @fn  UnregisterCommandEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param ICommandEventObserver * pCommandOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterCommandEventObserver(ICommandEventObserver* pCommandOb);

	/**
	 * @fn  RegisterKeyboardEventObserver        
	 * @brief   @interface ע������¼��۲��߽ӿ�
	 * @param IKeyboadEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterKeyboardEventObserver(IKeyboadEventObserver* pOb);

	/**
	 * @fn  UnregisterKeyboardEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param IKeyboadEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterKeyboardEventObserver(IKeyboadEventObserver* pOb);

	/**
	 * @fn  RegisterFrameEventObserver        
	 * @brief   @interface ע��֡�¼��۲��߽ӿ�
	 * @param IFrameEventObserver * pOb: ֡�¼��۲���
	 * @return void
	 */
	virtual void RegisterFrameEventObserver(IFrameEventObserver* pOb);

	/**
	 * @fn  UnregisterFrameEventObserver        
	 * @brief   @interface ȡ��֡�¼��۲���ע��ӿ�
	 * @param IFrameEventObserver * pOb: ֡�¼��۲���
	 * @return void
	 */
	virtual void UnregisterFrameEventObserver(IFrameEventObserver* pOb);

	/**
	 * @fn  RegisterDatagramEventObserver        
	 * @brief   @interface ע�����ݱ��¼��۲��߽ӿ�
	 * @param IDatagramEventObserver * pOb: ���ݱ��¼��۲���
	 * @return void
	 */
	virtual void RegisterDatagramEventObserver(IDatagramEventObserver* pOb);

	/**
	 * @fn  UnregisterDatagramEventObserver        
	 * @brief   @interface ȡ�����ݱ��¼��۲���ע��ӿ�
	 * @param IDatagramEventObserver * pOb: ���ݱ��¼��۲���
	 * @return void
	 */
	virtual void UnregisterDatagramEventObserver(IDatagramEventObserver* pOb);

	 /* @brief   @interface ע�᳡���¼��۲��߽ӿ�
	 * @param ISceneEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterSceneEventObserver(ISceneEventObserver* pOb);

	/**
	 * @fn  UnregisterSceneEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param ISceneEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterSceneEventObserver(ISceneEventObserver* pOb);

	//ע��״̬�¼��۲���
	/**
	 * @fn  RegisterStateEventObserver        
	 * @brief   @interface ע��״̬�¼��۲��߽ӿ�
	 * @param IStateEventObserver * pOb: ״̬�¼��۲���
	 * @return void
	 */
	virtual void RegisterStateEventObserver(IStateEventObserver* pOb);

	/**
	 * @fn  UnregisterStateEventObserver        
	 * @brief   @interface ȡ��״̬�¼��۲���ע��ӿ�
	 * @param IStateEventObserver * pOb: ״̬�¼��۲���
	 * @return void
	 */
	virtual void UnregisterStateEventObserver(IStateEventObserver* pOb);
	
	/**
	 * @fn  RegisterDropEventObserver        
	 * @brief   
	 * @param IDropEventObserver * pOb: 
	 * @return void
	 */
	virtual void RegisterDropEventObserver(IDropEventObserver* pOb);

	/**
	 * @fn  UnregisterDropEventObserver        
	 * @brief   
	 * @param IDropEventObserver * pOb: 
	 * @return void
	 */
	virtual void UnregisterDropEventObserver(IDropEventObserver* pOb);

	virtual void RegisterWindowEventObserver(IWindowEventObserver* pOb);

	virtual void UnregisterWindwoEventObserver(IWindowEventObserver* pOb);

	/**
	 * @fn  SendEvent        
	 * @brief   �����¼���Ϣ�����ӿ�
	 * @param   CEventObject & rEvent: ��Ҫ���͵���Ϣ
	 * @param   bool bPost: ָ�����ͷ�ʽ,true��ʾ���з�ʽ����,false��ʾֱ�ӷ���,�������ã������߳��е���
	 * @return @c bool ����true��ʾ��Ϣ���ͳɹ�,����false��ʾ��Ϣ����ʧ��
	 */

	virtual bool SendEvent(CEventObject* pEvent, bool bPost = false);

protected:

	virtual E_TASK_STATE OnRunTask();

	virtual void OnRecycleThreadQuit();

private:

	void *m_MapCommandEventObserver;

	//std::map<std::string,ICommandEventObserver*> m_MapCommandEventObserver;

	CThreadMutex *m_pCommandEventMutex;
	void* m_ListCommandObject;
	//std::list<CEventObject*> m_ListCommandObject;

	bool m_bRunning;

};

#endif // EventModule_h__
