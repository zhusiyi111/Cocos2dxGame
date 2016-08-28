#include "Backstage.h"
#include "EconomyCMD.h"
#include "EndRoundCMD.h"
#include "DataLayer.h"
#include "DefineOrConst.h"
#include "ThanksScene.h"
#include "WinHint.h"
USING_NS_CC;

MyData Backstage::Player1Data = MyData();
Backstage::Backstage()
{
}


Backstage::~Backstage()
{
}


bool Backstage::init()
{
	bool bRet = false;
	do
	{

		bRet = true;
	} while (0);

	return bRet;
}

void Backstage::FirstRoundInit()
{
	int minenum = ToMapLayer_1->mine_num;	//矿点初始化
	Player1Data._MineData.resize(minenum);
	for (int i = 0; i < minenum; i++)
	{
		MineData a;
		a.GoldNum = 100;
		a.MineId = i + 1;
		Player1Data._MineData[i] = a;
	}

	Player1Data = ToDataLayer_1->data;

	//科技树初始化
	Player1Data.isTunTian = 0;
	Player1Data.isRefine = 0;
	Player1Data.isTaxLaw = 0;
	Player1Data.isBoom = 0;

	Player1Data.isCityState = 0;
	Player1Data.isDespotic = 0;
	Player1Data.isDemocracy = 0;
	Player1Data.isMonarchy = 0;
	Player1Data.isRepublic = 0;
	Player1Data.isCapitalism = 0;
	Player1Data.isSocialism = 0;
}

CCNode *Backstage::creat()
{
	Backstage *node = Backstage::create();


	return node;
}



void Backstage::EndRound()
{
}




void Backstage::ReceiveEconomyCMD(EconomyCMD cmd)	//接收经济命令
{
	
	if (cmd.PlayerId == 1)
	{
		Player1EconomyCMD.push_back(cmd);
	}
}

void Backstage::ReceiveInteriorCMD(InteriorCMD cmd)	//接收内政命令
{

	if (cmd.PlayerId == 1)
	{
		Player1InteriorCMD.push_back(cmd);
	}
}

void Backstage::ReceiveArmyCMD(ArmyCMD cmd)	//接收军事命令
{

	if (cmd.PlayerId == 1)
	{
		Player1ArmyCMD.push_back(cmd);
	}
}

void Backstage::ReceiveTechnologyCMD(TechnologyCMD cmd)	//接收科技命令
{

	if (cmd.PlayerId == 1)
	{
		Player1TechnologyCMD.push_back(cmd);
	}
}


void Backstage::ReceiveEndRoundCMD(EndRoundCMD cmd)	//接收回合结束命令
{
	
	if (cmd.PlayerId == 1)
	{
		Player1EndRoundCMD.push_back(cmd);
	}
}


void Backstage::ProcessStart() //开始处理双方命令，最后开始下一回合
{
	BeforeProcessInit();
	for (int i = 0; i < Player1EconomyCMD.size(); i++)
	{
		ProcessEconomyCMD(Player1EconomyCMD[i]);
	}
	for (int i = 0; i < Player1InteriorCMD.size(); i++)
	{
		ProcessInteriorCMD(Player1InteriorCMD[i]);
	}
	for (int i = 0; i < Player1ArmyCMD.size(); i++)
	{
		ProcessArmyCMD(Player1ArmyCMD[i]);
	}
	for (int i = 0; i < Player1TechnologyCMD.size(); i++)
	{
		ProcessTechnologyCMD(Player1TechnologyCMD[i]);
	}



	for (int i = 0; i < Player1EndRoundCMD.size(); i++)
	{
		ProcessEndRoundCMD(Player1EndRoundCMD[i]);
	}


	NextRound();
	
}


void Backstage::ProcessEconomyCMD(EconomyCMD cmd) //处理经济命令
{
	switch (cmd.type)
	{
	case CMD_Economy_Mine:	//采矿命令
		DoCMDMine(cmd);
		break;
	case CMD_Economy_Tax:	//收税
		DoCMDTax(cmd);	
		break;
	case CMD_Economy_Treasure:	//寻宝
		DoCMDTreasure(cmd);
		break;	
	case CMD_Economy_Market:		//市场
		DoCMDMarket(cmd);
		break;
	case CMD_Economy_BlackMarket:	//黑市
		DoCMDBlackMarket(cmd);
		break;

	}

}


