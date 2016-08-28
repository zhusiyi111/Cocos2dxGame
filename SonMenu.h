#pragma once
#include "cocos2d.h"
#include"cocos-ext.h"
#include<vector>
USING_NS_CC;
USING_NS_CC_EXT;
class MenuLayer;

class SonMenu :public CCNode
{
public:
	SonMenu();
	~SonMenu();
	void BtncancelCallBack(CCObject *pSender);

public:
	std::string pic_background;
	std::string button_ok;
	std::string button_cancel;
	std::string viewi_check_pic;
	std::vector<std::string> left_button;
	std::vector<std::string> right_view;

	CCMenu* pMenu;
	CCMenuItemImage* viewi;

	MenuLayer *ToMenuLayer;


};

