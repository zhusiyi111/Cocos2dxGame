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
	int minenum = ToMapLayer_1->mine_num;	//����ʼ��
	Player1Data._MineData.resize(minenum);
	for (int i = 0; i < minenum; i++)
	{
		MineData a;
		a.GoldNum = 100;
		a.MineId = i + 1;
		Player1Data._MineData[i] = a;
	}

	Player1Data = ToDataLayer_1->data;

	//�Ƽ�����ʼ��
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




void Backstage::ReceiveEconomyCMD(EconomyCMD cmd)	//���վ�������
{
	
	if (cmd.PlayerId == 1)
	{
		Player1EconomyCMD.push_back(cmd);
	}
}

void Backstage::ReceiveInteriorCMD(InteriorCMD cmd)	//������������
{

	if (cmd.PlayerId == 1)
	{
		Player1InteriorCMD.push_back(cmd);
	}
}

void Backstage::ReceiveArmyCMD(ArmyCMD cmd)	//���վ�������
{

	if (cmd.PlayerId == 1)
	{
		Player1ArmyCMD.push_back(cmd);
	}
}

void Backstage::ReceiveTechnologyCMD(TechnologyCMD cmd)	//���տƼ�����
{

	if (cmd.PlayerId == 1)
	{
		Player1TechnologyCMD.push_back(cmd);
	}
}


void Backstage::ReceiveEndRoundCMD(EndRoundCMD cmd)	//���ջغϽ�������
{
	
	if (cmd.PlayerId == 1)
	{
		Player1EndRoundCMD.push_back(cmd);
	}
}


void Backstage::ProcessStart() //��ʼ����˫��������ʼ��һ�غ�
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


void Backstage::ProcessEconomyCMD(EconomyCMD cmd) //����������
{
	switch (cmd.type)
	{
	case CMD_Economy_Mine:	//�ɿ�����
		DoCMDMine(cmd);
		break;
	case CMD_Economy_Tax:	//��˰
		DoCMDTax(cmd);	
		break;
	case CMD_Economy_Treasure:	//Ѱ��
		DoCMDTreasure(cmd);
		break;	
	case CMD_Economy_Market:		//�г�
		DoCMDMarket(cmd);
		break;
	case CMD_Economy_BlackMarket:	//����
		DoCMDBlackMarket(cmd);
		break;

	}

}


void Backstage::ProcessInteriorCMD(InteriorCMD cmd) //������������
{
	switch (cmd.type)
	{
	case CMD_Interior_HelpPeople:	//��������(1)
		DoCMDHelpPeople(cmd);
		break;
	case CMD_Interior_Prevention:	//����
		DoCMDPrevention(cmd);
		break;
	case CMD_Interior_Pardon:		//��������
		DoCMDPardon(cmd);
		break;
	case CMD_Interior_BuildMiracle:	//�����漣
		switch (cmd.sec_type)
		{
		case CMD_Interior_BuildMiracle_Pyramid:			//������
			Player1Data._GoldDownFromDoInterior += __PyramidNeedMoney;
			Player1Data._CityDownFromDoInterior += __PyramidNeedCity;
			Player1Data.isPyramid = true;
			break;
		case CMD_Interior_BuildMiracle_Colossus:		//������
			Player1Data._GoldDownFromDoInterior += __ColossusNeedMoney;
			Player1Data._CityDownFromDoInterior += __ColossusNeedCity;
			Player1Data.isColossus = true;
			break;
		case CMD_Interior_BuildMiracle_Terracotta:		//����ٸ
			Player1Data._GoldDownFromDoInterior += __TerracottaNeedMoney;
			Player1Data._CityDownFromDoInterior += __TerracottaDownCity;
			Player1Data.isTerracotta = true;
			break;
		case CMD_Interior_BuildMiracle_HangingGarden:		//���л�԰
			Player1Data._CityDownFromDoInterior += __TerracottaDownCity;
			Player1Data._CrystalDownFromInterior += __HangingGardenDownCrystal;
			Player1Data.isHangingGarden = true;
			break;
		default:
			break;
		}
	}
}

