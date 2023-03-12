﻿
#include <iostream>

int main()
{
	// C++은 타입기반 언어이기 때문에 자료형이 없는 것을 허용하지 않고
	// 자료형이 변화시킬 수 도 없다.


	int Def;
	Def = 20;

	// 메모리가 만들어지면서 동시에 특정값을 받는 것을 
	// 초기화 라고 한다. Init
	// 선언만하고 사용하는걸 별로 좋아하지않는다.
	// 초기값을 왠만하면 지정하는것이 좋다.
	int Att = 0;

	// 이걸 카피 혹은 대입이라고 한다. Copy
	Att = 10;
}
