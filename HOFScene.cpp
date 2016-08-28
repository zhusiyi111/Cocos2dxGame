#include "HOFScene.h"
#include "WelcomeScene.h"

HOFScene::HOFScene()
{
}


HOFScene::~HOFScene()
{
}


Scene* HOFScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HOFScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HOFScene::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCMenuItemImage *background = CCMenuItemImage::create("mingrentang.png", "mingrentang.png");
		background->setPosition(ccp(0, 0));

		CCMenuItemImage *cancel = CCMenuItemImage::create("ButClose.png", "ButClose.png", this, menu_selector(HOFScene::menuCloseCallback));
		cancel->setPosition(ccp(size.width / 2 - 50, size.height / 2 - 50));

		CCMenu *cl = CCMenu::create(background, cancel, NULL);
		cl->setPosition(ccp(size.width / 2, size.height / 2));
		this->addChild(cl, 1);
		bRet = true;
	} while (0);
	return bRet;
}

void HOFScene::menuCloseCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::createScene());
}