#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

// 선언과 구현을 분리했다면 override를 생략한다.
void Monster::Render() /*override*/
{
	if (true == IsUpdate()) // 몬스터가 살아있을때
	{
		ConsoleGameObject::Render();
	}
	else if (0 < DeathTime)
	{
		if (DeathTime % 2) // 2로 나누어 떨어진다면 짝수 초일때 
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '@');
		}
		else // 홀수 초 일때
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '+');
		}

		--DeathTime;
	}
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}
}

void Monster::Xmove()
{
	XmoveEndCheck();
	Pos.X += XDir * 1;
}

void Monster::Ymove()
{

	YmoveEndCheck();
	Pos.Y += YDir * 1;
}

void Monster::XmoveEndCheck()
{
	int2 NextPos = { 0,0 };

	// 왼쪽 끝 체크
	{
		NextPos = Pos;
		NextPos.X -= 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			XDir = 1; // 오른쪽으로 간다.

		}
	}

	{
		NextPos = Pos;
		NextPos.X += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			XDir = -1; // 왼쪽으로 간다.
		}
	}
}

void Monster::YmoveEndCheck()
{
	int2 NextPos = { 0,0 };

	// 왼쪽 끝 체크
	{
		NextPos = Pos;
		NextPos.Y -= 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			YDir = 1; // 아래쪽으로 간다.
		}
	}

	{
		NextPos = Pos;
		NextPos.Y += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			YDir = -1; // 위쪽으로 간다.
		}
	}
}