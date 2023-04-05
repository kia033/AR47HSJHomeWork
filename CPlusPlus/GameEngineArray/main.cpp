// GameEngineArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameEngineArray.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // 컴파일러에서 지원하는 Arr형에는
    // operator = 함수를 구현하지 않았다.
    {
        //int Arr0[10];
        //int Arr1[10];

        // Arr0 = Arr1;
    }

    {
        GameEngineArray Array0(10);


        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        // 숙제 1 기존의 데이터를 보존하는 것을 말하는 거싱다.
        // 숙제 2 줄어들든 커지든 데이터는 보존되어야 한다.
        // 원래 데이터를 대입하고 삭제한다.
        Array0.ReSize(5);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }

        //GameEngineArray Array1(20);
        //Array0 = Array1;
    }

    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        // 숙제 3 왜 터지는지 이해하고 고쳐라.
        Array1 = Array0;

    }

    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        // 숙제 4 완전한 동일한 배열이 되게 만들어라.
        // 0은 10개짜리, 1은 5개짜리 배열인데 둘을 똑같이 10개짜리 배열로 만들어라.
        // 그러고 내부의 값이 들어가게 한다.
        Array1 = Array0;

        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d\n", Array1[i]);
        }
    }

}

