#include "ThanksScene.h"
#include "WelcomeScene.h"

ThanksScene::ThanksScene()
{
}


ThanksScene::~ThanksScene()
{
}


Scene* ThanksScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ThanksScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool ThanksScene::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCMenuItemImage *background = CCMenuItemImage::create("ThanksScene.png", "ThanksScene.png");
		background->setPosition(ccp(0,0));

		CCMenuItemImage *cancel = CCMenuItemImage::create("ButClose.png", "ButClose.png", this, menu_selector(ThanksScene::menuCloseCallback));
		cancel->setPosition(ccp(size.width / 2 - 50, size.height / 2 - 50));

		CCMenu *cl = CCMenu::create(background,cancel, NULL);
		cl->setPosition(ccp(size.width / 2, size.height / 2));
		this->addChild(cl, 1);
		bRet = true;
	} while (0);
	return bRet;
}

void ThanksScene::menuCloseCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::createScene());
}