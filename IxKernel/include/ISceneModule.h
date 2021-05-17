#ifndef ISceneModule_h__
#define ISceneModule_h__

#include "IModule.h"
#include <vector>
#include <string>
#include "ExtendStructureConstant.h"
#include "Color4D.h"
#include "Vector3D.h"

class CLayerStyle
{
public:
	CLayerStyle()
	{
		m_nLineWidth = 1.0;
		m_LineColor = CColor4D(0xff, 0xff, 0xff, 0xff);
		m_fAlpha = 1.0;
		m_nLineType = 1;

		m_TextColor = CColor4D(0xff, 0xff, 0xff, 0xff);
		m_nTextFontSize = 16;
		m_strTextFontFamily = "msyh.ttf";
		m_bDeclutter = false;
		m_strIconPath = "";

		m_FillColor = CColor4D(0xff, 0xff, 0xff, 0xff);
	}
	~CLayerStyle()
	{

	}

	float m_nLineWidth;					//�߿�
	CColor4D m_LineColor;				//����ɫ
	KFLOAT m_fAlpha;					//��͸����
	int m_nLineType;					//�ߵ�����(ʵ�ߣ�����)

	CColor4D m_TextColor;				//�ı���ɫ
	int m_nTextFontSize;				//�ı������С
	std::string m_strTextFontFamily;	//�ı�����"msyh.ttf"
	bool m_bDeclutter;					//�ı��Ƿ����
	std::string m_strIconPath;			//�ı�ͼ��

	CColor4D m_FillColor;				//����ɫ
};

class CViewport
{
public:
	CViewport()
		: m_nScreenWidth(0)
		, m_nScreenHeight(0)
	{
	}
	~CViewport(){}

	void SetScreenWidth(int nWidth)
	{
		m_nScreenWidth = nWidth;
	}

	void SetScreenHeight(int nHeight)
	{
		m_nScreenHeight = nHeight;
	}

	int GetScreenWidth() const
	{
		return m_nScreenWidth;
	}

	int GetScreenHeight() const
	{
		return m_nScreenHeight;
	}

protected:
	int m_nScreenWidth;
	int m_nScreenHeight;
};

class ISceneModule : public IModule
{
public:
	enum E_CALC_DISTANCE_TYPE
	{
		E_CALC_DISTANCE_TYPE_LINE = 0,
		E_CALC_DISTANCE_TYPE_SURFACE = 1,
	};

	enum E_CALC_AREA_TYPE
	{
		E_CALC_AREA_TYPE_PLAIN = 0,
	};

	enum E_EARTH_UNIT
	{
		E_EARTH_UNIT_METER = 1,		//��
		E_EARTH_UNIT_KILOMETER = 2,	//ǧ��
		E_EARTH_UNIT_FOOT = 3,		//Ӣ��
	};

	enum
	{
		NUM_MIN_SHAPE_RANGE = 0,
		NUM_MAX_SHAPE_RANGE = 18,
	};

	enum E_LAYER_TYPE
	{
		E_LAYER_TYPE_DOT = 0,
		E_LAYER_TYPE_LINE = 1,
		E_LAYER_TYPE_FACE = 2,
	};

	enum E_SCENE_TYPE
	{
		E_SCENE_TYPE_2D = 1,
		E_SCENE_TYPE_3D = 2,
		E_SCENE_TYPE_CUBE = 3,
	};
public:
	virtual ~ISceneModule(){}

	//����ת���ӿ�[deprecated]
	virtual bool ScreenToScene(CVector3D& rSceneCoord, const CVector3D& rScreenCoord) const = 0;

	//[deprecated]
	virtual bool SceneToScreen(CVector3D& rScreenCoord, const CVector3D& rSceneCoord) const = 0;

	virtual CVector3D ScreenToScene(const CVector3D& rScreen, bool* bOk = NULL) const = 0;

	virtual CVector3D SceneToScreen(const CVector3D& rScene, bool* bOk = NULL) const = 0;

	virtual int AddLayerFromeFile(E_LAYER_TYPE eLayerType, const std::string& strFilePath, const CLayerStyle& nStyle, 
		const std::string& strName = "", int nMinRange = NUM_MIN_SHAPE_RANGE, int nMaxRange = NUM_MAX_SHAPE_RANGE) = 0;

	//
	virtual void Home(KFLOAT fTime = 0.0) = 0;

	virtual void SetHome(const CVector3D& rPosition, const CVector3D& rPosture) = 0;

	virtual void Locate(const CVector3D& rPos, KFLOAT fTime = 0.0) = 0;

	virtual void SetLayerStyle(int nLayerID, const CLayerStyle& nStyle) = 0;

	virtual void SetLayerVisible(int nLayerID, bool bVisible) = 0;

	virtual bool IsLayerVisible(int nLayerID) const = 0;

	virtual bool RemoveLayer(int nLayerID) = 0;

	//����-�������
	virtual KFLOAT CaculateDistance(const CVector3D& rPt1, const CVector3D& rPt2, E_CALC_DISTANCE_TYPE eCalcType) = 0;

	//����-�������
	virtual KFLOAT CalulateArea(const std::vector<CVector3D>& rPts, E_CALC_AREA_TYPE eCalcType) = 0;

	//ʹ�õ�ͼ��λ
	virtual void UseEarthUnit(E_EARTH_UNIT eEarthUnit) = 0;

	//���ص�ͼ��λ
	virtual E_EARTH_UNIT GetCurrentEarthUnit() = 0;

	virtual void PickObject(int nId) = 0;

	virtual void HighlightObject(int nId, bool bHighlight) = 0;

	virtual void SetActive(bool bActive) = 0;

	virtual bool IsActive() = 0;

	virtual IObject* LookupObject(int nObjectID) const = 0;

	//��ȡһ���µ�ID
	virtual int GetNewID() = 0;

	virtual CViewport GetViewport() = 0;

	virtual E_SCENE_TYPE GetSceneType() = 0;
};
#endif // ISceneModule_h__
