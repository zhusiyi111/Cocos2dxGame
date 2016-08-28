#include "TechnologyTecTree.h"
#include "TechnologySonMenu.h"


TechnologyTecTree::TechnologyTecTree()
{
}


TechnologyTecTree::~TechnologyTecTree()
{
}


TechnologyTecTree *TechnologyTecTree::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	TechnologyTecTree *TechnologyTecTree = TechnologyTecTree::create();
	TechnologyTecTree->right_view = rightview;
	TechnologyTecTree->left_button = leftbtn;
	TechnologyTecTree->pic_background = pic_bac;
	TechnologyTecTree->button_ok = btn_ok;
	TechnologyTecTree->button_cancel = btn_can;
	TechnologyTecTree->init();
	return TechnologyTecTree;
}

bool TechnologyTecTree::init()
{
	bool bRet = false;
	do
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//����
		CCMenuItemImage* background = CCMenuItemImage::create(
			pic_background,	// ����״̬�µ�ͼƬ
			pic_background);// ���״̬�µ�ͼƬ	// ����˵���ʱ���ص��ĺ���

		//ȷ����ť
		CCMenuItemImage* btn_ok = CCMenuItemImage::create(
			button_ok,	// ����״̬�µ�ͼƬ
			button_ok,// ���״̬�µ�ͼƬ
			this,
			menu_selector(TechnologyTecTree::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(TechnologyTecTree::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
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
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(TechnologyTecTree::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(viewposition[i].x, viewposition[i].y));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);




		viewi = NULL; //��ʼ��viewi����Ȼ�����һ�θ��»ᱨ��


		bRet = true;
	} while (0);

	return bRet;
}

void TechnologyTecTree::BtnokCallBack(CCObject *pSender)
{
	ToTechnologySonMenu->technology_sec_kind_select = checknum;
	this->removeAllChildren();
}



void TechnologyTecTree::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	checknum = num + 1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//�ұߵ�View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	pMenu->addChild(viewi);

	this->addChild(pMenu);
}