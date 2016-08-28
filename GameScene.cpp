#include "GameScene.h"
#include "WelcomeScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "MapLayer.h"
#include "MenuLayer.h"
#include "Backstage.h"
#include "DataLayer.h"
#include "CommandLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::extension;


CCScene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{

		return false;
	}
	bool bRet = false;
	do
	{
		CCScene *scene = CCScene::create();

		backstage = Backstage::create();
		addChild(backstage, 0);

		maplayer = MapLayer::create();
		addChild(maplayer, 1);

		menulayer = MenuLayer::create();
		addChild(menulayer, 2);

		datalayer = DataLayer::create();
		addChild(datalayer, 3);

		commandlayer = CommandLayer::create();
		addChild(commandlayer);



		//初始化各层之间的相互指针
		menulayer->ToCmdLayer = commandlayer;
		menulayer->ToMapLayer = maplayer;
		menulayer->ToDataLayer = datalayer;

		commandlayer->ToDataLayer = datalayer;
		commandlayer->ToBackstage = backstage;

		datalayer->ToMenuLayer = menulayer;
		datalayer->ToMapLayer = maplayer;

		backstage->ToDataLayer_1 = datalayer;
		backstage->ToMapLayer_1 = maplayer;


		backstage->FirstRoundInit();


		this->schedule(schedule_selector(GameScene::myupdate),0.2f);
		bRet = true;
	} while (0);
	
	
	return bRet;
}

void GameScene::myupdate(float dt)
{
	datalayer->MyUpdate();
}
