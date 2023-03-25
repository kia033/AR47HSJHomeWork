// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 숙제 0 V
// 상하좌우로 다 움직이게 해주세요. 

// 숙제 1 V
// 잔상 지우기

// 숙제 2 V
// 화면 바깥으로 못나가게 하세요.

// 안해도 되는 숙제 
// 질문했을때 안받아줄겁니다.

// 숙제 3
// 장애물 만들고 배치하세요 당연히 플레이어는 거기로 못갑니다.

// 숙제 4
// 폭탄 f를 누를면 폭탄이 설치되고 눈에 보여야 합니다. 폭탄 @

// 숙제 5
// 일정시간이 지나고 폭탄이 터지면서
//     @
//     @
//     @
//  @@@@@@@
//     @
//     @
//     @

int main()
{
	const int ScreenYSize = 10;
	const int ScreenXSize = 10;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };



	// 정수를 정수로 나오면 실수는 버리고 정수의 값만 나옵니다.
	int PlayerY = ScreenYSize / 2; // 세로 중간
	int PlayerX = ScreenXSize / 2; // 가로  중간

	while (true)
	{
		system("cls");

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}

		Arr[PlayerY][PlayerX] = '*'; // 현재 플레이어의 위치 

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(200);
			// 일부러 멈추게 만들겁니다.
			continue; // 키를 안누르면 아래로 내려가지않는다.
		}

		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();


		// 현재 플레이어의 위치가 왼쪽 끝일때 
		// n 번째마다 
		//
		// 0 10 20 30 40 50 60 70 80 90 100 왼쪽
		// 9 19 29 39 49 59 69 79 89 99 109 오른쪽

		switch (Ch)
		{
		case 'a':
		case 'A':
			if (PlayerX != 0)
			{
				PlayerX -= 1;
			}
			break;
		case 'd':
		case 'D':
			if (PlayerX != ScreenXSize - 1)
			{
				PlayerX += 1;
			}
			break;
		case 'w':
		case 'W':
			if (PlayerY != 0)
			{
				PlayerY -= 1;
			}
			break;
		case 's':
		case 'S':
			if (PlayerY != ScreenYSize - 1)
			{
				PlayerY += 1;
			}
			break;
		default:
			break;
		}

		Sleep(200);
	}


}
