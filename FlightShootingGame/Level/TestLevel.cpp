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

	// 예외 처리
	if (_dTime > 1.0f)
	{
		return;
	}


	// ESC 키로 종료
	if (InputManager::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	// 적 생성
	static float elapseTime = 0.0f;
	static float spawnTime = RendomPercent(1.0f, 3.0f);

	// 타이머
	elapseTime += _dTime;
	if (elapseTime < spawnTime)
	{
		return;
	}

	// 타이머 리셋
	elapseTime = 0.0f;
	spawnTime = RendomPercent(1.0f, 3.0f);

	// 적 생성
	AddActor(new Enemy("[[0]]", Random(1, 10)));

}
