// HomeWork0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../GameEngineBase/GameEngineDebug.h"
#include "../GameEngineConsole/ConsoleGameScreen.h"
#include "../GameEngineConsole/ConsoleGameObject.h"
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include <conio.h>
#include "Player.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "item.h"



int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);
  
	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	ConsoleObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}


