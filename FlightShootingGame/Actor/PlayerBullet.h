#pragma once

#include <Actor/DrawableActor.h>

class PlayerBullet : public DrawableActor
{
	RTTI_DECLARATIONS(PlayerBullet, DrawableActor)
public:
	// ź���� ������ �� ��ġ�� ���� �޾ƾ� ��
	PlayerBullet(const Vector2& _pos);

	virtual void Update(float _dTime) override;

private:
	// �̵� ���� ����
	// �̵� �ӷ�(���� : ĭ/��)
	float  mSpeed = 20.0f;

	// y ��ġ
	float mPosY = 0.0f;
};