#include "Player.h"
#include "Engine/InputManager.h"

//Todo : ȭ���� �ִ���̸� ���� 40���� �����ߴµ� ScreenMax ������ ��� ó������ �����غ���
Player::Player(char _img)
	: Super(_img)
{
}

void Player::Update(float _dTime)
{
	// �θ� �Լ� ȣ��
	Super::Update(_dTime);

	// Ű �Է� ó��
	if (InputManager::Get().GetKey(VK_LEFT))
	{
		// �� ��ġ ���
		Vector2 newPos = pos;
		--newPos.x;
		if (newPos.x < 0)
		{
			newPos.x = 0;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_RIGHT))
	{
		// �� ��ġ ���
		Vector2 newPos = pos;
		++newPos.x;
		if (newPos.x > 40)
		{
			newPos.x = 40;
		}

		SetPosition(newPos);
	}
}
