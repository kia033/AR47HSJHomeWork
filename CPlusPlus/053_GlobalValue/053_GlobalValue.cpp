// 053_GlobalValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// c++은 객체지향 언어가 아니라는걸 확실히 설명할 수 있다.
// 전역의 존재 때문이다.

// 객체지향은 오직 클래스와 객체로만 코딩하는 것이 객체지향이다.
// 객체를 지향하지 않으면 객체 지향이 아니다.


class Monster
{
public:
    void Print()
    {
        printf("%d", Count);
    }

private:
    static const int Count = 1;


};


int main()
{
    Monster New = Monster();

    New.Print();

    std::cout << "Hello World!\n";
}