void Backstage::ProcessInteriorCMD(InteriorCMD cmd) //处理内政命令
{
	switch (cmd.type)
	{
	case CMD_Interior_HelpPeople:	//济世命令(1)
		DoCMDHelpPeople(cmd);
		break;
	case CMD_Interior_Prevention:	//防灾
		DoCMDPrevention(cmd);
		break;
	case CMD_Interior_Pardon:		//大赦天下
		DoCMDPardon(cmd);
		break;
	case CMD_Interior_BuildMiracle:	//建造奇迹
		switch (cmd.sec_type)
		{
		case CMD_Interior_BuildMiracle_Pyramid:			//金字塔
			Player1Data._GoldDownFromDoInterior += __PyramidNeedMoney;
			Player1Data._CityDownFromDoInterior += __PyramidNeedCity;
			Player1Data.isPyramid = true;
			break;
		case CMD_Interior_BuildMiracle_Colossus:		//巨人像
			Player1Data._GoldDownFromDoInterior += __ColossusNeedMoney;
			Player1Data._CityDownFromDoInterior += __ColossusNeedCity;
			Player1Data.isColossus = true;
			break;
		case CMD_Interior_BuildMiracle_Terracotta:		//兵马俑
			Player1Data._GoldDownFromDoInterior += __TerracottaNeedMoney;
			Player1Data._CityDownFromDoInterior += __TerracottaDownCity;
			Player1Data.isTerracotta = true;
			break;
		case CMD_Interior_BuildMiracle_HangingGarden:		//空中花园
			Player1Data._CityDownFromDoInterior += __TerracottaDownCity;
			Player1Data._CrystalDownFromInterior += __HangingGardenDownCrystal;
			Player1Data.isHangingGarden = true;
			break;
		default:
			break;
		}
	}
}

void Backstage::ProcessArmyCMD(ArmyCMD cmd) //处理军事命令
{
	switch (cmd.type)
	{
	case CMD_Army_Conscription:	//征兵
		DoCMDConscription(cmd);
		break;
	case CMD_Army_Colony:	//殖民
		DoCMDColony(cmd);
		break;
	case CMD_Army_Garrison:		//驻军
		DoCMDGarrison(cmd);
		break;
	}
}

void Backstage::ProcessTechnologyCMD(TechnologyCMD cmd) //处理科技命令
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isPhysics == true)	//判断是否有物理学科技
		{
			Player1Data._CrystalUpFromPhysics += random(0, 100) <= 100 * __PhysicsUpCrystal ? 1 : 0;	//如果有物理学科技，有一定几率获得1水晶
		}
	}
	switch (cmd.type)
	{
	case CMD_Technology_Economy:	//经济类
		DoCMDTechnology_Economy(cmd);
		break;
	case CMD_Technology_Interior:	//内政类
		DoCMDTechnology_Interior(cmd);
		break;
	case CMD_Technology_Army:		//军事类
		DoCMDTechnology_Army(cmd);		
		break;
	case CMD_Technology_Technology://科技类
		DoCMDTechnology_Technology(cmd);
		break;
	}
}



void Backstage::ProcessEndRoundCMD(EndRoundCMD cmd)	//处理回合结束命令（roundnum++) ！！很多每回合都变化的值及最大最小值都在这里处理！
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._RoundNum++;

		
		MineProduceGold();

		Player1GoldChangedProcess();	//金钱更新
		Player1LoyalChangedProcess();	//民忠更新
		Player1SoldierChangedProcess();	//士兵数更新
		Player1CityChangedProcess();	//城池数更新
		Player1CrystalChangedProcess();	//水晶数更新


		if (CheckPlayer1isWin())	//检查玩家1是否达成了胜利条件
		{
			WinHint *win = WinHint::createHint(Player1Data._RoundNum);
			this->ToDataLayer_1->ToMenuLayer->addChild(win);
		}
	}

}

void Backstage::DoCMDMine(EconomyCMD cmd)  //执行采矿指令
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldUpFromMine = Player1Data._MineData[cmd.sec_type - 1].GoldNum / __GetMineEachTime;
		Player1Data._MineData[cmd.sec_type - 1].GoldNum -= Player1Data._GoldUpFromMine;
	}
}


void Backstage::DoCMDTax(EconomyCMD cmd)  //执行收税指令
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldUpFromTax = __TaxUpGoldBase;
		Player1Data._LoyalDownFromTax = __TaxDownLoyal;


	}
}

