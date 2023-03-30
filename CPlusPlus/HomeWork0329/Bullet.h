#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Bullet
{
public:
	Bullet();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline void SetPlayerChPos(const char _Value)
	{

		ChBullet = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Fire(); // 총알이 움직이는 부분

protected:

private:

	char ChBullet = 'w'; // 플레이어가 마지막으로 움직인 방향 // 기본값 w


	int2 Pos = int2(0,0);

};


