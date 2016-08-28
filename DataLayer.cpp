#include "DataLayer.h"
#include "Backstage.h"
#include "MenuLayer.h"
#include "InteriorCMD.h"


MyData DataLayer::data = MyData();
DataLayer::DataLayer()
{
}


DataLayer::~DataLayer()
{
}

CCLayer *DataLayer::creatLayer()
{
	DataLayer *layer = DataLayer::create();

	return layer;
}

bool DataLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	bool bRet = false;

	do{
		showRoundNum();
		showGold();
		showLoyal();
		showSoldier();
		showCity();
		showCrystal();
		FirstRoundInit();
		bRet = true;
	} while (0);
	return bRet;
}

void DataLayer::FirstRoundInit()		//第一回合之前的初始化
{
	EconomyCMDFlag = 0;
	InteriorCMDFlag = 0;
	ArmyCMDFlag = 0;
	TechnologyCMDFlag = 0;


	data._RoundNum = 1;
	data._Gold = __FirstRoundGold;
	data._Loyal = __FirstRoundLoyal;
	data._Soldier = __FirstRoundSoldier;
	data._CityNum = __FirstRoundCity;
	data._Crystal = __FirstRoundCrystal;

	data.isTunTian = 0;
	data.isRefine = 0;
	data.isTaxLaw = 0;
	data.isBoom = 0;

	data.isCityState = 0;
	data.isDespotic = 0;
	data.isDemocracy = 0;
	data.isMonarchy = 0;
	data.isRepublic = 0;
	data.isCapitalism = 0;
	data.isSocialism = 0;

	data.isMilitia = 0;
	data.isMercenary = 0;
	data.isStandingArmy = 0;
	data.isAllSoldier = 0;
	data.isFort = 0;
	data.isSpy = 0;

	data.isPyramid = 0;
	data.isColossus = 0;
	data.isTerracotta = 0;
	data.isHangingGarden = 0;
}




void DataLayer::showRoundNum()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[6];
	sprintf(temp, "%d", data._RoundNum);
	RoundShow = CCLabelTTF::create(temp, "Arial", 25);
	RoundShow->setColor(ccc3(255, 255, 255));
	RoundShow->setPosition(ccp(size.width / 9, size.height * 8 / 9));
	this->addChild(RoundShow);
}

void DataLayer::showGold()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[8];
	sprintf(temp, "%d", data._Gold);
	GoldShow = CCLabelTTF::create(temp, "Arial", 25);
	GoldShow->setColor(ccc3(255, 255, 255));
	GoldShow->setPosition(ccp(size.width / 4, size.height * 9 / 10));
	this->addChild(GoldShow);
}

void DataLayer::showSoldier()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[6];
	sprintf(temp, "%d", data._Soldier);
	SoldierShow = CCLabelTTF::create(temp, "Arial", 25);
	SoldierShow->setColor(ccc3(255, 255, 255));
	SoldierShow->setPosition(ccp(size.width * 2 / 5, size.height * 9 / 10));
	this->addChild(SoldierShow);
}


void DataLayer::showLoyal()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[6];
	sprintf(temp, "%d", data._Loyal);
	LoyalShow = CCLabelTTF::create(temp, "Arial", 25);
	LoyalShow->setColor(ccc3(255, 255, 255));
	LoyalShow->setPosition(ccp(size.width *3/ 5, size.height * 9 / 10));
	this->addChild(LoyalShow);
}



void DataLayer::showCity()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[6];
	sprintf(temp, "%d", data._CityNum);
	CityShow = CCLabelTTF::create(temp, "Arial", 25);
	CityShow->setColor(ccc3(255, 255, 255));
	CityShow->setPosition(ccp(size.width * 4 / 5, size.height * 9 / 10));
	this->addChild(CityShow);
}

void DataLayer::showCrystal()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	char temp[6];
	sprintf(temp, "%d", data._Crystal);
	CrystalShow = CCLabelTTF::create(temp, "Arial", 25);
	CrystalShow->setColor(ccc3(255, 255, 255));
	CrystalShow->setPosition(ccp(size.width * 8 / 9, size.height * 9 / 10));
	this->addChild(CrystalShow);
}