void Backstage::DoCMDTreasure(EconomyCMD cmd)	//寻宝
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isProspect == false)	//如果没有“勘探技术”，就要花钱，有的话就不要花钱
		{
			Player1Data._GoldDownFromDoTreasure += __TreasureNeedMoney;			//寻宝花费的金钱
		}
		
		Player1Data._SoldierDownFromTreasure += __TreasureDownSoldier;		//寻宝减少的士兵数
		Player1Data._GoldUpFromTreasure += random(0, __TresureUpMaxMoney);	//获得0-max的金钱

		if (Player1Data.isProspect == false)
		{
			Player1Data._CrystalUpFromTreasue += random(0, 100) <= 100 * __TresureUpCrystalRate ? 1 : 0;	//有几率获得1水晶
		}
		else
		{
			Player1Data._CrystalUpFromTreasue += random(0, 100) <= 100 * __ProspectUpCrystalFromTreasureRate ? 1 : 0;	//如果有“勘探技术”，更大几率获得1水晶
		}	
		
	}
}


void Backstage::DoCMDBlackMarket(EconomyCMD cmd)	//黑市
{
	if (cmd.PlayerId == 1)
	{
		if (cmd.sec_type == CMD_Economy_BlackMarket_BuyCrystal)
		{
			Player1Data._GoldDownFromDoBlackMarket += __BlackMarketBuyCrystalNeedMoney;	//黑市买入水晶所需金钱
			Player1Data._CrystalUpFromBlackMarket += __BlackMarkeyBuyCrystalUpCrystal;	//黑市买水晶获得的水晶
		}
		else if (cmd.sec_type == CMD_Economy_BlackMarket_SellCrystal)
		{
			Player1Data._CrystalDownFromBlackMarket += __BlackMarkeySellCrystalDownCrystal;	//黑市卖水晶获需的水晶
			Player1Data._GoldUpFromBlackMarket += __BlackMarketSellCrystalUpGold;	//黑市卖水晶所得金钱
		}

	}
}

void Backstage::DoCMDMarket(EconomyCMD cmd)	//市场
{
	if (cmd.PlayerId == 1)
	{
		if (cmd.sec_type == CMD_Economy_Market_BuyCrystal)
		{
			Player1Data._GoldDownFromDoMarket += __MarketBuyCrystalNeedMoney;	//市场买入水晶所需金钱
			Player1Data._CrystalUpFromMarket += __MarkeyBuyCrystalUpCrystal;	//市场买水晶获得的水晶
		}
		else if (cmd.sec_type == CMD_Economy_Market_SellCrystal)
		{
			Player1Data._CrystalDownFromMarket += __MarkeySellCrystalDownCrystal;	//市场卖水晶获需的水晶
			Player1Data._GoldUpFromMarket += __MarketSellCrystalUpGold;	//市场卖水晶所得金钱
		}

	}
}

//执行济世指令
void Backstage::DoCMDHelpPeople(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldDownFromDoInterior += __HelpPeopleNeedMoney;
		Player1Data._Loyal += __HelpPeopleUpLoyal;
	}
}

//执行防灾指令
void Backstage::DoCMDPrevention(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{

	}
}

//执行大赦天下指令
void Backstage::DoCMDPardon(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldDownFromDoInterior += __PardonNeedMoney;
		Player1Data._Loyal += __PardonUpLoyal;

	}
}


//执行征兵指令
void Backstage::DoCMDConscription(ArmyCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isTerracotta == true)
		{
			Player1Data._CrystalUpFromTerracotta += random(0, 100) > __TerracottaUpCrystalRate * 100 ? 1 : 0;
		}
		Player1Data._GoldDownFromDoArmy += __ConscriptionNeedMoney;
		Player1Data._LoyalDownFromConscription += __ConscriptionDownLoyal;
		Player1Data._SoldierUpFromConscription += __ConscriptionUpSoldierBase/100*Player1Data._Loyal;//征兵数为Base*（民忠/100）;
	}
}

//执行殖民指令
void Backstage::DoCMDColony(ArmyCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isStandingArmy == true)
		{
			Player1Data._CrystalUpFromStandingArmy += random(0, 100) <= __StandingArmyUpCrystalRata * 100 ? 1 : 0;	//如果有常备军，有几率获得水晶
		}
		Player1Data._SoldierDownFromColony += __ColonyDownSoldier;
		Player1Data._LoyalDownFromColony += __ColonyDownLoyal;
		Player1Data._CityUpFromColony += __ColonyUpCity;
		
		

	}
}

