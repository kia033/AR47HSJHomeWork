#pragma once

typedef int DataType;

// ���� :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(int _Value) 
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{

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
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		size_t OtherArrCount = _Other.ArrCount;


		this->ArrCount = OtherArrCount;
		this->ArrPtr = new DataType[OtherArrCount];

		int Count = ArrCount <= OtherArrCount ? ArrCount : OtherArrCount;

		for (size_t i = 0; i < Count; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
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
		DataType* NewArrPtr = new DataType[_Value];

		if (nullptr != ArrPtr)
		{


			int Count = ArrCount <= _Value ? ArrCount : _Value;

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

