#pragma once
#include "Actor/DrawableActor.h"

// 적 탄약 클래스
class EnemyBullte : public DrawableActor
{
	RTTI_DECLARATIONS(EnemyBullte, DrawableActor)

public:
	EnemyBullte(const Vector2& _pos);

	virtual void Update(float _dTime) override;

private:
	// 이동 관련 변수(속성)
	float mSpeed = 15.0f;
	float mPosY = 0.0f;
};