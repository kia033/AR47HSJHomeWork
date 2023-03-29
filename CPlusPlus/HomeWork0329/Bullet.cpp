#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>

Bullet::Bullet()
{
	
}
// 화면바깥으로 못나가게 하세요. 
void Bullet::Fire()
{
	if (!ChBullet)
	{
		return;
	}


	int2 NextPos = { 0, 0 };


		Sleep(InterFrame);
		//ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos(), '@');
		switch (ChBullet)
		{
		case 'a':
		case 'A':
			NextPos = Pos;
			NextPos.X -= 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.X -= 1;
			}
			break;
		case 'd':
		case 'D':
			NextPos = Pos;
			NextPos.X += 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.X += 1;
			}
			break;
		case 'w':
		case 'W':
			NextPos = Pos;
			NextPos.Y -= 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.Y -= 1;
			}
			break;
		case 's':
		case 'S':
			NextPos = Pos;
			NextPos.Y += 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.Y += 1;
			}
			break;
		default:
			break;
		}




}
