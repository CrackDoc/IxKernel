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
	 * @brief   @interface 注册鼠标事件观察者接口
	 * @param IMouseEventObserver * pMouseOb: 鼠标事件观察者
	 * @return void
	 */
	virtual void RegisterMouseEventObserver(IMouseEventObserver* pMouseOb);

	/**
	 * @fn  UnregisterMouseEventObserver        
	 * @brief   @interface 取消鼠标事件观察者注册接口
	 * @param IMouseEventObserver * pMouseOb: 鼠标事件观察者
	 * @return void
	 */
	virtual void UnregisterMouseEventObserver(IMouseEventObserver* pMouseOb);

	/**
	 * @fn  RegisterCommandEventObserver        
	 * @brief  @interface 注册命令事件观察者接口
	 * @param ICommandEventObserver * pCommandOb: 命令事件观察者
	 * @return void
	 */
	virtual void RegisterCommandEventObserver(ICommandEventObserver* pCommandOb);

	/**
	 * @fn  UnregisterCommandEventObserver        
	 * @brief   @interface 取消命令事件观察者注册接口
	 * @param ICommandEventObserver * pCommandOb: 命令事件观察者
	 * @return void
	 */
	virtual void UnregisterCommandEventObserver(ICommandEventObserver* pCommandOb);

	/**
	 * @fn  RegisterKeyboardEventObserver        
	 * @brief   @interface 注册键盘事件观察者接口
	 * @param IKeyboadEventObserver * pOb: 键盘事件观察者
	 * @return void
	 */
	virtual void RegisterKeyboardEventObserver(IKeyboadEventObserver* pOb);

	/**
	 * @fn  UnregisterKeyboardEventObserver        
	 * @brief   @interface 取消键盘事件观察者注册接口
	 * @param IKeyboadEventObserver * pOb: 键盘事件观察者
	 * @return void
	 */
	virtual void UnregisterKeyboardEventObserver(IKeyboadEventObserver* pOb);

	/**
	 * @fn  RegisterFrameEventObserver        
	 * @brief   @interface 注册帧事件观察者接口
	 * @param IFrameEventObserver * pOb: 帧事件观察者
	 * @return void
	 */
	virtual void RegisterFrameEventObserver(IFrameEventObserver* pOb);

	/**
	 * @fn  UnregisterFrameEventObserver        
	 * @brief   @interface 取消帧事件观察者注册接口
	 * @param IFrameEventObserver * pOb: 帧事件观察者
	 * @return void
	 */
	virtual void UnregisterFrameEventObserver(IFrameEventObserver* pOb);

	/**
	 * @fn  RegisterDatagramEventObserver        
	 * @brief   @interface 注册数据报事件观察者接口
	 * @param IDatagramEventObserver * pOb: 数据报事件观察者
	 * @return void
	 */
	virtual void RegisterDatagramEventObserver(IDatagramEventObserver* pOb);

	/**
	 * @fn  UnregisterDatagramEventObserver        
	 * @brief   @interface 取消数据报事件观察者注册接口
	 * @param IDatagramEventObserver * pOb: 数据报事件观察者
	 * @return void
	 */
	virtual void UnregisterDatagramEventObserver(IDatagramEventObserver* pOb);

	 /* @brief   @interface 注册场景事件观察者接口
	 * @param ISceneEventObserver * pOb: 场景事件观察者
	 * @return void
	 */
	virtual void RegisterSceneEventObserver(ISceneEventObserver* pOb);

	/**
	 * @fn  UnregisterSceneEventObserver        
	 * @brief   @interface 取消场景事件观察者注册接口
	 * @param ISceneEventObserver * pOb: 场景事件观察者
	 * @return void
	 */
	virtual void UnregisterSceneEventObserver(ISceneEventObserver* pOb);

	//注册状态事件观察者
	/**
	 * @fn  RegisterStateEventObserver        
	 * @brief   @interface 注册状态事件观察者接口
	 * @param IStateEventObserver * pOb: 状态事件观察者
	 * @return void
	 */
	virtual void RegisterStateEventObserver(IStateEventObserver* pOb);

	/**
	 * @fn  UnregisterStateEventObserver        
	 * @brief   @interface 取消状态事件观察者注册接口
	 * @param IStateEventObserver * pOb: 状态事件观察者
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
	 * @brief   发送事件消息函数接口
	 * @param   CEventObject & rEvent: 需要发送的消息
	 * @param   bool bPost: 指明发送方式,true表示队列方式发送,false表示直接发送,立即调用，在主线程中调用
	 * @return @c bool 返回true表示消息发送成功,返回false表示消息发送失败
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
