#pragma once
#include "TechnologyTree.h"
class TechnologySonMenu;

class InteriorTecTree :
	public TechnologyTree
{
public:
	InteriorTecTree();
	~InteriorTecTree();

	virtual bool init();
	static InteriorTecTree *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(InteriorTecTree);

	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);


public:
	TechnologySonMenu *ToTechnologySonMenu;
	int checknum;
};