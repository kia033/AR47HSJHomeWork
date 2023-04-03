#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({2+i, i});
	}

}

void ShootingGame::Collision()
{

	// BulletArr는 생성한 총알의 주소값을 갖게 된다
	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알을  0부터 체크한다.
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// CurBullet 은 BulletIndex 번째에 해당하는 총알이다.
		Bullet& CurBullet = BulletArr[BulletIndex];
		
		// 총알이 발사되어 UpdateValue의 값이 true인지 체크한다.
		// 발사되었다면 true, 발사되지 않았다면 false이다.
		// 만약 총알이 발사되지 않았다면 continue한다.
		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		// 여기까지 왔다면 해당 총알은 true로 발사된 상태이다.
		// 몬스터를 0부터 체크한다.
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			//  CurMonster 는 MonsterIndex 번째의 몬스터이다.
			Monster& CurMonster = ArrMonster[MonsterIndex];

			// 몬스터가 출력되고 있는지 체크한다.
			// 몬스터가 죽어서 출력되고있지 않는다면
			// continue한다.
			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			// 여기까지 왔다면 몬스터도 true이다.
			// 출력된 상태의 총알과 몬스터의 위치가 동일하다면
			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				// 총알과 몬스터의 출력을 false로 바꾼다. / 없앤다.
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

		// 캐릭터 위치에 글자를 하나 띄운다.
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