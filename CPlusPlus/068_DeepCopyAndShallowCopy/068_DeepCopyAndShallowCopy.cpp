// 068_DeepCopyAndShallow Copy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
public:
    int* NewInt = nullptr;

    void Create()
    {
        // 나만의 메모리를 가진다.
        NewInt = new int();
    }

    void operator = (const A& _Other)
    {
        // 이걸 얕은 복사라고 하게 된다.
      
        // NewInt = _Other.NewInt;
        if (nullptr == _Other.NewInt)
        {
            //if (nullptr != NewInt)
            //{
            //    delete NewInt;
            //    NewInt = nullptr;
            //}
            return;
        }

        if (nullptr == NewInt)
        {
            // 딥카피의 준비를 한것.
            Create();
        }

        // 각클래스가 자신만의 메모리를 만들어야 한다는 것이다.
        *NewInt = *_Other.NewInt;

        return;
    }


public:
    ~A()
    {
        if (nullptr != NewInt)
        {
            delete NewInt;
            NewInt = nullptr;
        }
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        A NewInt0;
        A NewInt1;

        NewInt0.Create();

        NewInt0 = NewInt1;
    }

    // 얕은 복사
    // 주소값을 공유한다.
    {
        //           100
        int* NewInt0 = new int();

        //           100
        int* NewInt1 = NewInt0;

        if (nullptr != NewInt0)
        {
            delete NewInt0;
            NewInt0 = nullptr;
        }

        // NewInt0 을 삭제하면 NewInt1은 메모리 크러쉬가 발생한다.
        // ???????? NewInt1

        if (nullptr != NewInt1)
        {
            delete NewInt0;
            NewInt0 = nullptr;
        }
    }
    std::cout << "Hello World!\n";
}

