#include "Enemy.h"
#include "Engine/Engine.h"

Enemy::Enemy(const char* _img, int _posY)
	:DrawableActor(_img)
{
	// ���� ��ġ ����
	pos = Vector2(10, _posY);

	// �������� �̵��� ���� ����
	int random = Random(1, 10);
	if (random % 2 == 0)
	{
		// ¦���� ��쿡�� �������� �̵��ϵ��� ����
		mDir = DIRECTION::LEFT;

		// x��ǥ�� ȭ�� ������ ����
		mPosX = static_cast<float>(Engine::Get().ScreenSize().x - width);
	}
	else
	{
		// Ȧ���� ��쿡�� ���������� �̵��ϵ��� ����
		mDir = DIRECTION::RIGHT;

		// x��ǥ�� 0���� ����
		mPosX = 0.0f;
	}

	// ���� ��ġ ����
	pos = Vector2(static_cast<int>(mPosX), _posY);
}

void Enemy::Update(float _dTime)
{
	Super::Update(_dTime);

	// �¿� �̵�
	float factor = mDir == DIRECTION::LEFT ? -1.0f: 1.0f;
	mPosX += mSpeed * factor * _dTime;
	pos.x = static_cast<int>(mPosX);

	// ȭ�� �� ����� ����
	if (pos.x < 0.0f || pos.x > Engine::Get().ScreenSize().x - width)
	{
		Destroy();
	}
}
