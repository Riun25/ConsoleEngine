#pragma once

#include "Actor/DrawableActor.h"

class Enemy : public DrawableActor
{
	// �� ĳ���Ͱ� �̵��� ����
	enum class DIRECTION
	{
		NONE = -1,
		LEFT,
		RIGHT
	};

	RTTI_DECLARATIONS(Enemy, DrawableActor)

public:
	// �׸� �� ����� ���ڿ� ���� ���� y��ġ�� ���� ����
	Enemy(const char* _img, int _posY);

	virtual void Update(float _dTime) override;

private:

	DIRECTION mDir;

	// �¿� �̵��� �ʿ��� ����
	float mPosX = 0.0f;
	float mSpeed = 5.0f;
};