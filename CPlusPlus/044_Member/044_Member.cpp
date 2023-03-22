// 044_Member.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 어느 영역에도 속하지 않는 영역을
// 전역이라고 합니다.

//전역에 선언된 변수를 전역 변수라고 부릅니다.
int GlobalValue = 10;

// 사용자 정의 자료형 내부의 공간을 멤버 공간이라고 한다.
class Player
{
public:
    // 멤버 함수
    void Damage(int _Att)
    {
        // 다시 지역
    }
private: // 명확하게 선언
    int Hp; // 멤버 변수라고 부른다.
};

// Test 전역함수라고 부르게 됩니다.
void Test()
{
}

// 사용하지않는다.
// 생략
// using namespace AProgramer;

// 이렇게 전역안에 선언된 함수를 전역 함수라고 합니다.
int main()
{
    // c++ 에서 영역에 대한 구분은 
    // 전역, 지역. 멤버, 이름있는 NameSapce

}
