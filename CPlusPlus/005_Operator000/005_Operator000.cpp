﻿
// #include <iostream>  파일 입출력을 위해서 콘솔화면에 띄우기 위한 용도
// 헤더는 딱 필요한 헤더만 정확하게 #include 해놓는 것이 좋다.
// 그렇지 않으면 필요없는 코드가 추가되어 동작할때 불필요한 시간이 소요된다.
// 컴파일이 오래 걸리는 이유 > 복붙을 많이 하게되기 때문이다.


int main()
{
	// 연산자 특정 메모리를 변화시키는 명령을 축약해 놓는 기호이다.

	// 값을 100으로 바꾼다는 것은 그 위치의 비트를 수정하겠다는 이야기이다.

	// PlayerHp 번째에 있는 비트를 100의 비트로 바꾼 것을 의미하게 되고
	// = <= 연산자 라고 한다.
	int PlayerHp = 100;
	// 1. 4바이트의 공간을
	// 2. 다른 위치에 있는 100을 가져와서 
	// 3. PlayerHp 번째에 다른 위치에 있는 값 100을 복사해라
	// = <= 에 대한 설명.

	// 이미 만들어져있는 PlayerHp번째를 50이라는 값으로 바꿔라 
	PlayerHp = 50;

	// 비트라고 치면 
	// 00000000 00000000 00000000 00000000

	// 비트 구성을 바꾸는 명령 
	int Right = 7;
	int Left = 3;



}
