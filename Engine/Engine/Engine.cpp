#include "Engine.h"
#include <Windows.h>
#include <iostream>

Engine::Engine()
	: mIsQuit(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// ���� Ÿ�� ������ ����
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU �ð� ���
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	// ���� �ð� �� ���� �ð��� ���� �Լ�
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = 0;

	// ������ ����
	float targetFrameRate = 60.0f;

	// �� ������ �ð� ���
	float targetOneFrameTime = 1.0f / targetFrameRate;


	// Game-Loop
	while (true)
	{
		// ���� ����
		if (mIsQuit)
		{
			break;
		}

		// ���� ������ �ð� ����
		//currentTime = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// ������ �ð� ���
		float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);



		// ������ Ȯ��
		if (deltaTime >= targetOneFrameTime)
		{
			// �Է� ó�� (���� Ű�� ���� ���� Ȯ��)
			ProcessInput();

			Update(deltaTime);
			Draw();

			// Ű ���� ����
			SavePreviousKeyStates();

			// ���� ������ �ð� ����
			previousTime = currentTime;
		}
	}
}

bool Engine::GetKey(int _key)
{
	return mKeyStateArr[_key].isKeyDown;
}

bool Engine::GetKeyDown(int _key)
{
	return mKeyStateArr[_key].isKeyDown && !mKeyStateArr[_key].wasKeyDown;
}

bool Engine::GetKeyUp(int _key)
{
	return !mKeyStateArr[_key].isKeyDown && mKeyStateArr[_key].wasKeyDown;
}

void Engine::QuitGame()
{
	// ���� �÷��� ����
	mIsQuit = true;
}

void Engine::ProcessInput()
{
	for (int idx = 0; idx < 255; idx++)
	{
		mKeyStateArr[idx].isKeyDown = (GetAsyncKeyState(idx) & 0x8000) ? true : false;
	}
}

void Engine::Update(float _dTime)
{
	// ESCŰ�� ���� ����
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		QuitGame();
	}

	std::cout << "DeltaTime: " << _dTime << ", FPS: " << (1.0f / _dTime) << "\n";
}

void Engine::Draw()
{
}

void Engine::SavePreviousKeyStates()
{
	for (int idx = 0; idx < 255; idx++)
	{
		mKeyStateArr[idx].wasKeyDown = mKeyStateArr[idx].isKeyDown;
	}
}
