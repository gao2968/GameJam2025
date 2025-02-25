#include "QTESystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <unistd.h>
#include "InputControl.h"
#include "DxLib.h"

float QTESystem::elapsed_time = -1.f;
int QTESystem::button = 0;
int QTESystem::phase = 0;
float QTESystem::timer_qte = 0.f;

QTEState QTESystem::StartQTE(float second)
{
	if (elapsed_time <= -1.f)
	{
		elapsed_time = second;

		srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

		int button_rand = rand() % 4;

		button = button_rand;

		return success;
	}
	return faild;
}

QTEState QTESystem::StartQTEPhaseTwo(float second, int target_button)
{
	if (phase == 2)
	{
		elapsed_time = second;

		button = target_button;

		return success;
	}
	return faild;
}

QTEState QTESystem::InQTE()
{
	//timer_qte += 100.f / elapsed_time;

	if (elapsed_time-- <= 0.f)
	//if (timer_qte >= 100.f)
	{
		elapsed_time = -1.f;
		return faild;
	}

	switch (button)
	{
	case 0:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
		{
			elapsed_time = -1.f;
			return success;
		}
		else if (InputControl::GetButtonDown(XINPUT_BUTTON_B) || InputControl::GetButtonDown(XINPUT_BUTTON_X) || InputControl::GetButtonDown(XINPUT_BUTTON_Y))
		{
			return input_faild;
		}
		break;

	case 1:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
		{
			elapsed_time = -1.f;
			return success;
		}
		else if (InputControl::GetButtonDown(XINPUT_BUTTON_A) || InputControl::GetButtonDown(XINPUT_BUTTON_X) || InputControl::GetButtonDown(XINPUT_BUTTON_Y))
		{
			return input_faild;
		}
		break;

	case 2:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_X))
		{
			elapsed_time = -1.f;
			return success;
		}
		else if (InputControl::GetButtonDown(XINPUT_BUTTON_A) || InputControl::GetButtonDown(XINPUT_BUTTON_B) || InputControl::GetButtonDown(XINPUT_BUTTON_Y))
		{
			return input_faild;
		}
		break;

	case 3:
		if (InputControl::GetButtonDown(XINPUT_BUTTON_Y))
		{
			elapsed_time = -1.f;
			return success;
		}
		else if (InputControl::GetButtonDown(XINPUT_BUTTON_A) || InputControl::GetButtonDown(XINPUT_BUTTON_B) || InputControl::GetButtonDown(XINPUT_BUTTON_X))
		{
			return input_faild;
		}
		break;

	default:

		break;
	}

	return midway;
}

void QTESystem::SetPhase(int n)
{
	phase = n;
}

void QTESystem::Update()
{
}

void QTESystem::Draw()
{
	//DrawFormatString(300, 0, 0x00ff00, "button %d", button);
}

void QTESystem::Initialize()
{
	elapsed_time = -1.f;
	button = 0;
	phase = 1; 
}