//执行驻军指令
void Backstage::DoCMDGarrison(ArmyCMD cmd)
{
	if (cmd.PlayerId == 1)
	{

	}
}


void Backstage::Player1EconomyCMDClear()	//清空玩家1经济命令
{
	Player1EconomyCMD.clear();
}

void Backstage::Player1InteriorCMDClear()	//清空玩家1内政命令
{
	Player1InteriorCMD.clear();

}

void Backstage::Player1ArmyCMDClear()	//清空玩家1军事命令
{
	Player1ArmyCMD.clear();
}

void Backstage::Player1TechnologyCMDClear()	//清空玩家1科技命令
{
	Player1TechnologyCMD.clear();

}

void Backstage::Player1EndRoundCMDClear()	//清空玩家1回合结束命令
{
	Player1EndRoundCMD.clear();
}

void Backstage::ClaerAllPlayer1CMD()
{
	Player1EconomyCMDClear();
	Player1EndRoundCMDClear();
	Player1InteriorCMDClear();
	Player1ArmyCMDClear();
	Player1TechnologyCMDClear();
}

void Backstage::NextRound()
{
	ClaerAllPlayer1CMD();
	ToDataLayer_1->data = Player1Data;
	ToDataLayer_1->InsideDataClear();
}

void Backstage::MineProduceGold()	//	每回合矿点更新
{
	int minenum = ToMapLayer_1->mine_num;
	for (int i = 0; i < minenum; i++)
	{
		Player1Data._MineData[i].GoldNum += __MineProduceGoldEachRound;
	}

}



void Backstage::DoCMDTechnology_Economy(TechnologyCMD cmd)	//处理经济类科技指令
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Economy_TunTian:		//屯田制
			Player1Data.isTunTian = 1;
			Player1Data._GoldDownFromDoTechnology += __TunTianNeedMoney;
			break;
		case CMD_Technology_Economy_Refine:		//精炼技术
			Player1Data.isRefine = 1;
			Player1Data._GoldDownFromDoTechnology += __RefineNeedMoney;
			break;
		case CMD_Technology_Economy_MarketTrade:	//市场交易
			Player1Data.isMarketTrade = 1;
			Player1Data._GoldDownFromDoTechnology += __MarketTradeNeedMoney;
			break;
		case CMD_Technology_Economy_Prospect:		//勘探技术
			Player1Data.isProspect = 1;
			Player1Data._GoldDownFromDoTechnology += __ProspectNeedMoney;
			break;
		case CMD_Technology_Economy_TaxLaw:		//税法
			Player1Data.isTaxLaw = 1;
			Player1Data._GoldDownFromDoTechnology += __TaxLawNeedMoney;
			break;
		case CMD_Technology_Economy_Boom:	//繁荣
			Player1Data.isBoom = 1;
			Player1Data._GoldDownFromDoTechnology += __BoomNeedMoney;
			Player1Data._CrystalDownFromTechnology += __BoomDownCrystal;
			break;
		}
	}
	else
	{

	}

}


void Backstage::DoCMDTechnology_Interior(TechnologyCMD cmd)	//处理内政类科技命令
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Interior_CityState:	//联邦制
			Player1Data.isCityState = 1;
			Player1Data._GoldDownFromDoTechnology += __CityStateNeedMoney;
			break;
		case CMD_Technology_Interior_Despotic:		//专制
			Player1Data.isDespotic = 1;
			Player1Data._GoldDownFromDoTechnology += __DespoticNeedMoney;
			Player1Data._CityUpFromDespotic += __DespoticGetCity;
			break;
		case CMD_Technology_Interior_Democracy:	//民主制
			Player1Data.isDemocracy = 1;
			Player1Data._GoldDownFromDoTechnology += __DemocracyNeedMoney;
			break;
		case CMD_Technology_Interior_Monarchy:		//“君主制”
			Player1Data.isMonarchy = 1;
			Player1Data._GoldDownFromDoTechnology += __MonarchyNeedMoney;
			break;
		case CMD_Technology_Interior_Republic:		//“共和制”
			Player1Data.isRepublic = 1;
			Player1Data._GoldDownFromDoTechnology += __RepublicNeedMoney;
			Player1Data._LoyalUpFromRepublic += __RepublicSetLoyalTo;
			break;
		case CMD_Technology_Interior_Capitalism:	//“资本主义”
			Player1Data.isCapitalism = 1;
			Player1Data._GoldDownFromDoTechnology += __CapitalismNeedMoney;
			Player1Data._CrystalDownFromTechnology += __CapitalismUpCrystal;
			break;
		case CMD_Technology_Interior_Socialism:		//“社会主义”
			Player1Data.isSocialism = 1;
			Player1Data._GoldDownFromDoTechnology += __SocialismNeedMoney;
			break;
		
		}
	}
	else
	{

	}
}

