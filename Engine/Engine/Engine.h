#pragma once
#include "Core.h"

// @refector : ������ �̱����� �ʿ�� ����. �Ŵ������� ��ǲ�� Ÿ���� �̱��̾�� �ϴ°� �´�. ���� �����Ѵ�.
class TimeManager;
class InputManager;
class Level;

// ���� Ŭ����
class ENGINE_API Engine
{
public:
	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	virtual ~Engine();

	// ���� ���� �Լ�
	void Run();

	// ���� �߰� �Լ�
	void LoadLevel(Level* _newLevel);

	// ���� ���� �Լ�
	void QuitGame();

	bool const GetIsQuit();

	// �̱��� ��ü ���� �Լ�
	static Engine& Get();

	// �Ŵ��� ���� �Լ�
	TimeManager* GetTimeManager();
protected:
	void Update(float _dTime);			// Tick();
	void Draw();						// Render();
	void HandleGameLoop();
	void ProcessFrame();

private:
	// �̱��� ������ ���� ���� ���� ����
	static Engine* gInstance;

	// ID/�̸� ��


	// ������ �� ������ ����
	bool mIsQuit;

	TimeManager* mpTimeManager;
	InputManager* mpInputManager;

	// ���� ���� ����
	Level* mMainLevel;
};

