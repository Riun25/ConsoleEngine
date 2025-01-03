#pragma once
#include "PreCompiledHeader.h"

// ���� ����
class Actor;

class ENGINE_API Level
{
public:
	Level();
	virtual ~Level();

	//���� �߰� �Լ�
	void AddActor(Actor* _newActor);

	// ���� ó�� �Լ�
	virtual void Update(float _dTime);
	virtual void Draw();

protected:
	// ���� ������ ��ġ�Ǵ� ��ü(����) �迭
	Actor** mActors;
	// ������ �� �ִ� ������ ũ��
	int mCapacity;
	// ������ ��
	int mCount;
};

