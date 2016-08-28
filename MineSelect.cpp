#include "MineSelect.h"


MineSelect::MineSelect()
{
}


MineSelect::~MineSelect()
{
}

MineSelect *MineSelect::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	MineSelect *MineSelect = MineSelect::create();
	MineSelect->right_view = rightview;
	MineSelect->left_button = leftbtn;
	MineSelect->pic_background = pic_bac;
	MineSelect->button_ok = btn_ok;
	MineSelect->button_cancel = btn_can;
	MineSelect->init();
	return MineSelect;
}

bool MineSelect::init()
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
			menu_selector(MineSelect::BtnokCallBack));	// 点击菜单项时，回调的函数
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//取消按钮
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// 正常状态下的图片
			button_cancel,// 点击状态下的图片
			this,
			menu_selector(MineSelect::BtncancelCallBack));	// 点击菜单项时，回调的函数
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));



		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(MineSelect::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(-size.width / 3, size.height / 4 - 50 * i));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);



		viewi = NULL; //初始化viewi，不然下面第一次更新会报错

		bRet = true;
	} while (0);

	return bRet;
}



void MineSelect::BtnokCallBack(CCObject *pSender)
{
	
	this->removeAllChildren();
}

void MineSelect::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	ToFarmSonMenu->mine_num_select = num + 1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//右边的View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	pMenu->addChild(viewi);

	this->addChild(pMenu);
}

