#include "PreCompiledHeader.h"
#include "Engine.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Level/Level.h"

// ����ƽ ���� �ʱ�ȭ
Engine* Engine::instance = nullptr;

Engine::Engine()
	: mIsQuit(false), mMainLevel(nullptr)
{
	// �̱��� ��ü ����
	instance = this;
	mpTimeManager = new TimeManager();
	mpInputManager = new InputManager();
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
		Draw();
	}
}

void Engine::LoadLevel(Level* _newLevel)
{
	// ���� ������ �ִٸ� ���� �� ��ü
	

	// ���� ���� ����
	mMainLevel = _newLevel;
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
	if (!instance)
	{
		instance = new Engine();
	}
	return *instance;
}

TimeManager* Engine::GetTimeManager()
{
	return mpTimeManager;
}

InputManager* Engine::GetInputManager()
{
	return mpInputManager;
}

void Engine::Update(float _dTime)
{
	// ���� ������Ʈ
	if (mMainLevel != nullptr)
	{
		mMainLevel->Update(_dTime);
	}

	std::cout << "FPS: " << _dTime << "\n";
}

void Engine::Draw()
{
	if (mMainLevel != nullptr)
	{
		mMainLevel->Draw();
	}
}

void Engine::HandleGameLoop()
{
	mpInputManager->Update();
	Update(mpTimeManager->GetDeltaTime());

	// Ű ���� ����
	mpInputManager->SavePreviousKeyStates();
	// ���� ������ �ð� ����
	mpTimeManager->SaveCurrentTime();
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
