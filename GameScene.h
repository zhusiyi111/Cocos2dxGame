#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__
#include "cocos2d.h"
#include"cocos-ext.h"
#include "MapLayer.h"
#include "MenuLayer.h"
#include "Backstage.h"
#include "DataLayer.h"
#include "CommandLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

class GameScene: public cocos2d::CCLayer
{
public:
	virtual bool init();


	static cocos2d::CCScene* createScene();
	CREATE_FUNC(GameScene);
	Backstage *backstage;
	MapLayer *maplayer;
	MenuLayer *menulayer;
	DataLayer *datalayer;
	CommandLayer *commandlayer;
	

	void myupdate(float dt);

};

#endif
