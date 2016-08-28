#include "SonMenu.h"
#include"GameScene.h"
#include "EconomyCMD.h"
#include "MineSelect.h"

FarmSonMenu::FarmSonMenu()
{

}


FarmSonMenu::~FarmSonMenu()
{
}


FarmSonMenu *FarmSonMenu::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	FarmSonMenu *FarmSonMenu = FarmSonMenu::create();
	FarmSonMenu->right_view = rightview;
	FarmSonMenu->left_button = leftbtn;
	FarmSonMenu->pic_background = pic_bac;
	FarmSonMenu->button_ok = btn_ok;
	FarmSonMenu->button_cancel = btn_can;
	FarmSonMenu->init();
	return FarmSonMenu;
}





bool FarmSonMenu::init()
{
	bool bRet = false;
	do
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//背景
		CCMenuItemImage* background = CCMenuItemImage::create(
			pic_background,	// 正常状态下的图片
			pic_background);// 点击状态下的图片	// 点击菜单项时，回调的函数

		//确定按钮
		CCMenuItemImage* btn_ok = CCMenuItemImage::create(
			button_ok,	// 正常状态下的图片
			button_ok,// 点击状态下的图片
			this,
			menu_selector(FarmSonMenu::BtnokCallBack));	// 点击菜单项时，回调的函数
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//取消按钮
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// 正常状态下的图片
			button_cancel,// 点击状态下的图片
			this,
			menu_selector(FarmSonMenu::BtncancelCallBack));	// 点击菜单项时，回调的函数
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));



		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(FarmSonMenu::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(-size.width / 3, size.height / 4 - 50 * i));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);

		btn_mineselect = NULL;
		btn_check = NULL;
		
		viewi = NULL; //初始化viewi，不然下面第一次更新会报错
		economy_cmd_type = NULL; //初始化命令代码为0

		bRet = true;
	} while (0);

	return bRet;
}



void FarmSonMenu::BtnokCallBack(CCObject *pSender)
{
	EconomyCMD cmd = EconomyCMD();
	cmd.type = economy_cmd_type;
	cmd.sec_type = 0;
	if (cmd.type == CMD_Economy_Mine)
	{
		cmd.sec_type = 0;
		cmd.sec_type = mine_num_select;
	}
	else if (cmd.type == CMD_Economy_BlackMarket)
	{
		cmd.sec_type = blackmarket_num_select;
	}
	else if (cmd.type == CMD_Economy_Market)
	{
		cmd.sec_type = market_num_select;
	}
	ToMenuLayer->SendCmd(cmd);
	this->removeAllChildren();
}



void FarmSonMenu::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);
	pMenu->removeChild(btn_mineselect, true);
	
	int num = ((CCNode*)pSender)->getTag();
	economy_cmd_type = num + 1;
	mine_num_select = 0;	//初始化矿点为0
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//右边的View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	if (economy_cmd_type == CMD_Economy_Mine)
	{
		btn_mineselect = CCMenuItemImage::create(
			"selectmine.png",	// 正常状态下的图片
			"selectmine.png",// 点击状态下的图片
			this,
			menu_selector(FarmSonMenu::BtnMineSelectCallBack));	// 点击菜单项时，回调的函数
		btn_mineselect->setPosition(ccp(0, -size.height / 3));
		pMenu->addChild(btn_mineselect);
	}
	else if (economy_cmd_type == CMD_Economy_BlackMarket)
	{
		btn_check = CCMenuItemImage::create(
			"technologycheck.png",	// 正常状态下的图片
			"technologycheck.png",// 点击状态下的图片
			this,
			menu_selector(FarmSonMenu::BlackMarketBtncheckCallBack));	// 点击菜单项时，回调的函数
		btn_check->setPosition(ccp(0, -size.height / 3));
		pMenu->addChild(btn_check);
		btn_mineselect = CCMenuItemImage::create();
		pMenu->addChild(btn_mineselect);
	}
	else if (economy_cmd_type == CMD_Economy_Market)
	{
		btn_check = CCMenuItemImage::create(
			"technologycheck.png",	// 正常状态下的图片
			"technologycheck.png",// 点击状态下的图片
			this,
			menu_selector(FarmSonMenu::MarketBtncheckCallBack));	// 点击菜单项时，回调的函数
		btn_check->setPosition(ccp(0, -size.height / 3));
		pMenu->addChild(btn_check);
		btn_mineselect = CCMenuItemImage::create();
		pMenu->addChild(btn_mineselect);
	}
	else
	{
		btn_mineselect = CCMenuItemImage::create();
		pMenu->addChild(btn_mineselect);
		btn_check = CCMenuItemImage::create();
		pMenu->addChild(btn_check);
	}
	
	
	pMenu->addChild(viewi);
	
	this->addChild(pMenu);
}

void FarmSonMenu::BtnMineSelectCallBack(CCObject *pSender)
{
	std::vector<std::string> left_btn;
	left_btn.push_back("mine_east.png");
	left_btn.push_back("mine_south.png");
	left_btn.push_back("mine_west.png");
	left_btn.push_back("mine_north.png");
	std::vector<std::string> right_view;
	right_view.push_back("mineview.png");
	right_view.push_back("mineview.png");
	right_view.push_back("mineview.png");
	right_view.push_back("mineview.png");

	mineselect = MineSelect::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	mineselect->ToFarmSonMenu = this;
	this->addChild(mineselect);
}

void FarmSonMenu::BtnMineSelectOKCallBack(CCObject* pSender)
{

	this->removeChild(ToMapLayer);
	this->removeChild(mineselect_btn_ok);
}

void FarmSonMenu::BlackMarketBtncheckCallBack(CCObject *pSender)
{
	std::vector<std::string> left_btn;
	std::vector<std::string> right_view;
	left_btn.push_back("mairushuijing.png");
	left_btn.push_back("maichushuijing.png");


	right_view.push_back("mairushuijing(heishi).png");
	right_view.push_back("maichushuijing(heishi).png");

	blackmarketselect = BlackMarketSelect::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	blackmarketselect->ToFarmSonMenu = this;
	this->addChild(blackmarketselect);


}

void FarmSonMenu::MarketBtncheckCallBack(CCObject *pSender)
{
	std::vector<std::string> left_btn;
	std::vector<std::string> right_view;
	left_btn.push_back("mairushuijing.png");
	left_btn.push_back("maichushuijing.png");


	right_view.push_back("mairushuijing(shichang).png");
	right_view.push_back("maichushuijing(shichang).png");

	marketselect = MarketSelect::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	marketselect->ToFarmSonMenu = this;
	this->addChild(marketselect);


}