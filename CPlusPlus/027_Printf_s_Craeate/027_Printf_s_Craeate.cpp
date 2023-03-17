
#include <iostream>

void MyPrintf(const char* const _Ptr)
{
	int Count = 0;

	// 배열의 첫번째부터 마지막까지 이어서 출력하며
	// 배열의 마지막은 0이 나오므로 
	// while의 조건문을 0이 아닐때만 출력하기때문에 배열의 마지막인 0이 나오게 된다면
	// while의 조건문은 false 가 되어 반복을 종료하게 된다.
	while (0 != _Ptr[Count])
	{
		// 값을 확인하는 습관
		char Ch = _Ptr[Count];

		putchar(Ch);
		Count += 1;
	}

}


int main()
{
	// char Arr[10] = {};


	// const char[11]
	// 
	// 배열의 마지막이 0으로 끝나지 않기때문에 에러가 뜬다.
	const char ArrTest[2] = { 'a', 'b' };

	const char* Ptr = "test Print";
	//const char* Ptr = ArrTest;

	// 포인터 문법중 하나인
	// random index access
	char Ch0 = Ptr[0];
	char Ch1 = Ptr[1];
	char Ch2 = Ptr[2];
	char Ch3 = Ptr[3];
	char Ch4 = Ptr[4];
	char Ch5 = Ptr[5];
	char Ch6 = Ptr[6];
	char Ch7 = Ptr[7];
	char Ch8 = Ptr[8];
	char Ch9 = Ptr[9];
	char Ch10 = Ptr[10];
	char Ch11 = Ptr[11];
	char Ch12 = Ptr[12];
	char Ch13 = Ptr[13];
	char Ch14 = Ptr[14];
	char Ch15 = Ptr[15];
	char Ch16 = Ptr[16];

	MyPrintf(Ptr);

	
}
