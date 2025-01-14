#pragma once

#include "Actor/DrawableActor.h"

class Enemy : public DrawableActor
{
	// 적 캐릭터가 이동할 방향
	enum class DIRECTION
	{
		NONE = -1,
		LEFT,
		RIGHT
	};

	RTTI_DECLARATIONS(Enemy, DrawableActor)

public:
	// 그릴 때 사용할 문자열 값과 생성 y위치를 전달 받음
	Enemy(const char* _img, int _posY);

	virtual void Update(float _dTime) override;

private:

	DIRECTION mDir;

	// 좌우 이동에 필요한 변수
	float mPosX = 0.0f;
	float mSpeed = 5.0f;
};