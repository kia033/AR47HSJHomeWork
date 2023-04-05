// 065_DeleteHeap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream> // crtdbg.h 가 들어있다.

int main()
{
	// 릭 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// 중복할당
	{
		int* Newint = new int();
		//Newint = new int();
		delete Newint;

	}

	// 아래와 같이 한번 할당 한건 지우고 다시 받아서 사용하면 된다.
	{
		int* Newint = new int();
		delete Newint;
		Newint = new int();
		delete Newint;
	}

	{
		int* Newint = new int();

		// 습관 <=
		// 방어코드. 중단점
		if (nullptr == Newint)
		{
			return;
		}

		*Newint = 20;
		delete Newint;
	}

	// 지운거 또 지우기
	// 댕글링 포인터라고 합니다.
	{
		int* Newint = new int();

		delete Newint;
		// 메모리 크러쉬라고 합니다.
		//delete Newint;
	}

	{
		int* Newint = new int();

		// 안전한 삭제
		if (nullptr != Newint)
		{
			delete Newint;
			Newint = nullptr;
		}

		if (nullptr != Newint)
		{
			delete Newint;
			// Newint 500번지가 삭제되지 않고 남아있는게 당연하다.
			Newint = nullptr;
		}
	}
}

