// 048_This.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    Player()
    {
    }

    // 이 함수를 호출한 객체의 주소값이 들어가게 된다.
    // 클래스의 멤버함수를 사용한다는건 그 클래스의 포인터를 사용한다는 것이다.
    // Player const 가리키는 대상을 바꿀 수 없다.
    void Damage(/*Player* const this*/int _Att)
    {
        // 눈에 보이지 않지만 멤버함수에는
        // 첫번째 인자로 무조건 자기자신의 클래스의 포인터가 들어가게 된다.

        // * const 이기 때문에 this 가 가리키는 대상은 바꿀 수 없다.
        this->Hp -= _Att;
    }

    // 스택을 안 만들고 최적화
    inline int GetHp()
    {
        return Hp;
    }

    inline void SetHp(int _Value)
    {
        Hp = _Value;
    }

    inline int GetAtt()
    {
        return Att;
    }

    inline void SetAtt(int _Value)
    {
        Att = _Value;
    }

protected:

private:

public:
    int Hp = 100;
    int Att = 10;

};

void GlobalDamage(Player* _this, int _Att)
{
    // 클래스를 포인터로 사용할때는
    // 내부에 있는 멤버변수에 접근하는 방식이
    //.이 아니고 -> 이걸로 변경된다.
    _this->Hp -= _Att;
}

// 다른 주소에 새로운 플레이어를 만든다.
void GlobalDamageValue(Player _NewPlayer, int _Att)
{
    // 새로인 Player를 만든다.
    // 외부에 영향이 없다
    _NewPlayer.Hp -= _Att;
}

int main()
{
    Player NewPlayer0 = Player();
    Player NewPlayer1 = Player();

    // NewPlayer0.Hp -= 20;


    // 각 객체들이 함수를 호출해서 자신의 멤버변수들을 알아서 잘 찾아서 바꿀 수 있을까?
    // 80
    // GlobalDamage(&NewPlayer0, 20);  절차지향의 방식이다.
    NewPlayer0.Damage(/*&NewPlayer0,*/20);
    // 50
    // GlobalDamage(&NewPlayer1, 50);
    // NewPlayer1.Damage(/*&NewPlayer0,*/50);

    //NewPlayer.SetAtt(100);
    //NewPlayer.SetHp(100);
}

