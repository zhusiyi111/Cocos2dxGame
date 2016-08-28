#pragma once
#include "TechnologyTree.h"
class TechnologySonMenu;

class TechnologyTecTree :
	public TechnologyTree
{
public:
	TechnologyTecTree();
	~TechnologyTecTree();

	virtual bool init();
	static TechnologyTecTree *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(TechnologyTecTree);

	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);


public:
	TechnologySonMenu *ToTechnologySonMenu;
	int checknum;
};