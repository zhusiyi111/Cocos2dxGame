#pragma once
#include "SonMenu.h"
#include "BlackMarketSelect.h"
#include "MarketSelect.h"
class MarketSelect;
class BlackMarketSelect;
class MineSelect;
class MapLayer;
class FarmSonMenu :
	public SonMenu
{
public:
	FarmSonMenu();
	~FarmSonMenu();
	virtual bool init();
	static FarmSonMenu *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(FarmSonMenu);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);
	void BtnMineSelectCallBack(CCObject *pSender);
	void BtnMineSelectOKCallBack(CCObject* pSender);
	void BlackMarketBtncheckCallBack(CCObject *pSender);
	void MarketBtncheckCallBack(CCObject *pSender);

	int mine_num_select;
	MineSelect *mineselect;

	int blackmarket_num_select;
	BlackMarketSelect *blackmarketselect;	//黑市选择

	int market_num_select;	
	MarketSelect *marketselect;		//市场选择



private:
	int economy_cmd_type;
	
	MapLayer *ToMapLayer;
	CCMenuItemImage* btn_mineselect;		//矿点选择
	CCMenuItemImage *btn_check;				//查看
	CCMenu* mineselect_btn_ok;
	
};

