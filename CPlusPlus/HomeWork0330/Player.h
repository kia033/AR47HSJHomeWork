#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Bullet;
class Player
{
public:
	Player(Bullet& _Value);

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline int GetCount() const
	{
		return Count;
	}

	inline void UpCount()
	{
		Count++;
	}

	inline void InitCount()
	{
		Count = 0;
	}

	void Input();

	// �̻����� ����� ���� �̰� ��õ�Ѵ�.
	// 
	inline bool IsFire()
	{
		return Fire;
	}
	
	inline bool FireEnd()
	{
		return Fire = false;
	}

	void Shot();

	//void Test(Bullet Test) 
	//{

	//}

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	 int Count = 0;

	int2 Pos = int2(0, 0);


	Bullet* Bullet0;

	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	// Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	// Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};

