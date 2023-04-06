#pragma once

typedef int DataType;

// 설명 :
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

	// 값을 넘기고 지운다. 숙제 
	// 삼항 연산자 사용
	// 기존의 할당된 배열을 알고 있는것은 
	// 섣불리 지우면 안된다.

	// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.

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

