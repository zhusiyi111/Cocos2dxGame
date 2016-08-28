#ifndef __WELCOMESCENE_SCENE_H__
#define __WELCOMESCENE_SCENE_H__
#include "cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class WelcomeScene : public cocos2d::Layer
{
public:

	WelcomeScene();
	~WelcomeScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(WelcomeScene);
	void menuCloseCallback(CCObject *pSender);
};

#endif