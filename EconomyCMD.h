#pragma once
#include "CMD.h"
class EconomyCMD :
	public CMD
{
public:
	EconomyCMD();
	~EconomyCMD();

public:
	int type;
	int sec_type;
};

