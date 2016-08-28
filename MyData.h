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

	


	//��Ǯ�ı�ֵ����ԭ��
	int _GoldChanged;

	int _GoldUp;				//��Ǯ������
	int _GoldUpFromMine;		//�ɿ����ý�Ǯ
	int _GoldUpFromTax;			//��˰���ý�Ǯ
	int _GoldUpFromTreasure;	//Ѱ�����ý�Ǯ
	int _GoldUpFromTrade;		//ó�����ý�Ǯ
	int _GoldUpFromBlackMarket;	//�������ý�Ǯ
	int _GoldUpFromMarket;		//�г����ý�Ǯ
	int _GoldUpFromTunTian;     //�������ý�Ǯ
	int _GoldUpFromBiology;		//����ѧ���ý�Ǯ
	int _GoldUpFromPyramid;		//ӵ�н��������ý�Ǯ

	int _GoldDown;
	int _GoldDownFromDoTreasure;	//ִ��Ѱ��ָ����ٽ�Ǯ
	int _GoldDownFromDoBlackMarket;	//ִ�к���ָ����ٽ�Ǯ
	int _GoldDownFromDoMarket;		//ִ���г�ָ����ٽ�Ǯ
	int _GoldDownFromDoInterior;	//ִ������ָ�������ٽ�Ǯ
	int _GoldDownFromDoArmy;		//ִ�о���ָ�������ٽ�Ǯ
	int _GoldDownFromDoTechnology;	//�����Ƽ������ٽ�Ǯ



	//���Ҹı�ֵ����ԭ��
	int _LoyalChanged;

	int _LoyalUp;					//����������
	int _LoyalUpFromHelpPeople;		//������������
	int _LoyalUpFromPardon;			//����������������
	int _LoyalUpFromRepublic;		//��������������

	int _LoyalDown;					//���Ҽ�����
	int _LoyalDownFromEachRound;	//ÿ�غϼ�������ֵ
	int _LoyalDownFromTax;			//��˰��������ֵ
	int _LoyalDownFromConscription;	//������������ֵ
	int _LoyalDownFromColony;		//ֳ���������ֵ


	//ʿ���ı�ֵ����ԭ��
	int _SoldierChanged;

	int _SoldierUp;					//ʿ��������
	int _SoldierUpFromConscription;	//��������ʿ����
	int _SoldierUpFromMilitiaEachRound;	//�����ÿ�غ����ӵ�ʿ����
	int _SoldierUpFromColossusEachRound;	//������ÿ�غ����ӵ�ʿ����

	int _SoldierDown;				//ʿ��������
	int _SoldierDownFromTreasure;	//Ѱ�����ٵ�ʿ����
	int _SoldierDownFromColony;		//ֳ�����ʿ����


	//�ǳ����ı�ֵ����ԭ��
	int _CityChanged;

	int _CityUp;					//�ǳ�������
	int _CityUpFromColony;			//ֳ�����ӳǳ���
	int _CityUpFromDespotic;		//������ר�ơ�������õĳǳ���

	int _CityDown;					//�ǳؼ�����
	int _CityDownFromDoInterior;	//ִ������ָ����ٵĳǳ���


	//ˮ���ı�ֵ����ԭ��
	int _CrystalChanged;
	
	int _CrystalUp;					//ˮ��������
	int _CrystalUpFromTreasue;		//Ѱ�����ӵ�ˮ����
	int _CrystalUpFromBlackMarket;	//���������ӵ�ˮ����
	int _CrystalUpFromMarket;		//�г������ӵ�ˮ����
	int _CrystalUpFromStandingArmy;	//���������ӵ�ˮ����
	int _CrystalUpFromPhysics;		//����ѧ���ӵ�ˮ����
	int _CrystalUpFromChemistryEachRound;	//��ѧ���ӵ�ˮ����
	int _CrystalUpFromTerracotta;	//����ٸ���ӵ�ˮ��
	
	int _CrystalDown;				//ˮ��������
	int _CrystalDownFromBlackMarket;	//���м��ٵ�ˮ��
	int _CrystalDownFromMarket;		//�г����ٵ�ˮ����
	int _CrystalDownFromInterior;	//ִ������ָ����ٵ�ˮ��
	int _CrystalDownFromTechnology;	//�����Ƽ����ٵ�ˮ����


	//�漣����
	bool isPyramid;	//������
	bool isColossus;	//������
	bool isTerracotta;	//����ٸ
	bool isHangingGarden;//���л�԰

	



	//�Ƽ���
	bool isTunTian; //������
	bool isRefine;	//��������
	bool isMarketTrade;	//�г�����
	bool isProspect;	//��̽����
	bool isTaxLaw;	//˰��
	bool isBoom;	//����

	bool isCityState;	//�ǰ���
	bool isDespotic;	//ר��
	bool isDemocracy;	//������
	bool isMonarchy;	//������
	bool isRepublic;	//������
	bool isCapitalism;	//�ʱ�����
	bool isSocialism;	//�������

	bool isMilitia;		//�����
	bool isMercenary;	//��Ӷ����
	bool isStandingArmy;	//������
	bool isFort;		//����
	bool isAllSoldier;	//ȫ��Ա�
	bool isSpy;			//���

	bool isMath;		//��ѧ
	bool isPhysics;		//����ѧ
	bool isBiology;		//����ѧ
	bool isElectric;	//����ѧ
	bool isChemistry;	//��ѧ
	bool isSuperComputer;	//���������
	

};

