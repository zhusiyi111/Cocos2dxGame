#include "BlackMarketSelect.h"


BlackMarketSelect::BlackMarketSelect()
{
}


BlackMarketSelect::~BlackMarketSelect()
{
}

BlackMarketSelect *BlackMarketSelect::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	BlackMarketSelect *BlackMarketSelect = BlackMarketSelect::create();
	BlackMarketSelect->right_view = rightview;
	BlackMarketSelect->left_button = leftbtn;
	BlackMarketSelect->pic_background = pic_bac;
	BlackMarketSelect->button_ok = btn_ok;
	BlackMarketSelect->button_cancel = btn_can;
	BlackMarketSelect->init();
	return BlackMarketSelect;
}

bool BlackMarketSelect::init()
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
			menu_selector(BlackMarketSelect::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(BlackMarketSelect::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));



		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(BlackMarketSelect::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(-size.width / 3, size.height / 4 - 50 * i));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);



		viewi = NULL; //��ʼ��viewi����Ȼ�����һ�θ��»ᱨ��

		bRet = true;
	} while (0);

	return bRet;
}



void BlackMarketSelect::BtnokCallBack(CCObject *pSender)
{

	this->removeAllChildren();
}

void BlackMarketSelect::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	ToFarmSonMenu->blackmarket_num_select = num + 1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//�ұߵ�View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	pMenu->addChild(viewi);

	this->addChild(pMenu);
}

