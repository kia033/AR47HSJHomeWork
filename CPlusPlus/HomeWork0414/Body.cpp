#include "Body.h"
#include "../GameEngineBase/GameEngineRandom.h"
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Head.h"

Body::Body()
{
	RenderChar = 'i';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
}

Body::~Body()
{

}

void Body::Check()
{

	bool EndCheck = ConsoleGameScreen::GetMainScreen().ScreenEndCheck();

	if (EndCheck == false)
	{
		MsgBoxAssert("화면을 가득채워 더 이상 생성할 수 없습니다. 승리했습니다.");
		Death();
	}

	while (true)
	{
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
		SetPos({ X, Y });

		int BodyName = ConsoleGameScreen::GetMainScreen().GetArrScreen(Pos);

		if (BodyName == 'a')
		{
			break;
		}
	}

}


void Body::Update()
{
	ConsoleGameObject::Update();

}

