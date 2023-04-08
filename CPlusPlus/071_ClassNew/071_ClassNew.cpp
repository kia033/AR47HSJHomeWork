// 071_ClassNew.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
    char* ArrChar;

public:
    void Resize(size_t Size)
    {
        ArrChar = new char[Size];
    }
};

int main()
{
    char* Arrint = new char();

    delete Arrint;

    // 이녀석을 만든다는것 자체가 
    // char의 배열을 만든것과 같다는것.
    Test* ArrTest = new Test[10];

    delete[] ArrTest;

    // Test ArrTest = Test();

}
