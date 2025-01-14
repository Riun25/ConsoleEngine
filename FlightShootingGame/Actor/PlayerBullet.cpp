#include "PlayerBullet.h"
#include <cmath>
PlayerBullet::PlayerBullet(const Vector2& _pos)
	: DrawableActor("!")
{
	// 탄약 위치 설정
	this->pos = _pos;
	mPosY = static_cast<float>(_pos.y);
}

void PlayerBullet::Update(float _dTime)
{
	Super::Update(_dTime);

	// 위치 갱신
	mPosY -= mSpeed * _dTime;
	pos.y = static_cast<int>(roundf(mPosY));
	//--pos.y;

	// y 좌표가 화면을 벗어나면 액터 삭제
	if (pos.y < 0.0f)
	{
		Destroy();
		return;
	}
}
