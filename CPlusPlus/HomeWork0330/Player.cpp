#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"
#include <iostream>

int Player::FireCount = Bullet::ArrBulletCount;

Player::Player()
{

}
// ȭ��ٱ����� �������� �ϼ���. 
void Player::Input()
{
	printf_s("\n");
	printf_s("�Ѿ� : %d / %d", Player::FireCount, Bullet::ArrBulletCount);

	if (0 == _kbhit())
	{
		// 0.5�ʰ� �����.
		Sleep(InterFrame);
		// �Ϻη� ���߰� ����̴ϴ�.
		// continue; �ݺ��� ���ο����� ��밡��
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
	case 'f':
	case 'F':
		if (FireCount >  0)
		{
			BulletPtr[FireCount - 1].SetPos(Pos);
			BulletPtr[FireCount - 1].FireOn();
			FireCount--;
		}
		break;
	/*case 'r': // �Ѿ� ä���ֱ�
	case 'R':
		FireCount = Bullet::ArrBulletCount;
		break;*/
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}