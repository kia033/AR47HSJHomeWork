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
	// �����̹Ƿ� ArrBullet�̶�� �迭�� �� �ϳ��� �����ϰ� �ȴ�.
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	// private�� �����Ƿ� �ܺο��� ������ �Ұ����ϴ�.
	// �ܺο��� ������ �Ұ����ϰ� ���ο��� �������� ���� ArrBullet�� �ּҰ��� �ް��Ͽ� 
	// GetArrBullet �̿ܿ��� bullet Ŭ������ ������ �� ����.
	Bullet();
};

