#include "PlayerBullet.h"
#include <cmath>
PlayerBullet::PlayerBullet(const Vector2& _pos)
	: DrawableActor("!")
{
	// ź�� ��ġ ����
	this->pos = _pos;
	mPosY = static_cast<float>(_pos.y);
}

void PlayerBullet::Update(float _dTime)
{
	Super::Update(_dTime);

	// ��ġ ����
	mPosY -= mSpeed * _dTime;
	pos.y = static_cast<int>(roundf(mPosY));
	//--pos.y;

	// y ��ǥ�� ȭ���� ����� ���� ����
	if (pos.y < 0.0f)
	{
		Destroy();
		return;
	}
}
