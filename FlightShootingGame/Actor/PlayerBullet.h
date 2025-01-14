#pragma once

#include <Actor/DrawableActor.h>

class PlayerBullet : public DrawableActor
{
	RTTI_DECLARATIONS(PlayerBullet, DrawableActor)
public:
	// 탄약은 생성할 때 위치를 전달 받아야 함
	PlayerBullet(const Vector2& _pos);

	virtual void Update(float _dTime) override;

private:
	// 이동 관련 변수
	// 이동 속력(단위 : 칸/초)
	float  mSpeed = 20.0f;

	// y 위치
	float mPosY = 0.0f;
};