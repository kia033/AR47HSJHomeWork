// 052_ClassConst.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 멤버함수 뒤에 const 를 붙일 수 있다
// 이 함수를 호출한다고 해도
// 이 클래스를 통해서 만들어진 객체는 수정할 수 없다.
// 일단 const 붙히는 습관
// 필요하다면 const를 지운다.
// 

class Player
{
public:
    void SetHp(int _Value)
    {
        Hp = _Value;
    }

    int GetHp() const
    {
        return Hp;
    }

    // 맴버함수뒤에는 const를 붙일수 있다.

    // 이함수를 호출한다고 해도
    // 이 클래스를 통해서 만들어진 객체는 변화하지 않을거야.
    void PrintStatus(/*const Player* const this*/) const
    {
        // this;
        // 맴버함수 뒤에 const를 고치면 맴버변수를 고칠수 없다.
        // this->Att += 100;

        printf_s("플레이어의 능력치 ------------------------\n");

        printf_s("공격력 : %d\n", Att);

        printf_s("체  력 : %d\n", Hp);

        printf_s("----------------------------------------\n");
    }


protected:

private:
    int Hp = 100;
    int Att = 10;
};

int main()
{
    Player NewPlayer = Player();

    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
}
