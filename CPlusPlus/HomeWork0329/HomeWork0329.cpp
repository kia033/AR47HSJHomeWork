// HomeWork0329.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

int main()
{
	// 오늘의 숙제입니다.
	// 총알 1발을 발사하세요.
	// 방향 상관 없음.
	// 총알 클래스를 만든다.
	// 플레이어가 여러분들이 지정한 키를 누르르면 
	// 3번 움직이고 해제

	Bullet NewBullet = Bullet();
	Player NewPlayer = Player(NewBullet);
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');
		if (NewPlayer.IsFire() && NewPlayer.GetCount() < 4)
		{
			NewPlayer.Shot();
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBullet.GetPos(), '@');
			NewPlayer.UpCount();

			if (NewPlayer.GetCount() >= 4)
			{
				NewPlayer.InitCount();
				NewPlayer.FireEnd();
			}
		}
		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();





	}
}
