#include "Player.h"
#include "Engine/InputManager.h"

//Todo : ȭ���� �ִ���̸� ���� 40���� �����ߴµ� ScreenMax ������ ��� ó������ �����غ���
Player::Player(const char* _img)
	: Super(_img)
{
	// �÷��̾� ���� ��ġ
	pos = Vector2(0, 18);
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
		if (newPos.x > 28)
		{
			newPos.x = 28;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_UP))
	{
		// �� ��ġ ���
		Vector2 newPos = pos;
		--newPos.y;
		if (newPos.y < 0)
		{
			newPos.y = 0;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_DOWN))
	{
		// �� ��ġ ���
		Vector2 newPos = pos;
		++newPos.y;
		if (newPos.y > 25)
		{
			newPos.y = 25;
		}

		SetPosition(newPos);
	}
}
