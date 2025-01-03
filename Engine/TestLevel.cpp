#include "TestLevel.h"
#include "Actor/Actor.h"
#include "Engine/Engine.h"
#include "Engine/InputManager.h"
#include <Windows.h>
#include <iostream>


TestLevel::TestLevel()
{
	// �׽�Ʈ�� ���� �߰�
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
}

TestLevel::~TestLevel()
{

}

void TestLevel::Update(float _dTime)
{
	// �Է� Ȯ��
	if (Engine::Get().GetInputManager()->GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().GetIsQuit();
	}

	std::cout << "DeltaTime: " << _dTime << ", FPS: " << 1.0f/ _dTime << "\n";
}
