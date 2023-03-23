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
    // 딱맞거나 들어갈수 있으면 채운다.
    // 만약 들어갈 공간이 되지않는다면 빈 공간을 건너뛰고 새 공간을 만들어 넣는다.
    // 
    // 
};

inline void Test(Player Value, ...)
{
    __int64 Address = (__int64)&Value;
    char* Ptr = (char*)Address;


    // 0번에 int 4번에 short 6번에 int 10번에 short 12번에 char

    // 
    char Value0 = Ptr[0];
    char Valuea = Ptr[4];
    char Valueb = Ptr[8];
    char Valuec = Ptr[12];
    char Valued = Ptr[14];

    int a = 0;

}

int main()
{
    // 500번지의 플레이어를 대표하는 NewPlayer
    Player NewPlayer;

    // 플레이어 풀네임을 만들어주는 용도
    // 99%의 경우 FullName을 사용하지 않고 그냥 약칭으로 사용한다.
    NewPlayer./*Player::*/Hp;
    NewPlayer.Hp;

    // 일반적으로 멤버변수일 경우에는 아무런 의미도 없어요.
    // Player::Hp;
    


    // 일반적인 멤버변수를 ::통해서 사용할 순 없다.
    // Plyaer::Hp;
    // NewPlayer.Hp;

    Test(NewPlayer);
    int* Ptr = &NewPlayer.Hp;

    int Size = sizeof(Player);

    printf_s("%d", Size);
}

