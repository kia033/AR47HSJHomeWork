#pragma once

class Player
{
public:
	Player();
	void Damage(int _Damage);

	// �����Ϸ��� ���� ���Ѵ�.
	void Test();

private:
	int Hp = 100;
	int Att = 10;
};

// int Value = 20;