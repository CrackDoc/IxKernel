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

	float m_nLineWidth;					//线宽
	CColor4D m_LineColor;				//线颜色
	KFLOAT m_fAlpha;					//线透明度
	int m_nLineType;					//线的类型(实线，虚线)

	CColor4D m_TextColor;				//文本颜色
	int m_nTextFontSize;				//文本字体大小
	std::string m_strTextFontFamily;	//文本字体"msyh.ttf"
	bool m_bDeclutter;					//文本是否避让
	std::string m_strIconPath;			//文本图标

	CColor4D m_FillColor;				//面颜色
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
		E_EARTH_UNIT_METER = 1,		//米
		E_EARTH_UNIT_KILOMETER = 2,	//千米
		E_EARTH_UNIT_FOOT = 3,		//英尺
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

	//坐标转换接口[deprecated]
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

	//工具-计算距离
	virtual KFLOAT CaculateDistance(const CVector3D& rPt1, const CVector3D& rPt2, E_CALC_DISTANCE_TYPE eCalcType) = 0;

	//工具-面积计算
	virtual KFLOAT CalulateArea(const std::vector<CVector3D>& rPts, E_CALC_AREA_TYPE eCalcType) = 0;

	//使用地图单位
	virtual void UseEarthUnit(E_EARTH_UNIT eEarthUnit) = 0;

	//返回地图单位
	virtual E_EARTH_UNIT GetCurrentEarthUnit() = 0;

	virtual void PickObject(int nId) = 0;

	virtual void HighlightObject(int nId, bool bHighlight) = 0;

	virtual void SetActive(bool bActive) = 0;

	virtual bool IsActive() = 0;

	virtual IObject* LookupObject(int nObjectID) const = 0;

	//获取一个新的ID
	virtual int GetNewID() = 0;

	virtual CViewport GetViewport() = 0;

	virtual E_SCENE_TYPE GetSceneType() = 0;
};
#endif // ISceneModule_h__
