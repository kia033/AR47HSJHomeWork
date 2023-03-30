#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player(Bullet& _Value)
{
	Bullet0 = &_Value;
}
// 화면바깥으로 못나가게 하세요. 
void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5초간 멈춘다.
		Sleep(InterFrame);
		// 일부러 멈추게 만들겁니다.
		// continue; 반복문 내부에서만 사용가능
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
			if (!Fire)
			{
				Bullet0->SetPlayerChPos(Ch); // 플레이어가 움직인 방향을 총알에 전달.
			}

		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;			
			if (!Fire)
			{
				Bullet0->SetPlayerChPos(Ch); // 플레이어가 움직인 방향을 총알에 전달.
			}

		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
			if (!Fire)
			{
				Bullet0->SetPlayerChPos(Ch); // 플레이어가 움직인 방향을 총알에 전달.
			}

		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
			if (!Fire)
			{
				Bullet0->SetPlayerChPos(Ch); // 플레이어가 움직인 방향을 총알에 전달.
			}

		}
		break;
	case 'f':
	case 'F':
		if (!IsFire()) // 총을 쏜 상태가 아니라면 
		{
			Fire = true;
			Bullet0->SetPos(Pos); // 현재 플레이어의 위치가 총알의 시작 위치
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}

void Player::Shot()
{
	if (!Fire)
	{
		return;
	}

	Bullet0->Fire();



}
