#pragma once
#include "cocos2d.h"
#include "MyData.h"
#include "MenuLayer.h"
#include "MapLayer.h"
#include "DefineOrConst.h"
#include "ArmyCMD.h"
USING_NS_CC;


class DataLayer :public cocos2d::CCLayer
{
public:
	DataLayer();
	~DataLayer();

	virtual bool init();
	static cocos2d::CCLayer *creatLayer();
	CREATE_FUNC(DataLayer);



	void showRoundNum();
	void showGold();	//显示钱
	void showLoyal();	//显示民忠
	void showSoldier();	//显示士兵数
	void showCity();	//显示城池数
	void showCrystal();	//显示水晶数

	void MyUpdate();

	CCLabelTTF *RoundShow;
	CCLabelTTF *GoldShow;
	CCLabelTTF *LoyalShow;
	CCLabelTTF *SoldierShow;
	CCLabelTTF *CityShow;
	CCLabelTTF *CrystalShow;


	int DoCMD(EconomyCMD cmd);
	int DoCMD(InteriorCMD cmd);
	int DoCMD(ArmyCMD cmd);
	int DoCMD(TechnologyCMD cmd);
	
	void FirstRoundInit();

	void InsideDataClear();

public:
	MenuLayer *ToMenuLayer;
	MapLayer *ToMapLayer;
	static MyData data;
	
	bool EconomyCMDFlag;
	bool MineCMDFlag;

	bool InteriorCMDFlag;
	bool HelpPeopleCMDFlag;
	bool PreventionCMDFlag;
	bool PardonCMDFlag;

	bool ArmyCMDFlag;

	bool TechnologyCMDFlag;

};