void Backstage::DoCMDTechnology_Army(TechnologyCMD cmd)		//处理军事类科技命令
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Army_Militia:	//民兵役
			Player1Data.isMilitia = 1;
			Player1Data._GoldDownFromDoTechnology += __MilitiaNeedMoney;
			break;
		case CMD_Technology_Army_Mercenary:		//雇佣兵制
			Player1Data.isMercenary = 1;
			Player1Data._GoldDownFromDoTechnology += __MercenaryNeedMoney;
			break;
		case CMD_Technology_Army_StandingArmy:	//常备军
			Player1Data.isStandingArmy = 1;
			Player1Data._CrystalDownFromTechnology += __StandingArmyDownCrystal;
			break;
		case CMD_Technology_Army_Fort:		//“堡垒”
			Player1Data.isFort = 1;
			Player1Data._GoldDownFromDoTechnology += __FortNeedMoney;
			break;
		case CMD_Technology_Army_AllSoldier:		//“全民皆兵”
			Player1Data.isAllSoldier = 1;
			Player1Data._CrystalDownFromTechnology += __AllSoldierDownCrystal;
			Player1Data._GoldDownFromDoTechnology += __AllSoldierNeedMoney;
			break;
		case CMD_Technology_Army_Spy:				//“间谍”
			Player1Data.isSpy = 1;
			Player1Data._GoldDownFromDoTechnology += __SpyNeedMoney;
			break;

		}
	}
	else
	{

	}
}


void Backstage::DoCMDTechnology_Technology(TechnologyCMD cmd)		//处理科技类科技命令
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Technology_Math:	//数学
			Player1Data.isMath = 1;
			Player1Data._GoldDownFromDoTechnology += __MathNeedMoney;
			break;
		case CMD_Technology_Technology_Physics:		//物理学
			Player1Data.isPhysics = 1;
			Player1Data._GoldDownFromDoTechnology += __PhysicsNeedMoney;
			break;
		case CMD_Technology_Technology_Biology:	//生物学
			Player1Data.isBiology = 1;
			Player1Data._GoldDownFromDoTechnology += __BiologyNeedMoney;
			break;
		case CMD_Technology_Technology_Electric:		//电子学
			Player1Data.isElectric = 1;
			Player1Data._CrystalDownFromTechnology += __ElectricNeedCrystal;
			break;
		case CMD_Technology_Technology_Chemistry:		//化学
			Player1Data.isChemistry = 1;
			Player1Data._GoldDownFromDoTechnology += __ChemistryNeedMoney;
			break;
		case CMD_Technology_Technology_SuperComputer:				//超级计算机
			Player1Data.isSuperComputer = 1;
			Player1Data._GoldDownFromDoTechnology += __SuperComputerNeedMoney;
			Player1Data._CrystalDownFromTechnology += __SuperComputerNeedCrystal;
			break;

		}
	}
	else
	{

	}
}



void Backstage::BeforeProcessInit()	//每回合处理数据前的初始化
{
	BeforeProcessGoldInit();
	BeforeProcessLoyalInit();
	BeforeProcessSoldierInit();
	BeforeProcessCityInit();
	BeforeProcessCrystalInit();

}


void Backstage::BeforeProcessGoldInit()		//金钱变化初始化
{
	
	Player1Data._GoldChanged = 0;
	Player1Data._GoldUp = 0;
	Player1Data._GoldUpFromMine = 0;
	Player1Data._GoldUpFromTax = 0;
	Player1Data._GoldUpFromTreasure = 0;
	Player1Data._GoldUpFromBlackMarket = 0;
	Player1Data._GoldUpFromMarket = 0;
	Player1Data._GoldUpFromTrade = 0;
	Player1Data._GoldUpFromTunTian = 0;
	Player1Data._GoldUpFromBiology = 0;
	Player1Data._GoldUpFromPyramid = 0;

	Player1Data._GoldDown = 0;
	Player1Data._GoldDownFromDoTreasure = 0;
	Player1Data._GoldDownFromDoBlackMarket = 0;
	Player1Data._GoldDownFromDoMarket = 0;
	Player1Data._GoldDownFromDoArmy = 0;
	Player1Data._GoldDownFromDoInterior = 0;
	Player1Data._GoldDownFromDoTechnology = 0;
}

