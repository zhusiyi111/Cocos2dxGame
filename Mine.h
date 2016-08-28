#pragma once
#include "cocos2d.h"
class MapLayer;
USING_NS_CC;
class Mine :public Sprite
{
public:
	Mine();
	~Mine();
	virtual bool init();
	CREATE_FUNC(Mine);
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //µã»÷Ó¢ÐÛµ¯³öÃæ°å
	void addTouch();
	void setMineId(int id);
	int getMineId();

public:
	MapLayer *ToMapLayer;

	int MineId;
	int Goldnum;
	cocos2d::EventListenerTouchOneByOne * listener;
	cocos2d::Size visibleSize;
	cocos2d::Sprite * mineSprite;
};

