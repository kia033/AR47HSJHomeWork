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

	void Fire(); // �Ѿ��� �����̴� �κ�

protected:

private:

	char ChBullet = 'w'; // �÷��̾ ���������� ������ ���� // �⺻�� w


	int2 Pos = int2(0,0);

};


