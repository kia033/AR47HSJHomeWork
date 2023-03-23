// 049_ClassObjectPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    void Damage()
    {
        this->Hp -= 20;
        printf_s("맞았습니다.");
    }
public:
    int Hp = 100;
    int Att = 10;
};

int main()
{
    int Value = int();
    Player NewPlayer = Player();

    int* ValuePtr = &Value;
    Player* NewPlayerPtr = &NewPlayer;

    ValuePtr = nullptr;
    // nullptr 익셉션이 납니다.
    // *ValuePtr = 20;
   
    // NewPlayerPtr = nullptr;
    // nullptr 일때 안에 있는 메모리를 쓰면 터진다.
    // 오류가 난다면 nullptr 을 부여하는 구문이 있는지 확인한다.
    //NewPlayerPtr->Hp = 20;


}
