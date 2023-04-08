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
			MsgBoxAssert("0ũ���� �迭�� ����� �����ϴ�.");
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
		// ������ �޸𸮸� �����
		// ���� ������ �Ѵ�.
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

	// ���� �ѱ�� �����. ���� 
	// ���� ������ ���
	// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
	// ���Ҹ� ����� �ȵȴ�.

	// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.

	void ReSize(int _Value)
	{
		if (_Value <= 0)
		{
			MsgBoxAssert("Resize�� ���ڰ� 0���� �۽��ϴ�");
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

