
#include <iostream>

int main()
{
	int Left = 0b00000000000000000000000000000010;  // 2
	int Right = 0b00000000000000000000000000000001;  // 1
	int Result = 0b00000000000000000000000000000000;  // 0


	// 
	// 비트단위 연산자.
	// Not
	// 비트 0 을 1로, 1을 0으로 반전시킨다.
	// 0b00000000000000000000000000000000
	Result = ~0; // -1

	// and
	// a항과 b항의 비트를 곱하여 둘다 1일때만 1의 값을 준다.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000000   / 0
	Result = Left & Right; 

	// or
	// a항이나 b항중 둘중 하나라도 1이라면 값으로 1의 값을 준다.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000011   / 3
	Result = Left | Right;

	// xor
	// a항과 b항이 서로 다를때만 값으로 1을 준다.
	// 둘이 1로 같든 0으로 같든 같으면 false가 된다.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000011   / 3
	Result = Left ^ Right;

	// true 와 false 참과 거짓의 명확한 의미를 
	// 한번 짚고 넘어가겠습니다.
	// 특정 메모리 영역의 비트가 전부 0이라면 false 와 거짓
	// 특정 메모리 영역의 비트중 단 1개라도 1이 있다면 true 와 참
	
	bool bResult = 2;
	bResult = 3 && 10023123;

	// 비트 시프트 연산
	// <<  비트 왼쪽 시프트
	// >>  비트 오른쪽 시프트
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000001000

	Result = 1 << 3;

	// 이런식의 어떤 일이 발생할지 알 수 없는 코드는 애초에 쓰지 않는다.
	Result = 1 << 33;

	// 복합할당 연산자
	// 특정 메모리영역의 값을 기반으로 하는 이항 연산자에 가깝다.
	//덧셈 대입	a += b	예	예	T & T::operator+=(const T & b);	T& operator+=(T & a, const T & b);
	//뺄셈 대입	a -= b	예	예	T & T::operator-=(const T & b);	T& operator-=(T & a, const T & b);
	//곱셈 대입	a *= b	예	예	T & T::operator*=(const T & b);	T& operator*=(T & a, const T & b);
	//나눗셈 대입	a /= b	예	예	T & T::operator/=(const T & b);	T& operator/=(T & a, const T & b);
	//모듈러 대입	a %= b	예	예	T & T::operator%=(const T & b);	T& operator%=(T & a, const T & b);
	//비트 AND 대입	a &= b	예	예	T & T::operator&=(const T & b);	T& operator&=(T & a, const T & b);
	//비트 OR 대입	a |= b	예	예	T & T::operator|=(const T & b);	T& operator|=(T & a, const T & b);
	//비트 XOR 대입	a ^= b	예	예	T & T::operator^=(const T & b);	T& operator^=(T & a, const T & b);
	//비트 왼쪽 시프트 대입	a <<= b	예	예	T & T::operator<<=(const T & b);	T& operator<<=(T & a, const T & b);
	//비트 오른쪽 시프트 대입	a >>= b	예	예	T & T::operator>>=(const T & b);	T& operator>>=(T & a, const T & b);

	int Value = 20;

	Value += 10;

	Value += Value;
	Value = 1;
	Value <<= 3; // 8
}