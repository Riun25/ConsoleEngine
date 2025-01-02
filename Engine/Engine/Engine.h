#pragma once

// �Է� ó���� ���� ����ü
struct KeyState
{
	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool isKeyDown = false;

	// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��
	bool wasKeyDown = false;
};

// ���� Ŭ����
class Engine
{
public:
	Engine();
	virtual ~Engine();

	// ���� ���� �Լ�
	void Run();

	// �Է� ���� �Լ�
	bool GetKey(int _key);
	bool GetKeyDown(int _key);
	bool GetKeyUp(int _key);

	// ���� ���� �Լ�
	void QuitGame();

protected:
	void ProcessInput();				// �Է� ó��
	void Update(float _dTime);			// Tick();
	void Draw();						// Render();

	void SavePreviousKeyStates();

protected:

	// ������ �� ������ ����
	bool mIsQuit;

	// Ű ���¸� �����ϴ� �迭
	KeyState mKeyStateArr[255];
};

