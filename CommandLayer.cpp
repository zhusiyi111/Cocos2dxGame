#include "CommandLayer.h"
#include "EconomyCMD.h"
#include "DataLayer.h"
#include "EndRoundCMD.h"
#include "InteriorCMD.h"
#include "ArmyCMD.h"
USING_NS_CC;

CommandLayer::CommandLayer()
{
}


CommandLayer::~CommandLayer()
{
}

CCLayer *CommandLayer::creatLayer(){

	CommandLayer *layer = CommandLayer::create();

	return layer;
}

bool CommandLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	bool bRet = false;

	do{


		bRet = true;
	} while (0);
	return bRet;
}

//���վ�������
void CommandLayer::ReceiveCMD(EconomyCMD cmd)
{
	ProcessEcomomyCMD(cmd);
}

//�鿴ִ�о������������������Ϸ����浽�����������غϽ������͵�����������β��Ϸ���������Ӧ��
void CommandLayer::ProcessEcomomyCMD(EconomyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//����ִ�н����0Ϊ�ɹ�������Ϊ�������)
	switch (res)
	{
	case 0:	//����Ϸ�
		EconomyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;

	}
}

//������������
void CommandLayer::ReceiveCMD(InteriorCMD cmd)
{
	ProcessInteriorCMD(cmd);
}

//�鿴ִ���������������������Ϸ����浽�����������غϽ������͵�����������β��Ϸ���������Ӧ��
void CommandLayer::ProcessInteriorCMD(InteriorCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//����ִ�н����0Ϊ�ɹ�������Ϊ�������)
	switch (res)
	{
	case 0:	//����Ϸ�
		InteriorCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}
}

//���վ�������
void CommandLayer::ReceiveCMD(ArmyCMD cmd)
{
	ProcessArmyCMD(cmd);
}

//�鿴ִ�о������������������Ϸ����浽�����������غϽ������͵�����������β��Ϸ���������Ӧ��
void CommandLayer::ProcessArmyCMD(ArmyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//����ִ�н����0Ϊ�ɹ�������Ϊ�������)
	switch (res)
	{
	case 0:	//����Ϸ�
		ArmyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}
}


//���տƼ�����
void CommandLayer::ReceiveCMD(TechnologyCMD cmd)
{
	ProcessTechnologyCMD(cmd);
}

//�鿴ִ�пƼ����������������Ϸ����浽�����������غϽ������͵�����������β��Ϸ���������Ӧ��
void CommandLayer::ProcessTechnologyCMD(TechnologyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//����ִ�н����0Ϊ�ɹ�������Ϊ�������)
	CCLOG("RES=%d", res);
	switch (res)
	{
	case 0:			//����Ϸ�
		TechnologyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}

		
	
}

//���ջغϽ�������
void CommandLayer::ReceiveCMD(EndRoundCMD cmd)
{
	ProcessEndRoundCMD(cmd);
}

//ִ�лغϽ�������
void CommandLayer::ProcessEndRoundCMD(EndRoundCMD cmd)
{
	EndRoundCMDUpload.push_back(cmd);
	CCLOG("Next turn.");
	SendCMDToBackstage();

}

//������ҵĵ�ǰ�غϵ���������ָ�����̨/���������д���
void CommandLayer::SendCMDToBackstage()
{
	SendEconomyCMDToBackstage();
	SendInteriorCMDToBackstage();
	SendArmyCMDToBackstage();
	SendTechnologyCMDToBackstage();
	SendEndRoundCMDToBackstage();
	ToBackstage->ProcessStart();
	ClearAllCMDThisRound();
}

//���;��������̨
void CommandLayer::SendEconomyCMDToBackstage()
{
	for (int i = 0; i < EconomyCMDUpload.size(); i++)
	{
		EconomyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveEconomyCMD(EconomyCMDUpload[i]);
	}
	
}

//�������������̨
void CommandLayer::SendInteriorCMDToBackstage()
{
	for (int i = 0; i < InteriorCMDUpload.size(); i++)
	{
		InteriorCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveInteriorCMD(InteriorCMDUpload[i]);
	}

}

//���;��������̨
void CommandLayer::SendArmyCMDToBackstage()
{
	for (int i = 0; i < ArmyCMDUpload.size(); i++)
	{
		ArmyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveArmyCMD(ArmyCMDUpload[i]);
	}

}

//���ͿƼ������̨
void CommandLayer::SendTechnologyCMDToBackstage()
{
	for (int i = 0; i < TechnologyCMDUpload.size(); i++)
	{
		TechnologyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveTechnologyCMD(TechnologyCMDUpload[i]);
	}

}

//���ͻغϽ��������̨
void CommandLayer::SendEndRoundCMDToBackstage()
{
	for (int i = 0; i < EndRoundCMDUpload.size(); i++)
	{
		EndRoundCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveEndRoundCMD(EndRoundCMDUpload[i]);
	}
}


void CommandLayer::ClearAllCMDThisRound()
{
	EconomyCMDUpload.clear();
	EndRoundCMDUpload.clear();
	InteriorCMDUpload.clear();
	ArmyCMDUpload.clear();
	TechnologyCMDUpload.clear();
}