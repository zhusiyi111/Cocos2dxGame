#include "InteriorTecTree.h"
#include "TechnologySonMenu.h"


InteriorTecTree::InteriorTecTree()
{
}


InteriorTecTree::~InteriorTecTree()
{
}


InteriorTecTree *InteriorTecTree::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	InteriorTecTree *InteriorTecTree = InteriorTecTree::create();
	InteriorTecTree->right_view = rightview;
	InteriorTecTree->left_button = leftbtn;
	InteriorTecTree->pic_background = pic_bac;
	InteriorTecTree->button_ok = btn_ok;
	InteriorTecTree->button_cancel = btn_can;
	InteriorTecTree->init();
	return InteriorTecTree;
}

bool InteriorTecTree::init()
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
			menu_selector(InteriorTecTree::BtnokCallBack));	// 点击菜单项时，回调的函数
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//取消按钮
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// 正常状态下的图片
			button_cancel,// 点击状态下的图片
			this,
			menu_selector(InteriorTecTree::BtncancelCallBack));	// 点击菜单项时，回调的函数
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// 创建一个菜单，菜单和场景的概念差不多，也是虚拟的东西，用来存放各种菜单项
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));

		std::vector<Point> viewposition;
		viewposition.push_back(Point(-size.width / 3, size.height / 4));
		viewposition.push_back(Point(-size.width * 2 / 5, size.height / 10));
		viewposition.push_back(Point(-size.width * 4 / 15, size.height / 10));
		viewposition.push_back(Point(-size.width * 2 / 5, -size.height / 20));
		viewposition.push_back(Point(-size.width * 4 / 15, -size.height / 20));
		viewposition.push_back(Point(-size.width * 2 / 5, -size.height / 5));
		viewposition.push_back(Point(-size.width * 4 / 15, -size.height / 5));


		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(InteriorTecTree::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(viewposition[i].x, viewposition[i].y));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);




		viewi = NULL; //初始化viewi，不然下面第一次更新会报错


		bRet = true;
	} while (0);

	return bRet;
}

void InteriorTecTree::BtnokCallBack(CCObject *pSender)
{
	ToTechnologySonMenu->technology_sec_kind_select = checknum;
	this->removeAllChildren();
}



void InteriorTecTree::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	checknum = num + 1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//右边的View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	pMenu->addChild(viewi);

	this->addChild(pMenu);
}