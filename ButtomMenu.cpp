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
		// ����һ���˵������ΪͼƬ�˵�����
		CCMenuItemImage* pItem = CCMenuItemImage::create(
			pic_unpress,	// ����״̬�µ�ͼƬ
			pic_press,// ���״̬�µ�ͼƬ
			this,
			menu_selector(ButtomMenu::menuCloseCallback));	// ����˵���ʱ���ص��ĺ���

		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
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