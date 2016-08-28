#pragma once
#include "CMD.h"
class ArmyCMD :
	public CMD
{
public:
	ArmyCMD();
	~ArmyCMD();
public:
	int type;
	int sec_type;
};

