#include "ButtomMenu.h"


ButtomMenu::ButtomMenu()
{

}


ButtomMenu::~ButtomMenu()
{
}

ButtomMenu *ButtomMenu::create(std::string pic_unp, std::string pic_p){

	ButtomMenu *buttom_menu = ButtomMenu::create();
	buttom_menu->pic_press = pic_p;
	buttom_menu->pic_unpress = pic_unp;
	buttom_menu->init();

	return buttom_menu;
}


bool ButtomMenu::init(){
	bool bRet = false;
	do
	{
		// 创建一个菜单项，类型为图片菜单类型
		CCMenuItemImage* pItem = CCMenuItemImage::create(
			pic_unpress,	// 正常状态下的图片
			pic_press,// 点击状态下的图片
			this,
			menu_selector(ButtomMenu::menuCloseCallback));	// 点击菜单项时，回调的函数

		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		CCMenu* pMenu = CCMenu::create(pItem,NULL);
		pMenu->setPosition(ccp(0, 0));

		this->addChild(pMenu);
		bRet = true;
	} while (0);

	return bRet;
}

void ButtomMenu::addButtomMenu()
{
	this->addChild(pSprite);
	
}


void ButtomMenu::menuCloseCallback(CCObject *pSender){

}