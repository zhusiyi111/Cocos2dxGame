#include "HelloWorldScene.h"
#include"WelcomeScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::extension;


Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	bool bRet = false;
	do
	{
		// 获取屏幕大小
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

		// 创建一个菜单项，类型为图片菜单类型
		CCMenuItemImage* pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",	// 正常状态下的图片
			"CloseSelected.png",// 点击状态下的图片
			this,
			menu_selector(HelloWorld::menuCloseCallback));	// 点击菜单项时，回调的函数

		CCMenuItem *hehe = CCMenuItemImage::create(
			"potentiometerButton.png",
			"potentiometerTrack.png",
			this,
			menu_selector(HelloWorld::menuCloseCallback));

		// 创建一个标签
		CCLabelTTF* label = CCLabelTTF::create("I am Label Item.", "Arial", 30);

		// 用标签对象创建一个标签菜单项
		CCMenuItemLabel* pLabelItem = CCMenuItemLabel::create(label);

		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		CCMenu* pMenu = CCMenu::create(pCloseItem, pLabelItem, hehe, NULL);

		// 让所有的菜单项在垂直方向上自动排列
		pMenu->alignItemsVertically();

		// 设置菜单的坐标
		pMenu->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

		// 添加菜单到层里
		this->addChild(pMenu, 1);

		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::createScene());
}
