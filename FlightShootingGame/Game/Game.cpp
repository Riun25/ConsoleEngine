#include "Game.h"
#include "Engine/InputManager.h"

Game::Game()
{
	// Ŀ�� �Ⱥ��̰� ����
	InputManager::Get().SetCursorType(CURSOR_TYPE::NONE);
}

Game::~Game()
{
}
