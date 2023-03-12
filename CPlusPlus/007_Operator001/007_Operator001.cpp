
#include <iostream>

int main()
{
	// f5 => 한번에 실행 .중단점까지
	// f10 => 처리형태가 구분되는 한 명령씩 실행하라

	int Left = 7;
	int Right = 3;
	int Result = 0;

	// 연산자에는 보통
	//  단항 연산자 <= 메모리 영역이 1개만 필요하면 단항
	//  이항 연산자 <= 메모리 영역이 2개만 필요하면 이항
	//  삼항 연산자 <= 메모리 영역이 3개만 필요하면 삼항

	// ex) = 연산자는 이항 연산자 입니다.
	// Left, 3을 사용해서 2개의 메모리 영역이 있어야만 동작하기 때문에 
	// 이항 연산자라고 한다.

	// 산술연산자는 보통 이항이 많다.
	
	//		7		3
	Result = Left + Right;
	// 10

	Result = Left - Right;
	Result = Left * Right;
	// c++ 에서 정수의 나눗셈은 몫만 나온다.
	Result = Left / Right;
	// 나머지 연산자
	Result = Left % Right;

	Result = -Left;
	Result = +Left;

	// 전치, 전위
	// Left에 먼저 1을 더하는 계산을 한 뒤에  Result에 Left를 더한다.
	Result = ++Left;
	// 후치, 후위
	// Result에 Left의 값을 더하고 그 후에 Left 자신에 1을 더한다.
	Result = Left++;

	Result = --Left;
	Result = Left--;

	// 연산자 순서.
	Result = 1 + 2 * 3;
	// () 괄호 연산자
	// 연산순서를 프로그래머가 지정하게 해줄수 있는 연산자 입니다.
	Result = (1 + 2) * 3;
	
	// bool이라는 자료형은 논리형이라고 부른다.
	// 논리형은 true 와 false로
	// 참과 거짓이라는 2가지만으로 표현할 수 잇는 자료형을 논리형이라고 한다. 
	// true 논리형 상수 참
	// false 논리형 상수 거짓
	// 
	bool bResult = true;
	bResult = false;

	//비교 연산자 / 관계 연산자
	bResult = Left == Right; // 같다
 	bResult = Left != Right; // 같지 않다.
 	bResult = Left < Right; // 작다
 	bResult = Left > Right; // 크다
 	bResult = Left <= Right; // 작거나 같다
 	bResult = Left >= Right; // 크거나 같다
	

	// 논리 연산자
	// and
	bResult = true && true; // 둘다 참이라면 참이라면 참, 하나라도 거짓이라면 거짓 
	bResult = true && false;
	bResult = false && false;

	// or
	bResult = true || true; // 둘중 하나라도 참이라면 모두 참
	bResult = true || false; 
	bResult = false || false;
}

