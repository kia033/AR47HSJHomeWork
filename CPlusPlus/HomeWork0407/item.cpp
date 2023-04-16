#include "Item.h"
#include "../GameEngineBase/GameEngineRandom.h"
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include <iostream>
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include "GameEnum.h"

Item::Item()
{
	RenderChar = '&';
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
		SetPos({ X, Y });
}


Item::~Item()
{
}

void Item::Check()
{

	bool EndCheck = ConsoleGameScreen::GetMainScreen().ScreenEndCheck();

	if (EndCheck == false)
	{
		MsgBoxAssert("화면이 가득차서 생성할 수 없습니다.");
		Death();
	}

	while (true)
	{
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
		SetPos({ X, Y });

		int ItemName = ConsoleGameScreen::GetMainScreen().GetArrScreen(Pos);

		if (ItemName == 'a')
		{
			break;
		}
	}

}

void Item::Update()
{
	ConsoleGameObject::Update();

	std::list<ConsoleGameObject*>& PlayerGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Player);

	for (ConsoleGameObject* Ptr : PlayerGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 PlayerPos = Ptr->GetPos();

		if (Pos == PlayerPos)
		{
			Player::BombPower++;
			Death();
		}
	}

}

