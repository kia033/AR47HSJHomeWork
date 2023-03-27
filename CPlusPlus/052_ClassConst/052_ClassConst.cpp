// 052_ClassConst.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 멤버함수 뒤에 const 를 붙일 수 있다
// 이 함수를 호출한다고 해도
// 이 클래스를 통해서 만들어진 객체는 수정할 수 없다.
// 일단 const 붙히는 습관
// 필요하다면 const를 지운다.
// 

// 멤버함수 뒤에 const를 붙히면 멤버변수를 고칠 수 없다.

int main()
{
    std::cout << "Hello World!\n";
}