void Backstage::ProcessArmyCMD(ArmyCMD cmd) //�����������
{
	switch (cmd.type)
	{
	case CMD_Army_Conscription:	//����
		DoCMDConscription(cmd);
		break;
	case CMD_Army_Colony:	//ֳ��
		DoCMDColony(cmd);
		break;
	case CMD_Army_Garrison:		//פ��
		DoCMDGarrison(cmd);
		break;
	}
}

void Backstage::ProcessTechnologyCMD(TechnologyCMD cmd) //����Ƽ�����
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isPhysics == true)	//�ж��Ƿ�������ѧ�Ƽ�
		{
			Player1Data._CrystalUpFromPhysics += random(0, 100) <= 100 * __PhysicsUpCrystal ? 1 : 0;	//���������ѧ�Ƽ�����һ�����ʻ��1ˮ��
		}
	}
	switch (cmd.type)
	{
	case CMD_Technology_Economy:	//������
		DoCMDTechnology_Economy(cmd);
		break;
	case CMD_Technology_Interior:	//������
		DoCMDTechnology_Interior(cmd);
		break;
	case CMD_Technology_Army:		//������
		DoCMDTechnology_Army(cmd);		
		break;
	case CMD_Technology_Technology://�Ƽ���
		DoCMDTechnology_Technology(cmd);
		break;
	}
}



void Backstage::ProcessEndRoundCMD(EndRoundCMD cmd)	//����غϽ������roundnum++) �����ܶ�ÿ�غ϶��仯��ֵ�������Сֵ�������ﴦ��
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._RoundNum++;

		
		MineProduceGold();

		Player1GoldChangedProcess();	//��Ǯ����
		Player1LoyalChangedProcess();	//���Ҹ���
		Player1SoldierChangedProcess();	//ʿ��������
		Player1CityChangedProcess();	//�ǳ�������
		Player1CrystalChangedProcess();	//ˮ��������


		if (CheckPlayer1isWin())	//������1�Ƿ�����ʤ������
		{
			WinHint *win = WinHint::createHint(Player1Data._RoundNum);
			this->ToDataLayer_1->ToMenuLayer->addChild(win);
		}
	}

}

void Backstage::DoCMDMine(EconomyCMD cmd)  //ִ�вɿ�ָ��
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldUpFromMine = Player1Data._MineData[cmd.sec_type - 1].GoldNum / __GetMineEachTime;
		Player1Data._MineData[cmd.sec_type - 1].GoldNum -= Player1Data._GoldUpFromMine;
	}
}


void Backstage::DoCMDTax(EconomyCMD cmd)  //ִ����˰ָ��
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldUpFromTax = __TaxUpGoldBase;
		Player1Data._LoyalDownFromTax = __TaxDownLoyal;


	}
}

void Backstage::DoCMDTreasure(EconomyCMD cmd)	//Ѱ��
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isProspect == false)	//���û�С���̽����������Ҫ��Ǯ���еĻ��Ͳ�Ҫ��Ǯ
		{
			Player1Data._GoldDownFromDoTreasure += __TreasureNeedMoney;			//Ѱ�����ѵĽ�Ǯ
		}
		
		Player1Data._SoldierDownFromTreasure += __TreasureDownSoldier;		//Ѱ�����ٵ�ʿ����
		Player1Data._GoldUpFromTreasure += random(0, __TresureUpMaxMoney);	//���0-max�Ľ�Ǯ

		if (Player1Data.isProspect == false)
		{
			Player1Data._CrystalUpFromTreasue += random(0, 100) <= 100 * __TresureUpCrystalRate ? 1 : 0;	//�м��ʻ��1ˮ��
		}
		else
		{
			Player1Data._CrystalUpFromTreasue += random(0, 100) <= 100 * __ProspectUpCrystalFromTreasureRate ? 1 : 0;	//����С���̽�������������ʻ��1ˮ��
		}	
		
	}
}


