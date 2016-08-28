#include "SonMenu.h"
#include"GameScene.h"

SonMenu::SonMenu()
{

}


SonMenu::~SonMenu()
{
}

void SonMenu::BtncancelCallBack(CCObject *pSender)
{
	this->removeAllChildren();
}


