// 040_Class001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 만들었어 => 이게 기본이다.
// // 학원의 객체지향 학습 구성
//=> 나는 뭘 만들고싶다.
// => 클래스로 만든다.
// 선생님에게 피드백을 받는다.

// c++에서 클래스는 모든 것을 만들 수 있는 문법이다.
// int도 내가 만드는 개념과 다르지 않다는 것을 곧 알게된다.
//

// 플레이어는 이러이러한 존재이다. 선언
class Player
{
    // 2가지를 가지고 있습니다.
    // 
    // 속성과
    // 행동이라고 합니다.

    // 속성
    // 어떠어떠한 맷집이 쌔,
    // 속력이 빠르다. <= 속성
    // 
    // 멤버 변수 => 보통 명사
    // 내부에서 변수 선언하므로서 표현할 수 있다.

    // 이름이 있다
    const char* const Name = "Player";
     
    // 때릴 수 있다.
    int Att; // 공격력
    // 맞을 수 있다.
    int Hp; // 체력

    // 행동 => 보통 동사
    // 맞을 수 있어야 한다.
    // 뛸 수 있어야 한다.

    // 뛴다.
    void Run() 
    {

    }

    // 맞는다.
    void Damage(const int _Damage) {

    }

    // 능력치를 보여준다.
    void StatusRender()
    {
        printf_s("%s 의 스테이터스 ------------\n", Name);
        printf_s("공격력 : %d\n", Att);
        printf_s("체력 : %d\n", Hp);
        printf_s("---------------------------\n");
    }



};
// 이것도 사용자 정의 자료형중 하나이다.

// 자료형
// 기본자료형 int bool 
// 사용자정의 자료형 Player, Monster FightZone => 모든것을 표현할수 있다.

int main()
{
    // int도 기본클래스입니다.

    // 개념을 생각하고 개념을 class로 정의 내리고
    // NewPlayer가 객체입니다.
    Player NewPlayer0 = Player();
    Player NewPlayer1 = Player();
    Player NewPlayer2 = Player();

    Player ArrPlayer[3];

    int Value = int();

    // 플레이어
    // 공격력
    // 체력

    std::cout << "Hello World!\n";
}


// 플레이어는 이러이러한 존재야.
//class Player
//{
//    const char* const Name = "Player";
//    int Att;
//    int Hp; 
//
//    void Run() {
//
//    }
//    void Damage(const int _Damage) {
//
//    }
//    void StatusRender()
//    {
//        printf_s("%s 의 스테이터스 ------------\n", Name);
//        printf_s("공격력 : %d\n", Att);
//        printf_s("체력 : %d\n", Hp);
//        printf_s("---------------------------\n");
//    }
//};// 기본 자료형 int bool
// 사용자 정의 자료형 => 모든 것을 표현할 수 있다.


