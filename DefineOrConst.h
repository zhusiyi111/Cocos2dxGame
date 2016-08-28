#pragma once


const int __WinOfEconomyNeedGold = 10000;	//���û�ʤ��Ҫ�Ľ�Ǯ

const int __WinOfInteriorNeedMiracleNum = 2;	//������ʤ������漣������

const int __WinOfArmyNeedCity = 15;			//����ʤ����Ҫ�ĳǳ���

const int __WinOfTechnologyNeedTecNum = 2;	//�Ƽ�ʤ����Ҫ�Ķ��˿Ƽ���Ŀ


const int __FirstRoundGold = 300;			//��һ�غϽ�Ǯ
const int __FirstRoundLoyal = 60;			//��һ�غ�����
const int __FirstRoundSoldier = 100;		//��һ�غ�ʿ��
const int __FirstRoundCity = 1;				//��һ�غϳǳ�
const int __FirstRoundCrystal = 0;		//��һ�غ�ˮ��



const int __MineProduceGoldEachRound = 25;	//���ÿ�غϲ���
const int __GetMineEachTime = 3;   //ÿ���ռ����ļ���֮һ��

const int __LoyalDownEachRound = 4; //ÿ�غ������½�ֵ

const int __TaxUpGoldBase = 100;	//����˰�����ӵĻ�����Ǯ
const int __TaxDownLoyal = 15;		//����˰����������ֵ

const int __TreasureNeedMoney = 100;	//Ѱ����Ҫ�Ľ�Ǯ
const int __TreasureDownSoldier = 100;	//Ѱ����Ҫ��ʿ��
const int __TresureUpMaxMoney = __TreasureNeedMoney;	//Ѱ���õ�������Ǯ
const float __TresureUpCrystalRate = 0.2;	//Ѱ�����ˮ���ĸ���

const int __MarketBuyCrystalNeedMoney = 500;		//�г�����ˮ�������Ǯ
const int __MarkeyBuyCrystalUpCrystal = 1;			//�г�����ˮ������ˮ��
const int __MarkeySellCrystalDownCrystal = 1;		//�г�����ˮ������ˮ��
const int __MarketSellCrystalUpGold = 300;			//�г�����ˮ�����ý�Ǯ

const int __BlackMarketBuyCrystalNeedMoney = 1000;		//��������ˮ�������Ǯ
const int __BlackMarkeyBuyCrystalUpCrystal = 1;			//��������ˮ������ˮ��
const int __BlackMarkeySellCrystalDownCrystal = 1;		//��������ˮ������ˮ��
const int __BlackMarketSellCrystalUpGold = 100;			//��������ˮ�����ý�Ǯ

const int __HelpPeopleNeedMoney = 30;	//�������������Ǯ
const int __HelpPeopleUpLoyal = 10; //��������������ֵ

const int __PardonNeedMoney = 150;	//���������¡������Ǯ
const int __PardonUpLoyal = 30;		//���������¡���������ֵ

const int __ConscriptionNeedMoney = 100;	//�������������Ǯ
const int __ConscriptionDownLoyal = 5;		//����������������
const int __ConscriptionUpSoldierBase = 200;//�����������ӵĻ���ʿ����

const int __ColonyDownSoldier = 100;		//��ֳ������ʿ��
const int __ColonyDownLoyal = 10;			//��ֳ����������
const int __ColonyUpCity = 1;				//��ֳ�����ӳǳ���


const int __TunTianNeedMoney = 100;	//�������ơ������Ǯ
const int __TunTianBaseGold = 5;	//�������ơ�ÿ�غϻ�õĻ�����Ǯ
const int __TunTianFlowGold = 5;    //�������ơ�ÿ�غϻ�õĸ�����Ǯ���Ϊ

const int __RefineNeedMoney = 150;	//�����������������Ǯ
const float __RefineUpRataTo = 1.5;	//���������������ɿ��ü������ٱ�

const int __MarketTradeNeedMoney = 150;	//���г����ס������Ǯ

const int __ProspectNeedMoney = 150;	//����̽�����������Ǯ
const float __ProspectUpCrystalFromTreasureRate = 0.5;	//����̽�����������ڵ�ˮ���ĸ�����

