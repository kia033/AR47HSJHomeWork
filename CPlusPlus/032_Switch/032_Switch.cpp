// 32_Switch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 자동완성 기능
    // swi 치고 tab

    // 컨트롤 + 스페이스


    int Check = 0;

    // case 상수 메모리만 올수 있습니다.

    // if(메모리) 메모리영역이 참인지 거짓인지를 판단해서 코드를 실행해주는 
    // 조건문이에요.

    // switch(메모리)영역과 완전히 같은 상수 메모리가 있는지 비교해주는 
    // 조건문이고.


    const int CheckValue = 0;

    int Value = 4;
    switch (Value) // Value의 값과 동일한 조건을 찾는다.   / 현재 Value는 0
    {
        // case Check:
    case CheckValue:   // CheckValue 는 0 이므로 Value의 값과 동일하다.
    {
        int a = 0;
        printf_s("Value 0");  // Value 0 을 출력한다.
        break;     // 스위치 구문을 빠져나간다.
    }
    case 1:
    {
        printf_s("Value 1");
        break;
    }
    case 2:
    {
        printf_s("Value 2");
        break;
    }
    case 3:
    {
        printf_s("Value 3");
        break;
    }
    default:  // 위에서 같은 조건을 찾지 못했다면 default로 들어가 실행한다. i
    {         // if 구문에서 else와 동일한 역할
        printf_s("Value not");
        break;
    }
    }

    printf_s("\n");

    char InputKey = 'a';

    switch (InputKey)
    {
    case 'a': // 조건문을 지날때 break가 없다면 조건문을 나갈때까지 아래로 탐색한다
    case 'A': // 'a' 일때 break 가 없으므로 'a' 가 오거나 'A'가 와도 똑같이 
        printf_s("에이를 쳤습니다."); // 에이를 쳤습니다 라는 문구가 출력된다.
        break;                        // 스위치 구문을 빠져나간다. 
    default:
        break;
    }
}
