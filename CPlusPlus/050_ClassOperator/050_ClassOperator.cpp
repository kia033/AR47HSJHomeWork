// 050_ClassOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Number
{
private:
    int Value;

public:
    // 멤버 이니셜라이저.
    Number(int _Value) 
        : Value(_Value)
    {
    }

    bool operator ==(int _Value)
    {
        return Value == _Value;
    }

    // 클래스가 연산자를 사용할 수 있게 만들어주는 것이다.
    int operator +(int _Value)
    {
        return Value + _Value;
    }
};

int main()
{
    {
        int Value = 10;

        Value + 10;
    }
    {
        // 자신이 논리적으로 이 연산자는 이렇게 만들면 되겠다 할 수 있는 
        // 연산은 다 만드는 것
        Number Value = 10;

        // 연산자 겹지정 함수라고 부릅니다.
        Value + 10;
        Value.operator+(10);

    }

}

