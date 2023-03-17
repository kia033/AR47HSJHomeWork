
#include <iostream>

int main()
{
	printf_s("aaaa");

	{
		int Value = 10;

		int* Ptr = &Value;


		// 자로형*
		const int* cPtr = &Value;
		// * 뒤에 뭔가를 붙이는건 이제부터 *에 영향을 주는 문법이 된다.

		// const int*
		// 포인터형 변수가 사용할때 *을 붙인다는 것은
		// 자신의 자료형에서 *을 뺀 자료형으로 사용하겠다는 뜻이다.
		// ex) *Ptr
		// Ptr == const int*
		// *Ptr == const int

		const int const ValueTTT0 = 10;

		const int const ValueTTT1 = 10;

		//int const ValueTTT0 = 10;

		//const int ValueTTT1 = 10;

		// printf_s();
	}

	{
		// 100번지에 있는 A
		char Test0 = 'A';
		// 110번지에 있는 B
		char Test1 = 'B';

		// 120번지에 있는 100번지
		// 100번지 안에 있는 값을 const화 시키는 게 아니라
		// 100번지라고 하는 내가 가리키고 있는
		// 주소 자체를 못 바꾸게 하고싶을때 사용한다. / 뒤에 const
		const char* const Chr= &Test0;

		// 120번지에 있는 110번지
		//Chr= &Test1;

		// 자료형    |  주소값  을 바꾸지않겠다.
		// const char*   const                     Chr = &Test0;
		//



		// const char
		// *Chr = 'c';

		// const char*
		// <= 정보값 수정 불가, 주소값 수정 가능
		// 120번지 안에 있는 100번지의 내부 값을 수정할 수 없다.
		// 
		// char* const
		// <= 정보값 수정 가능, 주소값 수정 불가 
		// 120번지 안에 있는 100번지라는 주소값을 수정할 수 없다.
		// 
	}

}

