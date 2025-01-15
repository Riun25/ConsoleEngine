#include "EnemyBullet.h"
#include "Engine/Engine.h"

EnemyBullte::EnemyBullte(const Vector2& _pos)
	:DrawableActor("*")
{
	// ��ġ ����
	pos = _pos;
	mPosY = static_cast<float>(_pos.y);
}

void EnemyBullte::Update(float _dTime)
{
	Super::Update(_dTime);

	// �̵�����
	mPosY += mSpeed * _dTime;
	pos.y = static_cast<int>(mPosY);

	// ȭ�� ����� ����
	if (mPosY > Engine::Get().ScreenSize().y - 1)
	{
		Destroy();
	}
}
