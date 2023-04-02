#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}

	Xmove();
	Ymove();
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