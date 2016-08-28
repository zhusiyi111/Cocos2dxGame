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
		// ��ȡ��Ļ��С
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

		// ����һ���˵������ΪͼƬ�˵�����
		CCMenuItemImage* pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",	// ����״̬�µ�ͼƬ
			"CloseSelected.png",// ���״̬�µ�ͼƬ
			this,
			menu_selector(HelloWorld::menuCloseCallback));	// ����˵���ʱ���ص��ĺ���

		CCMenuItem *hehe = CCMenuItemImage::create(
			"potentiometerButton.png",
			"potentiometerTrack.png",
			this,
			menu_selector(HelloWorld::menuCloseCallback));

		// ����һ����ǩ
		CCLabelTTF* label = CCLabelTTF::create("I am Label Item.", "Arial", 30);

		// �ñ�ǩ���󴴽�һ����ǩ�˵���
		CCMenuItemLabel* pLabelItem = CCMenuItemLabel::create(label);

		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		CCMenu* pMenu = CCMenu::create(pCloseItem, pLabelItem, hehe, NULL);

		// �����еĲ˵����ڴ�ֱ�������Զ�����
		pMenu->alignItemsVertically();

		// ���ò˵�������
		pMenu->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

		// ��Ӳ˵�������
		this->addChild(pMenu, 1);

		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::createScene());
}