const int __TaxLawNeedMoney = 200;	//��˰���������Ǯ
const int __TaxProduceGoldEachCity = 50;	//��˰�����Ƽ�ÿ���ǳ����ӵĶ����Ǯ

const int __BoomNeedMoney = 250;	//�����١������Ǯ
const int __BoomDownCrystal = 2;	//�����١�����ˮ��


const int __CityStateNeedMoney = 100;	//���ǰ��ơ������Ǯ

const int __DespoticNeedMoney = 150;	//��ר�ơ������Ǯ
const int __DespoticGetCity = 1;		//��ר�ơ�����õĳǳ���

const int __DemocracyNeedMoney = 150;	//�������ơ������Ǯ
const int __DemocracyDownLoyalDownEachRound = 2;	//�������ơ�ÿ�غϼ��ٵ������½�ֵ

const int __MonarchyNeedMoney = 200;	//�������ơ������Ǯ
const float __MonarchyUpConscriptionRate = 1.5;	//�������ơ�����������
const float __MonarchyUpMoneyRateFromTax = 1.5;	//�������ơ�����˰��������

const int __RepublicNeedMoney = 200;	//�������ơ������Ǯ
const int __RepublicSetLoyalTo = 100;	//�������ơ�����������Ϊ

const int __CapitalismNeedMoney = 100;	//���ʱ����塱�����Ǯ
const int __CapitalismUpCrystal = 2;	//�ʱ���������ˮ��
const int __CapitalismUpMoneyRate = 1.5;	//���ʱ����塱���ӽ�Ǯ������

const int __SocialismNeedMoney = 250;	//��������塱�����Ǯ


const int __MilitiaNeedMoney = 100;		//����������Ǯ
const int __MilitiaUpSoldierEachRound = 10;		//�����ÿ�غϻ��ʿ����

const int __MercenaryNeedMoney = 150;	//��Ӷ���������Ǯ

const int __StandingArmyNeedSoldier = 500;	//����������ʿ����������������ʿ����������Ҫ�����ֵ��
const int __StandingArmyDownCrystal = 1;	//����������ˮ��
const float __StandingArmyUpCrystalRata = 0.2;	//������ ִ��ֳ������ʱ���ˮ���ļ���

const int __FortNeedMoney = 200;		//���������Ǯ

const int __AllSoldierNeedMoney = 250;	//ȫ��Ա������Ǯ
const int __AllSoldierDownCrystal = 1;	//ȫ��Ա�����ˮ��
const int __AllSoldierUpSoldierEachCity = 30;	//ȫ��Ա�ÿ���ǳض������ļӳ�ֵ

const int __SpyNeedMoney = 250;		//��������Ǯ


const int __MathNeedMoney = 100;	//��ѧ�����Ǯ

const int __PhysicsNeedMoney = 150;	//����ѧ�����Ǯ
const float __PhysicsUpCrystal = 0.3;	//����ѧ�����Ƽ�ʱ���ˮ������

const int __BiologyNeedMoney = 150;	//����ѧ�����Ǯ
const float __BiologyUpMoneyRateEachRound = 0.1;	//����ѧÿ�غϻ��ʿ����һ���ٷֱȵĽ�Ǯ

const int __ElectricNeedCrystal = 1;	//����ѧ����ˮ��

const int __ChemistryNeedMoney = 200;	//��ѧ�����Ǯ
const float __ChemistryUpCrystalRateEachRound = 0.5;	//��ѧÿ�غ����ӵ�ˮ����

const int __SuperComputerNeedMoney = 250;	//��������������Ǯ
const int __SuperComputerNeedCrystal = 1;	//�������������ˮ��





const int __PyramidNeedMoney = 1000;	//�����������Ǯ
const int __PyramidNeedCity = 2;		//����������ǳ���
const int __PyramidUpGoldEachRound = 100;	//������ÿ�غ����ӽ�Ǯ

const int __ColossusNeedMoney = 300;		//�����������Ǯ
const int __ColossusNeedCity = 5;			//����������ǳ���
const float __ColossusUpSoldierRateEachRound = 0.1;	//������ÿ�غ�����ʿ�����ı���

