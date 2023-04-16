#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;


bool ConsoleGameScreen::ScreenEndCheck()
{
	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			if (ArrScreen[y][x] == 'a')
			{
				return true;
			}
		}
	}
	return false; // a가 남아있지않다.
}

void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			ArrScreen[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", ArrScreen[y][x]);
		}
		printf_s("\n");
	}
}

ConsoleGameScreen::~ConsoleGameScreen()
{
	//for (size_t i = 0; i < Size.Y; i++)
	//{
	//	if (nullptr == ArrScreen[i])
	//	{
	//		continue;
	//	}
	//	delete[] ArrScreen[i];
	//	ArrScreen[i] = nullptr;
	//}

	//if (nullptr != ArrScreen)
	//{
	//	delete[] ArrScreen;
	//	ArrScreen = nullptr;
	//}
}

void ConsoleGameScreen::SetScreenSize(int2 _Size)
{
	this->Size = _Size;

	// ArrScreen[y][x]

	// char**
	// ArrScreen = new char* Arr[y];

	//ArrScreen = new char*[Size.Y];

	//for (size_t i = 0; i < Size.Y; i++)
	//{
	//	// ArrScreen == char**
	//	// ArrScreen[i] == char*
	//	ArrScreen[i] = new char[Size.X];
	//}

	// ArrScreen == GameEngineArray<GameEngineArray<char>>
	// ArrScreen DataType == GameEngineArray<char>
	this->ArrScreen.ReSize(Size.Y);

	for (size_t i = 0; i < Size.Y; i++)
	{
		// ArrScreen[i] == GameEngineArray<char>
		// ArrScreen[i] DataType == char
		this->ArrScreen[i].ReSize(Size.X);
	}


}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (this->Size.X <= _Pos.X)
	{
		return true;
	}

	if (this->Size.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	this->ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}



ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return this->Size;
}