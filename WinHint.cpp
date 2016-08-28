#include "WinHint.h"

std::string WinHint::picture = "";
int WinHint::Round = 0;
WinHint::WinHint()
{
}


WinHint::~WinHint()
{
}

WinHint *WinHint::createHint()
{
	WinHint::picture = "winhint.png";
	WinHint *layer = WinHint::create();

	return layer;
}

WinHint *WinHint::createHint(int round)
{
	WinHint::Round = round;
	WinHint::picture = "winhint.png";
	WinHint *layer = WinHint::create();

	return layer;
}

bool WinHint::init()
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
			menu_selector(WinHint::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(0, -size.height / 5));




		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_cancel, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));

		this->addChild(pMenu);

		
		char temp[6];
		sprintf(temp, "%d", Round);
		CCLabelTTF* RoundShow = CCLabelTTF::create(temp, "Arial", 35);
		RoundShow->setColor(ccc3(255, 255, 255));
		RoundShow->setPosition(ccp(size.width / 2, size.height / 2));
		this->addChild(RoundShow);

		bRet = true;
	} while (0);

	return bRet;
}

void WinHint::BtncancelCallBack(CCObject *pSender)
{
	this->setVisible(0);
}