const int __TerracottaNeedMoney = 500;	//����ٸ�����Ǯ
const int __TerracottaDownCity = 3;		//����ٸ����ǳ���
const float __TerracottaUpCrystalRate = 0.2;	//����ٸ������ʱ�ṩ�Ļ��ˮ������
const int __TerracottaUpSoldierRata = 2;	//����ٸ���������ı���

const int __HangingGardenDownCity = 2;		//���л�԰����ǳ�
const int __HangingGardenDownCrystal = 7;	//���л�԰����ˮ��






enum
{
	CMD_Economy_Mine = 1,	//�ɿ�
	CMD_Economy_Tax = 2,	//��˰
	CMD_Economy_Trade = 3,	//ó��
	CMD_Economy_Treasure = 4,	//Ѱ��
	CMD_Economy_Market = 5,		//�г�
	CMD_Economy_BlackMarket = 6	//����
};

enum
{
	CMD_Interior_HelpPeople = 1,	//����
	CMD_Interior_Prevention = 2,	//����
	CMD_Interior_Pardon = 3,		//��������
	CMD_Interior_BuildMiracle = 4	//�����漣
};

enum
{
	CMD_Interior_BuildMiracle_Pyramid = 1,	//������
	CMD_Interior_BuildMiracle_Colossus = 2,	//������
	CMD_Interior_BuildMiracle_Terracotta = 3,//����ٸ
	CMD_Interior_BuildMiracle_HangingGarden = 4	//���л�԰
};

enum
{
	CMD_Technology_Economy = 1,	//������
	CMD_Technology_Interior = 2,	//������
	CMD_Technology_Army = 3,		//������
	CMD_Technology_Technology = 4  //�Ƽ���
};

enum
{
	CMD_Technology_Economy_TunTian = 1,	//����
	CMD_Technology_Economy_Refine = 2,	//��������
	CMD_Technology_Economy_MarketTrade = 3,	//�г�����
	CMD_Technology_Economy_Prospect = 4,	//��̽����
	CMD_Technology_Economy_TaxLaw = 5,		//˰��
	CMD_Technology_Economy_Boom = 6  //����
};

enum
{
	CMD_Army_Conscription = 1,	//����
	CMD_Army_Colony = 2,	//ֳ��
	CMD_Army_Garrison = 3		//ռ��
};

enum
{
	CMD_Technology_Interior_CityState = 1,	//�ǰ���
	CMD_Technology_Interior_Despotic = 2,	//ר��
	CMD_Technology_Interior_Democracy = 3,	//������
	CMD_Technology_Interior_Monarchy = 4,	//������
	CMD_Technology_Interior_Republic = 5,	//������
	CMD_Technology_Interior_Capitalism = 6,//�ʱ�����
	CMD_Technology_Interior_Socialism = 7	//�������

};


enum
{
	CMD_Technology_Army_Militia = 1,		//�����
	CMD_Technology_Army_Mercenary = 2,		//��Ӷ����
	CMD_Technology_Army_StandingArmy = 3,	//������
	CMD_Technology_Army_Fort = 4,			//����
	CMD_Technology_Army_AllSoldier = 5,		//ȫ��Ա�
	CMD_Technology_Army_Spy = 6				//���
};


enum
{
	CMD_Technology_Technology_Math = 1,			//��ѧ
	CMD_Technology_Technology_Physics = 2,		//����ѧ	
	CMD_Technology_Technology_Biology = 3,		//����ѧ
	CMD_Technology_Technology_Electric = 4,		//����ѧ
	CMD_Technology_Technology_Chemistry = 5,	//��ѧ
	CMD_Technology_Technology_SuperComputer = 6	//���������

};

enum
{
	CMD_Economy_BlackMarket_BuyCrystal = 1,		//��������ˮ��
	CMD_Economy_BlackMarket_SellCrystal = 2		//��������ˮ��
};

enum
{
	CMD_Economy_Market_BuyCrystal = 1,		//�г�����ˮ��
	CMD_Economy_Market_SellCrystal = 2		//�г�����ˮ��
};