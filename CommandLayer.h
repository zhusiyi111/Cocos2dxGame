#pragma once
#include"cocos2d.h"
#include "EconomyCMD.h"
#include "EndRoundCMD.h"
#include "Backstage.h"
#include "CMDCantHint.h"
#include "ArmyCMD.h"
class DataLayer;

class CommandLayer :public cocos2d::CCLayer
{
public:
	CommandLayer();
	~CommandLayer();

	virtual bool init();
	static cocos2d::CCLayer *creatLayer();
	void ReceiveCMD(EconomyCMD cmd);
	void ProcessEcomomyCMD(EconomyCMD cmd);

	void ReceiveCMD(EndRoundCMD cmd);
	void ProcessEndRoundCMD(EndRoundCMD cmd);

	void ReceiveCMD(InteriorCMD cmd);
	void ProcessInteriorCMD(InteriorCMD cmd);

	void ReceiveCMD(ArmyCMD cmd);
	void ProcessArmyCMD(ArmyCMD cmd);

	void ReceiveCMD(TechnologyCMD cmd);
	void ProcessTechnologyCMD(TechnologyCMD cmd);

	void SendCMDToBackstage();

	void SendEconomyCMDToBackstage();
	void SendInteriorCMDToBackstage();
	void SendArmyCMDToBackstage();
	void SendEndRoundCMDToBackstage();
	void SendTechnologyCMDToBackstage();


	void ClearAllCMDThisRound();
	
	CREATE_FUNC(CommandLayer);

public:
	DataLayer *ToDataLayer;
	Backstage *ToBackstage;
	

	std::vector<EconomyCMD> EconomyCMDUpload;
	std::vector<EndRoundCMD> EndRoundCMDUpload;
	std::vector<InteriorCMD> InteriorCMDUpload;
	std::vector<ArmyCMD> ArmyCMDUpload;
	std::vector<TechnologyCMD> TechnologyCMDUpload;
	
};

