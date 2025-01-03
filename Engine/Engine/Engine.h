#pragma once
class TimeManager;
class InputManager;
class Level;

// ���� Ŭ����
class Engine
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
	InputManager* GetInputManager();
protected:
	void Update(float _dTime);			// Tick();
	void Draw();						// Render();
	void HandleGameLoop();
	void ProcessFrame();

private:
	// ID/�̸� ��


	// ������ �� ������ ����
	bool mIsQuit;

	TimeManager* mpTimeManager;
	InputManager* mpInputManager;

	// �̱��� ������ ���� ���� ���� ����
	static Engine* instance;

	// ���� ���� ����
	Level* mMainLevel;
};

