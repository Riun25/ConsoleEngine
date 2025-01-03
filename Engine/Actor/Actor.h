#pragma once
#include "PreCompiledHeader.h"


// ������ �⺻ ��ü
class ENGINE_API Actor
{
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

