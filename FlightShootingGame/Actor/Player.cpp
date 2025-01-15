#include "Player.h"
#include "Engine/InputManager.h"
#include "Engine/Engine.h"
#include "Actor/PlayerBullet.h"

//Todo : ȭ���� �ִ���̸� ���� 40���� �����ߴµ� ScreenMax ������ ��� ó������ �����غ���
Player::Player(const char* _img)
	: Super(_img)
{
	// �÷��̾� ���� ��ġ
	pos = Vector2(Engine::Get().ScreenSize().x / 2, Engine::Get().ScreenSize().y - 1);
}

void Player::Update(float _dTime)
{
	// �θ� �Լ� ȣ��
	Super::Update(_dTime);

	// ź�� �߻�
	if (InputManager::Get().GetKeyDown(VK_SPACE))
	{
		Vector2 bulletPos(pos.x + width / 2, pos.y - 1);
   		Engine::Get().AddActor(new PlayerBullet(bulletPos));
	}

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
		if (newPos.x > 27)
		if (newPos.x > Engine::Get().ScreenSize().x - width)
		{
			newPos.x = Engine::Get().ScreenSize().x - width;
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
		if (newPos.y > 24)
		{
			newPos.y = 24;
		}

		SetPosition(newPos);
	}
}