void Backstage::BeforeProcessLoyalInit()			//民忠变化初始化
{
	
	Player1Data._LoyalChanged = 0;

	Player1Data._LoyalUp = 0;
	Player1Data._LoyalUpFromHelpPeople = 0;
	Player1Data._LoyalUpFromPardon = 0;
	Player1Data._LoyalUpFromRepublic = 0;

	Player1Data._LoyalDown = 0;
	Player1Data._LoyalDownFromTax = 0;
	Player1Data._LoyalDownFromColony = 0;
	Player1Data._LoyalDownFromConscription = 0;
	Player1Data._LoyalDownFromEachRound = 0;
}


void Backstage::BeforeProcessSoldierInit()			//士兵数变化初始化
{

	Player1Data._SoldierChanged = 0;

	Player1Data._SoldierUp = 0;
	Player1Data._SoldierUpFromConscription = 0;
	Player1Data._SoldierUpFromMilitiaEachRound = 0;
	Player1Data._SoldierUpFromColossusEachRound = 0;
	
	Player1Data._SoldierDown = 0;
	Player1Data._SoldierDownFromTreasure = 0;
	Player1Data._SoldierDownFromColony = 0;

}


void Backstage::BeforeProcessCityInit()			//城池数变化初始化
{

	Player1Data._CityChanged = 0;

	Player1Data._CityUp = 0;
	Player1Data._CityUpFromColony = 0;
	Player1Data._CityUpFromDespotic = 0;

	Player1Data._CityDown = 0;
	Player1Data._CityDownFromDoInterior = 0;

}

void Backstage::BeforeProcessCrystalInit()			//水晶数变化初始化
{

	Player1Data._CrystalChanged = 0;

	Player1Data._CrystalUp = 0;
	Player1Data._CrystalUpFromTreasue = 0;
	Player1Data._CrystalUpFromBlackMarket = 0;
	Player1Data._CrystalUpFromMarket = 0;
	Player1Data._CrystalUpFromStandingArmy = 0;
	Player1Data._CrystalUpFromPhysics = 0;
	Player1Data._CrystalUpFromChemistryEachRound = 0;
	Player1Data._CrystalUpFromTerracotta = 0;

	Player1Data._CrystalDown = 0;
	Player1Data._CrystalDownFromBlackMarket = 0;
	Player1Data._CrystalDownFromMarket = 0;
	Player1Data._CrystalDownFromInterior = 0;
	Player1Data._CrystalDownFromTechnology = 0;
	


}

