// 016_ArraryToString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
   // 어떤 자료형을 봤다면 그것은 추가적인 문법으로
	// 모두 다 배열이 될 수 있다.
	
	{
		int Value1 = 10;
		int Value2 = 10;

	}
	{
		// 자동으로 전부 다 0으로 초기화된다.
		int ArrValue[5] = {};

		int ArrValue2[5] = {0, };

		// 제로베이스 
		//                  1  2  3  4  5
		int ArrValue3[5] = {0, 1, 2, 3, 4};

		// 2, 0, 0, 0, 0
		int ArrValue4[5] = { 2, };

		int  a = 0;
	}

	{
		// 초기화는 꼭 해야한다.
		bool ArrValue[5] = {};

		bool ArrValue2[5] = {true, };


		// 제로베이스 
		//                  1		  2		3	   4		5
		bool ArrValue3[5] = { false, true, true , false, true };

		bool ArrValue4[5] = { true, };
		bool a = 0;
	}


	// 문법적으로 정해졌다. 문자의 배열은 축약형 표현을 사용할 수 있다.
	// 추가적인 규칙이 있다.
	{
	
		char ArrValue1[5] = {'a', 'b', 'c'};

		char ArrValue2[5] = "abc";

	
 		bool a = 0;

		// 모든 이름은 시작위치를 표현하게 된다.
		// => 자료형을 선언하고 그 뒤에 이름을 붙였다. 
		// [] <=  랜덤 인덱스 연산자
		ArrValue2[0];


		// V <= 이런 이름은 무조건 메모리의 시작 위치를 표현하게 된다.
		char V;

		// V[0]
		// 배열의 경우에는 랜덤 인덱스 연산자를 통해서
		// ArrValue2 가 100번지라고 하면
		// ArrValue2[정수]
		// ArrValue2 시작위치 + (sizeof(자료형) * 정수)
		// ArrValue2[3];
		// ArrValue2 == 100번지
		// 100+ sizeof(char) * 3
		// 100 + 1 * 3
		// 103

		char ArrTest[10] = "abcdefghi";
		//char GetValue = ArrTest[0];
		char GetValue = ArrTest[0];

	}
}