void DataLayer::MyUpdate()
{
	removeAllChildren();
	
	showGold();
	showLoyal();
	showSoldier();
	showCity();
	showCrystal();
	showRoundNum();
}

//执行经济命令，如何能执行返回0，否则返回错误代码
int DataLayer::DoCMD(EconomyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//什么事都没做
		return 1;
		break;
	case 1:			//采矿
		if (EconomyCMDFlag == true )
		{
			return 2;		//已经执行过经济类命令，返回错误代码2
		}
		else if (cmd.sec_type == 0)	//未指定矿点
		{
			return 1;
		}
		else
		{
			MineCMDFlag = 1;	//是否执行采矿指令标志位
			EconomyCMDFlag = true;
			return 0;
		}
		break;
	case 2:			//收税
		if (EconomyCMDFlag == true)
		{
			return 2;		//已经执行过经济类命令，返回错误代码2
		}
		else if (data._Loyal<__TaxDownLoyal)	
		{
			return 1;
		}
		else
		{
			EconomyCMDFlag = true;
			return 0;
		}
		break;
	case 3:
		return 999;
		break;
	case CMD_Economy_Treasure:			//寻宝
		if (EconomyCMDFlag == true)
		{
			return 2;		//已经执行过经济类命令，返回错误代码2
		}
		else if (data._Gold < __TreasureNeedMoney || data._Soldier < __TreasureDownSoldier )
		{
			return 1;
		}
		else
		{
			EconomyCMDFlag = true;
			return 0;
		}
		break;
	case CMD_Economy_Market:	//市场
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
			break;
		case CMD_Economy_Market_BuyCrystal:	//市场买入水晶
			if (EconomyCMDFlag == true)
			{
				return 2;		//已经执行过经济类命令，返回错误代码2
			}
			else if (data._Gold < __MarketBuyCrystalNeedMoney || data.isMarketTrade == false)
			{
				return 1;
			}
			else
			{
				EconomyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Economy_Market_SellCrystal:	//市场卖出水晶
			if (EconomyCMDFlag == true)
			{
				return 2;		//已经执行过经济类命令，返回错误代码2
			}
			else if (data._Crystal < __MarkeySellCrystalDownCrystal || data.isMarketTrade == false)
			{
				return 1;
			}
			else
			{
				EconomyCMDFlag = true;
				return 0;
			}
			break;
		}
	case CMD_Economy_BlackMarket:	//黑市
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
			break;
		case CMD_Economy_BlackMarket_BuyCrystal:	//黑市买入水晶
			if (EconomyCMDFlag == true)
			{
				return 2;		//已经执行过经济类命令，返回错误代码2
			}
			else if (data._Gold < __BlackMarketBuyCrystalNeedMoney )
			{
				return 1;
			}
			else
			{
				EconomyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Economy_BlackMarket_SellCrystal:	//黑市卖出水晶
			if (EconomyCMDFlag == true)
			{
				return 2;		//已经执行过经济类命令，返回错误代码2
			}
			else if (data._Crystal < __BlackMarkeySellCrystalDownCrystal)	
			{
				return 1;
			}
			else
			{
				EconomyCMDFlag = true;
				return 0;
			}
			break;
		}

	default:
		return 1;
		break;
		}

	

}

