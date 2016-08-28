#pragma once
#include "cocos2d.h"
#include "SonMenu.h"
#include "CommandLayer.h"
#include "EconomyCMD.h"
#include "FarmSonMenu.h"
#include "InteriorSonMenu.h"
#include "CMDCantHint.h"
#include "TechnologySonMenu.h"
#include "ArmySonMenu.h"
#include "ArmyCMD.h"
USING_NS_CC;

class CommandLayer;//前向声明，应用于引用指针
class TechnologySonMenu;

class MenuLayer : public cocos2d::CCLayer
{
public:
	MenuLayer();
	~MenuLayer();
	virtual bool init();
	static cocos2d::CCLayer *creatLayer();
	CREATE_FUNC(MenuLayer);

	void CloseButtonCallBack(CCObject* pSender);
	void FarmBtnCallBack(CCObject* pSender);
	void InteriorBtnCallBack(CCObject* pSender);
	void ArmyBtnCallBack(CCObject* pSender);
	void EndroundBtnCallBack(CCObject* pSender);
	void TechnologyBtnCallBack(CCObject* pSender);


	void SendCmd(EconomyCMD cmd);
	void SendCmd(EndRoundCMD cmd);
	void SendCmd(InteriorCMD cmd);
	void SendCmd(ArmyCMD cmd);
	void SendCmd(TechnologyCMD cmd);

	void ShowFalseNum(int val);


public:
	CommandLayer *ToCmdLayer;
	MapLayer *ToMapLayer;
	DataLayer *ToDataLayer;


	CMDCantHint *cmdhint;

	CCMenu *farm_menu;
	CCMenu *interior_menu;
	CCMenu *army_menu;
	CCMenu *technology_menu;

	FarmSonMenu *FarmSon; //“经济”子菜单
	InteriorSonMenu *InteriorSon;	//“内政”子菜单
	ArmySonMenu *ArmySon;	//“军事”子菜单
	TechnologySonMenu *TechnologySon; //“科技”子菜单
	

	
	
	CCSprite *round_show;
	CCMenu *end_round;
	CCMenu *close;
	CCSprite *money;

private:
	
};

