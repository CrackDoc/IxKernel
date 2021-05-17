/**
 * @file IEventModule.h
 * @brief �¼�ģ��ӿ�
 * @note ʹ�÷���:
 �¼�ģ�����ע���ȡ��ע����̡���ꡢ���֡�����������ݱ����������¼��Ĺ۲���;

 ��Ҫ�����¼��Ķ���,�̳���Ӧ�Ĺ۲��߽ӿ�;

 ���ļ��ṩ:

	(1)�����¼��۲��߽ӿ�
 
	(2)����¼��۲��߽ӿ�
 
	(3)�����¼��۲��߽ӿ�

	(4)֡�¼��۲��߽ӿ�

	(5)�����¼��۲��߽ӿ�

	(6)���ݱ��¼��۲��߽ӿ�

	(7)�����ı��¼��۲��߽ӿ�

	(8)�����¼�

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
* @brief ����¼��۲���
* @note  ʹ��˵��:

  ��������¼�,��Ҫ�̳иýӿ�,��ʵ�ֶ�Ӧ�ĺ���;
  
  [�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class IMouseEventObserver 
{
public:
	virtual ~IMouseEventObserver(){}

	/**
	 * @fn  OnLeftMouseButtonDown        
	 * @brief   �����������¼�������
	 * @param   ISceneModule * pSceneModule: ָ����������Ϣ�ĳ���
	 * @param   int x: �������¼�ʱ,������ڵ���Ļ������
	 * @param   int y: �������¼�ʱ,������ڵ���Ļ������
	 * @return void
	 */
	virtual bool OnLeftMouseButtonDown(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLeftMouseButtonUp        
	 * @brief   �����������¼�������
	 * @param   ISceneModule * pSceneModule: ָ���������¼��ĳ���
	 * @param   int x: �������¼�ʱ,������ڵ���Ļ������
	 * @param   int y: �������¼�ʱ,������ڵ���Ļ������
	 * @return void
	 */
	virtual bool OnLeftMouseButtonUp(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnRightMouseButtonDown        
	 * @brief ����Ҽ���ť�����¼�������  
	 * @param ISceneModule * pSceneModule: ָ���������¼��ĳ���
	 * @param int x: �������¼�ʱ,������ڵ���Ļ������
	 * @param int y: �������¼�ʱ,������ڵ���Ļ������
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

	// Brief:�����ӿ�.��ʱ��ʹ�ô��� [2017/9/19 CETC] 
	virtual bool OnLeftMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual bool OnMiddleMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual bool OnRightMouseButtonClick(ISceneModule* pSceneModule, int x, int y,CEventObject *pObject = NULL) {return false;}

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

//�����¼��۲���
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
* @brief �����¼��۲���
* @note  ʹ��˵��:

��дOnCommand�ӿ�,�����յ�������;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class ICommandEventObserver 
{
public:
	virtual ~ICommandEventObserver(){}

	/**
	 * @fn  OnCommand        
	 * @brief �����¼�����ӿ�  
	 * @param IScriptFunctionAnalyse * pAna: ���������
	 * @return void
	 */
	virtual void OnCommand(IScriptFunctionAnalyse* pAna,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

/**
* @class IFrameEventObserver
* @brief ֡�¼��۲���
* @note  ʹ��˵��:

��дOnFrameEvent�ӿ�,����֡�����¼�;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class IFrameEventObserver 
{
public:
	virtual ~IFrameEventObserver(){}

	/**
	 * @fn  OnFrameEvent        
	 * @brief ֡�¼�������  
	 * @param ISceneModule * pScene: ָ�����͸��¼��ĳ���
	 * @param double dElapsedTime: ���θ��µ�ʱ���
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
* @brief ���ݱ��¼��۲���
* @note  ʹ��˵��:

��дOnDispatchDatagram�ӿ�,�����յ������ݱ���;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class IDatagramEventObserver 
{
public:
	virtual ~IDatagramEventObserver(){}

	/**
	 * @fn  OnDispatchDatagram        
	 * @brief �������ݱ��Ľӿ�  
	 * @param const CDatagramEventObject & rEvent: ���ݱ��¼�
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
* @brief �����¼��۲���
* @note  ʹ��˵��:

��дOnSceneEvent�ӿ�,�����������¼�;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class QMenu;
class ISceneEventObserver 
{
public:
	virtual ~ISceneEventObserver(){}

	/**
	 * @fn  OnObjectMenuInvoke        
	 * @brief   ���в˵�
	 * @param ISceneModule * pScene: 
	 * @param QMenu * pMenu: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual void OnMenuInvoke(ISceneModule* pScene, QMenu* pMenu, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectPick        
	 * @brief ���屻ѡ��  
	 * @param ISceneModule * pScene: ����ָ��
	 * @param int nObjectID: ����ID
	 * @return void
	 */
	virtual bool OnObjectPick(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectDrag        
	 * @brief �����϶�  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectDrag(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectMouseHover        
	 * @brief ���������ͣ  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectMouseHover(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnObjectMouseLeave        
	 * @brief ��������뿪  
	 * @param ISceneModule * pScene: 
	 * @param int nObjectID: 
	 * @return void
	 */
	virtual bool OnObjectMouseLeave(ISceneModule* pScene, int nObjectID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelPick        
	 * @brief ���Ƶ�ѡ  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelPick(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelMouseHover        
	 * @brief ���������ͣ  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelMouseHover(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelMouseLeave        
	 * @brief ��������뿪  
	 * @param ISceneModule * pScene: 
	 * @param int nLabelID: 
	 * @return void
	 */
	virtual bool OnLabelMouseLeave(ISceneModule* pScene, int nLabelID,CEventObject *pObject = NULL) = 0;

	/**
	 * @fn  OnLabelDrag        
	 * @brief �����϶�  
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
* @brief ״̬�¼��۲���
* @note  ʹ��˵��:

��дOnStateChanged�ӿ�,����״̬�ı��¼�;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
*/
class IStateEventObserver 
{
public:
	virtual ~IStateEventObserver(){}

	/**
	 * @fn  OnStateChanged        
	 * @brief ״̬�ı��¼�����ӿ�  
	 * @param const CStateEventObject & rEvent: ״̬�¼�
	 * @return void
	 */
	virtual bool OnStateChanged(const CStateEventObject& rEvent,CEventObject *pObject = NULL) = 0;

	virtual std::string GetObServerId() = 0;

	virtual void SetObServerId(std::string id) = 0;
};

class CDropEventObject;
/**
* @class IStateEventObserver
* @brief ��ק�¼��۲���
* @note  ʹ��˵��:

��дDropEvent�ӿ�,������ק�¼�;

[�ر�˵��]ʹ�ýӿ���Ч,��Ҫ���ýӿڵ���������ע��ΪEventModule�Ĺ۲���
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

//ģ������
extern KERNEL_EXPORT std::string STR_EVENT_MODULE_NAME;

/**
* @class IEventModule
* @brief �¼�ģ��
* @note  ʹ��GetModule(STR_EVENT_MODULE_NAME)�������Է��ظ�ģ��ָ��
*/
class IEventModule : public IModule
{
public:
	virtual ~IEventModule(){}

	/**
	 * @fn  RegisterMouseEventObserver        
	 * @brief   @interface ע������¼��۲��߽ӿ�
	 * @param IMouseEventObserver * pMouseOb: ����¼��۲���
	 * @return void
	 */
	virtual void RegisterMouseEventObserver(IMouseEventObserver* pMouseOb) = 0;

	/**
	 * @fn  UnregisterMouseEventObserver        
	 * @brief   @interface ȡ������¼��۲���ע��ӿ�
	 * @param IMouseEventObserver * pMouseOb: ����¼��۲���
	 * @return void
	 */
	virtual void UnregisterMouseEventObserver(IMouseEventObserver* pMouseOb) = 0;

	/**
	 * @fn  RegisterCommandEventObserver        
	 * @brief  @interface ע�������¼��۲��߽ӿ�
	 * @param ICommandEventObserver * pCommandOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterCommandEventObserver(ICommandEventObserver* pCommandOb) = 0;

	/**
	 * @fn  UnregisterCommandEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param ICommandEventObserver * pCommandOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterCommandEventObserver(ICommandEventObserver* pCommandOb) = 0;

	/**
	 * @fn  RegisterKeyboardEventObserver        
	 * @brief   @interface ע������¼��۲��߽ӿ�
	 * @param IKeyboadEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterKeyboardEventObserver(IKeyboadEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterKeyboardEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param IKeyboadEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterKeyboardEventObserver(IKeyboadEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterFrameEventObserver        
	 * @brief   @interface ע��֡�¼��۲��߽ӿ�
	 * @param IFrameEventObserver * pOb: ֡�¼��۲���
	 * @return void
	 */
	virtual void RegisterFrameEventObserver(IFrameEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterFrameEventObserver        
	 * @brief   @interface ȡ��֡�¼��۲���ע��ӿ�
	 * @param IFrameEventObserver * pOb: ֡�¼��۲���
	 * @return void
	 */
	virtual void UnregisterFrameEventObserver(IFrameEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterDatagramEventObserver        
	 * @brief   @interface ע�����ݱ��¼��۲��߽ӿ�
	 * @param IDatagramEventObserver * pOb: ���ݱ��¼��۲���
	 * @return void
	 */
	virtual void RegisterDatagramEventObserver(IDatagramEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterDatagramEventObserver        
	 * @brief   @interface ȡ�����ݱ��¼��۲���ע��ӿ�
	 * @param IDatagramEventObserver * pOb: ���ݱ��¼��۲���
	 * @return void
	 */
	virtual void UnregisterDatagramEventObserver(IDatagramEventObserver* pOb) = 0;

	/**
	 * @fn  RegisterSceneEventObserver        
	 * @brief   @interface ע�᳡���¼��۲��߽ӿ�
	 * @param ISceneEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void RegisterSceneEventObserver(ISceneEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterSceneEventObserver        
	 * @brief   @interface ȡ�������¼��۲���ע��ӿ�
	 * @param ISceneEventObserver * pOb: �����¼��۲���
	 * @return void
	 */
	virtual void UnregisterSceneEventObserver(ISceneEventObserver* pOb) = 0;

	//ע��״̬�¼��۲���
	/**
	 * @fn  RegisterStateEventObserver        
	 * @brief   @interface ע��״̬�¼��۲��߽ӿ�
	 * @param IStateEventObserver * pOb: ״̬�¼��۲���
	 * @return void
	 */
	virtual void RegisterStateEventObserver(IStateEventObserver* pOb) = 0;

	/**
	 * @fn  UnregisterStateEventObserver        
	 * @brief   @interface ȡ��״̬�¼��۲���ע��ӿ�
	 * @param IStateEventObserver * pOb: ״̬�¼��۲���
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
	 * @brief   �����¼���Ϣ�����ӿ�
	 * @param   CEventObject & rEvent: ��Ҫ���͵���Ϣ
	 * @param   bool bPost: ָ�����ͷ�ʽ,true��ʾ���з�ʽ����,false��ʾֱ�ӷ���
	 * @return @c bool ����true��ʾ��Ϣ���ͳɹ�,����false��ʾ��Ϣ����ʧ��
	 */
	virtual bool SendEvent(CEventObject* pEvent, bool bPost = false) = 0;
};
#endif // IEventModule_h__