void Backstage::Player1GoldChangedProcess()
{
	if (Player1Data.isTunTian == true)	//判断是否有“屯田制”科技
	{
		Player1Data._GoldUpFromTunTian = __TunTianBaseGold + random(0, __TunTianFlowGold);	//如果有的话，产生5+（0，5）的金钱
	}
	if (Player1Data.isRefine == true)	//判断是否有“精炼技术”科技
	{
		Player1Data._GoldUpFromMine = __RefineUpRataTo * Player1Data._GoldUpFromMine;	//	如果有，增加金矿所得金钱0.5倍
	}
	if (Player1Data.isTaxLaw == true)	//判断是否有“税法”科技
	{
		if (Player1Data._GoldUpFromTax > 0)		//判断当前回合是否执行了收税指令
		{
			Player1Data._GoldUpFromTax += __TaxProduceGoldEachCity * Player1Data._CityNum;	//如果有，每个城池加成
		}
	}
	if (Player1Data.isMonarchy == true)	//判断是否有“君主制”
	{
		Player1Data._GoldUpFromTax *= __MonarchyUpMoneyRateFromTax;	//如果有，增加税收所得率
	}
	if (Player1Data.isPyramid == true)	//判断是否有“金字塔”
	{
		Player1Data._GoldUpFromPyramid += __PyramidUpGoldEachRound;
	}
	if (Player1Data.isBiology == true)	//判断是否有生物学
	{
		Player1Data._GoldUpFromBiology += Player1Data._Soldier*__BiologyUpMoneyRateEachRound;	//如果有，获得士兵数一定百分比的金钱
	}
	if (Player1Data.isSuperComputer == true)
	{
		Player1Data._GoldDownFromDoTechnology = 0;	//如果有超级计算机，升级科技不再需要金钱
	}

	//判断是否有“税法”科技加成 在原函数中执行
	
	Player1Data._GoldUp += Player1Data._GoldUpFromMine +	//将各项收入所得加起来
		Player1Data._GoldUpFromTax +
		Player1Data._GoldUpFromTrade +
		Player1Data._GoldUpFromBlackMarket +
		Player1Data._GoldUpFromMarket +
		Player1Data._GoldUpFromTunTian +
		Player1Data._GoldUpFromBiology +
		Player1Data._GoldUpFromPyramid +
		Player1Data._GoldUpFromTreasure;

	if (Player1Data.isSocialism == true)	//判断是否有“资本主义”科技
	{
		Player1Data._GoldUp *= __CapitalismUpMoneyRate;	//如果有，增加相应倍率。
	}
	if (Player1Data.isBoom == true)	//判断是否有"繁荣"科技
	{
		Player1Data._GoldUp = Player1Data._GoldUp + Player1Data._GoldUp;	//如果有，所有收入所得加倍
	}

	Player1Data._GoldDown += Player1Data._GoldDownFromDoArmy +
		Player1Data._GoldDownFromDoInterior +
		Player1Data._GoldDownFromDoTechnology +
		Player1Data._GoldDownFromDoTreasure +
		Player1Data._GoldDownFromDoBlackMarket +
		Player1Data._GoldDownFromDoMarket;

	Player1Data._GoldChanged = Player1Data._GoldUp - Player1Data._GoldDown;	//金钱改变等于获得数减去支出数

	Player1Data._Gold += Player1Data._GoldChanged;	//	更新金钱
	
}

void Backstage::Player1LoyalChangedProcess()
{
	if (Player1Data.isSocialism == true)	//判断是否有“社会主义”科技
	{
		Player1Data._Loyal = 100;	//如果有，直接将民忠置为100，然后退出
		return;
	}
	Player1Data._LoyalDownFromEachRound += __LoyalDownEachRound;	//民忠值每回合减少值	
	if (Player1Data.isDemocracy == true)
	{
		Player1Data._LoyalDownFromEachRound -= __DemocracyDownLoyalDownEachRound;	//如果有“民主制”，每回合减少民忠下降值
	}
	if (Player1Data.isMercenary == true)
	{
		Player1Data._LoyalDownFromConscription = 0;			//如果有“雇佣兵制”，征兵不再减少民忠值
	}
	if (Player1Data.isColossus == true)
	{
		Player1Data._LoyalDownFromColony = 0;			//如果有“巨人像”，殖民不再减少民忠值
	}

	Player1Data._LoyalUp = Player1Data._LoyalUpFromHelpPeople +		//民忠增加的部分
		Player1Data._LoyalUpFromPardon+
		Player1Data._LoyalUpFromRepublic;

	Player1Data._LoyalDown = Player1Data._LoyalDownFromColony +		//民忠减少的部分
		Player1Data._LoyalDownFromConscription +
		Player1Data._LoyalDownFromEachRound+
		Player1Data._LoyalDownFromTax;

	Player1Data._LoyalChanged = Player1Data._LoyalUp - Player1Data._LoyalDown;	//民忠改变值

	Player1Data._Loyal += Player1Data._LoyalChanged;

	if (Player1Data._Loyal > 100)	//民忠值最大为100
	{
		Player1Data._Loyal = 100;
	}
}

