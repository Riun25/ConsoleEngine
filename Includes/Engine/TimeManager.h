#pragma once
#include "Core.h"

class ENGINE_API TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void Initialize();

	void Update();

	float GetDeltaTime();
	void SaveCurrentTime();

	void LimitFrame(float _limit);
	bool IsLimitFrame();
	bool CheckOverTargetFrame();

private:
	// CPU �ð� ��� : �ý��� �ð� -> ���ػ� ī����(10000000)
	LARGE_INTEGER mFrequency;
	// ���� �ð� �� ���� �ð��� ���� ����
	LARGE_INTEGER mTime;

	__int64 mCurrentTime;
	__int64 mPreviousTime;
	float mDeltaTime;

	// ������ ������ ���� ����ϴ� ����
	// Ÿ�� ������
	float mTargetFrameRate;
	// �� ������ �ð� ��(���� : ��)
	float mTargetOneFrameTime;
	bool mIsLimitFrame;
};

