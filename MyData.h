#pragma once
#include "cocos2d.h"
#include"MineData.h"
USING_NS_CC;

class MyData
{
public:
	MyData();
	~MyData();
	int _RoundNum;
	int _Gold;
	int _Loyal;
	int	_Soldier;
	int _CityNum;
	int _Crystal;	

	std::vector<MineData> _MineData;

	


	//金钱改变值及其原因
	int _GoldChanged;

	int _GoldUp;				//金钱增加数
	int _GoldUpFromMine;		//采矿所得金钱
	int _GoldUpFromTax;			//收税所得金钱
	int _GoldUpFromTreasure;	//寻宝所得金钱
	int _GoldUpFromTrade;		//贸易所得金钱
	int _GoldUpFromBlackMarket;	//黑市所得金钱
	int _GoldUpFromMarket;		//市场所得金钱
	int _GoldUpFromTunTian;     //屯田所得金钱
	int _GoldUpFromBiology;		//生物学所得金钱
	int _GoldUpFromPyramid;		//拥有金字塔所得金钱

	int _GoldDown;
	int _GoldDownFromDoTreasure;	//执行寻宝指令减少金钱
	int _GoldDownFromDoBlackMarket;	//执行黑市指令减少金钱
	int _GoldDownFromDoMarket;		//执行市场指令减少金钱
	int _GoldDownFromDoInterior;	//执行内政指令所减少金钱
	int _GoldDownFromDoArmy;		//执行军事指令所减少金钱
	int _GoldDownFromDoTechnology;	//升级科技所减少金钱



	//民忠改变值及其原因
	int _LoyalChanged;

	int _LoyalUp;					//民忠增加数
	int _LoyalUpFromHelpPeople;		//济世所加民忠
	int _LoyalUpFromPardon;			//大赦天下所加民忠
	int _LoyalUpFromRepublic;		//共和制所加民忠

	int _LoyalDown;					//民忠减少数
	int _LoyalDownFromEachRound;	//每回合减少民忠值
	int _LoyalDownFromTax;			//收税减少民忠值
	int _LoyalDownFromConscription;	//征兵减少民忠值
	int _LoyalDownFromColony;		//殖民减少民忠值


	//士兵改变值及其原因
	int _SoldierChanged;

	int _SoldierUp;					//士兵增加数
	int _SoldierUpFromConscription;	//征兵增加士兵数
	int _SoldierUpFromMilitiaEachRound;	//民兵役每回合增加的士兵数
	int _SoldierUpFromColossusEachRound;	//巨人像每回合增加的士兵数

	int _SoldierDown;				//士兵减少数
	int _SoldierDownFromTreasure;	//寻宝减少的士兵数
	int _SoldierDownFromColony;		//殖民减少士兵数


	//城池数改变值及其原因
	int _CityChanged;

	int _CityUp;					//城池增加数
	int _CityUpFromColony;			//殖民增加城池数
	int _CityUpFromDespotic;		//升级“专制”立即获得的城池数

	int _CityDown;					//城池减少数
	int _CityDownFromDoInterior;	//执行内政指令减少的城池数


	//水晶改变值及其原因
	int _CrystalChanged;
	
	int _CrystalUp;					//水晶增加数
	int _CrystalUpFromTreasue;		//寻宝增加的水晶数
	int _CrystalUpFromBlackMarket;	//黑市所增加的水晶数
	int _CrystalUpFromMarket;		//市场所增加的水晶数
	int _CrystalUpFromStandingArmy;	//常备军增加的水晶数
	int _CrystalUpFromPhysics;		//物理学增加的水晶数
	int _CrystalUpFromChemistryEachRound;	//化学增加的水晶数
	int _CrystalUpFromTerracotta;	//兵马俑增加的水晶
	
	int _CrystalDown;				//水晶减少数
	int _CrystalDownFromBlackMarket;	//黑市减少的水晶
	int _CrystalDownFromMarket;		//市场减少的水晶数
	int _CrystalDownFromInterior;	//执行内政指令减少的水晶
	int _CrystalDownFromTechnology;	//升级科技减少的水晶数


	//奇迹建筑
	bool isPyramid;	//金字塔
	bool isColossus;	//巨人像
	bool isTerracotta;	//兵马俑
	bool isHangingGarden;//空中花园

	



	//科技树
	bool isTunTian; //屯田制
	bool isRefine;	//精炼技术
	bool isMarketTrade;	//市场交易
	bool isProspect;	//勘探技术
	bool isTaxLaw;	//税法
	bool isBoom;	//繁荣

	bool isCityState;	//城邦制
	bool isDespotic;	//专制
	bool isDemocracy;	//民主制
	bool isMonarchy;	//君主制
	bool isRepublic;	//共和制
	bool isCapitalism;	//资本主义
	bool isSocialism;	//社会主义

	bool isMilitia;		//民兵役
	bool isMercenary;	//雇佣兵制
	bool isStandingArmy;	//常备军
	bool isFort;		//堡垒
	bool isAllSoldier;	//全民皆兵
	bool isSpy;			//间谍

	bool isMath;		//数学
	bool isPhysics;		//物理学
	bool isBiology;		//生物学
	bool isElectric;	//电子学
	bool isChemistry;	//化学
	bool isSuperComputer;	//超级计算机
	

};

