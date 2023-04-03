#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({2+i, i});
	}

}

void ShootingGame::Collision()
{

	// BulletArr�� ������ �Ѿ��� �ּҰ��� ���� �ȴ�
	Bullet* BulletArr = Bullet::GetArrBullet();

	// ��� �Ѿ���  0���� üũ�Ѵ�.
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// CurBullet �� BulletIndex ��°�� �ش��ϴ� �Ѿ��̴�.
		Bullet& CurBullet = BulletArr[BulletIndex];
		
		// �Ѿ��� �߻�Ǿ� UpdateValue�� ���� true���� üũ�Ѵ�.
		// �߻�Ǿ��ٸ� true, �߻���� �ʾҴٸ� false�̴�.
		// ���� �Ѿ��� �߻���� �ʾҴٸ� continue�Ѵ�.
		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		// ������� �Դٸ� �ش� �Ѿ��� true�� �߻�� �����̴�.
		// ���͸� 0���� üũ�Ѵ�.
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			//  CurMonster �� MonsterIndex ��°�� �����̴�.
			Monster& CurMonster = ArrMonster[MonsterIndex];

			// ���Ͱ� ��µǰ� �ִ��� üũ�Ѵ�.
			// ���Ͱ� �׾ ��µǰ����� �ʴ´ٸ�
			// continue�Ѵ�.
			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			// ������� �Դٸ� ���͵� true�̴�.
			// ��µ� ������ �Ѿ˰� ������ ��ġ�� �����ϴٸ�
			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				// �Ѿ˰� ������ ����� false�� �ٲ۴�. / ���ش�.
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	for (size_t i = 1; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].Xmove();
	}
	ArrMonster[0].Ymove();
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}