#include "Player.h"
#include "BaseHeader.h"

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Damage(int _Value)
{
	if (_Value <= 0)
	{
		MsgBoxAssert("�������� 0 �����Դϴ�");

	}
}