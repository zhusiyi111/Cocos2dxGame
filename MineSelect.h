#pragma once
#include "SonMenu.h"
#include "FarmSonMenu.h"
class MineSelect : public SonMenu
{
public:
	MineSelect();
	~MineSelect();
	virtual bool init();
	static MineSelect *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(MineSelect);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);

	FarmSonMenu *ToFarmSonMenu;
private:
	int mine_num;
};

