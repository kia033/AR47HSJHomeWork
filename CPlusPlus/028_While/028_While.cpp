
#include <iostream>

int main()
{
   // 반복문중 while을 사용합니다.

	// while (메모리영역, 조건문)
	// {
	//		// 실핼코드
	// 
	// 
	// }

	// 조건문
	// 실행코드

	
	// while (내부에는 , 를 통해서 여러가지 조건을 넣을 수 있습니다.)
	// 가장 무조건 오른쪽에 있는 , 의 메모리 영역의 값만을 조건으로 칩니다.

	// while ( 특정 메모리여역이 참인가 거짓인가)

	{

		int Value = 5;
		// while
		// 조건문 -> 실행코드 순으로 진행된다.
		while (printf_s("조건문\n"), Value)
		{
			--Value;
			printf_s("실행코드\n");
		}
	}

	{
		int Value = 5;
		// do while
		// 실행코드 -> 조건문 순으로 진행된다
		do
		{
			--Value;
			printf_s("실행코드\n");
		} while (Value);


	}

}