void Backstage::DoCMDBlackMarket(EconomyCMD cmd)	//����
{
	if (cmd.PlayerId == 1)
	{
		if (cmd.sec_type == CMD_Economy_BlackMarket_BuyCrystal)
		{
			Player1Data._GoldDownFromDoBlackMarket += __BlackMarketBuyCrystalNeedMoney;	//��������ˮ�������Ǯ
			Player1Data._CrystalUpFromBlackMarket += __BlackMarkeyBuyCrystalUpCrystal;	//������ˮ����õ�ˮ��
		}
		else if (cmd.sec_type == CMD_Economy_BlackMarket_SellCrystal)
		{
			Player1Data._CrystalDownFromBlackMarket += __BlackMarkeySellCrystalDownCrystal;	//������ˮ�������ˮ��
			Player1Data._GoldUpFromBlackMarket += __BlackMarketSellCrystalUpGold;	//������ˮ�����ý�Ǯ
		}

	}
}

void Backstage::DoCMDMarket(EconomyCMD cmd)	//�г�
{
	if (cmd.PlayerId == 1)
	{
		if (cmd.sec_type == CMD_Economy_Market_BuyCrystal)
		{
			Player1Data._GoldDownFromDoMarket += __MarketBuyCrystalNeedMoney;	//�г�����ˮ�������Ǯ
			Player1Data._CrystalUpFromMarket += __MarkeyBuyCrystalUpCrystal;	//�г���ˮ����õ�ˮ��
		}
		else if (cmd.sec_type == CMD_Economy_Market_SellCrystal)
		{
			Player1Data._CrystalDownFromMarket += __MarkeySellCrystalDownCrystal;	//�г���ˮ�������ˮ��
			Player1Data._GoldUpFromMarket += __MarketSellCrystalUpGold;	//�г���ˮ�����ý�Ǯ
		}

	}
}

//ִ�м���ָ��
void Backstage::DoCMDHelpPeople(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldDownFromDoInterior += __HelpPeopleNeedMoney;
		Player1Data._Loyal += __HelpPeopleUpLoyal;
	}
}

//ִ�з���ָ��
void Backstage::DoCMDPrevention(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{

	}
}

//ִ�д�������ָ��
void Backstage::DoCMDPardon(InteriorCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		Player1Data._GoldDownFromDoInterior += __PardonNeedMoney;
		Player1Data._Loyal += __PardonUpLoyal;

	}
}


//ִ������ָ��
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
		Player1Data._SoldierUpFromConscription += __ConscriptionUpSoldierBase/100*Player1Data._Loyal;//������ΪBase*������/100��;
	}
}

//ִ��ֳ��ָ��
void Backstage::DoCMDColony(ArmyCMD cmd)
{
	if (cmd.PlayerId == 1)
	{
		if (Player1Data.isStandingArmy == true)
		{
			Player1Data._CrystalUpFromStandingArmy += random(0, 100) <= __StandingArmyUpCrystalRata * 100 ? 1 : 0;	//����г��������м��ʻ��ˮ��
		}
		Player1Data._SoldierDownFromColony += __ColonyDownSoldier;
		Player1Data._LoyalDownFromColony += __ColonyDownLoyal;
		Player1Data._CityUpFromColony += __ColonyUpCity;
		
		

	}
}

//ִ��פ��ָ��
void Backstage::DoCMDGarrison(ArmyCMD cmd)
{
	if (cmd.PlayerId == 1)
	{

	}
}


void Backstage::Player1EconomyCMDClear()	//������1��������
{
	Player1EconomyCMD.clear();
}

void Backstage::Player1InteriorCMDClear()	//������1��������
{
	Player1InteriorCMD.clear();

}

void Backstage::Player1ArmyCMDClear()	//������1��������
{
	Player1ArmyCMD.clear();
}

void Backstage::Player1TechnologyCMDClear()	//������1�Ƽ�����
{
	Player1TechnologyCMD.clear();

}

void Backstage::Player1EndRoundCMDClear()	//������1�غϽ�������
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

void Backstage::MineProduceGold()	//	ÿ�غϿ�����
{
	int minenum = ToMapLayer_1->mine_num;
	for (int i = 0; i < minenum; i++)
	{
		Player1Data._MineData[i].GoldNum += __MineProduceGoldEachRound;
	}

}



