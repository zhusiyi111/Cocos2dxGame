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

void DataLayer::FirstRoundInit()		//��һ�غ�֮ǰ�ĳ�ʼ��
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

//ִ�о�����������ִ�з���0�����򷵻ش������
int DataLayer::DoCMD(EconomyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//ʲô�¶�û��
		return 1;
		break;
	case 1:			//�ɿ�
		if (EconomyCMDFlag == true )
		{
			return 2;		//�Ѿ�ִ�й�������������ش������2
		}
		else if (cmd.sec_type == 0)	//δָ�����
		{
			return 1;
		}
		else
		{
			MineCMDFlag = 1;	//�Ƿ�ִ�вɿ�ָ���־λ
			EconomyCMDFlag = true;
			return 0;
		}
		break;
	case 2:			//��˰
		if (EconomyCMDFlag == true)
		{
			return 2;		//�Ѿ�ִ�й�������������ش������2
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
	case CMD_Economy_Treasure:			//Ѱ��
		if (EconomyCMDFlag == true)
		{
			return 2;		//�Ѿ�ִ�й�������������ش������2
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
	case CMD_Economy_Market:	//�г�
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
			break;
		case CMD_Economy_Market_BuyCrystal:	//�г�����ˮ��
			if (EconomyCMDFlag == true)
			{
				return 2;		//�Ѿ�ִ�й�������������ش������2
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
		case CMD_Economy_Market_SellCrystal:	//�г�����ˮ��
			if (EconomyCMDFlag == true)
			{
				return 2;		//�Ѿ�ִ�й�������������ش������2
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
	case CMD_Economy_BlackMarket:	//����
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
			break;
		case CMD_Economy_BlackMarket_BuyCrystal:	//��������ˮ��
			if (EconomyCMDFlag == true)
			{
				return 2;		//�Ѿ�ִ�й�������������ش������2
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
		case CMD_Economy_BlackMarket_SellCrystal:	//��������ˮ��
			if (EconomyCMDFlag == true)
			{
				return 2;		//�Ѿ�ִ�й�������������ش������2
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

//ִ��������������ִ�з���0�����򷵻ش������
int DataLayer::DoCMD(InteriorCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//ʲô�¶�û��
		return 1;
		break;
	case CMD_Interior_HelpPeople:			//����
		if (InteriorCMDFlag == true)	
		{
			return 2;			//�Ѿ�ִ�й�����������ش������2
		}
		else if (data._Gold < __HelpPeopleNeedMoney)
		{
			return 1;
		}
		else
		{
			HelpPeopleCMDFlag = 1;	//�Ƿ�ִ�м���ָ���־λ
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_Prevention:     //����
		return 999;			//��ʱ�ر�
		if (InteriorCMDFlag == true)
		{
			return 2;
		}
		else
		{
			PreventionCMDFlag = 1;	//�Ƿ�ִ�з���ָ���־λ
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_Pardon:		//��������
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
			PardonCMDFlag = 1;	//�Ƿ�ִ�д�������ָ���־λ
			InteriorCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Interior_BuildMiracle:
		switch (cmd.sec_type)
		{
		case 0:
			return 1;
		case CMD_Interior_BuildMiracle_Pyramid:		//������
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
		case CMD_Interior_BuildMiracle_Colossus:	//������
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
		case CMD_Interior_BuildMiracle_Terracotta:	//����ٸ
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
		case CMD_Interior_BuildMiracle_HangingGarden:	//���л�԰
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


//ִ�о�����������ִ�з���0�����򷵻ش������
int DataLayer::DoCMD(ArmyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//ʲô�¶�û��
		return 1;
		break;
	case CMD_Army_Conscription:			//����
		if (ArmyCMDFlag == true)
		{
			return 2;			//�Ѿ�ִ�й�����������ش������2
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

	case CMD_Army_Colony:     //ֳ��
		if (ArmyCMDFlag == true)
		{
			return 2;			//�Ѿ�ִ�й�����������ش������2
		}
		else if (data._Soldier < __ColonyDownSoldier || data._Loyal<__ColonyDownLoyal || data.isCityState==0 /*��Ҫ���ǰ��ơ��Ƽ�*/)
		{
			return 1;
		}
		else
		{
			ArmyCMDFlag = true;
			return 0;
		}
		break;

	case CMD_Army_Garrison:		//פ��
		return 999;
		break;
	default:
		return 1;
	}
}

//ִ�пƼ���������ִ�з���0�����򷵻ش������
int DataLayer::DoCMD(TechnologyCMD cmd)
{
	switch (cmd.type)
	{
	case 0:			//ʲô�¶�û��
		return 1;
		break;
	case 1:			//������Ƽ�
		switch (cmd.sec_type)
		{
		case CMD_Technology_Economy_TunTian:		//������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isTunTian == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Economy_Refine:			//��������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isRefine == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Economy_MarketTrade:			//�г�����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isMarketTrade == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Economy_Prospect:			//��̽����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isProspect == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Economy_TaxLaw:		//˰��
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
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
		case CMD_Technology_Economy_Boom:		//����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isBoom == true )
			{
				return 3;
			}
			else if (data._Gold < __BoomNeedMoney || (data.isTaxLaw==false && data.isProspect==false)  /*��û�п�̽����Ҳû��˰��*/ || data._Crystal < __BoomDownCrystal)
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
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isCityState == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Interior_Despotic:	//ר��
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isDespotic == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
			}
			else if (data._Gold < __DespoticNeedMoney || data.isCityState==false || data.isMath == false || data.isDemocracy == true /*����Ѿ��������ƣ��Ͳ�������ר��*/)
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Democracy:	//������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isDemocracy == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
			}
			else if (data._Gold < __DemocracyNeedMoney || data.isCityState==false || data.isMath == false ||data.isDespotic == true /*�������ר�ƣ��Ͳ���������������*/ )
			{
				return 1;
			}
			else
			{
				TechnologyCMDFlag = true;
				return 0;
			}
			break;
		case CMD_Technology_Interior_Monarchy:	//������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isMonarchy == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Interior_Republic:	//������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isRepublic == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Interior_Capitalism:	//�ʱ�����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isCapitalism == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Interior_Socialism:	//�������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isSocialism == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_Militia:		//�����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isMilitia == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_Mercenary:		//��Ӷ����
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isMercenary == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_StandingArmy:		//������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isStandingArmy == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_Fort:			//����
			return 999;		//��ʱ����������ʵ�ֺ�ɾȥ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isFort == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_AllSoldier:				//ȫ��Ա�
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isAllSoldier == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Army_Spy:					//���
			return 999;				//��ʱ����������ʵ�ֺ�ɾȥ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isSpy == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
	case CMD_Technology_Technology:		//�Ƽ���Ƽ�
		switch (cmd.sec_type)
		{
		case CMD_Technology_Technology_Math:		//��ѧ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isMath == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Technology_Physics:		//����ѧ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isPhysics == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Technology_Biology:		//����ѧ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isBiology == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Technology_Electric:		//����ѧ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isElectric == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Technology_Chemistry:		//��ѧ
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isChemistry == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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
		case CMD_Technology_Technology_SuperComputer:		//���������
			if (TechnologyCMDFlag == true)
			{
				return 2;		//��ִ�й��Ƽ�����
			}
			else if (data.isSuperComputer == true)
			{
				return 3;		//3Ϊ���и���Ƽ��Ĵ������
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