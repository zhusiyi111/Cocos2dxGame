#pragma once
#include "SonMenu.h"
#include "EconomyTecTree.h"
#include "TechnologyCMD.h"
#include "InteriorTecTree.h"
#include "ArmyTecTree.h"
#include "TechnologyTecTree.h"
class EconomyTecTree;
class TechnologySonMenu:public SonMenu
{
public:
	TechnologySonMenu();
	~TechnologySonMenu();
	virtual bool init();
	static TechnologySonMenu *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(TechnologySonMenu);
	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);
	void BtncheckCallBack(CCObject *pSender);

	int technology_sec_kind_select;

	EconomyTecTree *economy_tec_tree;
	InteriorTecTree *interior_tec_tree;
	ArmyTecTree *army_tec_tree;
	TechnologyTecTree *technology_tec_tree;


private:
	int technology_cmd_type;
};

