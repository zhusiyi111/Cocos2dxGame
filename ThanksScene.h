#pragma once
#include "cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class ThanksScene : public cocos2d::Layer
{
public:
	ThanksScene();
	~ThanksScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ThanksScene);
	void menuCloseCallback(CCObject *pSender);
};

