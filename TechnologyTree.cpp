#include "TechnologyTree.h"


TechnologyTree::TechnologyTree()
{
}


TechnologyTree::~TechnologyTree()
{
}

void TechnologyTree::BtncancelCallBack(CCObject *pSender)
{
	this->removeAllChildren();
}