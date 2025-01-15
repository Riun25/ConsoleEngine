#include "Player.h"
#include "Engine/InputManager.h"
#include "Engine/Engine.h"
#include "Actor/PlayerBullet.h"

//Todo : 화면의 최대넓이를 현재 40으로 지정했는데 ScreenMax 변수를 어디에 처리할지 생각해보기
Player::Player(const char* _img)
	: Super(_img)
{
	// 플레이어 시작 위치
	pos = Vector2(Engine::Get().ScreenSize().x / 2, Engine::Get().ScreenSize().y - 1);
}

void Player::Update(float _dTime)
{
	// 부모 함수 호출
	Super::Update(_dTime);

	// 탄약 발사
	if (InputManager::Get().GetKeyDown(VK_SPACE))
	{
		Vector2 bulletPos(pos.x + width / 2, pos.y - 1);
   		Engine::Get().AddActor(new PlayerBullet(bulletPos));
	}

	// 키 입력 처리
	if (InputManager::Get().GetKey(VK_LEFT))
	{
		// 새 위치 계산
		Vector2 newPos = pos;
		--newPos.x;
		if (newPos.x < 0)
		{
			newPos.x = 0;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_RIGHT))
	{
		// 새 위치 계산
		Vector2 newPos = pos;
		++newPos.x;
		if (newPos.x > 27)
		if (newPos.x > Engine::Get().ScreenSize().x - width)
		{
			newPos.x = Engine::Get().ScreenSize().x - width;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_UP))
	{
		// 새 위치 계산
		Vector2 newPos = pos;
		--newPos.y;
		if (newPos.y < 0)
		{
			newPos.y = 0;
		}

		SetPosition(newPos);
	}

	if (InputManager::Get().GetKey(VK_DOWN))
	{
		// 새 위치 계산
		Vector2 newPos = pos;
		++newPos.y;
		if (newPos.y > 24)
		{
			newPos.y = 24;
		}

		SetPosition(newPos);
	}
}
