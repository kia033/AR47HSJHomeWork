// 046_BytePadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 주소값 확인 
// 바이트 할당때 빈공간이 생기게 되면 바로 붙어서 오는가 아니면 사이에 빈 공간이 있는가
// int, short, __int64  
// 4     2       8    / 총 16바이트 공간이 생길때
// int  4/   / 2  /  8 인가
// 4  /2  /  /  8 인가


// 바이트패딩은 변수가 선언된 순서대로 할당하여 공간이 부족하면 새로 만들어서 넣는다.


// short 2바이트 정수형;

class Player
{
public:
    int Hp = 1;          // 4
    short Value3 = 2;    // 4
    int Value4 = 3;      // 4
    short Value9 = 4;    // 4
    char TTT = 5;

    // 8바이트 이하 가장큰 바이트의 자료형을 찾아요.
    // 4바이트
    // 먼저 4바이트를 할당했다고 쳐보자
    // 딱맞거나 들어갈수 있으면 그대로 픽스
    // 4바이트 할당한다.
    // char
    // 8바이트
};

inline void Test(Player Value, ...)
{
    __int64 Address = (__int64)&Value;
    char* Ptr = (char*)Address;


    // 0번에 int 4번에 short 6번에 int 10번에 short 12번에 char
    char Value0 = Ptr[0];
    char Valuea = Ptr[1];
    char Valueb = Ptr[2];
    char Valuec = Ptr[3];
    char Valued = Ptr[4];

    int a = 0;

}

int main()
{

    Player NewPlayer;


    Test(NewPlayer);
    int* Ptr = &NewPlayer.Hp;

    int Size = sizeof(Player);

    printf_s("%d", Size);
}

