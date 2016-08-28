#pragma once
#include"cocos2d.h"
USING_NS_CC;
class WinHint :public CCNode
{
public:
	WinHint();
	virtual ~WinHint();
	virtual bool init();
	static WinHint *createHint();
	static WinHint *createHint(int round);
	CREATE_FUNC(WinHint);
	void BtncancelCallBack(CCObject *pSender);

public:
	CCMenu *pMenu;
	static std::string picture;
	static int Round;
};

