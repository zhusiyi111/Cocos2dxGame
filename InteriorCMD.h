#pragma once
#include"CMD.h"
class InteriorCMD : public CMD
{
public:
	InteriorCMD();
	virtual ~InteriorCMD();
public:
	int type;
	int sec_type;
};

