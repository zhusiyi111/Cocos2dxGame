#include "WinHint.h"

std::string WinHint::picture = "";
int WinHint::Round = 0;
WinHint::WinHint()
{
}


WinHint::~WinHint()
{
}

WinHint *WinHint::createHint()
{
	WinHint::picture = "winhint.png";
	WinHint *layer = WinHint::create();

	return layer;
}

WinHint *WinHint::createHint(int round)
{
	WinHint::Round = round;
	WinHint::picture = "winhint.png";
	WinHint *layer = WinHint::create();

	return layer;
}

bool WinHint::init()
{
	bool bRet = false;
	do
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//背景
		CCMenuItemImage* background = CCMenuItemImage::create(
			picture,	// 正常状态下的图片
			picture);// 点击状态下的图片
		background->setPosition(ccp(0, 0));
		//取消按钮
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			"ButClose.png",	// 正常状态下的图片
			"ButClose.png",// 点击状态下的图片
			this,
			menu_selector(WinHint::BtncancelCallBack));	// 点击菜单项时，回调的函数
		btn_cancel->setPosition(ccp(0, -size.height / 5));




		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		pMenu = CCMenu::create(background, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));

		this->addChild(pMenu);

		
		char temp[6];
		sprintf(temp, "%d", Round);
		CCLabelTTF* RoundShow = CCLabelTTF::create(temp, "Arial", 35);
		RoundShow->setColor(ccc3(255, 255, 255));
		RoundShow->setPosition(ccp(size.width / 2, size.height / 2));
		this->addChild(RoundShow);

		bRet = true;
	} while (0);

	return bRet;
}

void WinHint::BtncancelCallBack(CCObject *pSender)
{
	this->setVisible(0);
}