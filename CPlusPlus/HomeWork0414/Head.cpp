#include "Head.h"
#include <conio.h>
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Body.h"
#include "Parts.h"
#include <vector>

bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = 'O';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());


}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& TailGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Tail);

	std::list<ConsoleGameObject*>::iterator Start = TailGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = TailGroup.end();

	for (; Start != End; ++Start)
	{
		ConsoleGameObject* Object = *Start;

		if (nullptr == Object || false == Object->IsUpdate())
		{
			continue;
		}

		PrevPos = Object->GetPos();
		Object->SetPos(NextPos);
		NextPos = PrevPos;


	}

}

void Head::NewBodyCreateCheck()
{


	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* Ptr : BodyGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = Ptr->GetPos();

		if (Pos == BodyPos)
		{
			Ptr->Death();
			//ConsoleObjectManager::CreateConsoleObject<Parts>(ObjectOrder::Tail);
			Body* NewBody = ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
			NewBody->Check();
			Tail = true;

		}
	}
}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
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

	int2 NextPos = Pos;

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


	SetPos(GetPos() + Dir);
	if (Tail == true)
	{
		IsBodyCheck();
	}

	NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}
