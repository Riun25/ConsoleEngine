#include "Enemy.h"
#include "Engine/Engine.h"

Enemy::Enemy(const char* _img, int _posY)
	:DrawableActor(_img)
{
	// 시작 위치 설정
	pos = Vector2(10, _posY);

	// 랜덤으로 이동할 방향 선택
	int random = Random(1, 10);
	if (random % 2 == 0)
	{
		// 짝수인 경우에는 왼쪽으로 이동하도록 설정
		mDir = DIRECTION::LEFT;

		// x좌표를 화면 끝으로 설정
		mPosX = static_cast<float>(Engine::Get().ScreenSize().x - width);
	}
	else
	{
		// 홀수인 경우에는 오른쪽으로 이동하도록 설정
		mDir = DIRECTION::RIGHT;

		// x좌표를 0으로 설정
		mPosX = 0.0f;
	}

	// 시작 위치 설정
	pos = Vector2(static_cast<int>(mPosX), _posY);
}

void Enemy::Update(float _dTime)
{
	Super::Update(_dTime);

	// 좌우 이동
	float factor = mDir == DIRECTION::LEFT ? -1.0f: 1.0f;
	mPosX += mSpeed * factor * _dTime;
	pos.x = static_cast<int>(mPosX);

	// 화면 밖 벗어나면 삭제
	if (pos.x < 0.0f || pos.x > Engine::Get().ScreenSize().x - width)
	{
		Destroy();
	}
}
