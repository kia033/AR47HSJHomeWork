// 047_ClassConstructer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Weapon
{
public:
    int Att = 200;

public:
    Weapon()
    {
    }
};

class Potion
{
public:
    int Heal = 100;

public:
    Potion()
    {

    }

};

class Player
{
public:
    // 리터럴 초기화라고 부르는 초기화 방식을 이용할 수 있다.
    // 11 이전에는 안됬던 방식이고 회사에서 사용하지 않을수 도 있다.
    // 초기화시 메모리는 위에서 아래순으로 생성된다.
    int Hp = 20;
    int Maxatt = 20;
    int MintAtt = 20;
    int PDef = 20;
    int MDef = 20;
    int Crit = 20;
    Weapon PlayerWeapon = Weapon();
    Potion PlayerPotion = Potion();

    void TestFunction()
    {

    }

public:
    // 생성자만의 규칙 / 예외적이다.
    // 무조건 클래스 이름과 완전히 동일해야 한다.
    // 리턴값이 없는 이유. => 리턴값이 그 클래스의 객체이기 때문이다.
    // 객체 없이 호출가능하다. => 일반적인 클래스의 함수는 무조건 객체가 필요한데
    // 객체를 만들어내야하는 함수가 객체를 필요로 하면 모순이 생긴다.
    // 멤버이니셜라이저라는 문법을 사용할 수 있습니다.
    // 리터럴 초기화와 비교하면 멤버이니셜라이저가 2순위이기 때문에
    // 멤버이니셜라이저의 값이 최종 적용된다.
    // 생성과 대입의 차이는 프로그래머들이 정말 꼼꼼하게 신경쓰는 차이이기 때문에 
    //
	//Player(int Value)
	//	: Hp(30)
	//	, Maxatt(30)
	//	, MintAtt(30)
	//	, PDef(30)
	//	, MDef(30)
	//	, Crit(Value)
	//{
	//	// 이건 대입이라고 한다.  / 초기화 x
	//	Hp = 10;
	//}

    Player(int _Value0, int _Value1)
    {

    }
};

void Test(const Player& _Player)
{

}


int main()
{
    // 생성자는 기본적으로 함수로 인식된다.

    // 클래스를 내가 만들었는데
    // 내가 정의하지 않은 행동을 할 수 있다면 컴파일러가 그렇게 한 것이다.
    // 그리고 그건 내 눈에 생략된 것이다.
    // 클래스는 내가 만든대로 동작하고 만든대로만 동작할 수 있다.
    // 함수에 인자가 있다면 생성자를 생략할 수 있다.
    Player NewPlayer0 = Player(20, 30);

    // 리스트 이니셜라이저 문법이라고 한다.
    Player NewPlayer1 = {20, 30};
    // 생략된 상태
    // Player NewPlayer1 = Player{20, 30};

    // int의 생성자가 호출되서 인자에 20을 넣고 
    // int Value에 대입한다.
    int Value = int(20);

    // 아래와 같이 사용할 수가 없다.
    // Player::TestFunction();

    // 전역함수처럼 그냥 함수쓰듯이 사용할 수는 없다.
    // 클래스의 멤버함수는 무조건 객체를 필요로 합니다.
    // 하지만 이 제약에서 벗어난 함수가 2종이 존재한다.
    // 그중 1종이 생성자이다.
    // 생성자는 객체를 만들어내는 전역함수를 의미한다.
    NewPlayer0.TestFunction();
    
    // 
    

    std::cout << "Hello World!\n";
}

