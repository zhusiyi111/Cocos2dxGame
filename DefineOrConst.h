#pragma once


const int __WinOfEconomyNeedGold = 10000;	//经济获胜需要的金钱

const int __WinOfInteriorNeedMiracleNum = 2;	//内政获胜所需的奇迹建筑数

const int __WinOfArmyNeedCity = 15;			//军事胜利需要的城池数

const int __WinOfTechnologyNeedTecNum = 2;	//科技胜利需要的顶端科技数目


const int __FirstRoundGold = 300;			//第一回合金钱
const int __FirstRoundLoyal = 60;			//第一回合民忠
const int __FirstRoundSoldier = 100;		//第一回合士兵
const int __FirstRoundCity = 1;				//第一回合城池
const int __FirstRoundCrystal = 0;		//第一回合水晶



const int __MineProduceGoldEachRound = 25;	//金矿每回合产金
const int __GetMineEachTime = 3;   //每次收集矿点的几分之一金

const int __LoyalDownEachRound = 4; //每回合民忠下降值

const int __TaxUpGoldBase = 100;	//“收税”增加的基础金钱
const int __TaxDownLoyal = 15;		//“收税”减少民忠值

const int __TreasureNeedMoney = 100;	//寻宝需要的金钱
const int __TreasureDownSoldier = 100;	//寻宝需要的士兵
const int __TresureUpMaxMoney = __TreasureNeedMoney;	//寻宝得到的最多金钱
const float __TresureUpCrystalRate = 0.2;	//寻宝获得水晶的概率

const int __MarketBuyCrystalNeedMoney = 500;		//市场买入水晶所需金钱
const int __MarkeyBuyCrystalUpCrystal = 1;			//市场买入水晶所得水晶
const int __MarkeySellCrystalDownCrystal = 1;		//市场卖出水晶所需水晶
const int __MarketSellCrystalUpGold = 300;			//市场卖出水晶所得金钱

const int __BlackMarketBuyCrystalNeedMoney = 1000;		//黑市买入水晶所需金钱
const int __BlackMarkeyBuyCrystalUpCrystal = 1;			//黑市买入水晶所得水晶
const int __BlackMarkeySellCrystalDownCrystal = 1;		//黑市卖出水晶所需水晶
const int __BlackMarketSellCrystalUpGold = 100;			//黑市卖出水晶所得金钱

const int __HelpPeopleNeedMoney = 30;	//“济世”所需金钱
const int __HelpPeopleUpLoyal = 10; //“济世”加民忠值

const int __PardonNeedMoney = 150;	//“大赦天下”所需金钱
const int __PardonUpLoyal = 30;		//“大赦天下”增加民忠值

const int __ConscriptionNeedMoney = 100;	//“征兵”所需金钱
const int __ConscriptionDownLoyal = 5;		//“征兵”所需民忠
const int __ConscriptionUpSoldierBase = 200;//“征兵”增加的基础士兵数

const int __ColonyDownSoldier = 100;		//“殖民”所需士兵
const int __ColonyDownLoyal = 10;			//“殖民”所需民忠
const int __ColonyUpCity = 1;				//“殖民”增加城池数


const int __TunTianNeedMoney = 100;	//“屯田制”所需金钱
const int __TunTianBaseGold = 5;	//“屯田制”每回合获得的基础金钱
const int __TunTianFlowGold = 5;    //“屯田制”每回合获得的浮动金钱最多为

const int __RefineNeedMoney = 150;	//“精炼技术”所需金钱
const float __RefineUpRataTo = 1.5;	//“精炼技术”将采矿获得加至多少倍

const int __MarketTradeNeedMoney = 150;	//“市场交易”所需金钱

const int __ProspectNeedMoney = 150;	//“勘探技术”所需金钱
const float __ProspectUpCrystalFromTreasureRate = 0.5;	//“勘探技术”提升挖到水晶的概率至

