
#include <iostream>

int main()
{
	int Left = 0b00000000000000000000000000000010;  // 2
	int Right = 0b00000000000000000000000000000001;  // 1
	int Result = 0b00000000000000000000000000000000;  // 0


	// 
	// ��Ʈ���� ������.
	// Not
	// ��Ʈ 0 �� 1��, 1�� 0���� ������Ų��.
	// 0b00000000000000000000000000000000
	Result = ~0; // -1

	// and
	// a�װ� b���� ��Ʈ�� ���Ͽ� �Ѵ� 1�϶��� 1�� ���� �ش�.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000000   / 0
	Result = Left & Right; 

	// or
	// a���̳� b���� ���� �ϳ��� 1�̶�� ������ 1�� ���� �ش�.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000011   / 3
	Result = Left | Right;

	// xor
	// a�װ� b���� ���� �ٸ����� ������ 1�� �ش�.
	// ���� 1�� ���� 0���� ���� ������ false�� �ȴ�.
	// 0b00000000000000000000000000000010
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000000011   / 3
	Result = Left ^ Right;

	// true �� false ���� ������ ��Ȯ�� �ǹ̸� 
	// �ѹ� ¤�� �Ѿ�ڽ��ϴ�.
	// Ư�� �޸� ������ ��Ʈ�� ���� 0�̶�� false �� ����
	// Ư�� �޸� ������ ��Ʈ�� �� 1���� 1�� �ִٸ� true �� ��
	
	bool bResult = 2;
	bResult = 3 && 10023123;

	// ��Ʈ ����Ʈ ����
	// <<  ��Ʈ ���� ����Ʈ
	// >>  ��Ʈ ������ ����Ʈ
	// 0b00000000000000000000000000000001
	// 0b00000000000000000000000000001000

	Result = 1 << 3;

	// �̷����� � ���� �߻����� �� �� ���� �ڵ�� ���ʿ� ���� �ʴ´�.
	Result = 1 << 33;

	// �����Ҵ� ������
	// Ư�� �޸𸮿����� ���� ������� �ϴ� ���� �����ڿ� ������.
	//���� ����	a += b	��	��	T & T::operator+=(const T & b);	T& operator+=(T & a, const T & b);
	//���� ����	a -= b	��	��	T & T::operator-=(const T & b);	T& operator-=(T & a, const T & b);
	//���� ����	a *= b	��	��	T & T::operator*=(const T & b);	T& operator*=(T & a, const T & b);
	//������ ����	a /= b	��	��	T & T::operator/=(const T & b);	T& operator/=(T & a, const T & b);
	//��ⷯ ����	a %= b	��	��	T & T::operator%=(const T & b);	T& operator%=(T & a, const T & b);
	//��Ʈ AND ����	a &= b	��	��	T & T::operator&=(const T & b);	T& operator&=(T & a, const T & b);
	//��Ʈ OR ����	a |= b	��	��	T & T::operator|=(const T & b);	T& operator|=(T & a, const T & b);
	//��Ʈ XOR ����	a ^= b	��	��	T & T::operator^=(const T & b);	T& operator^=(T & a, const T & b);
	//��Ʈ ���� ����Ʈ ����	a <<= b	��	��	T & T::operator<<=(const T & b);	T& operator<<=(T & a, const T & b);
	//��Ʈ ������ ����Ʈ ����	a >>= b	��	��	T & T::operator>>=(const T & b);	T& operator>>=(T & a, const T & b);

	int Value = 20;

	Value += 10;

	Value += Value;
	Value = 1;
	Value <<= 3; // 8
}