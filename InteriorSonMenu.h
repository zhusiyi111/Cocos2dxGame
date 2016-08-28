#pragma once
#include "SonMenu.h"
class MiracleBuilding;
class InteriorSonMenu :
	public SonMenu
{
public:
	InteriorSonMenu();
	~InteriorSonMenu();
	virtual bool init();
	static InteriorSonMenu *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(InteriorSonMenu);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);
	void BtncheckCallBack(CCObject *pSender);

	CCMenuItemImage *btn_check;
	int interior_sec_kind_select;

	MiracleBuilding *miracle_building;


private:
	int interior_cmd_type;
	

};

