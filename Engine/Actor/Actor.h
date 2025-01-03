#pragma once

// ������ �⺻ ��ü
class Actor
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

