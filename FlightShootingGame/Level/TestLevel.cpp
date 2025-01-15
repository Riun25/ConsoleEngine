#include "../FlightShootingGame/Level/TestLevel.h"
#include "Engine/Engine.h"
#include "Engine/InputManager.h"
#include "Actor/Player.h"
#include "Actor/PlayerBullet.h"
#include "Actor/Enemy.h"
#include "Actor/EnemyBullet.h"

// 적 캐릭터 종류
static const char* enemyType[]
{
	";(^);",
	"zZTZz",
	"oO&Oo",
	"<=-=>",
	")~O~(",
	"[[0]]"
};

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

	// 점수 출력
	SetColor(COLOR::CYAN);
	InputManager::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y + 1);
	Log("Score: %d", mScore);
	SetColor(COLOR::WHITE);

	// 적 생성
	SpawnEnemy(_dTime);

	// 플레이어 탄약과 적의 충돌 처리 
	ProcessCollisionPlayerBulletAndEnemy();

	// 적 탄약과 플레이어의 충돌 처리
	ProcessCollisionPlayerAndEnemyBullet();
}

void TestLevel::SpawnEnemy(float _dTime)
{
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

	static int length = sizeof(enemyType) / sizeof(enemyType[0]);
	int index = Random(0, length - 1);

	// 적 생성
	AddActor(new Enemy(enemyType[index], Random(5, 15)));
}

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
	// 탄약 및 적 캐릭터 배열 선언
	List<PlayerBullet*> bullets;
	List<Enemy*> enemies;

	// 레벨에 배치된 엑터를 순회하면서 리스트 채우기
	for (Actor* pActor : mActorVec)
	{
		// 탄약으로 형변환 후 확인해서 리스트 채우기
		PlayerBullet* bullet = pActor->As<PlayerBullet>();
		if (bullet)
		{
			bullets.PushBack(bullet);
			continue;
		}
		// 적으로 형변환 후 확인해서 리스트 채우기
		Enemy* enemy = pActor->As<Enemy>();
		if (enemy)
		{
			enemies.PushBack(enemy);
		}
	}

	// 예외 처리
	if (bullets.Size() == 0 || enemies.Size() == 0)
	{
		return;
	}

	// 두 배열을 순회하면서 충돌 처리
	for (PlayerBullet* bullet : bullets)
	{
		for (Enemy* enemy : enemies)
		{
			// 적이 비활성화 상태라면 건너뛰기
			if (!enemy->IsActive())
			{
				continue;
			}

			// 충돌 처리
			if (enemy->Intersect(*bullet))
			{
				// 충돌했으면 적 제거
				enemy->Destroy();

				// 탄약도 제거
				bullet->Destroy();

				// 점수 추가
				mScore += 100;
			}
		}
	}
}

void TestLevel::ProcessCollisionPlayerAndEnemyBullet()
{
	Player* player = nullptr;
	List<EnemyBullte*> bullets;

	for (Actor* pActor : mActorVec)
	{
		// 플레이어 엑터 찾기
		if (!player)
		{
			player = pActor->As<Player>();
			continue;
		}

		// 탄약으로 형변환 후 확인해서 리스트 채우기
		EnemyBullte* bullet = pActor->As<EnemyBullte>();
		if (bullet)
		{
			bullets.PushBack(bullet);
			continue;
		}
	}

	// 예외 처리
	if (player == nullptr || bullets.Size() == 0)
	{
		return;
	}

	// 배열을 순회하면서 충돌 처리
	for (EnemyBullte* bullet : bullets)
	{
		// 플레이어가 비활성화 상태라면 종료
		if (!player->IsActive())
		{
			return;
		}

		// 충돌 처리
		if (player->Intersect(*bullet))
		{
			// 충돌했으면 플레이어 제거
			player->Destroy();

			int y = Engine::Get().ScreenSize().y;
			int x = player->Position().x - player->Width() / 2;
			InputManager::Get().SetCursorPosition(x, y - 1);
			Log("  .  ");
			InputManager::Get().SetCursorPosition(x, y);
			Log(".:∀:.");
			InputManager::Get().SetCursorPosition(x, y + 1);
			Log("GameOver!\n");

			// 약 2초간 정지
			Sleep(2000);

			// 게임 종료
			Engine::Get().QuitGame();
		}
	}
}
