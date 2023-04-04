#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	
	void Xmove();
	void Ymove();

	void Render() override;

private:
	void XmoveEndCheck();
	void YmoveEndCheck();

private:
	int DeathTime = 4;
	int XDir = -1;
	int YDir = 1;
};

