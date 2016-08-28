#pragma once
#include"cocos2d.h"
#include "MyData.h"
#include "EconomyCMD.h"
#include "EndRoundCMD.h"
#include "InteriorCMD.h"
#include "TechnologyCMD.h"
#include "ArmyCMD.h"
class DataLayer;
class MapLayer;
USING_NS_CC;


class Backstage:public CCNode
{
public:
	Backstage();
	~Backstage();

	virtual bool init();
	static cocos2d::CCNode *creat();
	CREATE_FUNC(Backstage);
	void receive(MyData val);
	static MyData send();
	static void EndRound();

	void ReceiveEconomyCMD(EconomyCMD cmd);
	void ReceiveEndRoundCMD(EndRoundCMD cmd);
	void ReceiveInteriorCMD(InteriorCMD cmd);
	void ReceiveArmyCMD(ArmyCMD cmd);
	void ReceiveTechnologyCMD(TechnologyCMD cmd);
	

	void ProcessStart(); //开始处理双方命令

	void ProcessEconomyCMD(EconomyCMD cmd);	
	void ProcessEndRoundCMD(EndRoundCMD cmd);
	void ProcessInteriorCMD(InteriorCMD cmd);
	void ProcessArmyCMD(ArmyCMD cmd);
	void ProcessTechnologyCMD(TechnologyCMD cmd);

	//清除
	void Player1EconomyCMDClear();	
	void Player1EndRoundCMDClear();
	void Player1InteriorCMDClear();
	void Player1ArmyCMDClear();
	void Player1TechnologyCMDClear();
	

	void NextRound();	//下一回合开始
	void ClaerAllPlayer1CMD(); //清除玩家1的所有命令


	void DoCMDMine(EconomyCMD cmd);	//采矿
	void DoCMDTax(EconomyCMD cmd);	//收税
	void DoCMDTreasure(EconomyCMD cmd);	//寻宝
	void DoCMDBlackMarket(EconomyCMD cmd);	//黑市
	void DoCMDMarket(EconomyCMD cmd);	//市场

	void DoCMDHelpPeople(InteriorCMD cmd);	//济世
	void DoCMDPrevention(InteriorCMD cmd);	//防灾
	void DoCMDPardon(InteriorCMD cmd);		//大赦天下

	void DoCMDConscription(ArmyCMD cmd);	//征兵
	void DoCMDColony(ArmyCMD cmd);			//殖民
	void DoCMDGarrison(ArmyCMD cmd);		//驻军

	void DoCMDTechnology_Economy(TechnologyCMD cmd);	//执行经济类科技命令
	void DoCMDTechnology_Interior(TechnologyCMD cmd);	//执行内政类科技命令
	void DoCMDTechnology_Army(TechnologyCMD cmd);		//执行军事类科技命令
	void DoCMDTechnology_Technology(TechnologyCMD cmd);	//知性科技类科技命令

	void FirstRoundInit();	//第一回合之前的初始化
	void BeforeProcessInit();	//每回合处理数据前的初始化
	void BeforeProcessGoldInit();	//每回合前的金钱数据初始化
	void BeforeProcessLoyalInit();	//每回合前的民忠数据初始化
	void BeforeProcessSoldierInit();//每回合前的士兵数据初始化
	void BeforeProcessCityInit();//每回合前的城池数据初始化
	void BeforeProcessCrystalInit();	//每回合前的水晶数据初始化


	void MineProduceGold();		//每回合产矿

	void Player1GoldChangedProcess();	//玩家1的该回合金钱变化处理
	void Player1LoyalChangedProcess();	//玩家1的该回合民忠变化处理
	void Player1SoldierChangedProcess();	//玩家1的该回合士兵数变化处理
	void Player1CityChangedProcess();	//玩家1的该回合城池数变化处理
	void Player1CrystalChangedProcess();	//玩家1的该回合水晶数变化处理

	bool CheckPlayer1isWin();	//判断玩家1是否达成胜利条件
	
	bool CheckPlayer1isWinOfEconomy();	//判断玩家1的经济获胜条件
	bool CheckPlayer1isWinOfInterior();	//判断玩家1的内政获胜条件
	bool CheckPlayer1isWinOfArmy();		//判断玩家1的军事获胜条件
	bool CheckPlayer1isWinOfTechnology();	//判断玩家1的科技获胜条件
	
public:
	static MyData Player1Data;
	DataLayer *ToDataLayer_1;
	MapLayer *ToMapLayer_1;

	std::vector<EconomyCMD> Player1EconomyCMD;
	std::vector<EndRoundCMD> Player1EndRoundCMD;
	std::vector<InteriorCMD> Player1InteriorCMD;
	std::vector<ArmyCMD> Player1ArmyCMD;
	std::vector<TechnologyCMD> Player1TechnologyCMD;


};



