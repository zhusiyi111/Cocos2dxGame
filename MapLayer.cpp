#include "MapLayer.h"
#include "GameScene.h"
#include "WelcomeScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "Mine.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::extension;


CCLayer* MapLayer::createLayer()
{
	// 'layer' is an autorelease object
	MapLayer *layer = MapLayer::create();


	return layer;
}


bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	std::string file = "map.tmx";
	auto str = String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename(file.c_str()).c_str());
	_tileMap = TMXTiledMap::createWithXML(str->getCString(), "");
	_background = _tileMap->layerNamed("background");
	
	_citys = _tileMap->layerNamed("citys");
	_mines = _tileMap->layerNamed("mines");
	addChild(_tileMap, -1);

	TMXObjectGroup *Stronghold = _tileMap->getObjectGroup("Stronghold");
	CCASSERT(NULL != Stronghold, "'Stronghold' object group not found");

	TMXObjectGroup *MineLayer = _tileMap->getObjectGroup("Mine");
	CCASSERT(NULL != MineLayer, "'Mine' object group not found");

	MineGroupinit(MineLayer);
	





	MineSelect = 0;

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(MapLayer::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
	listener->onTouchCancelled = CC_CALLBACK_2(MapLayer::onTouchCancelled, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}


void MapLayer::setViewPointCenter(Point position) {
	auto winSize = Director::getInstance()->getWinSize();


	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);
	auto actualPosition = Point(x, y);


	auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
	auto viewPoint = centerOfView - actualPosition;
	this->setPosition(viewPoint);
}

bool MapLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto beginpoint = touch->getLocation();
	beginpoint = this->convertToNodeSpace(beginpoint);
	BeginPoint = beginpoint;
	return true;
}

void MapLayer::onTouchMoved(Touch *touch, Event *unused_event)
{



}

void MapLayer::onTouchCancelled(Touch *touch, Event *unused_event)
{

}


void MapLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	auto touchpoint = touch->getLocation();
	touchpoint = this->convertToNodeSpace(touchpoint);
	int cha_x = touchpoint.x - BeginPoint.x;
	int cha_y = touchpoint.y - BeginPoint.y;
	CCLOG("X:%f", cha_x);
	CCLOG("Y:%f", cha_y);
	touchpoint.x = BeginPoint.x - cha_x;
	touchpoint.y = BeginPoint.y - cha_y;

	this->setViewPointCenter(touchpoint);
}

void MapLayer::setPlayerPosition(Point position)
{

}


void MapLayer::MineGroupinit(TMXObjectGroup *MineLayer)
{
	int num = MineLayer->getObjects().size();
	mine_num = num;
	for (int i = 1; i <= num; i++)
	{
		std::stringstream ss;
		std::string s;
		ss << i;
		ss >> s;
		std::string aa = "Mine" + s;
		auto Mine1 = MineLayer->getObject(aa);
		CCASSERT(!Mine1.empty(), "Mine1 object not found");
		int x = Mine1["x"].asInt();
		int y = Mine1["y"].asInt();
		Mine *_player;
		_player = Mine::create();
		_player->setPosition(x + _tileMap->getTileSize().width / 2, y + _tileMap->getTileSize().height / 2);
		_player->setScale(1);
		_player->setMineId(i);
		_player->ToMapLayer = this;

		Mines.push_back(_player);
		addChild(_player);
	}
}

