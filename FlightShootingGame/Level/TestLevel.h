#pragma once
#include "Level/Level.h"

class TestLevel :public	Level
{
	// RTTI ����
	RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();
	~TestLevel();

	virtual void Update(float _dTime) override;


private:
	// �� ���� �Լ�
	void SpawnEnemy(float _dTime);

	// �÷��̾� ź��� ���� �浹 ó��
	void ProcessCollisionPlayerBulletAndEnemy();

	// �� ź��� �÷��̾��� �浹 ó��
	void ProcessCollisionPlayerAndEnemyBullet();
private:
	// ����
	int mScore = 0;
};

