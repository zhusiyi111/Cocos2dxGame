#include "CMDCantHint.h"

std::string CMDCantHint::picture = "";
CMDCantHint::CMDCantHint()
{
}


CMDCantHint::~CMDCantHint()
{
}

CMDCantHint *CMDCantHint::createHint()
{
	CMDCantHint::picture = "cmdcant.png";
	CMDCantHint *layer = CMDCantHint::create();

	return layer;
}

CMDCantHint *CMDCantHint::createHint(std::string pic)
{
	CMDCantHint::picture = pic;
	CMDCantHint *layer = CMDCantHint::create();

	return layer;
}

bool CMDCantHint::init()
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
			menu_selector(CMDCantHint::BtncancelCallBack));	// 点击菜单项时，回调的函数
		btn_cancel->setPosition(ccp(0, -size.height / 5));


		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		pMenu = CCMenu::create(background, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));

		this->addChild(pMenu);
		bRet = true;
	} while (0);

	return bRet;
}

void CMDCantHint::BtncancelCallBack(CCObject *pSender)
{
	this->setVisible(0);
}