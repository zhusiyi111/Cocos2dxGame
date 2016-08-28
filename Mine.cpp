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

	Goldnum = 0;	//����ʼ��ǮΪ0
	//��Ӵ����¼�
	addTouch();


	return true;
}


bool Mine::onTouchBegan(Touch* pTouch, Event* pEvent) //���Ӣ�۵������
{
	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());

	// ��ȡ��ǰ�����������԰�ť��λ������   
	Point locationInNode = target->convertToNodeSpace(pTouch->getLocation());          //һ��Ҫ������
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// �����Χ�жϼ��
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
