
#include <iostream>

// 가변 인자
void VarFunction(...)
{

	
}


//			      100번지  108번지 116번지
void TestFunction(int _1, int _2, int _3)
{
	int* ValuePtr0 = &_1;
	//int* ValuePtr1 = &_2;
	//int* ValuePtr2 = &_3;

	// int 배열은 4바이트 
	// 주소값은 8바이트씩 떨어져 있으므로
	// int 배열의 크기마다 그 다음 주소값의 위치가 된다.
	// ex) 인자 10, 20, 30
	// Value1 = 10
	// Value2 = 20
	// Value3 = 30
	int Value1 = ValuePtr0[0];
	int Value2 = ValuePtr0[2];
	int Value3 = ValuePtr0[4];

	//__int64 Address0 = 0;
	//__int64 Address1 = 0;
	//__int64 Address2 = 0;

	//Address0 = (__int64)ValuePtr0;
	//Address1 = (__int64)ValuePtr1;
	//Address2 = (__int64)ValuePtr2;
}


void TestFunction2(int _1, ...)
{
	// 가변 인자 찾기
	// int 배열이므로 배열의 크기는 4바이트
	// 주소값은 8바이트 단위이므로
	// 첫번째 인자가 n = 0 이라고 시작하고
	// 두번째 인자는 n = 1, 세번째 인자는 n = 2 같은 규칙으로 변한다면
	// ValuePtr0[n*2] 가 주소값이 된다.
	int* ValuePtr0 = &_1;

	int Value1 = ValuePtr0[2];
	int Value2 = ValuePtr0[4];
	int Value3 = ValuePtr0[6];
	int Value4 = ValuePtr0[8];
	int Value5 = ValuePtr0[10];

}

int main()
{
    VarFunction(2, 3, 4, 5, 6, 7);

    VarFunction("1", "2", "3", "4");

	TestFunction(10, 20, 30);

	TestFunction2(53123, 1, 2, 3, 4, 5);
}

