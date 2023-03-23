
#include <iostream>

class Number
{
private:
    int Value;

public:
    // 멤버 이니셜라이저.
    Number(int _Value)
        : Value(_Value)
    {
    }

    

    // 사칙 연산
    int operator =(int _Value)
    {
        return Value = _Value;
    }

    int operator +(int _Value)
    {
        return Value + _Value;
    }
    
    int operator -(int _Value)
    {
        return Value - _Value;
    }

    int operator *(int _Value)
    {
        return Value * _Value;
    }

    int operator /(int _Value)
    {
        return Value / _Value;
    }

    int operator %(int _Value)
    {
        return Value % _Value;
    }

    int operator ++()
    {
        return ++Value;
    }

    int operator ++(int _Value)
    {
        return Value++;
    }

    int operator --()
    {
        return --Value;
    }

    int operator --(int _Value)
    {
        return Value--;
    }

    int operator +()
    {
        return +Value;
    }

    int operator -()
    {
        return -Value;
    }


    // 복합 할당 연산자
    int operator +=(int _Value)
    {
        return Value += _Value;
    }

    int operator -=(int _Value)
    {
        return Value -= _Value;
    }

    int operator *=(int _Value)
    {
        return Value *= _Value;
    }

    int operator /=(int _Value)
    {
        return Value /= _Value;
    }

    int operator %=(int _Value)
    {
        return Value %= _Value;
    }


    // 비교 연산자
    bool operator ==(int _Value)
    {
        return Value == _Value;
    }

    bool operator !=(int _Value)
    {
        return Value != _Value;
    }

    bool operator <(int _Value)
    {
        return Value < _Value;
    }

    bool operator <=(int _Value)
    {
        return Value <= _Value;
    }

    bool operator >(int _Value)
    {
        return Value > _Value;
    }

    bool operator >=(int _Value)
    {
        return Value >= _Value;
    }

    // 논리 연산자
    bool operator !()
    {
        return !Value;
    }
    bool operator &&(int _Value)
    {
        return Value && _Value;
    }

    bool operator ||(int _Value)
    {
        return Value || _Value;
    }

    // 
    int operator [](size_t _Value)
    {
        return Value;
    }
};

int main()
{

    {
   
        Number Value = 10;
		/*printf("%d\n", -Value);

		-Value;
		printf("%d\n", +Value);

		+Value;
		printf("%d\n", Value);*/

        
    }

}

