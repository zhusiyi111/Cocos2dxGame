#pragma once
#include "TechnologyTree.h"
#include "InteriorSonMenu.h"
class MiracleBuilding :
	public TechnologyTree	//�̳е��ǿƼ�����
{
public:
	MiracleBuilding();
	~MiracleBuilding();

	virtual bool init();
	static MiracleBuilding *create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview);
	CREATE_FUNC(MiracleBuilding);

	void BtnokCallBack(CCObject *pSender);
	void leftbtnCallBack(CCObject *pSender);

public:
	InteriorSonMenu *ToInteriorSonMenu;
	int checknum;
};