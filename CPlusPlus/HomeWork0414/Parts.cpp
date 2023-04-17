#include "Parts.h"
#include "../GameEngineConsole/ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Body.h"

Parts::Parts()
{
	RenderChar = 'o';
}

Parts::~Parts()
{
}

void Parts::Update()
{
	ConsoleGameObject::Update();
}