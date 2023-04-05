// 066_ArrayHeap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 정적 바인딩
	// 개수가 정해져있고 코드가 실행되면 바뀌지 않는 메모리 영역들을 말한다.
	{
		int Arr[10];
		int* Ptr = Arr;
		Ptr[0];
	}

	// 힙을 사용하는 행위 자체가 동적 바인딩을 의마한다.
	// 동적 바인딩
	{
		//  2가지 new 를 사용해서 배열을 만들 수 도 있다.
		int* Ptr = new int[100];

		// 지울때 이 방식을 통해서 지우는게 힙배열 삭제의 정식 문법이다.
		// 배열은 이 방식으로 지워야 한다.
		delete[] Ptr;

		// 상황에 따라서 배열할당은 delete로는 삭제가 안될때가 있다.
		// delete Ptr;
	}


}

