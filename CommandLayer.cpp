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

//接收经济命令
void CommandLayer::ReceiveCMD(EconomyCMD cmd)
{
	ProcessEcomomyCMD(cmd);
}

//查看执行经济命令的条件，如果合法，存到命令栏，待回合结束发送到服务器。如何不合法，不做反应。
void CommandLayer::ProcessEcomomyCMD(EconomyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//返回执行结果（0为成功，非零为错误代码)
	switch (res)
	{
	case 0:	//命令合法
		EconomyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;

	}
}

//接收内政命令
void CommandLayer::ReceiveCMD(InteriorCMD cmd)
{
	ProcessInteriorCMD(cmd);
}

//查看执行内政命令的条件，如果合法，存到命令栏，待回合结束发送到服务器。如何不合法，不做反应。
void CommandLayer::ProcessInteriorCMD(InteriorCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//返回执行结果（0为成功，非零为错误代码)
	switch (res)
	{
	case 0:	//命令合法
		InteriorCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}
}

//接收军事命令
void CommandLayer::ReceiveCMD(ArmyCMD cmd)
{
	ProcessArmyCMD(cmd);
}

//查看执行军事命令的条件，如果合法，存到命令栏，待回合结束发送到服务器。如何不合法，不做反应。
void CommandLayer::ProcessArmyCMD(ArmyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//返回执行结果（0为成功，非零为错误代码)
	switch (res)
	{
	case 0:	//命令合法
		ArmyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}
}


//接收科技命令
void CommandLayer::ReceiveCMD(TechnologyCMD cmd)
{
	ProcessTechnologyCMD(cmd);
}

//查看执行科技命令的条件，如果合法，存到命令栏，待回合结束发送到服务器。如何不合法，不做反应。
void CommandLayer::ProcessTechnologyCMD(TechnologyCMD cmd)
{
	int res = ToDataLayer->DoCMD(cmd);	//返回执行结果（0为成功，非零为错误代码)
	CCLOG("RES=%d", res);
	switch (res)
	{
	case 0:			//命令合法
		TechnologyCMDUpload.push_back(cmd);
		break;
	default:
		ToDataLayer->ToMenuLayer->ShowFalseNum(res);
		break;
	}

		
	
}

//接收回合结束命令
void CommandLayer::ReceiveCMD(EndRoundCMD cmd)
{
	ProcessEndRoundCMD(cmd);
}

//执行回合结束命令
void CommandLayer::ProcessEndRoundCMD(EndRoundCMD cmd)
{
	EndRoundCMDUpload.push_back(cmd);
	CCLOG("Next turn.");
	SendCMDToBackstage();

}

//将本玩家的当前回合的所有命令指令发到后台/服务器进行处理
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

//发送经济命令到后台
void CommandLayer::SendEconomyCMDToBackstage()
{
	for (int i = 0; i < EconomyCMDUpload.size(); i++)
	{
		EconomyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveEconomyCMD(EconomyCMDUpload[i]);
	}
	
}

//发送内政命令到后台
void CommandLayer::SendInteriorCMDToBackstage()
{
	for (int i = 0; i < InteriorCMDUpload.size(); i++)
	{
		InteriorCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveInteriorCMD(InteriorCMDUpload[i]);
	}

}

//发送军事命令到后台
void CommandLayer::SendArmyCMDToBackstage()
{
	for (int i = 0; i < ArmyCMDUpload.size(); i++)
	{
		ArmyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveArmyCMD(ArmyCMDUpload[i]);
	}

}

//发送科技命令到后台
void CommandLayer::SendTechnologyCMDToBackstage()
{
	for (int i = 0; i < TechnologyCMDUpload.size(); i++)
	{
		TechnologyCMDUpload[i].PlayerId = 1;
		ToBackstage->ReceiveTechnologyCMD(TechnologyCMDUpload[i]);
	}

}

//发送回合结束命令到后台
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