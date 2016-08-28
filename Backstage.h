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
	

	void ProcessStart(); //��ʼ����˫������

	void ProcessEconomyCMD(EconomyCMD cmd);	
	void ProcessEndRoundCMD(EndRoundCMD cmd);
	void ProcessInteriorCMD(InteriorCMD cmd);
	void ProcessArmyCMD(ArmyCMD cmd);
	void ProcessTechnologyCMD(TechnologyCMD cmd);

	//���
	void Player1EconomyCMDClear();	
	void Player1EndRoundCMDClear();
	void Player1InteriorCMDClear();
	void Player1ArmyCMDClear();
	void Player1TechnologyCMDClear();
	

	void NextRound();	//��һ�غϿ�ʼ
	void ClaerAllPlayer1CMD(); //������1����������


	void DoCMDMine(EconomyCMD cmd);	//�ɿ�
	void DoCMDTax(EconomyCMD cmd);	//��˰
	void DoCMDTreasure(EconomyCMD cmd);	//Ѱ��
	void DoCMDBlackMarket(EconomyCMD cmd);	//����
	void DoCMDMarket(EconomyCMD cmd);	//�г�

	void DoCMDHelpPeople(InteriorCMD cmd);	//����
	void DoCMDPrevention(InteriorCMD cmd);	//����
	void DoCMDPardon(InteriorCMD cmd);		//��������

	void DoCMDConscription(ArmyCMD cmd);	//����
	void DoCMDColony(ArmyCMD cmd);			//ֳ��
	void DoCMDGarrison(ArmyCMD cmd);		//פ��

	void DoCMDTechnology_Economy(TechnologyCMD cmd);	//ִ�о�����Ƽ�����
	void DoCMDTechnology_Interior(TechnologyCMD cmd);	//ִ��������Ƽ�����
	void DoCMDTechnology_Army(TechnologyCMD cmd);		//ִ�о�����Ƽ�����
	void DoCMDTechnology_Technology(TechnologyCMD cmd);	//֪�ԿƼ���Ƽ�����

	void FirstRoundInit();	//��һ�غ�֮ǰ�ĳ�ʼ��
	void BeforeProcessInit();	//ÿ�غϴ�������ǰ�ĳ�ʼ��
	void BeforeProcessGoldInit();	//ÿ�غ�ǰ�Ľ�Ǯ���ݳ�ʼ��
	void BeforeProcessLoyalInit();	//ÿ�غ�ǰ���������ݳ�ʼ��
	void BeforeProcessSoldierInit();//ÿ�غ�ǰ��ʿ�����ݳ�ʼ��
	void BeforeProcessCityInit();//ÿ�غ�ǰ�ĳǳ����ݳ�ʼ��
	void BeforeProcessCrystalInit();	//ÿ�غ�ǰ��ˮ�����ݳ�ʼ��


	void MineProduceGold();		//ÿ�غϲ���

	void Player1GoldChangedProcess();	//���1�ĸûغϽ�Ǯ�仯����
	void Player1LoyalChangedProcess();	//���1�ĸûغ����ұ仯����
	void Player1SoldierChangedProcess();	//���1�ĸûغ�ʿ�����仯����
	void Player1CityChangedProcess();	//���1�ĸûغϳǳ����仯����
	void Player1CrystalChangedProcess();	//���1�ĸûغ�ˮ�����仯����

	bool CheckPlayer1isWin();	//�ж����1�Ƿ���ʤ������
	
	bool CheckPlayer1isWinOfEconomy();	//�ж����1�ľ��û�ʤ����
	bool CheckPlayer1isWinOfInterior();	//�ж����1��������ʤ����
	bool CheckPlayer1isWinOfArmy();		//�ж����1�ľ��»�ʤ����
	bool CheckPlayer1isWinOfTechnology();	//�ж����1�ĿƼ���ʤ����
	
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



