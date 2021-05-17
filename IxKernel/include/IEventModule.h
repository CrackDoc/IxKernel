/**
 * @file IEventModule.h
 * @brief 事件模块接口
 * @note 使用方法:
 事件模块可以注册或取消注册键盘、鼠标、命令、帧、场景、数据报、变量等事件的观察者;

 需要处理事件的对象,继承相应的观察者接口;

 本文件提供:

	(1)键盘事件观察者接口
 
	(2)鼠标事件观察者接口
 
	(3)命令事件观察者接口

	(4)帧事件观察者接口

	(5)场景事件观察者接口

	(6)数据报事件观察者接口

	(7)变量改变事件观察者接口

	(8)窗口事件

 * @author crack
 * @date 2020/06/07
 * @version V00.00.01
 * @CopyRight swiet.com
 */
#ifndef IEventModule_h__
#define IEventModule_h__

#include "IModule.h"
#include "ISceneModule.h"
#include "IThreadEvent.h"
#include "EventObject.h"

class CEventObject;

class IScriptFunctionAnalyse;

/**
* @class IMouseEventObserver
* @brief 鼠标事件观察者
* @note  使用说明:

  处理鼠标事件,需要继承该接口,并实现对应的函数;
  
  [特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class IMouseEventObserver 
{
public:
	virtual ~IMouseEventObserver(){}

	/**
	 * @fn  OnLeftMouseButtonDown        
	 * @brief   鼠标左键按下事件处理函数
	 * @param   ISceneModule * pSceneModule: 指定发出该消息的场景
	 * @param   int x: 产生该事件时,鼠标所在的屏幕横坐标
	 * @param   int y: 产生该事件时,鼠标所在的屏幕纵坐标
	 * @return void
	 */
	virtual bool OnLeftMouseButtonDown(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLeftMouseButtonUp        
	 * @brief   鼠标左键弹起事件处理函数
	 * @param   ISceneModule * pSceneModule: 指明产生该事件的场景
	 * @param   int x: 产生该事件时,鼠标所在的屏幕横坐标
	 * @param   int y: 产生该事件时,鼠标所在的屏幕纵坐标
	 * @return void
	 */
	virtual bool OnLeftMouseButtonUp(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnRightMouseButtonDown        
	 * @brief 鼠标右键按钮按下事件处理函数  
	 * @param ISceneModule * pSceneModule: 指明产生该事件的场景
	 * @param int x: 产生该事件时,鼠标所在的屏幕横坐标
	 * @param int y: 产生该事件时,鼠标所在的屏幕纵坐标
	 * @return void
	 */
	virtual bool OnRightMouseButtonDown(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnRightMouseButtonUp(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnMiddleMouseButtonDown(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnMiddleMouseButtonUp(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnMiddleMouseWheel(ISceneModule* pSceneModule, int x, int y, float nDeltaX, float nDeltaY,CEventObject *pObject = NULL) = 0;

	virtual bool OnMouseMove(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnLeftMouseButtownDoubleClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnRightMouseButtonDoubleClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	virtual bool OnMouseDrag(ISceneModule* pSceneModeul, int x, int y,CEventObject *pObject = NULL) = 0;

	// Brief:新增接口.暂时不使用纯虚 [2017/9/19 CETC] 
	virtual bool OnLeftMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual bool OnMiddleMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual bool OnRightMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

//键盘事件观察者
class IKeyboadEventObserver 
{
public:
	virtual ~IKeyboadEventObserver(){}

	virtual bool OnKeydown(ISceneModule* pSceneModule, int nKey, int nModifier,CEventObject *pObject = NULL) = 0;

	virtual bool OnKeyup(ISceneModule* pSceneModule, int nKey, int nModifier,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

/**
* @class ICommandEventObserver
* @brief 命令事件观察者
* @note  使用说明:

重写OnCommand接口,处理收到的命令;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class ICommandEventObserver 
{
public:
	virtual ~ICommandEventObserver(){}

	/**
	 * @fn  OnCommand        
	 * @brief 命令事件处理接口  
	 * @param IScriptFunctionAnalyse * pAna: 命令解析器
	 * @return void
	 */
	virtual void OnCommand(IScriptFunctionAnalyse* pAna,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

/**
* @class IFrameEventObserver
* @brief 帧事件观察者
* @note  使用说明:

重写OnFrameEvent接口,处理帧更新事件;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class IFrameEventObserver 
{
public:
	virtual ~IFrameEventObserver(){}

	/**
	 * @fn  OnFrameEvent        
	 * @brief 帧事件处理函数  
	 * @param ISceneModule * pScene: 指明发送该事件的场景
	 * @param double dElapsedTime: 两次更新的时间差
	 * @return void
	 */
	virtual void OnFrameEvent(ISceneModule* pScene, double dElapsedTime,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

//
class CDatagramEventObject;
/**
* @class IDatagramEventObserver
* @brief 数据报事件观察者
* @note  使用说明:

重写OnDispatchDatagram接口,处理收到的数据报文;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class IDatagramEventObserver 
{
public:
	virtual ~IDatagramEventObserver(){}

	/**
	 * @fn  OnDispatchDatagram        
	 * @brief 处理数据报文接口  
	 * @param const CDatagramEventObject & rEvent: 数据报事件
	 * @return void
	 */
	virtual void OnDispatchDatagram(const CDatagramEventObject& rEvent,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

class CEventObject;
class CSceneEventObject;
/**
* @class ISceneEventObserver
* @brief 场景事件观察者
* @note  使用说明:

重写OnSceneEvent接口,处理场景产生事件;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class QMenu;
class ISceneEventObserver 
{
public:
	virtual ~ISceneEventObserver(){}

	/**
	 * @fn  OnObjectMenuInvoke        
	 * @brief   呼叫菜单
	 * @param ISceneModule * pScene: 
	 * @param QMenu * pMenu: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual void OnMenuInvoke(ISceneModule* pScene, QMenu* pMenu, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectPick        
	 * @brief 物体被选中  
	 * @param ISceneModule * pScene: 场景指针
	 * @param int nObjectID: 对象ID
	 * @return void
	 */
	virtual bool OnObjectPick(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectDrag        
	 * @brief 对象拖动  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectDrag(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectMouseHover        
	 * @brief 对象鼠标悬停  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectMouseHover(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectMouseLeave        
	 * @brief 对象鼠标离开  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectMouseLeave(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelPick        
	 * @brief 标牌点选  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelPick(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelMouseHover        
	 * @brief 标牌鼠标悬停  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelMouseHover(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelMouseLeave        
	 * @brief 标牌鼠标离开  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelMouseLeave(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelDrag        
	 * @brief 标牌拖动  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelDrag(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

class CStateEventObject;
/**
* @class IStateEventObserver
* @brief 状态事件观察者
* @note  使用说明:

重写OnStateChanged接口,处理状态改变事件;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class IStateEventObserver 
{
public:
	virtual ~IStateEventObserver(){}

	/**
	 * @fn  OnStateChanged        
	 * @brief 状态改变事件处理接口  
	 * @param const CStateEventObject & rEvent: 状态事件
	 * @return void
	 */
	virtual bool OnStateChanged(const CStateEventObject& rEvent,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

class CDropEventObject;
/**
* @class IStateEventObserver
* @brief 拖拽事件观察者
* @note  使用说明:

重写DropEvent接口,处理拖拽事件;

[特别说明]使该接口生效,需要将该接口的衍生对象注册为EventModule的观察者
*/
class QEvent;
class IDropEventObserver
{
public:

	/**
	 * @fn  dropEvent        
	 * @brief   
	 * @param QEvent * event: 
	 * @return void
	 */
	virtual bool DropEvent(QEvent* event,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

class CWindowEventObject;
class IWindowEventObserver
{
public:
	virtual ~IWindowEventObserver(){}

	virtual bool OnWindowEvent(ISceneModule* pSceneModule, const CWindowEventObject& rEvent,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

//模块名字
extern KERNEL_EXPORT std::string STR_EVENT_MODULE_NAME;

/**
* @class IEventModule
* @brief 事件模块
* @note  使用GetModule(STR_EVENT_MODULE_NAME)函数可以返回该模块指针
*/
class IEventModule : public IModule
{
public:
	virtual ~IEventModule(){}

	/**
	 * @fn  RegisterMouseEventObserver        
	 * @brief   @interface 注册鼠标事件观察者接口
	 * @param IMouseEventObserver * pMouseOb: 鼠标事件观察者
	 * @return void
	 */
	virtual void RegisterMouseEventObserver(IMouseEventObserver* pMouseOb) = 0;

	/**
	 * @fn  UnregisterMouseEventObserver        
	 * @brief   @interface 取消鼠标事件观察者注册接口
	 * @param IMouseEventObserver * pMouseOb: 鼠标事件观察者
	 * @return void
	 */
	virtual void UnregisterMouseEventObserver(IMouseEventObserver* pMouseOb) = 0;

	/**
	 * @fn  RegisterCommandEventObserver        
	 * @brief  @interface 注册命令事件观察者接口
	 * @param ICommandEventObserver * pCommandOb: 命令事件观察者
	 * @return void
	 */
	virtual void RegisterCommandEventObserver(ICommandEventObserver* pCommandOb) = 0;

	/**
	 * @fn  UnregisterCommandEventObserver        
	 * @brief   @interface 取消命令事件观察者注册接口
	 * @param ICommandEventObserver * pCommandOb: 命令事件观察者
	 * @return void
	 */
	virtual void UnregisterCommandEventObserver(ICommandEventObserver* pCommandOb) = 0;

	/**
	 * @fn  RegisterKeyboardEventObserver        
	 * @brief   @interface 注册键盘事件观察者接口
	 * @param IKeyboadEventObserver * pOb: 键盘事件观察者
	 * @return void
	 */
	virtual void RegisterKeyboardEventObserver(IKeyboadEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterKeyboardEventObserver        
	 * @brief   @interface 取消键盘事件观察者注册接口
	 * @param IKeyboadEventObserver * pOb: 键盘事件观察者
	 * @return void
	 */
	virtual void UnregisterKeyboardEventObserver(IKeyboadEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterFrameEventObserver        
	 * @brief   @interface 注册帧事件观察者接口
	 * @param IFrameEventObserver * pOb: 帧事件观察者
	 * @return void
	 */
	virtual void RegisterFrameEventObserver(IFrameEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterFrameEventObserver        
	 * @brief   @interface 取消帧事件观察者注册接口
	 * @param IFrameEventObserver * pOb: 帧事件观察者
	 * @return void
	 */
	virtual void UnregisterFrameEventObserver(IFrameEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterDatagramEventObserver        
	 * @brief   @interface 注册数据报事件观察者接口
	 * @param IDatagramEventObserver * pOb: 数据报事件观察者
	 * @return void
	 */
	virtual void RegisterDatagramEventObserver(IDatagramEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterDatagramEventObserver        
	 * @brief   @interface 取消数据报事件观察者注册接口
	 * @param IDatagramEventObserver * pOb: 数据报事件观察者
	 * @return void
	 */
	virtual void UnregisterDatagramEventObserver(IDatagramEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterSceneEventObserver        
	 * @brief   @interface 注册场景事件观察者接口
	 * @param ISceneEventObserver * pOb: 场景事件观察者
	 * @return void
	 */
	virtual void RegisterSceneEventObserver(ISceneEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterSceneEventObserver        
	 * @brief   @interface 取消场景事件观察者注册接口
	 * @param ISceneEventObserver * pOb: 场景事件观察者
	 * @return void
	 */
	virtual void UnregisterSceneEventObserver(ISceneEventObserver* pOb) = 0;

	//注册状态事件观察者
	/**
	 * @fn  RegisterStateEventObserver        
	 * @brief   @interface 注册状态事件观察者接口
	 * @param IStateEventObserver * pOb: 状态事件观察者
	 * @return void
	 */
	virtual void RegisterStateEventObserver(IStateEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterStateEventObserver        
	 * @brief   @interface 取消状态事件观察者注册接口
	 * @param IStateEventObserver * pOb: 状态事件观察者
	 * @return void
	 */
	virtual void UnregisterStateEventObserver(IStateEventObserver* pOb) = 0;
	
	/**
	 * @fn  RegisterDropEventObserver        
	 * @brief   
	 * @param IDropEventObserver * pOb: 
	 * @return void
	 */
	virtual void RegisterDropEventObserver(IDropEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterDropEventObserver        
	 * @brief   
	 * @param IDropEventObserver * pOb: 
	 * @return void
	 */
	virtual void UnregisterDropEventObserver(IDropEventObserver* pOb) = 0;

	virtual void RegisterWindowEventObserver(IWindowEventObserver* pOb) = 0;

	virtual void UnregisterWindwoEventObserver(IWindowEventObserver* pOb) = 0;

	/**
	 * @fn  SendEvent        
	 * @brief   发送事件消息函数接口
	 * @param   CEventObject & rEvent: 需要发送的消息
	 * @param   bool bPost: 指明发送方式,true表示队列方式发送,false表示直接发送
	 * @return @c bool 返回true表示消息发送成功,返回false表示消息发送失败
	 */
	virtual bool SendEvent(CEventObject* pEvent, bool bPost = false) = 0;
};
#endif // IEventModule_h__
