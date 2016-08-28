#include "MenuLayer.h"
#include"ButtomMenu.h"
#include"GameScene.h"
#include"WelcomeScene.h"
#include"SonMenu.h"
#include "Backstage.h"
#include "DataLayer.h"
#include "EconomyCMD.h"
#include "EndRoundCMD.h"
#include "InteriorCMD.h"


MenuLayer::MenuLayer()
{
}


MenuLayer::~MenuLayer()
{
}


CCLayer *MenuLayer::creatLayer(){

	MenuLayer *layer = MenuLayer::create();

	return layer;
}

bool MenuLayer::init(){
	if (!CCLayer::init())
	{
		return false;
	}

	bool bRet = false;

	do{
		//�����Ļ�ߴ�
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

		CCLabelTTF *test = CCLabelTTF::create("CSJ SB", "Arial", 30);
		CC_BREAK_IF(!test);
		test->setPosition(ccp(100, 200));
		this -> addChild(test);

		//��ũ����ã����˵�
		MenuItemImage *farmm = MenuItemImage::create("farm.png", "farm.png", this, menu_selector(MenuLayer::FarmBtnCallBack));
		farm_menu = CCMenu::create(farmm, NULL);
		farm_menu->setPosition(ccp(visibleSize.width / 4, visibleSize.height / 10));
		CC_BREAK_IF(!farm_menu);
		this->addChild(farm_menu);

		//��̫�ظ������������˵�
		MenuItemImage *neizheng = MenuItemImage::create("neizheng.png", "neizheng.png", this, menu_selector(MenuLayer::InteriorBtnCallBack));
		interior_menu = CCMenu::create(neizheng, NULL);
		interior_menu->setPosition(ccp(visibleSize.width * 5 / 12, visibleSize.height / 10));
		CC_BREAK_IF(!interior_menu);
		this->addChild(interior_menu);

		//����Ӫ�������£��˵�
		MenuItemImage *bingying = MenuItemImage::create("bingying.png", "bingying.png",this, menu_selector(MenuLayer::ArmyBtnCallBack));
		army_menu = CCMenu::create(bingying, NULL);
		army_menu->setPosition(ccp(visibleSize.width * 7 / 12, visibleSize.height / 10));
		CC_BREAK_IF(!army_menu);
		this->addChild(army_menu);

		//����ѧ�ݡ����Ƽ����˵�
		MenuItemImage *tecc = MenuItemImage::create("technology.png", "technology.png", this, menu_selector(MenuLayer::TechnologyBtnCallBack));
		technology_menu = CCMenu::create(tecc, NULL);
		technology_menu->setPosition(ccp(visibleSize.width * 3 / 4, visibleSize.height / 10));
		CC_BREAK_IF(!technology_menu);
		this->addChild(technology_menu);

		//�غ���ʾ
		round_show = CCSprite::create("bout.png");
		round_show->setPosition(ccp(visibleSize.width / 8, visibleSize.height * 8 / 9));
		CC_BREAK_IF(!round_show);
		this->addChild(round_show);

		//��ʾ��Ǯ��
		money = CCSprite::create("money1.png");
		money->setPosition(ccp(visibleSize.width / 4, visibleSize.height * 9 / 10));
		CC_BREAK_IF(!money);
		this->addChild(money);

		//��ʾʿ��ֵ
		CCSprite *army = CCSprite::create("army.png");
		army->setPosition(ccp(visibleSize.width*5/12, visibleSize.height * 9 / 10));
		CC_BREAK_IF(!army);
		this->addChild(army);

		//��ʾ����ֵ
		CCSprite *loyal = CCSprite::create("minzhong.png");
		loyal->setPosition(ccp(visibleSize.width * 7 /12 , visibleSize.height * 9 / 10));
		CC_BREAK_IF(!loyal);
		this->addChild(loyal);

		//��ʾ�ǳ�ֵ
		CCSprite *citys = CCSprite::create("chengchi.png");
		citys->setPosition(ccp(visibleSize.width * 3 / 4, visibleSize.height * 9 / 10));
		CC_BREAK_IF(!citys);
		this->addChild(citys);

		//��ʾˮ��ֵ
		CCSprite *crystal = CCSprite::create("shuijing.png");
		crystal->setPosition(ccp(visibleSize.width * 11 / 12, visibleSize.height * 9 / 10));
		CC_BREAK_IF(!crystal);
		this->addChild(crystal);

		//δ�����������������ʾ
		cmdhint = CMDCantHint::createHint();
		cmdhint->setVisible(0);
		addChild(cmdhint);

		//���غϽ�������ť
		MenuItemImage *end_roundd = MenuItemImage::create("end_round.png", "end_round.png", this, menu_selector(MenuLayer::EndroundBtnCallBack));
		end_round = CCMenu::create(end_roundd, NULL);
		end_round->setPosition(ccp(visibleSize.width * 9 / 10, visibleSize.height / 10));
		CC_BREAK_IF(!end_round);
		this->addChild(end_round);

		bRet = true;
	} while (0);

	return bRet;

}


