#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/InputManager.h"

DrawableActor::DrawableActor(const char* _img)
	:Actor()/*, image(_img)*/
{
	auto length = strlen(_img) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, _img);

	//�ʺ� ����
	width = static_cast<int>(strlen(image));
}

DrawableActor::~DrawableActor()
{
	delete[] image;
}

void DrawableActor::Draw()
{
	Super::Draw();

	// �׸���
	// 1�ܰ� : �ܼ� ��ǥ �ű��
	InputManager::Get().SetCursorPosition(pos);

	// 2�ܰ� : �׸���(�ܼ� ���)
	Log(image);
}

void DrawableActor::SetPosition(const Vector2& _newPos)
{
	/*InputManager::Get().SetCursorPosition(pos);
	Log(" ");*/

	// ��ġ�� ���� �ű��
	Super::SetPosition(_newPos);
}
