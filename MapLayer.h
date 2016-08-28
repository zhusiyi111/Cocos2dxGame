#ifndef __MAPLAYER_SCENE_H__
#define __MAPLAYER_SCENE_H__
#include "cocos2d.h"
class Mine;
class MenuLayer;
USING_NS_CC;

class MapLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();


	static cocos2d::CCLayer* createLayer();
	CREATE_FUNC(MapLayer);

	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void setViewPointCenter(cocos2d::Point position);
	void setPlayerPosition(cocos2d::Point position);

	cocos2d::Point tileCoordForPosition(cocos2d::Point position);


	void MineGroupinit(TMXObjectGroup *MineLayer);
	int sendMineSelect();

	


public:
	int MineSelect;
	MenuLayer *ToMenuLayer;
	std::vector<Mine*> Mines;
	int mine_num;
	


private:
	cocos2d::TMXTiledMap *_tileMap;
	cocos2d::TMXLayer *_background;
	cocos2d::TMXLayer *_citys;
	cocos2d::TMXLayer *_mines;

private:
	Point BeginPoint;
	Point EndPoint;

	TMXObjectGroup *MineGroup;
	

};

#endif
