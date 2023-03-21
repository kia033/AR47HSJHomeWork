// 038_Class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// c++ => c를 기반 문법으로 해서
// + 객체지향을 추가한 언어입니다.
// + 다른 언어에서 좋다고 칭찬받은 문법들을 
// 마구잡이로 흡수하기 시작했다.

//특정 대상이 다른 대상을 때린다.
// 데이터를 변화싴켜서 목적을 이룬다.

// 

void StatusRender(const char* const _Name, const int& _Att, const int& _Hp)
{
	printf_s("%s 의 스테이터스------", _Name);
	printf_s("공격력 : %d", _Att);
	printf_s("체력   : %d", _Hp);
	printf_s("----------------------");
}

int main()
{
	// 초기형 프로그래밍인 절차지향은
	// 

	// 몬스터와 플레이어가 싸우는 게임을 만들고 싶다.
	// // 플레이어를 만들어야 한다.
	// c는 데이터를 기반으로 시작한다.
	// 행동을 정의하기 시작한다.

	int PlayerHp = 100;
	int PlayerAtt = 10;

	int MonsterHp = 100;
	int MonsterAtt = 10;

	while (true)
	{
		system("cls");
		// 추후 설명
		// 콘솔 화면에 모든 글자를 지운다. system("cls");

		StatusRender("Player", PlayerAtt, PlayerHp);
		StatusRender("Monster", MonsterAtt, MonsterHp);

	}
	
}

