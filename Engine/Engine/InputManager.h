#pragma once
#include "PreCompiledHeader.h"


// �Է� ó���� ���� ����ü
struct KeyState
{
	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool isKeyDown = false;

	// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��
	bool wasKeyDown = false;
};

class ENGINE_API InputManager
{
public:
	InputManager();
	~InputManager();

	// �Է� ó�� (���� Ű�� ���� ���� Ȯ��)
	void Update();

	// �Է� ���� �Լ�
	bool GetKey(int _key);
	bool GetKeyDown(int _key);
	bool GetKeyUp(int _key);
	void SavePreviousKeyStates();

private:
	// Ű ���¸� �����ϴ� �迭
	KeyState mKeyStateArr[255];
};

