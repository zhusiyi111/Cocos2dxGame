#pragma once
#include "TechnologyTree.h"
class TechnologySonMenu;


class EconomyTecTree :
	public TechnologyTree
{
public:
	EconomyTecTree();
	~EconomyTecTree();

	virtual bool init();
	static EconomyTecTree *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(EconomyTecTree);

	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);

public:
	TechnologySonMenu *ToTechnologySonMenu;
	int checknum;

};

