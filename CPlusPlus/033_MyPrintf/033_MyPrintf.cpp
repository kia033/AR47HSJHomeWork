// 033_MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//              100       108
inline void Test(int Value, ...)
{
	// 인자로 들어온 Value는 int이므로 
	// (__int64)로 형변환한다.
	__int64 Address = (__int64)&Value;
	int* Ptr = (int*)Address;

	int Value0 = Ptr[2];
	int Value1 = Ptr[4];
	int Value2 = Ptr[6];
	int Value3 = Ptr[8];

	int a = 0;

}

inline int MyPrintf(const char* const _Value, ...) // 인자를 수정하지 않는다.
{

	// 가상인자 부분 복습

	// const char* const _Value 이므로 &를 달아 내부에서 수정을 하여도 외부에는 영향이 가지 않는다.
	__int64 Address = (__int64)&_Value; // char을 __int64로 형변환여 인자의 주소값을 불러온다.
	char* Ptr = (char*)Address; // 포인터 Ptr을 만들고 Address를 char*로 형변환하여 주소값을 받아온다.
	Ptr += 8;                   // 8바이트 만큼 건너뛰어 첫번째 인자를 넘긴다. // 즉 2번째 인자인 숫자의 주소가 Address에 담긴다
	int* IntPtr = (int*)Ptr;    // Ptr은 char* 이므로 int*로 형변환하여 InPtr에 복사한다.
	int Value0 = *IntPtr;       // Value0은 *InPtr 이다.
	
	//  


	// return 0;

	int Count = 0; // 카운터 변수

	while (0 != _Value[Count]) // _Value[Count]가 0이 아니라면 
	{
		char Value = _Value[Count]; // char Value는 Value[Count]의 값을 불러온다.
		if ('%' == Value) // _Value[Count]가 % 라면
		{
			++Count; // Count를 하나 늘리고 
			char Format = _Value[Count]; // _Value[Count 번째 문자열을 불러온다.

			switch (Format) // 해당 문자열이
			{
			case 'd':   // d 라면 // %d 숫자열
			{
				int* ValuePtr = (int*)Address; // 현재 Address는  += 8 을 하여 2번째 인자인 숫자값의 주소를 담고 있다.
											   // int* ValuePtr = (int*)Address; 포인터 이므로 숫자값을 받아올 수 있다.
				int Value = *ValuePtr;         // Value 는 2번째 인자인 숫자값을 받아온다.
				printf_s("%d", Value);         //  %d 는 숫자열출력이므로 int값을 부호있는 10진수 숫자로 표현한다.
											   // 
				break;
			}
			case 's':   // s 라면  // %s 문자열
			{

				break;
			}
			default:  // d,s 둘다 아니라면
				break;
			}
		}
		else
		{
			putchar(Value);
		}

		Count++;
	}

	return 0;
}

//      100 108 116 
// Test(int 첫번째인자 int 두번째인자 int int int) 
// {
// //      100
//    int* Ptr = &첫번째인자;
//    Ptr += 2; 첫번째인자
//    Ptr[2]
// }

void Test(int _1, int, int)
{
	__int64 Address = (__int64)&_1;
	Address += 8;
	int* _2 = (int*)Address;
	Address += 8;
	int* _3 = (int*)Address;


}

int main()
{
	Test(10, 1, 2, 3, 4);

	 // printf_s("abcdefg %s", 321312); // 숫자열인데 문자열을 출력한다.

	MyPrintf("abcdefg %d fasdfasdfasdf", 111);
	// abcdefg fasdfasdfasdf

	// Printf_s 출력 형식 
	// % 뒤에 붙이는
  /*d	int값을 부호있는 10진수로 출력
	i	d와 같음
	u	int값을 부호없는 10진수로 출력
	X	int값을 부호없는 16진수로 출력  10~15은  'A'~'F'로 표시
	x	int값을 부호없는 16진수로 출력  10~15은  'a'~'f'로 표시
	o	int값을 부호없는 8진수로 출력
	p	포인터값을 16진수로 출력
	s	문자열 출력
	c	int값을 문자로 출력
	C	c와 같음
	f	double값을 소수로 출력(예：12.566371)
	e	double값을 지수로 출력(예：1.256637e+001)
	E	e와 같음 'e'가 'E'로 표시(예：1.256637E+001)。
	g	숫자값의 크기에 따라 f나 e로 출력(예：12.5664、2.99792e+008)
	숫자값의 절대치가 너무 커서 precision의 자리수를 넘는 경우와 숫자값의 절대값이 0.0001보다 작은 경우 e형식이 사용되어짐.
	그 외의 경우는 f형식으로 사용됨
	G	9와 같음 'e'가 'E'로 표시*/
}
