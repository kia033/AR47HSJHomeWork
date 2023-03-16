

#include <iostream>

// 함수의 스택에서의 메모리 크기는 컴파일시
// 고정되어야 하기때문이다.
// ex) c++의 함수의 실행흐름을 만들기 위한(스택 크기(는 
//	   exe파일에 이미 다 정의되어 있어야 한다.
int main()
{
	// 특정 자료형앞에 const 키워드를 붙이면
	// 그 메모리의 비트적 상수화를 시킨다.
	const int ArrSize = 20;

	int Value[ArrSize] = {};

	printf_s();
}