//执行内政命令，如何能执行返回0，否则返回错误代码
int DataLayer::DoCMD(InteriorCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//什么事都没做
		return 1;
		break;
	case CMD_Interior_HelpPeople:			//济世
		if (InteriorCMDFlag == true)	
		{
			return 2;			//已经执行过内政命令，返回错误代码2
		}
		else if (data._Gold < __HelpPeopleNeedMoney)
		{
			return 1;
		}
		else
		{
			HelpPeopleCMDFlag = 1;	//是否执行济世指令标志位
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_Prevention:     //防灾
		return 999;			//暂时关闭
		if (InteriorCMDFlag == true)
		{
			return 2;
		}
		else
		{
			PreventionCMDFlag = 1;	//是否执行防灾指令标志位
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_Pardon:		//大赦天下
		if (InteriorCMDFlag == true)
		{
			return 2;
		}
		else if (data._Gold < __PardonNeedMoney)
		{
			return 1;
		}
		else
		{
			PardonCMDFlag = 1;	//是否执行大赦天下指令标志位
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_BuildMiracle:
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
		case CMD_Interior_BuildMiracle_Pyramid:		//金字塔
			if (InteriorCMDFlag == true)
			{
				return 2;
			}
			if (data.isPyramid == true)
			{
				return 3;
			}
			else if (data._Gold < __PyramidNeedMoney || data._CityNum < __PyramidNeedCity || data.isRefine==false )
			{
				return 1;
			}
			else
			{
				InteriorCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Interior_BuildMiracle_Colossus:	//巨人像
			if (InteriorCMDFlag == true)
			{
				return 2;
			}
			if (data.isColossus == true)
			{
				return 3;
			}
			else if (data._Gold < __ColossusNeedMoney || data._CityNum < __ColossusNeedCity || data.isMercenary == false)
			{
				return 1;
			}
			else
			{
				InteriorCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Interior_BuildMiracle_Terracotta:	//兵马俑
			if (InteriorCMDFlag == true)
			{
				return 2;
			}
			if (data.isTerracotta == true)
			{
				return 3;
			}
			else if (data._Gold < __TerracottaNeedMoney || data._CityNum < __TerracottaDownCity || data.isStandingArmy == false)
			{
				return 1;
			}
			else
			{
				InteriorCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Interior_BuildMiracle_HangingGarden:	//空中花园
			if (InteriorCMDFlag == true)
			{
				return 2;
			}
			if (data.isHangingGarden == true)
			{
				return 3;
			}
			else if (data._CityNum < __HangingGardenDownCity || data._Crystal < __HangingGardenDownCrystal || data.isBiology == false)
			{
				return 1;
			}
			else
			{
				InteriorCMDFlag = true;
				return 0;
			}
			break;
		default:
			return 999;
			break;
		}
	default:
		return 1;
	}
}


//执行军事命令，如果能执行返回0，否则返回错误代码
int DataLayer::DoCMD(ArmyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//什么事都没做
		return 1;
		break;
	case CMD_Army_Conscription:			//征兵
		if (ArmyCMDFlag == true)
		{
			return 2;			//已经执行过军事命令，返回错误代码2
		}
		else if (data._Gold < __ConscriptionNeedMoney || data._Loyal<__ConscriptionDownLoyal)
		{
			return 1;
		}
		else
		{
			ArmyCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Army_Colony:     //殖民
		if (ArmyCMDFlag == true)
		{
			return 2;			//已经执行过军事命令，返回错误代码2
		}
		else if (data._Soldier < __ColonyDownSoldier || data._Loyal<__ColonyDownLoyal || data.isCityState==0 /*需要“城邦制“科技*/)
		{
			return 1;
		}
		else
		{
			ArmyCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Army_Garrison:		//驻军
		return 999;
		break;
	default:
		return 1;
	}
}

//执行科技命令，如果能执行返回0，否则返回错误代码
int DataLayer::DoCMD(TechnologyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//什么事都没做
		return 1;
		break;
	case 1:			//经济类科技
		switch (cmd.sec_type)
		{
		case CMD_Technology_Economy_TunTian:		//屯田制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isTunTian == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __TunTianNeedMoney)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Economy_Refine:			//精炼技术
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isRefine == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __RefineNeedMoney || data.isTunTian == false)
			{
				return 1;	
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Economy_MarketTrade:			//市场交易
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isMarketTrade == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __MarketTradeNeedMoney || data.isTunTian == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Economy_Prospect:			//勘探技术
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isProspect == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __ProspectNeedMoney || data.isRefine == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Economy_TaxLaw:		//税法
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isTaxLaw == true )
			{
				return 3;
			}
			else if (data._Gold < __TaxLawNeedMoney || data.isMarketTrade == false || data.isMath == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Economy_Boom:		//繁荣
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isBoom == true )
			{
				return 3;
			}
			else if (data._Gold < __BoomNeedMoney || (data.isTaxLaw==false && data.isProspect==false)  /*既没有勘探技术也没有税法*/ || data._Crystal < __BoomDownCrystal)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		default:
			return 1;
			break;
		}
	case 2:    
		switch (cmd.sec_type)
		{
		case CMD_Technology_Interior_CityState:
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isCityState == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __CityStateNeedMoney)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Despotic:	//专制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isDespotic == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __DespoticNeedMoney || data.isCityState==false || data.isMath == false || data.isDemocracy == true /*如果已经有民主制，就不能升级专制*/)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Democracy:	//民主制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isDemocracy == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __DemocracyNeedMoney || data.isCityState==false || data.isMath == false ||data.isDespotic == true /*如果有了专制，就不能再升级民主制*/ )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Monarchy:	//君主制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isMonarchy == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __MonarchyNeedMoney || data.isDespotic == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Republic:	//共和制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isRepublic == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __RepublicNeedMoney || data.isDemocracy == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Capitalism:	//资本主义
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isCapitalism == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __CapitalismNeedMoney || data.isMonarchy == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Socialism:	//社会主义
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isSocialism == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __SocialismNeedMoney || data.isRepublic == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		default:
			return 1;

		}
	case 3:		
		switch (cmd.sec_type)
		{
		case CMD_Technology_Army_Militia:		//民兵役
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isMilitia == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __MilitiaNeedMoney )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Army_Mercenary:		//雇佣兵制
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isMercenary == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __MercenaryNeedMoney || data.isMilitia == false )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Army_StandingArmy:		//常备军
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isStandingArmy == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Soldier < __StandingArmyNeedSoldier || data.isMercenary == false || data._Crystal < __StandingArmyDownCrystal )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Army_Fort:			//堡垒
			return 999;		//暂时保留，具体实现后删去
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isFort == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __FortNeedMoney || data.isMercenary == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Army_AllSoldier:				//全民皆兵
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isAllSoldier == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __AllSoldierNeedMoney || data.isStandingArmy == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Army_Spy:					//间谍
			return 999;				//暂时保留，具体实现后删去
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isSpy == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __SpyNeedMoney || data.isFort == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		default:
			return 1;
			break;
		}
	case CMD_Technology_Technology:		//科技类科技
		switch (cmd.sec_type)
		{
		case CMD_Technology_Technology_Math:		//数学
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isMath == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __MathNeedMoney )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Technology_Physics:		//物理学
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isPhysics == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __PhysicsNeedMoney || data.isMath == false )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Technology_Biology:		//生物学
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isBiology == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __BiologyNeedMoney || data.isMath == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Technology_Electric:		//电子学
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isElectric == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Crystal < __ElectricNeedCrystal || data.isPhysics == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Technology_Chemistry:		//化学
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isChemistry == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Gold < __ChemistryNeedMoney || data.isBiology == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Technology_SuperComputer:		//超级计算机
			if (TechnologyCMDFlag == true)
			{
				return 2;		//已执行过科技命令
			}
			else if (data.isSuperComputer == true)
			{
				return 3;		//3为已有该项科技的错误代码
			}
			else if (data._Crystal < __SuperComputerNeedCrystal || data._Gold < __SuperComputerNeedMoney || data.isElectric == false)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		default:
			return 1;
			break;
		}
	default:
		return 1;
	}
}

void DataLayer::InsideDataClear()
{
	EconomyCMDFlag = 0;
	MineCMDFlag = 0;
	InteriorCMDFlag = 0;
	HelpPeopleCMDFlag = 0;
	PreventionCMDFlag = 0;
	PardonCMDFlag = 0;
	ArmyCMDFlag = 0;
	TechnologyCMDFlag = 0;
}