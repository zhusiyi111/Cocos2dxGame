#pragma once
#include"cocos2d.h"
USING_NS_CC;
class CMDCantHint:public CCNode
{
public:
	CMDCantHint();
	virtual ~CMDCantHint();
	virtual bool init();
	static CMDCantHint *createHint();
	static CMDCantHint *createHint(std::string pic);
	CREATE_FUNC(CMDCantHint);
	void BtncancelCallBack(CCObject *pSender);

public:
	CCMenu *pMenu;
	static std::string picture;
};

