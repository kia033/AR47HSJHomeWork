#pragma once
#include "ConsoleGameObject.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet : public ConsoleGameObject
{
public:
	static const int ArrBulletCount = 10;

	static Bullet* GetArrBullet() 
	{
		return ArrBullet;
	}

	static void AllOff();
	static void AllRender();
	static void AllUpdate();

	void Update();

protected:

private:
	// 전역이므로 ArrBullet이라는 배열은 단 하나만 존재하게 된다.
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	// private에 있으므로 외부에서 생성이 불가능하다.
	// 외부에서 생성이 불가능하고 내부에서 전역으로 만든 ArrBullet의 주소값만 받게하여 
	// GetArrBullet 이외에는 bullet 클래스에 접근할 수 없다.
	Bullet();
};

