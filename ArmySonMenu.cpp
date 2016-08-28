#include "ArmySonMenu.h"
#include "ArmyCMD.h"
#include "MenuLayer.h"

ArmySonMenu::ArmySonMenu()
{
}


ArmySonMenu::~ArmySonMenu()
{
}


ArmySonMenu *ArmySonMenu::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	ArmySonMenu *ArmySonMenu = ArmySonMenu::create();
	ArmySonMenu->right_view = rightview;
	ArmySonMenu->left_button = leftbtn;
	ArmySonMenu->pic_background = pic_bac;
	ArmySonMenu->button_ok = btn_ok;
	ArmySonMenu->button_cancel = btn_can;
	ArmySonMenu->init();
	return ArmySonMenu;
}





bool ArmySonMenu::init()
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
			menu_selector(ArmySonMenu::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(ArmySonMenu::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));



		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(ArmySonMenu::leftbtnCallBack));
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


void ArmySonMenu::BtnokCallBack(CCObject *pSender)
{
	ArmyCMD cmd = ArmyCMD();
	cmd.type = army_cmd_type;
	cmd.sec_type = 0;
	
	ToMenuLayer->SendCmd(cmd);
	this->removeAllChildren();
}



void ArmySonMenu::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	army_cmd_type = num + 1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//�ұߵ�View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));


	pMenu->addChild(viewi);

	this->addChild(pMenu);
}