void Backstage::DoCMDTechnology_Economy(TechnologyCMD cmd)	//��������Ƽ�ָ��
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Economy_TunTian:		//������
			Player1Data.isTunTian = 1;
			Player1Data._GoldDownFromDoTechnology += __TunTianNeedMoney;
			break;
		case CMD_Technology_Economy_Refine:		//��������
			Player1Data.isRefine = 1;
			Player1Data._GoldDownFromDoTechnology += __RefineNeedMoney;
			break;
		case CMD_Technology_Economy_MarketTrade:	//�г�����
			Player1Data.isMarketTrade = 1;
			Player1Data._GoldDownFromDoTechnology += __MarketTradeNeedMoney;
			break;
		case CMD_Technology_Economy_Prospect:		//��̽����
			Player1Data.isProspect = 1;
			Player1Data._GoldDownFromDoTechnology += __ProspectNeedMoney;
			break;
		case CMD_Technology_Economy_TaxLaw:		//˰��
			Player1Data.isTaxLaw = 1;
			Player1Data._GoldDownFromDoTechnology += __TaxLawNeedMoney;
			break;
		case CMD_Technology_Economy_Boom:	//����
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


void Backstage::DoCMDTechnology_Interior(TechnologyCMD cmd)	//����������Ƽ�����
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Interior_CityState:	//������
			Player1Data.isCityState = 1;
			Player1Data._GoldDownFromDoTechnology += __CityStateNeedMoney;
			break;
		case CMD_Technology_Interior_Despotic:		//ר��
			Player1Data.isDespotic = 1;
			Player1Data._GoldDownFromDoTechnology += __DespoticNeedMoney;
			Player1Data._CityUpFromDespotic += __DespoticGetCity;
			break;
		case CMD_Technology_Interior_Democracy:	//������
			Player1Data.isDemocracy = 1;
			Player1Data._GoldDownFromDoTechnology += __DemocracyNeedMoney;
			break;
		case CMD_Technology_Interior_Monarchy:		//�������ơ�
			Player1Data.isMonarchy = 1;
			Player1Data._GoldDownFromDoTechnology += __MonarchyNeedMoney;
			break;
		case CMD_Technology_Interior_Republic:		//�������ơ�
			Player1Data.isRepublic = 1;
			Player1Data._GoldDownFromDoTechnology += __RepublicNeedMoney;
			Player1Data._LoyalUpFromRepublic += __RepublicSetLoyalTo;
			break;
		case CMD_Technology_Interior_Capitalism:	//���ʱ����塱
			Player1Data.isCapitalism = 1;
			Player1Data._GoldDownFromDoTechnology += __CapitalismNeedMoney;
			Player1Data._CrystalDownFromTechnology += __CapitalismUpCrystal;
			break;
		case CMD_Technology_Interior_Socialism:		//��������塱
			Player1Data.isSocialism = 1;
			Player1Data._GoldDownFromDoTechnology += __SocialismNeedMoney;
			break;
		
		}
	}
	else
	{

	}
}

void Backstage::DoCMDTechnology_Army(TechnologyCMD cmd)		//���������Ƽ�����
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Army_Militia:	//�����
			Player1Data.isMilitia = 1;
			Player1Data._GoldDownFromDoTechnology += __MilitiaNeedMoney;
			break;
		case CMD_Technology_Army_Mercenary:		//��Ӷ����
			Player1Data.isMercenary = 1;
			Player1Data._GoldDownFromDoTechnology += __MercenaryNeedMoney;
			break;
		case CMD_Technology_Army_StandingArmy:	//������
			Player1Data.isStandingArmy = 1;
			Player1Data._CrystalDownFromTechnology += __StandingArmyDownCrystal;
			break;
		case CMD_Technology_Army_Fort:		//�����ݡ�
			Player1Data.isFort = 1;
			Player1Data._GoldDownFromDoTechnology += __FortNeedMoney;
			break;
		case CMD_Technology_Army_AllSoldier:		//��ȫ��Ա���
			Player1Data.isAllSoldier = 1;
			Player1Data._CrystalDownFromTechnology += __AllSoldierDownCrystal;
			Player1Data._GoldDownFromDoTechnology += __AllSoldierNeedMoney;
			break;
		case CMD_Technology_Army_Spy:				//�������
			Player1Data.isSpy = 1;
			Player1Data._GoldDownFromDoTechnology += __SpyNeedMoney;
			break;

		}
	}
	else
	{

	}
}


