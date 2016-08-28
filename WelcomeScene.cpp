#include "WelcomeScene.h"
#include "HelloWorldScene.h"
#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "ThanksScene.h"
#include "HOFScene.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::extension;

WelcomeScene::WelcomeScene()
{
}


WelcomeScene::~WelcomeScene()
{
}

Scene* WelcomeScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = WelcomeScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


bool WelcomeScene::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCMenuItemImage *background = CCMenuItemImage::create("welcome.png", "welcome.png");
		background->setPosition(ccp(size.width / 2, size.height / 2));
		this->addChild(background,0);

		CCLabelTTF *labelstart = CCLabelTTF::create("StartGame", "Arial", 40);
		CCLabelTTF *labelhelp = CCLabelTTF::create("Thanks", "Arial", 40);
		CCLabelTTF *labelHOF = CCLabelTTF::create("Hall Of Fame", "Arial", 40);
		CCLabelTTF *labelexit = CCLabelTTF::create("ExitGame", "Arial", 40);


		CCMenuItemLabel *mi01 = CCMenuItemLabel::create(labelstart, this, menu_selector(WelcomeScene::menuCloseCallback));
		mi01->setTag(1);
		mi01->setPosition(ccp(200, 200));

		CCMenuItemLabel *mi02 = CCMenuItemLabel::create(labelhelp, this, menu_selector(WelcomeScene::menuCloseCallback));
		mi02->setTag(2);
		mi02->setPosition(ccp(200, 150));

		CCMenuItemLabel *mi03 = CCMenuItemLabel::create(labelHOF, this, menu_selector(WelcomeScene::menuCloseCallback));
		mi03->setTag(3);
		mi03->setPosition(ccp(200, 100));

		CCMenuItemLabel *mi04 = CCMenuItemLabel::create(labelexit, this, menu_selector(WelcomeScene::menuCloseCallback));
		mi04->setTag(4);
		mi04->setPosition(ccp(200, 0));

		CCMenu *pMenu = CCMenu::create(mi01, mi02, mi03,mi04, NULL);

		pMenu->setPosition(size.width / 2, size.height / 2);
		this->addChild(pMenu,1);




		bRet = true;
	} while (0);
	return bRet;
}

void WelcomeScene::menuCloseCallback(CCObject *pSender)
{
	switch (((CCNode*)pSender)->getTag())
	{
	case 1:
		CCDirector::sharedDirector()->replaceScene(GameScene::createScene());
		break;
	case 2:
		CCDirector::sharedDirector()->replaceScene(ThanksScene::createScene());
		break;
	case 3:
		CCDirector::sharedDirector()->replaceScene(HOFScene::createScene());
		break;
	case 4:
		CCDirector::sharedDirector()->end();
	}
}