const int __TaxLawNeedMoney = 200;	//“税法”所需金钱
const int __TaxProduceGoldEachCity = 50;	//“税法”科技每个城池增加的额外金钱

const int __BoomNeedMoney = 250;	//“繁荣”所需金钱
const int __BoomDownCrystal = 2;	//“繁荣”所需水晶


const int __CityStateNeedMoney = 100;	//“城邦制”所需金钱

const int __DespoticNeedMoney = 150;	//“专制”所需金钱
const int __DespoticGetCity = 1;		//“专制”所获得的城池数

const int __DemocracyNeedMoney = 150;	//“民主制”所需金钱
const int __DemocracyDownLoyalDownEachRound = 2;	//“民主制”每回合减少的民忠下降值

const int __MonarchyNeedMoney = 200;	//“君主制”所需金钱
const float __MonarchyUpConscriptionRate = 1.5;	//“君主制”提升征兵率
const float __MonarchyUpMoneyRateFromTax = 1.5;	//“君主制”提升税收所得率

const int __RepublicNeedMoney = 200;	//“共和制”所需金钱
const int __RepublicSetLoyalTo = 100;	//“共和制”将民忠重置为

const int __CapitalismNeedMoney = 100;	//“资本主义”所需金钱
const int __CapitalismUpCrystal = 2;	//资本主义所需水晶
const int __CapitalismUpMoneyRate = 1.5;	//“资本主义”增加金钱倍率至

const int __SocialismNeedMoney = 250;	//“社会主义”所需金钱


const int __MilitiaNeedMoney = 100;		//民兵役所需金钱
const int __MilitiaUpSoldierEachRound = 10;		//民兵役每回合获得士兵数

const int __MercenaryNeedMoney = 150;	//雇佣兵制所需金钱

const int __StandingArmyNeedSoldier = 500;	//常备军所需士兵数（升级不减少士兵数，但是要有这个值）
const int __StandingArmyDownCrystal = 1;	//常备军所需水晶
const float __StandingArmyUpCrystalRata = 0.2;	//常备军 执行殖民命令时获得水晶的几率

const int __FortNeedMoney = 200;		//堡垒所需金钱

const int __AllSoldierNeedMoney = 250;	//全民皆兵所需金钱
const int __AllSoldierDownCrystal = 1;	//全民皆兵所需水晶
const int __AllSoldierUpSoldierEachCity = 30;	//全民皆兵每个城池对征兵的加成值

const int __SpyNeedMoney = 250;		//间谍所需金钱


const int __MathNeedMoney = 100;	//数学所需金钱

const int __PhysicsNeedMoney = 150;	//物理学所需金钱
const float __PhysicsUpCrystal = 0.3;	//物理学升级科技时获得水晶几率

const int __BiologyNeedMoney = 150;	//生物学所需金钱
const float __BiologyUpMoneyRateEachRound = 0.1;	//生物学每回合获得士兵数一定百分比的金钱

const int __ElectricNeedCrystal = 1;	//电子学所需水晶

const int __ChemistryNeedMoney = 200;	//化学所需金钱
const float __ChemistryUpCrystalRateEachRound = 0.5;	//化学每回合增加的水晶数

const int __SuperComputerNeedMoney = 250;	//超级计算机所需金钱
const int __SuperComputerNeedCrystal = 1;	//超级计算机所需水晶





const int __PyramidNeedMoney = 1000;	//金字塔所需金钱
const int __PyramidNeedCity = 2;		//金字塔所需城池数
const int __PyramidUpGoldEachRound = 100;	//金字塔每回合增加金钱

const int __ColossusNeedMoney = 300;		//巨人像所需金钱
const int __ColossusNeedCity = 5;			//巨人像所需城池数
const float __ColossusUpSoldierRateEachRound = 0.1;	//巨人像每回合提升士兵数的倍率

