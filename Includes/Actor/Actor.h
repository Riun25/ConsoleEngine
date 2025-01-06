#pragma once
#include "Core.h"
#include "RTTI.h"

// ������ �⺻ ��ü
class ENGINE_API Actor :public RTTI
{
	// RTTI ����
	RTTI_DECLARATIONS(Actor, RTTI);

public:
	Actor();
	virtual ~Actor();

	// ���� ó�� �Լ�
	virtual void Update(float _dTime);
	virtual void Draw();
protected:
	// Ȱ��ȭ ���������� ��Ÿ���� ����
	bool mIsActive;

	// ������ ���� ��û�� �ƴ��� ���θ� ��Ÿ���� ����
	bool mIsExpired;
};

