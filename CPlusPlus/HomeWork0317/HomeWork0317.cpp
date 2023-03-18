// HomeWork0317.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String) // 문자열 수 
{
    __int64 Address = (__int64)&_String;
    char* Ptr = (char*)Address;              
    int* IntPtr = (int*)Ptr;    
    int Value0 = *IntPtr; 

    int Count = 0;

    while (0 != _String[Count])
    {
        Count++;
    }

    
    printf_s("%d", Count);
    putchar('\n');
    return 4;
}

int TrimDelete(char* _String)  // 빈칸 지우기 
{
    __int64 Address = (__int64)&_String;
    char* Ptr = (char*)Address;
    int* IntPtr = (int*)Ptr;
    int Value0 = *IntPtr;

    char Arr[1024] = {};
    int Count = 0;
    int ArrCount = 0;

    

    while (0 != _String[Count])
    {
        char Value = _String[Count];
        if (Value == ' ')
        {
            Count++;
        }
        else
        {
            Arr[ArrCount] = Value;
            ArrCount++;
            Count++;
        }

    }

    int StringNum = Count;

    Count = 0;
    ArrCount = 0;

    while (0 != StringNum)
    {
        _String[Count] = Arr[Count];
        
        StringNum--;
        Count++;
    }

    putchar('\n');
    return 4;
}

int StringToInt(const char* _String) // 문자열을 숫자열로 바꾸기
{
    return 4;
}

int main()
{
    /*int Return0 = StringCount("aaaa");
    int Return1 = StringCount("aaaa ggg sss");

    
    char Arr0[1024] = "a b c d e";
    char Arr1[1024] = "a    b c    d    e      a          b";
    char Arr2[1024] = "ab    cde  f         g  ";

    TrimDelete(Arr0);
    printf_s(Arr0);
    TrimDelete(Arr1);
    printf_s(Arr1);
    TrimDelete(Arr2);
    printf_s(Arr2);
    */

    
    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1111");
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");
    

}
