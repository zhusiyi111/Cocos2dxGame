#pragma once
#include "SonMenu.h"
class ArmySonMenu :
	public SonMenu
{
public:
	ArmySonMenu();
	~ArmySonMenu();
	virtual bool init();
	static ArmySonMenu *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(ArmySonMenu);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);


private:
	int army_cmd_type;


};

