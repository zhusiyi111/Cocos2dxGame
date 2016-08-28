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
	void showGold();	//��ʾǮ
	void showLoyal();	//��ʾ����
	void showSoldier();	//��ʾʿ����
	void showCity();	//��ʾ�ǳ���
	void showCrystal();	//��ʾˮ����

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

