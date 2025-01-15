#pragma once
#include "Actor/DrawableActor.h"

// �� ź�� Ŭ����
class EnemyBullte : public DrawableActor
{
	RTTI_DECLARATIONS(EnemyBullte, DrawableActor)

public:
	EnemyBullte(const Vector2& _pos);

	virtual void Update(float _dTime) override;

private:
	// �̵� ���� ����(�Ӽ�)
	float mSpeed = 15.0f;
	float mPosY = 0.0f;
};