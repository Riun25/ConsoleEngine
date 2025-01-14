#include "../FlightShootingGame/Level/TestLevel.h"
#include "Engine/Engine.h"
#include "Engine/InputManager.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"

TestLevel::TestLevel()
{
	AddActor(new Player("<A>"));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float _dTime)
{
	Super::Update(_dTime);

	// ���� ó��
	if (_dTime > 1.0f)
	{
		return;
	}


	// ESC Ű�� ����
	if (InputManager::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	// �� ����
	static float elapseTime = 0.0f;
	static float spawnTime = RendomPercent(1.0f, 3.0f);

	// Ÿ�̸�
	elapseTime += _dTime;
	if (elapseTime < spawnTime)
	{
		return;
	}

	// Ÿ�̸� ����
	elapseTime = 0.0f;
	spawnTime = RendomPercent(1.0f, 3.0f);

	// �� ����
	AddActor(new Enemy("[[0]]", Random(1, 10)));

}
