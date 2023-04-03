#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	
	void Xmove();
	void Ymove();

private:
	void XmoveEndCheck();
	void YmoveEndCheck();

private:
	int XDir = -1;
	int YDir = 1;
};

