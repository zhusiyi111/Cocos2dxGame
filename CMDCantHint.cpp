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

		//����
		CCMenuItemImage* background = CCMenuItemImage::create(
			picture,	// ����״̬�µ�ͼƬ
			picture);// ���״̬�µ�ͼƬ
		background->setPosition(ccp(0, 0));
		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			"ButClose.png",	// ����״̬�µ�ͼƬ
			"ButClose.png",// ���״̬�µ�ͼƬ
			this,
			menu_selector(CMDCantHint::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(0, -size.height / 5));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
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