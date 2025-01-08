#include "PreCompiledHeader.h"
#include "DrawableActor.h"
//#include "Engine/Engine.h"
#include "Engine/InputManager.h"

DrawableActor::DrawableActor(char _img)
	:Actor(), image(_img)
{
}

void DrawableActor::Draw()
{
	Super::Draw();

	// �׸���
	// 1�ܰ� : �ܼ� ��ǥ �ű��
	InputManager::Get().SetCursorPosition(pos);
	//Engine::Get().GetInputManager()->SetCursorPosition(pos);

	// 2�ܰ� : �׸���(�ܼ� ���)
	Log("%c", image);
}

void DrawableActor::SetPosition(const Vector2& _newPos)
{
	InputManager::Get().SetCursorPosition(pos);
	Log(" ");

	// ��ġ�� ���� �ű��
	Super::SetPosition(_newPos);
}
