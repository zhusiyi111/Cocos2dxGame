#pragma once
#include "cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class HOFScene : public cocos2d::Layer
{
public:
	HOFScene();
	~HOFScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HOFScene);
	void menuCloseCallback(CCObject *pSender);
};

