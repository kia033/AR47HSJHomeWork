
#include <iostream>

void EqiupPtr(int* _Ptr)
{
	*_Ptr = 300;
}

void EqiupRef(int& _Ref)
{
	_Ref = 200;
}

void TestFunction(const int& _Ref)
{
	// const 이기 때문에 인자에 변화는 없다.
}


int main()
{
   // 이 레퍼런스라는 의미가
	//

	int Value0 = 10;
	int Value1 = 20;


	// 대부분의 언어에서 참조라는 의미는
	//  => 특정 메모리영역의 위치를 가리킨다.
	// 포인터 <= 참조
	// 
	// 포인터형 이라고 합니다.
	// 포인터는 언제든지 자신이 참조(가리킨다) 대상을 바꿀 수 있다.
	int* Ptr = nullptr;
	 Ptr = &Value0;
	 Ptr = &Value1;


	 // 포인터 연산자를 통해서 다양한 행위를 할 수 있는게 포인터의
	 // 장점이라고 할 수 있다.
	 // 포인터는 주소값만 가지고 있는 것이다.
	 // 

	 // *Ptr;

	 // 참조형이라고 합니다.
	 // 무조건 누군가를 가리켜야한다.

	 // *Ptr; <= 항상 왼쪽처럼 값을 끌어내서 사용하는 포인터이다.
	 // 특정 이름의 변수가 있다고 쳤을때
	 // 이제 부터 Value0이라는 애를 이제부터 Ref라고도 부를께.
	 // 한번 초기화시 참조한 메모리 영역을 바꿀 수 가 없다.
	 // 
	 // 래퍼런스는  그게 패시브
	 int& Ref = Value0;
	 Ref = Value1;

	 // 모든 포인터의 크기는 8바이트이다.
	 // 레퍼런스는 상시 포인터인 변수이므로 8바이트가 아니라고 나올 수 도 있다.
	 int Value = sizeof(Ref);


	 // 포인터와 레퍼런스 
	 *Ptr = 100;
	 Ref = 100;


	 EqiupPtr(nullptr);

	 int ItemEuip = 0;
	 EqiupRef(ItemEuip);

	 TestFunction(2000);


}