void MenuLayer::CloseButtonCallBack(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::createScene());
}

void MenuLayer::FarmBtnCallBack(CCObject* pSender)
{
	std::vector<std::string> left_btn;
	left_btn.push_back("caikuang.png");
	left_btn.push_back("zhengshui.png");
	left_btn.push_back("maoyi.png");
	left_btn.push_back("xunbao.png");
	left_btn.push_back("shichang.png");
	left_btn.push_back("heishi.png");

	std::vector<std::string> right_view;
	right_view.push_back("caikuangview.png");
	right_view.push_back("zhengshuiview.png");
	right_view.push_back("maoyiview.png");
	right_view.push_back("xunbaoview.png");
	right_view.push_back("shichangview.png");
	right_view.push_back("heishiview.png");

	FarmSon = FarmSonMenu::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	FarmSon->ToMenuLayer = this;
	this->addChild(FarmSon);
}


void MenuLayer::InteriorBtnCallBack(CCObject* pSender)
{
	std::vector<std::string> left_btn;
	left_btn.push_back("HelpPeople.png");
	left_btn.push_back("fangzai.png");
	left_btn.push_back("dashetianxia.png");
	left_btn.push_back("jianzaoqiji.png");

	std::vector<std::string> right_view;
	right_view.push_back("HelpPeopleView.png");
	right_view.push_back("fangzaiview.png");
	right_view.push_back("dashetianxiaview.png");
	right_view.push_back("jianzaoqijiview.png");

	InteriorSon = InteriorSonMenu::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	InteriorSon->ToMenuLayer = this;
	this->addChild(InteriorSon);
}

void MenuLayer::ArmyBtnCallBack(CCObject* pSender)
{
	std::vector<std::string> left_btn;
	left_btn.push_back("zhengbing.png");
	left_btn.push_back("zhimin.png");
	left_btn.push_back("zhujun.png");


	std::vector<std::string> right_view;
	right_view.push_back("zhengbingview.png");
	right_view.push_back("zhiminview.png");
	right_view.push_back("zhujunview.png");

	ArmySon = ArmySonMenu::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	ArmySon->ToMenuLayer = this;
	this->addChild(ArmySon);
}


void MenuLayer::TechnologyBtnCallBack(CCObject* pSender)
{
	std::vector<std::string> left_btn;
	left_btn.push_back("economytec.png");
	left_btn.push_back("interiortec.png");
	left_btn.push_back("armytec.png");
	left_btn.push_back("technologytec.png");


	std::vector<std::string> right_view;
	right_view.push_back("economyview.png");
	right_view.push_back("interiorview.png");
	right_view.push_back("armyview.png");
	right_view.push_back("technologyview.png");

	TechnologySon = TechnologySonMenu::create("sonback.png", "ButtonOK.png", "ButClose.png", left_btn, right_view);
	TechnologySon->ToMenuLayer = this;
	this->addChild(TechnologySon);
}

void MenuLayer::EndroundBtnCallBack(CCObject* pSender)
{
	EndRoundCMD cmd = EndRoundCMD();
	SendCmd(cmd);
}

//���;�����������
void MenuLayer::SendCmd(EconomyCMD cmd)
{
	ToCmdLayer->ReceiveCMD(cmd);
}

//����������������
void MenuLayer::SendCmd(InteriorCMD cmd)
{
	ToCmdLayer->ReceiveCMD(cmd);
}

//���;�����������
void MenuLayer::SendCmd(ArmyCMD cmd)
{
	ToCmdLayer->ReceiveCMD(cmd);
}

//���ͿƼ���������
void MenuLayer::SendCmd(TechnologyCMD cmd)
{
	ToCmdLayer->ReceiveCMD(cmd);
}

//���ͻغϽ�����������
void MenuLayer::SendCmd(EndRoundCMD cmd)
{
	ToCmdLayer->ReceiveCMD(cmd);
}


void MenuLayer::ShowFalseNum(int val)	//�ɴ��������ʾ������Ϣ
{
	switch (val)
	{
	case 1:
		cmdhint = CMDCantHint::createHint();
		break;
	case 2:
		cmdhint = CMDCantHint::createHint("zhixingguo.png");
		break;
	case 3:
		cmdhint = CMDCantHint::createHint("yijingyoutec.png");
		break;
	case 999:
		cmdhint = CMDCantHint::createHint("weikaitong.png");
		break;
	default:
		break;
	}
	cmdhint->setVisible(1);
	this->addChild(cmdhint);

		 
}