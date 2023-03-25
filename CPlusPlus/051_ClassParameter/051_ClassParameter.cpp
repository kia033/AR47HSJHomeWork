// 051_ClassParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    int Vlaue0;
    int Vlaue1;
    int Vlaue2;
    int Vlaue3;
    int Vlaue4;
    int Vlaue5;
    int Vlaue6;
    int Vlaue7;

};

// 플레이어가 1마리도 없을 가능성이 있다면 포인터
void StatusRender(const Player* _Player)
{
    if (nullptr == _Player)
    {

        return;
    }
}

// 플레이어가 1마리도 없을 가능성이 없다면 레퍼런스

void StatusRenderRef(const Player& _Player)
{

}

int ReturnFunction()
{
    return 10;
}

int& ReturnFunctionRef() 
{
    int Value = 20;

    return Value; // 지워진 메모리를 참조하게된다
}

int FunctionTest(int* _Ptr)
{
    return 10;
}

int main()
{
    int TestValue = 20;

    FunctionTest(&TestValue);



    // 접근해서 수정할 수 없다.
    int Value = ReturnFunction();

    if (Value)
    {

    }

    int Value = sizeof(Player);

    std::cout << "Hello World!\n";
}

