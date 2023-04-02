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

	// ���� �� üũ
	{
		NextPos = Pos;
		NextPos.X -= 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			XDir = 1; // ���������� ����.

		}
	}

	{
		NextPos = Pos;
		NextPos.X += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			XDir = -1; // �������� ����.
		}
	}
}

void Monster::YmoveEndCheck()
{
	int2 NextPos = { 0,0 };

	// ���� �� üũ
	{
		NextPos = Pos;
		NextPos.Y -= 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			YDir = 1; // �Ʒ������� ����.
		}
	}

	{
		NextPos = Pos;
		NextPos.Y += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			YDir = -1; // �������� ����.
		}
	}
}