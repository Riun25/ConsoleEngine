#pragma once
#include "PreCompiledHeader.h"
#include "InputManager.h"

// ����ƽ ���� �ʱ�ȭ
InputManager* InputManager::gInstance = nullptr;

InputManager::InputManager()
{
	// �̱��� ��ü ����
	gInstance = this;
}

InputManager::~InputManager()
{
}

InputManager& InputManager::Get()
{
	if (!gInstance)
	{
		gInstance = new InputManager();
	}
	return *gInstance;
}

void InputManager::Update() //ProcessInput()
{
	for (int idx = 0; idx < 255; idx++)
	{
		mKeyStateArr[idx].isKeyDown = (GetAsyncKeyState(idx) & 0x8000) ? true : false;
	}
}

bool InputManager::GetKey(int _key)
{
	return mKeyStateArr[_key].isKeyDown;
}

bool InputManager::GetKeyDown(int _key)
{
	return mKeyStateArr[_key].isKeyDown && !mKeyStateArr[_key].wasKeyDown;
}

bool InputManager::GetKeyUp(int _key)
{
	return !mKeyStateArr[_key].isKeyDown && mKeyStateArr[_key].wasKeyDown;
}

void InputManager::SavePreviousKeyStates()
{
	for (int idx = 0; idx < 255; idx++)
	{
		mKeyStateArr[idx].wasKeyDown = mKeyStateArr[idx].isKeyDown;
	}
}

void InputManager::SetCursorType(CURSOR_TYPE _type)
{
	// 1. Ŀ�� �Ӽ� ����ü ����
	CONSOLE_CURSOR_INFO info = {};

	// Ÿ�� ���� ����ü �� ����
	switch (_type)
	{
	case CURSOR_TYPE::NONE:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case CURSOR_TYPE::SOLID:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case CURSOR_TYPE::NORMAL:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	default:
		break;
	}

	// 2. Ŀ�� ���� : ��¼�� �� �� �ϱ� ������ handle�� ���� ������ ó������ ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void InputManager::SetCursorPosition(const Vector2& _pos)
{
	SetCursorPosition(_pos.x, _pos.y);
}

void InputManager::SetCursorPosition(int _x, int _y)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { static_cast<short>(_x), static_cast<short>(_y) };
	SetConsoleCursorPosition(handle, coord);
}
