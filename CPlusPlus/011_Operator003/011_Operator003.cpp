
#include <iostream>

int main()
{
    // 삼항 연산자
    // a ? b : c

    // 참 옥은 거짓 메모리
    // ? 참일때 메모리
    // : 거짓일때 메모리

    int Left = 7;
    int Right = 3;
    int Result = 0;

    // Left 와 Right 가 같지 않다는 명제
    // 명제가 참이라면 100을 리턴
    // 명제가 거짓이라면 200을 리턴
    Result = (Left != Right ? 100 : 200);

 
    Result = true ? 100 : 200; // 100을 리턴
    Result = false ? 100 : 200; // 200을 리턴


    // sizeof 연산자, 단항 연산자
    // // ()안에 있는 메모리 영역의 바이트 크기를 리턴합니다.
    // sizeof(메모리영역)
    // sizeof(int 영역)
    Result = sizeof(Left);
    Result = sizeof(int);
    Result = sizeof(bool);

}