void Backstage::Player1SoldierChangedProcess()
{

	if (Player1Data.isMonarchy == true)
	{
		Player1Data._SoldierUpFromConscription *= __MonarchyUpConscriptionRate;	//如果有“君主制”，征兵时征兵率增加
	}
	if (Player1Data.isMilitia == true)
	{
		Player1Data._SoldierUpFromMilitiaEachRound = __MilitiaUpSoldierEachRound;	//如果有“民兵役”，每回合获得一定士兵数
	}
	if (Player1Data.isAllSoldier == true)
	{
		Player1Data._SoldierUpFromConscription += __AllSoldierUpSoldierEachCity*Player1Data._CityNum;	//如果有“全民皆兵”，每个城池对征兵数有加成
	}
	if (Player1Data.isColossus == true)
	{
		Player1Data._SoldierUpFromColossusEachRound += Player1Data._Soldier*__ColossusUpSoldierRateEachRound;	//如果有巨人像，每回合获得上回合士兵数一定百分比的士兵
	}
	Player1Data._SoldierUp = Player1Data._SoldierUpFromConscription				//士兵数增加的部分
							+Player1Data._SoldierUpFromMilitiaEachRound
							+ Player1Data._SoldierUpFromColossusEachRound;

	if (Player1Data.isHangingGarden == true)
	{
		Player1Data._SoldierDownFromTreasure = 0;			//如果有空中花园，寻宝不再需要士兵
	}

	Player1Data._SoldierDown = Player1Data._SoldierDownFromColony				//士兵数减少的部分
							 + Player1Data._SoldierDownFromTreasure;		
		

	Player1Data._SoldierChanged = Player1Data._SoldierUp - Player1Data._SoldierDown;	//士兵数改变值

	Player1Data._Soldier += Player1Data._SoldierChanged;

}


void Backstage::Player1CityChangedProcess()
{
	Player1Data._CityUp = Player1Data._CityUpFromColony	//城池数增加部分
						+ Player1Data._CityUpFromDespotic;		
		
	Player1Data._CityDown = Player1Data._CityDownFromDoInterior;			//城池数减少部分

	Player1Data._CityChanged = Player1Data._CityUp - Player1Data._CityDown;	//城池数变化部分

	Player1Data._CityNum += Player1Data._CityChanged;

}


void Backstage::Player1CrystalChangedProcess()		
{
	if (Player1Data.isChemistry == true)
	{
		Player1Data._CrystalUpFromChemistryEachRound += random(0, 100) < 100 * __ChemistryUpCrystalRateEachRound ? 1 : 0;	//如果有化学，每回合有一定几率增加水晶1
	}
	if (Player1Data.isHangingGarden == true)
	{
		Player1Data._CrystalDownFromTechnology = 0;				//如果有空中花园，升级科技不再需要水晶
	}
	Player1Data._CrystalUp = Player1Data._CrystalUpFromTreasue				//水晶数增加部分
						   + Player1Data._CrystalUpFromBlackMarket
						   + Player1Data._CrystalUpFromMarket
						   + Player1Data._CrystalUpFromPhysics
						   + Player1Data._CrystalUpFromChemistryEachRound
						   + Player1Data._CrystalUpFromStandingArmy
						   + Player1Data._CrystalUpFromTerracotta;

	Player1Data._CrystalDown = Player1Data._CrystalDownFromTechnology					//水晶数减少部分
							 + Player1Data._CrystalDownFromInterior
							 + Player1Data._CrystalDownFromBlackMarket
							 + Player1Data._CrystalDownFromMarket;

	Player1Data._CrystalChanged = Player1Data._CrystalUp - Player1Data._CrystalDown;	//水晶数变化部分

	Player1Data._Crystal += Player1Data._CrystalChanged;

}



bool Backstage::CheckPlayer1isWin()	//判断玩家1是否达成胜利条件
{
	int sum = CheckPlayer1isWinOfEconomy() + CheckPlayer1isWinOfInterior() + CheckPlayer1isWinOfArmy() + CheckPlayer1isWinOfTechnology();
	if (sum >= 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Backstage::CheckPlayer1isWinOfEconomy()	//判断玩家1的经济获胜条件
{
	if (Player1Data._Gold >= __WinOfEconomyNeedGold)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Backstage::CheckPlayer1isWinOfInterior()	//判断玩家1的内政获胜条件
{
	if (Player1Data.isPyramid + Player1Data.isColossus + Player1Data.isTerracotta + Player1Data.isHangingGarden >= __WinOfInteriorNeedMiracleNum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Backstage::CheckPlayer1isWinOfArmy()	//判断玩家1的军事获胜条件
{
	if (Player1Data._CityNum >= __WinOfArmyNeedCity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Backstage::CheckPlayer1isWinOfTechnology()	//判断玩家1的科技获胜条件
{
	if (Player1Data.isBoom
		+ (Player1Data.isAllSoldier || Player1Data.isSpy)
		+ (Player1Data.isCapitalism || Player1Data.isSocialism)
		+ Player1Data.isSuperComputer
		>= __WinOfTechnologyNeedTecNum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}