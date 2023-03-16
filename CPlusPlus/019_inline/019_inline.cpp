// 019_inline.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 컴파일러 판단에 따라 안될 수도 있다.
inline void Test()
{
	printf_s("Function");
}


int main()
{
	// 함수를 복붙하는 느낌으로 스택을 만들지 않도록 
	// 최적화할 수 있다면 해달라는 코드.
	printf_s("Function");


	//Test();
}
        