#include "Level.h"
#include "../Actor/Actor.h"
#include <iostream>
Level::Level()
	:mActors(nullptr), mCapacity(4), mCount(0)
{
	// ���� �迭 ����
	mActors = new Actor * [mCapacity];

	// �ʱ�ȭ
	memset(mActors, 0, sizeof(size_t) * mCapacity); // 0 : nullptr
}

Level::~Level()
{
	// ���� �迭 �޸� ����
	for (int idx = 0; idx < mCount; idx++)
	{
		// ���� ����
		delete mActors[idx];
	}
	 // ���� �迭 ����
	delete[] mActors;
}

void Level::AddActor(Actor* _newActor)
{
	// ���� �Ҵ�� ������ ������� Ȯ��
	if (mCount == mCapacity)
	{
		// ���� �߰� �Ҵ�
		int newCapacity = mCapacity * 2;

		// �ӽ� ����
		Actor** temp = new Actor * [newCapacity];

		// ���� �� ����
		memcpy(temp, mActors, sizeof(size_t) * mCapacity);

		// ���� �迭 ����
		delete[] mActors;

		// �迭 ��ü
		mActors = temp;
		temp = nullptr;

		// ũ�� ����
		mCapacity = newCapacity;
	}
	// ���� �߰�
	mActors[mCount] = _newActor;
	mCount++;
}

void Level::Update(float _dTime)
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
	for (int idx = 0; idx < mCount; idx++)
	{
		mActors[idx]->Update(_dTime);
	}
}

void Level::Draw()
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
	for (int idx = 0; idx < mCount; idx++)
	{
		mActors[idx]->Draw();
	}
}
