#include "Head.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <list>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>

bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	for (ConsoleGameObject* BodyPtr : BombGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("�ٵ�׷� �ʿ� �ٵ� �ƴ� ��ü�� ����־����ϴ�.");
				return;
			}

			Parts* Last = GetLast(); // �ǳ��� �ּҸ� ã�´�.

			//int2 PrevPos = GetPrevPos();
			//BodyPart->SetPos(PrevPos);
			// ??BodyPart
			Last->SetNext(BodyPart); // ������ �������� ��ġ�Ѵ�.
			NewBodyCreateCheck();
			return;
		}
	}
}

void Head::NewBodyCreateCheck()
{

	Body* BodyPtr = ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);

	while (true)
	{
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
		BodyPtr->SetPos({ X, Y });
		EndCheck();

		int2 BodyPos = BodyPtr->GetPos();
		int BodyName = ConsoleGameScreen::GetMainScreen().GetArrScreen(BodyPos);

		if (BodyName == 'a')
		{
			break;
		}
	}

}

void Head::EndCheck()
{
	bool EndCheck = ConsoleGameScreen::GetMainScreen().ScreenEndCheck();

	if (EndCheck == false)
	{
		MsgBoxAssert("�¸�");
		IsPlay = false;
	}
}
 
// ȭ��ٱ����� �������� �ϼ���. 
void Head::Update()
{

	this;

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
	
	

	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		// NewBodyCreateCheck();
		
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	// ���� �̷��� �������ٰ� ġ�ڽ��ϴ�.



	SetPos(GetPos() + Dir);
	IsBodyCheck();

	NextMove();

	//Parts* CurPart = this;
	//while (true)
	//{
	//	Parts* Next = CurPart->GetNext();

	//	if (nullptr == Next)
	//	{
	//		break;
	//	}

	//	Next->SetPos(CurPart->GetPrevPos());
	//	CurPart = CurPart->GetNext();
	//}


	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}





}
