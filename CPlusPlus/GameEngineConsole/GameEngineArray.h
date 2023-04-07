#pragma once

#include "../GameEngineBase/GameEngineDebug.h"


#define MsgBoxAssert(Text)     MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);

//typedef int DataType;

template<typename DataType>
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
	{
		if (_Value <= 0)
		{
			MsgBoxAssert("0크기의 배열은 만들수 없습니다.");
		}

		ReSize(_Value);
	}
	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}


	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		// 나만의 메모리를 만들고
		// 깊은 복사라고 한다.
		ReSize(_Other.ArrCount);
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other[i];
		}

		return *this;
	}

	size_t Count() const
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index) const
	{
		return ArrPtr[_Index];
	}

	// 값을 넘기고 지운다. 숙제 
	// 삼항 연산자 사용
	// 기존의 할당된 배열을 알고 있는것은 
	// 섣불리 지우면 안된다.

	// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.

	void ReSize(int _Value)
	{
		if (_Value <= 0)
		{
			MsgBoxAssert("Resize의 인자가 0보다 작습니다");
		}


		DataType* NewArrPtr = new DataType[_Value];

		if (nullptr != ArrPtr)
		{
			int Count = ArrCount < _Value ? ArrCount : _Value;

			for (size_t i = 0; i < Count; i++)
			{
				NewArrPtr[i] = ArrPtr[i];
			}

			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = NewArrPtr;
		ArrCount = _Value;

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr ;
};

