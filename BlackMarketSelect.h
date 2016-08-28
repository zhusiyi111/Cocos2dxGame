#pragma once
#include "SonMenu.h"
#include "FarmSonMenu.h"
class FarmSonMenu;
class BlackMarketSelect : public SonMenu
{
public:
	BlackMarketSelect();
	~BlackMarketSelect();
	virtual bool init();
	static BlackMarketSelect *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(BlackMarketSelect);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);

	FarmSonMenu *ToFarmSonMenu;
private:
	int check_num;
};

