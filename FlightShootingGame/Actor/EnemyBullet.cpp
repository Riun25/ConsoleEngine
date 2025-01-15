#include "EnemyBullet.h"
#include "Engine/Engine.h"

EnemyBullte::EnemyBullte(const Vector2& _pos)
	:DrawableActor("*")
{
	// 위치 설정
	pos = _pos;
	mPosY = static_cast<float>(_pos.y);
}

void EnemyBullte::Update(float _dTime)
{
	Super::Update(_dTime);

	// 이동로직
	mPosY += mSpeed * _dTime;
	pos.y = static_cast<int>(mPosY);

	// 화면 벗어나면 제거
	if (mPosY > Engine::Get().ScreenSize().y - 1)
	{
		Destroy();
	}
}
