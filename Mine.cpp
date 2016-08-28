#include "Mine.h"
#include "MapLayer.h"


Mine::Mine() 
{
}


Mine::~Mine()
{
}

bool Mine::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	visibleSize = Director::sharedDirector()->getVisibleSize();

	mineSprite = Sprite::create("mine.png");
	addChild(mineSprite);

	Goldnum = 0;	//金矿初始金钱为0
	//添加触摸事件
	addTouch();


	return true;
}


bool Mine::onTouchBegan(Touch* pTouch, Event* pEvent) //点击英雄弹出面板
{
	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());

	// 获取当前点击点所在相对按钮的位置坐标   
	Point locationInNode = target->convertToNodeSpace(pTouch->getLocation());          //一定要这样做
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		CCLOG("touchMine:%d",MineId);
		ToMapLayer->MineSelect = MineId;
		return true;
	}
	return false;
}

void Mine::addTouch()
{
	auto dispatcher = this->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Mine::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this->mineSprite);
}

void Mine::setMineId(int id)
{
	MineId = id;
}
int Mine::getMineId()
{
	return MineId;
}