const int __TerracottaNeedMoney = 500;	//兵马俑所需金钱
const int __TerracottaDownCity = 3;		//兵马俑所需城池数
const float __TerracottaUpCrystalRate = 0.2;	//兵马俑在征兵时提供的获得水晶几率
const int __TerracottaUpSoldierRata = 2;	//兵马俑提升征兵的倍率

const int __HangingGardenDownCity = 2;		//空中花园所需城池
const int __HangingGardenDownCrystal = 7;	//空中花园所需水晶






enum
{
	CMD_Economy_Mine = 1,	//采矿
	CMD_Economy_Tax = 2,	//收税
	CMD_Economy_Trade = 3,	//贸易
	CMD_Economy_Treasure = 4,	//寻宝
	CMD_Economy_Market = 5,		//市场
	CMD_Economy_BlackMarket = 6	//黑市
};

enum
{
	CMD_Interior_HelpPeople = 1,	//济世
	CMD_Interior_Prevention = 2,	//防灾
	CMD_Interior_Pardon = 3,		//大赦天下
	CMD_Interior_BuildMiracle = 4	//建造奇迹
};

enum
{
	CMD_Interior_BuildMiracle_Pyramid = 1,	//金字塔
	CMD_Interior_BuildMiracle_Colossus = 2,	//巨人像
	CMD_Interior_BuildMiracle_Terracotta = 3,//兵马俑
	CMD_Interior_BuildMiracle_HangingGarden = 4	//空中花园
};

enum
{
	CMD_Technology_Economy = 1,	//经济类
	CMD_Technology_Interior = 2,	//防灾类
	CMD_Technology_Army = 3,		//军事类
	CMD_Technology_Technology = 4  //科技类
};

enum
{
	CMD_Technology_Economy_TunTian = 1,	//屯田
	CMD_Technology_Economy_Refine = 2,	//精炼技术
	CMD_Technology_Economy_MarketTrade = 3,	//市场交易
	CMD_Technology_Economy_Prospect = 4,	//勘探技术
	CMD_Technology_Economy_TaxLaw = 5,		//税法
	CMD_Technology_Economy_Boom = 6  //繁荣
};

enum
{
	CMD_Army_Conscription = 1,	//征兵
	CMD_Army_Colony = 2,	//殖民
	CMD_Army_Garrison = 3		//占领
};

enum
{
	CMD_Technology_Interior_CityState = 1,	//城邦制
	CMD_Technology_Interior_Despotic = 2,	//专制
	CMD_Technology_Interior_Democracy = 3,	//民主制
	CMD_Technology_Interior_Monarchy = 4,	//君主制
	CMD_Technology_Interior_Republic = 5,	//共和制
	CMD_Technology_Interior_Capitalism = 6,//资本主义
	CMD_Technology_Interior_Socialism = 7	//社会主义

};


enum
{
	CMD_Technology_Army_Militia = 1,		//民兵役
	CMD_Technology_Army_Mercenary = 2,		//雇佣兵制
	CMD_Technology_Army_StandingArmy = 3,	//常备军
	CMD_Technology_Army_Fort = 4,			//堡垒
	CMD_Technology_Army_AllSoldier = 5,		//全民皆兵
	CMD_Technology_Army_Spy = 6				//间谍
};


enum
{
	CMD_Technology_Technology_Math = 1,			//数学
	CMD_Technology_Technology_Physics = 2,		//物理学	
	CMD_Technology_Technology_Biology = 3,		//生物学
	CMD_Technology_Technology_Electric = 4,		//电子学
	CMD_Technology_Technology_Chemistry = 5,	//化学
	CMD_Technology_Technology_SuperComputer = 6	//超级计算机

};

enum
{
	CMD_Economy_BlackMarket_BuyCrystal = 1,		//黑市买入水晶
	CMD_Economy_BlackMarket_SellCrystal = 2		//黑市卖出水晶
};

enum
{
	CMD_Economy_Market_BuyCrystal = 1,		//市场买入水晶
	CMD_Economy_Market_SellCrystal = 2		//市场卖出水晶
};