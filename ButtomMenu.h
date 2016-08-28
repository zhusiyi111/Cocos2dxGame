#pragma once
#include "cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class ButtomMenu:public CCNode
{
public:
	ButtomMenu();
	~ButtomMenu();

	virtual bool init();
	static ButtomMenu *create(std::string pic_unp,std::string pic_p);

	void addButtomMenu();
	CREATE_FUNC(ButtomMenu);
	void menuCloseCallback(CCObject *pSender);


public:
	std::string pic_unpress;
	std::string pic_press;
	CCSprite *pSprite;


};

