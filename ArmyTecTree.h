#pragma once
#include "TechnologyTree.h"
class TechnologySonMenu;


class ArmyTecTree :
	public TechnologyTree
{
public:
	ArmyTecTree();
	~ArmyTecTree();

	virtual bool init();
	static ArmyTecTree *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(ArmyTecTree);

	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);

public:
	TechnologySonMenu *ToTechnologySonMenu;
	int checknum;

};

