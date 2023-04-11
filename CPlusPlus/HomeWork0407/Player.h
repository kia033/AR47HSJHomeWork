#pragma once
#include "../GameEngineConsole/ConsoleGameObject.h"


class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;

	bool IsBomb(int2 _NextPos);


private:
	int BombPower = 5;

};

