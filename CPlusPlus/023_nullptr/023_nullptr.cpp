
#include <iostream>

int main()
{
	int Value = 10;

	// nullptr == 0 이라고 부른다.
	// null
	// 주소를 가리키지 않는다. 아직 아무도 가리키고 있지않다.

	// 보통은 nullptr로 초기화 한다.
	int* Ptr = nullptr;

	Ptr = &Value;


	// *Ptr = 200;

	// c 스타일
	//int* Ptr = 0;

}