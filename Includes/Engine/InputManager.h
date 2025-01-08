#pragma once
#include "Core.h"
#include "Math/Vector2.h"

// �Է� ó���� ���� ����ü
struct KeyState
{
	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool isKeyDown = false;

	// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��
	bool wasKeyDown = false;
};

// Ŀ���� ������ ������ �� ����� ������
enum class CURSOR_TYPE
{
	NONE,
	SOLID,
	NORMAL,
};

class ENGINE_API InputManager
{
public:
	InputManager();
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager();

	// �̱��� ��ü ���� �Լ�
	static InputManager& Get();

	// �Է� ó�� (���� Ű�� ���� ���� Ȯ��)
	void Update();

	// �Է� ���� �Լ�
	bool GetKey(int _key);
	bool GetKeyDown(int _key);
	bool GetKeyUp(int _key);
	void SavePreviousKeyStates();

	// ȭ�� ��ǥ ���� �Լ�
	void SetCursorType(CURSOR_TYPE _type);
	void SetCursorPosition(const Vector2& _pos);
	void SetCursorPosition(int _x, int _y);

private:
	// �̱��� ������ ���� ���� ���� ����
	static InputManager* gInstance;

	// Ű ���¸� �����ϴ� �迭
	KeyState mKeyStateArr[255];
};

