#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}
// ȭ��ٱ����� �������� �ϼ���. 

bool Player::IsBomb(int2 _NextPos)
{
	// ��ź�� ��ġ�Ǿ��ٸ� ������ϰ� ������������.
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);


	// Ranged for ��� �����̿���

	// ������������. ���ο��� ������ ������ �ٲ�� �ൿ�� �ϸ� �ȵǿ�.
	// push_back
	// push_front
	// erase

	for (ConsoleGameObject* Ptr : BombGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BombPos = Ptr->GetPos();

		if (BombPos == _NextPos)
		{
			return false;
		}
	}


	return true;
}


void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		Sleep(200);

		// ��ź��ġ
		break;
	}
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && true == IsBomb(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && true == IsBomb(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && true == IsBomb(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && true == IsBomb(NextPos))
		{
			Pos.Y += 1;

		}
		break;
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}

}

