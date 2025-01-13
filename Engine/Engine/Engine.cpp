#include "PreCompiledHeader.h"
#include "Engine.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Level/Level.h"
#include "Actor/Actor.h"

// ����ƽ ���� �ʱ�ȭ
Engine* Engine::gInstance = nullptr;

Engine::Engine()
	: mIsQuit(false), mMainLevel(nullptr)
{
	// �̱��� ��ü ����
	gInstance = this;
	mpTimeManager = new TimeManager();
	mpInputManager = &InputManager::Get();
}

Engine::~Engine()
{
	delete mpInputManager;
	delete mpTimeManager;

	// ���� ���� �޸� ����
	if (mMainLevel != nullptr)
	{
		delete mMainLevel;
	}
}

void Engine::Run()
{
	mpTimeManager->Initialize();
	mpTimeManager->LimitFrame(60.0f);

	// Game-Loop
	while (true)
	{
		// ���� ����
		if (mIsQuit)
		{
			break;
		}

		mpTimeManager->Update();
		ProcessFrame();
		if (mShouldUpdate)
		{
			Draw();
		}
	}
}

void Engine::LoadLevel(Level* _newLevel)
{
	// ���� ������ �ִٸ� ���� �� ��ü
	

	// ���� ���� ����
	mMainLevel = _newLevel;
}

void Engine::AddActor(Actor* _newActor)
{
	// ���� ó��
	if (mMainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�
	mShouldUpdate = false;
	mMainLevel->AddActor(_newActor);
}

void Engine::DestroyActor(Actor* _targetActor)
{
	// ���� ó��
	if (mMainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�
	mShouldUpdate = false;
	_targetActor->Destroy();
}

void Engine::QuitGame()
{
	// ���� �÷��� ����
	mIsQuit = true;
}


bool const Engine::GetIsQuit()
{
	return mIsQuit;
}

Engine& Engine::Get()
{
	if (!gInstance)
	{
		gInstance = new Engine();
	}
	return *gInstance;
}

TimeManager* Engine::GetTimeManager()
{
	return mpTimeManager;
}

void Engine::Update(float _dTime)
{
	// ���� ������Ʈ
	if (mMainLevel != nullptr)
	{
		mMainLevel->Update(_dTime);
	}

	//std::cout << "FPS: " << _dTime << "\n";
}

void Engine::Clear()
{
	// ȭ���� 0,0���� �̵�
	mpInputManager->SetCursorPosition(0, 0);

	// ȭ�� �����
	int height = 30;
	for (int i = 0; i < height; i++)
	{
		Log("                              \n");
	}

	// ȭ���� 0,0���� �̵�
	mpInputManager->SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	// ȭ�� �����.
	Clear();

	if (mMainLevel != nullptr)
	{
		mMainLevel->Draw();
	}
}

void Engine::HandleGameLoop()
{
	mpInputManager->Update();

	// ������Ʈ ������ ���¿����� ������ ������Ʈ ó��
	if (mShouldUpdate)
	{
		Update(mpTimeManager->GetDeltaTime());
	}

	// Ű ���� ����
	mpInputManager->SavePreviousKeyStates();
	// ���� ������ �ð� ����
	mpTimeManager->SaveCurrentTime();

	// ���� ���� (���� ��û�� ���͵� ����)
	if (mMainLevel)
	{
		//mMainLevel->DestroyActor();
		mMainLevel->ProcessAddedAndDestroyedActor();
	}

	// ������ Ȱ��ȭ
	mShouldUpdate = true;
}

void Engine::ProcessFrame()
{
	if (mpTimeManager->IsLimitFrame())
	{
		// ������ Ȯ��
		if (mpTimeManager->CheckOverTargetFrame())
		{
			HandleGameLoop();
		}
	}
	else
	{
		HandleGameLoop();
	}
}
