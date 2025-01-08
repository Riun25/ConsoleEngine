#include "PreCompiledHeader.h"
#include "Level.h"
#include "../Actor/Actor.h"
Level::Level()
{
}

Level::~Level()
{
	// �޸� ����
	for (Actor* pActor : mActorVec)
	{
		delete pActor;
	}
}

void Level::AddActor(Actor* _newActor)
{
	mActorVec.PushBack(_newActor);
}

void Level::Update(float _dTime)
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
	for (Actor* pActor : mActorVec)
	{
		pActor->Update(_dTime);
	}
}

void Level::Draw()
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
	for (Actor* pActor : mActorVec)
	{
		pActor->Draw();
	}
}