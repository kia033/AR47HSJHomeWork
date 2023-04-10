#include "Bomb.h"
#include "../GameEngineConsole/ConsoleGameScreen.h"

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::Init()
{
	RenderChar = '@';
}

void Bomb::explogen()
{
	int2 Left = Pos;
	int2 Right = Pos;
	int2 Up = Pos;
	int2 Down = Pos;



	
	for (size_t i = 0; i < 3; i++)
	{
		Left.X -= 1;
		Right.X += 1;
		Up.Y -= 1;
		Down.Y += 1;
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Left, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Right, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Up, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Down, '@');
	}


}

void Bomb::Update()
{
	ConsoleGameObject::Update();


	if (0 >= --BoomCount)
	{
		Off();

	}
}


void Bomb::Render()
{

	RenderChar = '@';

	if (1 == BoomCount)
	{
		explogen();
	}

	ConsoleGameObject::Render();


}