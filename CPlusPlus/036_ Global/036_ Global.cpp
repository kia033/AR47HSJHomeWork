﻿// 036_ Global.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 어떠한 지역에도 속하지 않은 변수를 만들어 낼 수 있다
// 기본적으로 이름이 있는 함수나 그 외부에 있는 변수들을
// 전역변수라고 부른다.
int GlobalValue = 0;

// 선언 이후 아래부터 어디서든 사용 할 수 있다.
// 어디에도 속해있지 않기 때문에 존재만 알고 있다면
// 어디서든 사용 할 수 있다.

// 어디서든 쓸 수 있는 이유
// 전역변수는 전부 데이터 영역에 존재한다.

void Function()
{
    ++GlobalValue;
}

int main()
{ // 지역의 시작
    int Value = 0; // 지역변수라고 합니다.

    Function();

    std::cout << "Hello World!\n";
} // 지역의 끝