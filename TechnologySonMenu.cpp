#include "TechnologySonMenu.h"
#include"MenuLayer.h"


TechnologySonMenu::TechnologySonMenu()
{
}


TechnologySonMenu::~TechnologySonMenu()
{
}


TechnologySonMenu *TechnologySonMenu::create(std::string pic_bac, std::string btn_ok, std::string btn_can, std::vector<std::string> leftbtn, std::vector<std::string> rightview)
{

	TechnologySonMenu *TechnologySonMenu = TechnologySonMenu::create();
	TechnologySonMenu->right_view = rightview;
	TechnologySonMenu->left_button = leftbtn;
	TechnologySonMenu->pic_background = pic_bac;
	TechnologySonMenu->button_ok = btn_ok;
	TechnologySonMenu->button_cancel = btn_can;
	TechnologySonMenu->init();
	return TechnologySonMenu;
}





bool TechnologySonMenu::init()
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
			menu_selector(TechnologySonMenu::BtnokCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_ok->setPosition(ccp(size.width / 6, -size.height / 3));

		//ȡ����ť
		CCMenuItemImage* btn_cancel = CCMenuItemImage::create(
			button_cancel,	// ����״̬�µ�ͼƬ
			button_cancel,// ���״̬�µ�ͼƬ
			this,
			menu_selector(TechnologySonMenu::BtncancelCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_cancel->setPosition(ccp(size.width / 3, -size.height / 3));

		//�鿴��ť
		CCMenuItemImage* btn_check = CCMenuItemImage::create(
			"technologycheck.png",	// ����״̬�µ�ͼƬ
			"technologycheck.png",// ���״̬�µ�ͼƬ
			this,
			menu_selector(TechnologySonMenu::BtncheckCallBack));	// ����˵���ʱ���ص��ĺ���
		btn_check->setPosition(ccp(0, -size.height / 3));


		// ����һ���˵����˵��ͳ����ĸ����࣬Ҳ������Ķ�����������Ÿ��ֲ˵���
		pMenu = CCMenu::create(background, btn_ok, btn_cancel, btn_check, NULL);
		pMenu->setPosition(ccp(size.width / 2, size.height / 2));


		for (int i = 0; i < left_button.size(); i++)
		{
			CCMenuItemImage *menui = CCMenuItemImage::create(left_button[i], left_button[i], this, menu_selector(TechnologySonMenu::leftbtnCallBack));
			menui->setTag(i);
			menui->setPosition(ccp(-size.width / 3, size.height / 4 - 50 * i));
			pMenu->addChild(menui);

		}
		this->addChild(pMenu);


		viewi = NULL; //��ʼ��viewi����Ȼ�����һ�θ��»ᱨ��
		technology_cmd_type = NULL; //��ʼ���������Ϊ0

		bRet = true;
	} while (0);

	return bRet;
}



void TechnologySonMenu::BtnokCallBack(CCObject *pSender)
{
	TechnologyCMD cmd = TechnologyCMD();
	cmd.type = technology_cmd_type;
	cmd.sec_type = technology_sec_kind_select;
	ToMenuLayer->SendCmd(cmd);
	this->removeAllChildren();
	
}



void TechnologySonMenu::leftbtnCallBack(CCObject *pSender)
{
	this->removeChild(pMenu);

	pMenu->removeChild(viewi, true);

	int num = ((CCNode*)pSender)->getTag();
	technology_cmd_type = num + 1;
	technology_sec_kind_select = 0;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//�ұߵ�View
	viewi = CCMenuItemImage::create(right_view[num], right_view[num]);
	viewi->setPosition(ccp(size.width / 7, 0));



	pMenu->addChild(viewi);

	this->addChild(pMenu);
}

void TechnologySonMenu::BtncheckCallBack(CCObject *pSender)
{
	std::vector<std::string> left_btn;
	std::vector<std::string> right_view;
	switch (technology_cmd_type)
	{
	case 1:			//�������Ӳ˵�
		
		left_btn.push_back("tuntian.png");
		left_btn.push_back("jinlian.png");
		left_btn.push_back("shichangjiaoyi.png");
		left_btn.push_back("kantanjishu.png");
		left_btn.push_back("shuifa.png");
		left_btn.push_back("fanrong.png");

		
		right_view.push_back("tuntianview.png");
		right_view.push_back("jinlianview.png");
		right_view.push_back("shichangjiaoyiview.png");
		right_view.push_back("kantanjishuview.png");
		right_view.push_back("shuifaview.png");
		right_view.push_back("fanrongview.png");



		economy_tec_tree = EconomyTecTree::create("sonbackeconomy.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
		economy_tec_tree->ToTechnologySonMenu = this;
		this->addChild(economy_tec_tree);
		break;

	case 2:			//�������Ӳ˵�
		left_btn.push_back("chengbangzhi.png");
		left_btn.push_back("zhuanzhi.png");
		left_btn.push_back("minzhuzhi.png");
		left_btn.push_back("junzhuzhi.png");
		left_btn.push_back("gonghezhi.png");
		left_btn.push_back("zibenzhuyi.png");
		left_btn.push_back("shehuizhuyi.png");

		right_view.push_back("chengbangzhiview.png");
		right_view.push_back("zhuanzhiview.png");
		right_view.push_back("minzhuzhiview.png");
		right_view.push_back("junzhuzhiview.png");
		right_view.push_back("gonghezhiview.png");
		right_view.push_back("zibenzhuyiview.png");
		right_view.push_back("shehuizhuyiview.png");

		interior_tec_tree = InteriorTecTree::create("sonbackinterior.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
		interior_tec_tree->ToTechnologySonMenu = this;
		this->addChild(interior_tec_tree);
		break;

	case 3:						//�������Ӳ˵�
		left_btn.push_back("minbingyi.png");
		left_btn.push_back("guyongbingzhi.png");
		left_btn.push_back("changbeijun.png");
		left_btn.push_back("baolei.png");
		left_btn.push_back("quanminjiebing.png");
		left_btn.push_back("jiandie.png");

		right_view.push_back("minbingyiview.png");
		right_view.push_back("guyongbingzhiview.png");
		right_view.push_back("changbeijunview.png");
		right_view.push_back("baoleiview.png");
		right_view.push_back("quanminjiebingview.png");
		right_view.push_back("jiandieview.png");

		army_tec_tree = ArmyTecTree::create("sonbackarmy.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
		army_tec_tree->ToTechnologySonMenu = this;
		this->addChild(army_tec_tree);
		break;

	case 4:						//�Ƽ����Ӳ˵�
		left_btn.push_back("shuxue.png");
		left_btn.push_back("wulixue.png");
		left_btn.push_back("shengwuxue.png");
		left_btn.push_back("dianzixue.png");
		left_btn.push_back("huaxue.png");
		left_btn.push_back("chaojijisuanji.png");

		right_view.push_back("shuxueview.png");
		right_view.push_back("wulixueview.png");
		right_view.push_back("shengwuxueview.png");
		right_view.push_back("dianzixueview.png");
		right_view.push_back("huaxueview.png");
		right_view.push_back("chaojijisuanjiview.png");

		technology_tec_tree = TechnologyTecTree::create("sonbacktechnology.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
		technology_tec_tree->ToTechnologySonMenu = this;
		this->addChild(technology_tec_tree);
		break;

	}
}