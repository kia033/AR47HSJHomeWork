// 041_Class003_Struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
    // private: 디폴트 접근제한 지정자
private:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

struct Monster
{
    // public: 디폴트 접근제한 지정자
private:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    Player NewPlayer;

    Monster NewMonster;

}