void Backstage::DoCMDTechnology_Technology(TechnologyCMD cmd)		//����Ƽ���Ƽ�����
{
	if (cmd.PlayerId == 1)
	{
		switch (cmd.sec_type)
		{
		case CMD_Technology_Technology_Math:	//��ѧ
			Player1Data.isMath = 1;
			Player1Data._GoldDownFromDoTechnology += __MathNeedMoney;
			break;
		case CMD_Technology_Technology_Physics:		//����ѧ
			Player1Data.isPhysics = 1;
			Player1Data._GoldDownFromDoTechnology += __PhysicsNeedMoney;
			break;
		case CMD_Technology_Technology_Biology:	//����ѧ
			Player1Data.isBiology = 1;
			Player1Data._GoldDownFromDoTechnology += __BiologyNeedMoney;
			break;
		case CMD_Technology_Technology_Electric:		//����ѧ
			Player1Data.isElectric = 1;
			Player1Data._CrystalDownFromTechnology += __ElectricNeedCrystal;
			break;
		case CMD_Technology_Technology_Chemistry:		//��ѧ
			Player1Data.isChemistry = 1;
			Player1Data._GoldDownFromDoTechnology += __ChemistryNeedMoney;
			break;
		case CMD_Technology_Technology_SuperComputer:				//���������
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



void Backstage::BeforeProcessInit()	//ÿ�غϴ�������ǰ�ĳ�ʼ��
{
	BeforeProcessGoldInit();
	BeforeProcessLoyalInit();
	BeforeProcessSoldierInit();
	BeforeProcessCityInit();
	BeforeProcessCrystalInit();

}


void Backstage::BeforeProcessGoldInit()		//��Ǯ�仯��ʼ��
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

void Backstage::BeforeProcessLoyalInit()			//���ұ仯��ʼ��
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


void Backstage::BeforeProcessSoldierInit()			//ʿ�����仯��ʼ��
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


void Backstage::BeforeProcessCityInit()			//�ǳ����仯��ʼ��
{

	Player1Data._CityChanged = 0;

	Player1Data._CityUp = 0;
	Player1Data._CityUpFromColony = 0;
	Player1Data._CityUpFromDespotic = 0;

	Player1Data._CityDown = 0;
	Player1Data._CityDownFromDoInterior = 0;

}

void Backstage::BeforeProcessCrystalInit()			//ˮ�����仯��ʼ��
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
	if (Player1Data.isTunTian == true)	//�ж��Ƿ��С������ơ��Ƽ�
	{
		Player1Data._GoldUpFromTunTian = __TunTianBaseGold + random(0, __TunTianFlowGold);	//����еĻ�������5+��0��5���Ľ�Ǯ
	}
	if (Player1Data.isRefine == true)	//�ж��Ƿ��С������������Ƽ�
	{
		Player1Data._GoldUpFromMine = __RefineUpRataTo * Player1Data._GoldUpFromMine;	//	����У����ӽ�����ý�Ǯ0.5��
	}
	if (Player1Data.isTaxLaw == true)	//�ж��Ƿ��С�˰�����Ƽ�
	{
		if (Player1Data._GoldUpFromTax > 0)		//�жϵ�ǰ�غ��Ƿ�ִ������˰ָ��
		{
			Player1Data._GoldUpFromTax += __TaxProduceGoldEachCity * Player1Data._CityNum;	//����У�ÿ���ǳؼӳ�
		}
	}
	if (Player1Data.isMonarchy == true)	//�ж��Ƿ��С������ơ�
	{
		Player1Data._GoldUpFromTax *= __MonarchyUpMoneyRateFromTax;	//����У�����˰��������
	}
	if (Player1Data.isPyramid == true)	//�ж��Ƿ��С���������
	{
		Player1Data._GoldUpFromPyramid += __PyramidUpGoldEachRound;
	}
	if (Player1Data.isBiology == true)	//�ж��Ƿ�������ѧ
	{
		Player1Data._GoldUpFromBiology += Player1Data._Soldier*__BiologyUpMoneyRateEachRound;	//����У����ʿ����һ���ٷֱȵĽ�Ǯ
	}
	if (Player1Data.isSuperComputer == true)
	{
		Player1Data._GoldDownFromDoTechnology = 0;	//����г���������������Ƽ�������Ҫ��Ǯ
	}

	//�ж��Ƿ��С�˰�����Ƽ��ӳ� ��ԭ������ִ��
	
	Player1Data._GoldUp += Player1Data._GoldUpFromMine +	//�������������ü�����
		Player1Data._GoldUpFromTax +
		Player1Data._GoldUpFromTrade +
		Player1Data._GoldUpFromBlackMarket +
		Player1Data._GoldUpFromMarket +
		Player1Data._GoldUpFromTunTian +
		Player1Data._GoldUpFromBiology +
		Player1Data._GoldUpFromPyramid +
		Player1Data._GoldUpFromTreasure;

	if (Player1Data.isSocialism == true)	//�ж��Ƿ��С��ʱ����塱�Ƽ�
	{
		Player1Data._GoldUp *= __CapitalismUpMoneyRate;	//����У�������Ӧ���ʡ�
	}
	if (Player1Data.isBoom == true)	//�ж��Ƿ���"����"�Ƽ�
	{
		Player1Data._GoldUp = Player1Data._GoldUp + Player1Data._GoldUp;	//����У������������üӱ�
	}

	Player1Data._GoldDown += Player1Data._GoldDownFromDoArmy +
		Player1Data._GoldDownFromDoInterior +
		Player1Data._GoldDownFromDoTechnology +
		Player1Data._GoldDownFromDoTreasure +
		Player1Data._GoldDownFromDoBlackMarket +
		Player1Data._GoldDownFromDoMarket;

	Player1Data._GoldChanged = Player1Data._GoldUp - Player1Data._GoldDown;	//��Ǯ�ı���ڻ������ȥ֧����

	Player1Data._Gold += Player1Data._GoldChanged;	//	���½�Ǯ
	
}

void Backstage::Player1LoyalChangedProcess()
{
	if (Player1Data.isSocialism == true)	//�ж��Ƿ��С�������塱�Ƽ�
	{
		Player1Data._Loyal = 100;	//����У�ֱ�ӽ�������Ϊ100��Ȼ���˳�
		return;
	}
	Player1Data._LoyalDownFromEachRound += __LoyalDownEachRound;	//����ֵÿ�غϼ���ֵ	
	if (Player1Data.isDemocracy == true)
	{
		Player1Data._LoyalDownFromEachRound -= __DemocracyDownLoyalDownEachRound;	//����С������ơ���ÿ�غϼ��������½�ֵ
	}
	if (Player1Data.isMercenary == true)
	{
		Player1Data._LoyalDownFromConscription = 0;			//����С���Ӷ���ơ����������ټ�������ֵ
	}
	if (Player1Data.isColossus == true)
	{
		Player1Data._LoyalDownFromColony = 0;			//����С������񡱣�ֳ���ټ�������ֵ
	}

	Player1Data._LoyalUp = Player1Data._LoyalUpFromHelpPeople +		//�������ӵĲ���
		Player1Data._LoyalUpFromPardon+
		Player1Data._LoyalUpFromRepublic;

	Player1Data._LoyalDown = Player1Data._LoyalDownFromColony +		//���Ҽ��ٵĲ���
		Player1Data._LoyalDownFromConscription +
		Player1Data._LoyalDownFromEachRound+
		Player1Data._LoyalDownFromTax;

	Player1Data._LoyalChanged = Player1Data._LoyalUp - Player1Data._LoyalDown;	//���Ҹı�ֵ

	Player1Data._Loyal += Player1Data._LoyalChanged;

	if (Player1Data._Loyal > 100)	//����ֵ���Ϊ100
	{
		Player1Data._Loyal = 100;
	}
}

void Backstage::Player1SoldierChangedProcess()
{

	if (Player1Data.isMonarchy == true)
	{
		Player1Data._SoldierUpFromConscription *= __MonarchyUpConscriptionRate;	//����С������ơ�������ʱ����������
	}
	if (Player1Data.isMilitia == true)
	{
		Player1Data._SoldierUpFromMilitiaEachRound = __MilitiaUpSoldierEachRound;	//����С�����ۡ���ÿ�غϻ��һ��ʿ����
	}
	if (Player1Data.isAllSoldier == true)
	{
		Player1Data._SoldierUpFromConscription += __AllSoldierUpSoldierEachCity*Player1Data._CityNum;	//����С�ȫ��Ա�����ÿ���ǳض��������мӳ�
	}
	if (Player1Data.isColossus == true)
	{
		Player1Data._SoldierUpFromColossusEachRound += Player1Data._Soldier*__ColossusUpSoldierRateEachRound;	//����о�����ÿ�غϻ���ϻغ�ʿ����һ���ٷֱȵ�ʿ��
	}
	Player1Data._SoldierUp = Player1Data._SoldierUpFromConscription				//ʿ�������ӵĲ���
							+Player1Data._SoldierUpFromMilitiaEachRound
							+ Player1Data._SoldierUpFromColossusEachRound;

	if (Player1Data.isHangingGarden == true)
	{
		Player1Data._SoldierDownFromTreasure = 0;			//����п��л�԰��Ѱ��������Ҫʿ��
	}

	Player1Data._SoldierDown = Player1Data._SoldierDownFromColony				//ʿ�������ٵĲ���
							 + Player1Data._SoldierDownFromTreasure;		
		

	Player1Data._SoldierChanged = Player1Data._SoldierUp - Player1Data._SoldierDown;	//ʿ�����ı�ֵ

	Player1Data._Soldier += Player1Data._SoldierChanged;

}


void Backstage::Player1CityChangedProcess()
{
	Player1Data._CityUp = Player1Data._CityUpFromColony	//�ǳ������Ӳ���
						+ Player1Data._CityUpFromDespotic;		
		
	Player1Data._CityDown = Player1Data._CityDownFromDoInterior;			//�ǳ������ٲ���

	Player1Data._CityChanged = Player1Data._CityUp - Player1Data._CityDown;	//�ǳ����仯����

	Player1Data._CityNum += Player1Data._CityChanged;

}


void Backstage::Player1CrystalChangedProcess()		
{
	if (Player1Data.isChemistry == true)
	{
		Player1Data._CrystalUpFromChemistryEachRound += random(0, 100) < 100 * __ChemistryUpCrystalRateEachRound ? 1 : 0;	//����л�ѧ��ÿ�غ���һ����������ˮ��1
	}
	if (Player1Data.isHangingGarden == true)
	{
		Player1Data._CrystalDownFromTechnology = 0;				//����п��л�԰�������Ƽ�������Ҫˮ��
	}
	Player1Data._CrystalUp = Player1Data._CrystalUpFromTreasue				//ˮ�������Ӳ���
						   + Player1Data._CrystalUpFromBlackMarket
						   + Player1Data._CrystalUpFromMarket
						   + Player1Data._CrystalUpFromPhysics
						   + Player1Data._CrystalUpFromChemistryEachRound
						   + Player1Data._CrystalUpFromStandingArmy
						   + Player1Data._CrystalUpFromTerracotta;

	Player1Data._CrystalDown = Player1Data._CrystalDownFromTechnology					//ˮ�������ٲ���
							 + Player1Data._CrystalDownFromInterior
							 + Player1Data._CrystalDownFromBlackMarket
							 + Player1Data._CrystalDownFromMarket;

	Player1Data._CrystalChanged = Player1Data._CrystalUp - Player1Data._CrystalDown;	//ˮ�����仯����

	Player1Data._Crystal += Player1Data._CrystalChanged;

}



bool Backstage::CheckPlayer1isWin()	//�ж����1�Ƿ���ʤ������
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

bool Backstage::CheckPlayer1isWinOfEconomy()	//�ж����1�ľ��û�ʤ����
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

bool Backstage::CheckPlayer1isWinOfInterior()	//�ж����1��������ʤ����
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

bool Backstage::CheckPlayer1isWinOfArmy()	//�ж����1�ľ��»�ʤ����
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

bool Backstage::CheckPlayer1isWinOfTechnology()	//�ж����1�ĿƼ���ʤ����
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