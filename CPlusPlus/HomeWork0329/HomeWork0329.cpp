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
		system("cls"); // 화면을 지운다

		ConsoleGameScreen::GetMainScreen().ScreenClear();       // 움직일 수 있는 공간을 a로 채운다.

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');  // 플레이어의 위치는 *로 표기
		if (NewPlayer.IsFire())  // 플레이어가 총을 쏜 상태라면
		{
			NewPlayer.Shot(); // 총알을 이동
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBullet.GetPos(), '@'); // 총알의 위치는 @로 표기
			NewPlayer.UpCount(); // 총알 타이머 카운트

			if (NewPlayer.GetCount() >= 4) // 4번 움직이면
			{
				NewPlayer.InitCount(); // 카운트 초기화
				NewPlayer.FireEnd();  // 총 발사 종료
			}
		}
		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();





	}
}
