#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include "ConsoleObjectManager.h"
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
	GameEngineArray<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	

	for (size_t i = 0; i < BombGroup.Count(); i++)
	{
		if (nullptr == BombGroup[i])
		{
			continue;
		}

		int2 BombPos = BombGroup[i]->GetPos();

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
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			if (true == IsBomb(NextPos))
			{
				Pos.X -= 1;
			}

		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			if (true == IsBomb(NextPos))
			{
				Pos.X += 1;
			}
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			if (true == IsBomb(NextPos))
			{
				Pos.Y -= 1;
			}
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			if (true == IsBomb(NextPos))
			{
				Pos.Y += 1;
			}
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

