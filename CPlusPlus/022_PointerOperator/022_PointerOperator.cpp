

#include <iostream>

void ValueChange(int* Ptr, int _1)
{
    // 주소값을 건드림으로써 함수 외부의 인자에 영향을 줄 수 있다.
    // 포인터를 쓰지않으면 별개의 변수가 되어 영향이 가지 않는다.

    // 100번지에 있는 값을 10에서  _1 값으로 바꾼다.
    // 함수가 끝나면 외부에서 들어온 인자가 _1의 값으로 바뀌어 적용된다.
    *Ptr = _1;
}

void Damage(int* _hp, int Damage)
{
    *_hp -= Damage;

    if (_hp <= 0)
    {
        int A = 0;
    }
}

int main()
{
    {
        int Value = 10;

        // 모든 변수는 

        // 포인터의 주소값이 따로 있다.
        int* Ptr = &Value;

        // 다중 포인터 
        // 10이라는 값이 있는데 주소만 100번지이다,  
        // 변수의 이름이 있으면 값과 주소는 항상 존재한다.

        // 포인터는 값은 동일하지만 주소값만 다를뿐이다.
        int** PtrPtr = &Ptr;

        // 그 위치의 메모리를 사용하겠다.
        // 포인터 변수의 앞에 *을 붙이는 연산자는
        // *Ptr 100번지의 값을 사용하겠다.
        
        ValueChange(Ptr, 30);
        ValueChange(&Value, 30);
    }

    {
        int PlayerHp = 10;

        // 함수는 기능을 분리해서 가독성을 좋게하기 위해서이다.
        Damage(&PlayerHp, 10);

    }
}
