#include "../FlightShootingGame/Level/TestLevel.h"
#include "Engine/Engine.h"
#include "Engine/InputManager.h"
#include "Actor/Player.h"
#include "Actor/PlayerBullet.h"
#include "Actor/Enemy.h"
#include "Actor/EnemyBullet.h"

// �� ĳ���� ����
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

	// ���� ���
	SetColor(COLOR::CYAN);
	InputManager::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y + 1);
	Log("Score: %d", mScore);
	SetColor(COLOR::WHITE);

	// �� ����
	SpawnEnemy(_dTime);

	// �÷��̾� ź��� ���� �浹 ó�� 
	ProcessCollisionPlayerBulletAndEnemy();

	// �� ź��� �÷��̾��� �浹 ó��
	ProcessCollisionPlayerAndEnemyBullet();
}

void TestLevel::SpawnEnemy(float _dTime)
{
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

	static int length = sizeof(enemyType) / sizeof(enemyType[0]);
	int index = Random(0, length - 1);

	// �� ����
	AddActor(new Enemy(enemyType[index], Random(5, 15)));
}

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
	// ź�� �� �� ĳ���� �迭 ����
	List<PlayerBullet*> bullets;
	List<Enemy*> enemies;

	// ������ ��ġ�� ���͸� ��ȸ�ϸ鼭 ����Ʈ ä���
	for (Actor* pActor : mActorVec)
	{
		// ź������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���
		PlayerBullet* bullet = pActor->As<PlayerBullet>();
		if (bullet)
		{
			bullets.PushBack(bullet);
			continue;
		}
		// ������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���
		Enemy* enemy = pActor->As<Enemy>();
		if (enemy)
		{
			enemies.PushBack(enemy);
		}
	}

	// ���� ó��
	if (bullets.Size() == 0 || enemies.Size() == 0)
	{
		return;
	}

	// �� �迭�� ��ȸ�ϸ鼭 �浹 ó��
	for (PlayerBullet* bullet : bullets)
	{
		for (Enemy* enemy : enemies)
		{
			// ���� ��Ȱ��ȭ ���¶�� �ǳʶٱ�
			if (!enemy->IsActive())
			{
				continue;
			}

			// �浹 ó��
			if (enemy->Intersect(*bullet))
			{
				// �浹������ �� ����
				enemy->Destroy();

				// ź�൵ ����
				bullet->Destroy();

				// ���� �߰�
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
		// �÷��̾� ���� ã��
		if (!player)
		{
			player = pActor->As<Player>();
			continue;
		}

		// ź������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���
		EnemyBullte* bullet = pActor->As<EnemyBullte>();
		if (bullet)
		{
			bullets.PushBack(bullet);
			continue;
		}
	}

	// ���� ó��
	if (player == nullptr || bullets.Size() == 0)
	{
		return;
	}

	// �迭�� ��ȸ�ϸ鼭 �浹 ó��
	for (EnemyBullte* bullet : bullets)
	{
		// �÷��̾ ��Ȱ��ȭ ���¶�� ����
		if (!player->IsActive())
		{
			return;
		}

		// �浹 ó��
		if (player->Intersect(*bullet))
		{
			// �浹������ �÷��̾� ����
			player->Destroy();

			int y = Engine::Get().ScreenSize().y;
			int x = player->Position().x - player->Width() / 2;
			InputManager::Get().SetCursorPosition(x, y - 1);
			Log("  .  ");
			InputManager::Get().SetCursorPosition(x, y);
			Log(".:��:.");
			InputManager::Get().SetCursorPosition(x, y + 1);
			Log("GameOver!\n");

			// �� 2�ʰ� ����
			Sleep(2000);

			// ���� ����
			Engine::Get().QuitGame();
		}
	}
}
