#include "SonMenu.h"
#include"GameScene.h"
#include "InteriorSonMenu.h"
#include"InteriorCMD.h"
#include "MiracleBuilding.h"



InteriorSonMenu::InteriorSonMenu()
{

}


InteriorSonMenu::~InteriorSonMenu()
{
}


InteriorSonMenu *InteriorSonMenu::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	InteriorSonMenu *InteriorSonMenu = InteriorSonMenu::create();
	InteriorSonMenu->right_view = rightview;
	InteriorSonMenu->left_button = leftbtn;
	InteriorSonMenu->pic_background = pic_bac;
	InteriorSonMenu->button_ok = btn_ok;
	InteriorSonMenu->button_cancel = btn_can;
	InteriorSonMenu->init();
	return InteriorSonMenu;
}





bool InteriorSonMenu::init()
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
			menu_selector(InteriorSonMenu::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(InteriorSonMenu::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));




		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));


		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(InteriorSonMenu::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(-size.width / 3, size.height / 4 - 50 * i));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);

		btn_check = NULL;

		viewi = NULL; //��ʼ��viewi����Ȼ�����һ�θ��»ᱨ��
		interior_cmd_type = NULL; //��ʼ���������Ϊ0

		bRet = true;
	} while (0);

	return bRet;
}



void InteriorSonMenu::BtnokCallBack(CCObject *pSender)
{
	InteriorCMD cmd = InteriorCMD();
	cmd.type = interior_cmd_type;
	cmd.sec_type = interior_sec_kind_select;
	ToMenuLayer->SendCmd(cmd);
	this->removeChild(pMenu);
}



void InteriorSonMenu::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);
	pMenu->removeChild(btn_check, true);

	int num = ((CCNode*)pSender)->getTag();
	interior_cmd_type = num + 1;
	interior_sec_kind_select = 0;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//�ұߵ�View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));

	if (interior_cmd_type == CMD_Interior_BuildMiracle)
	{
		btn_check = CCMenuItemImage::create(
			"technologycheck.png",	// ����״̬�µ�ͼƬ
			"technologycheck.png",// ���״̬�µ�ͼƬ
			this,
			menu_selector(InteriorSonMenu::BtncheckCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_check->setPosition(ccp(0, -size.height / 3));
		pMenu->addChild(btn_check);
	}
	else
	{
		btn_check = CCMenuItemImage::create();
		pMenu->addChild(btn_check);
	}

	pMenu->addChild(viewi);

	this->addChild(pMenu);
}

void InteriorSonMenu::BtncheckCallBack(CCObject *pSender)
{
	std::vector<std::string> left_btn;
	std::vector<std::string> right_view;
	left_btn.push_back("jinzita.png");
	left_btn.push_back("jurenxiang.png");
	left_btn.push_back("bingmayong.png");
	left_btn.push_back("kongzhonghuayuan.png");

	right_view.push_back("jinzitaview.png");
	right_view.push_back("jurenxiangview.png");
	right_view.push_back("bingmayongview.png");
	right_view.push_back("kongzhonghuayuanview.png");

	miracle_building = MiracleBuilding::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	miracle_building->ToInteriorSonMenu = this;
	this->addChild(miracle_building);


}