#include "MiracleBuilding.h"


MiracleBuilding::MiracleBuilding()
{
}


MiracleBuilding::~MiracleBuilding()
{
}


MiracleBuilding *MiracleBuilding::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	MiracleBuilding *MiracleBuilding = MiracleBuilding::create();
	MiracleBuilding->right_view = rightview;
	MiracleBuilding->left_button = leftbtn;
	MiracleBuilding->pic_background = pic_bac;
	MiracleBuilding->button_ok = btn_ok;
	MiracleBuilding->button_cancel = btn_can;
	MiracleBuilding->init();
	return MiracleBuilding;
}

bool MiracleBuilding::init()
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
			menu_selector(MiracleBuilding::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(MiracleBuilding::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));

		std::vector<Point> viewposition;
		viewposition.push_back(Point(-size.width * 3 / 7+30, size.height / 6));
		viewposition.push_back(Point(-size.width * 1 / 4, size.height / 6));
		viewposition.push_back(Point(-size.width * 3 / 7+30, -size.height / 6));
		viewposition.push_back(Point(-size.width * 1 / 4, -size.height / 6));


		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(MiracleBuilding::leftbtnCallBack));
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

void MiracleBuilding::BtnokCallBack(CCObject *pSender)
{
	ToInteriorSonMenu->interior_sec_kind_select = checknum;
	this->removeAllChildren();
}



void MiracleBuilding::leftbtnCallBack(CCObject *pSender)
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