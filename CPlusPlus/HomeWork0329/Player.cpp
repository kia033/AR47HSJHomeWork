#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player(Bullet& _Value)
{
	Bullet0 = &_Value;
}
// ȭ��ٱ����� �������� �ϼ���. 
void Player::Input()
{
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
			if (!Fire)
			{
				Bullet0->SetPlayerChPos(Ch); // �÷��̾ ������ ������ �Ѿ˿� ����.
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
				Bullet0->SetPlayerChPos(Ch); // �÷��̾ ������ ������ �Ѿ˿� ����.
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
				Bullet0->SetPlayerChPos(Ch); // �÷��̾ ������ ������ �Ѿ˿� ����.
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
				Bullet0->SetPlayerChPos(Ch); // �÷��̾ ������ ������ �Ѿ˿� ����.
			}

		}
		break;
	case 'f':
	case 'F':
		if (!IsFire()) // ���� �� ���°� �ƴ϶�� 
		{
			Fire = true;
			Bullet0->SetPos(Pos); // ���� �÷��̾��� ��ġ�� �Ѿ��� ���� ��ġ
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
