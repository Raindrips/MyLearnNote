#pragma once
#include "Draw.h"
class Draw;	//��������

//������
class Factory
{

public:
	Draw* getDraw(const char *str);
};

