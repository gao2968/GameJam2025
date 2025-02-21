//#include <afxwin.h>
#include "GameMainScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include <stdio.h>
#include <math.h>


GameMainScene::GameMainScene()
{
	
}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	stage = new Stage;
	player = new Player;

	stage->Initialize();
	player->Initialize();
}

eSceneType GameMainScene::Update()
{
	stage->Update();
	player->Update();

	Vector2D velocity(GetInputVelocity());
	if(player->GetCameraStopX())
	{ 
		velocity.x = 0.f;
	}

	if (player->GetCameraStopY())
	{
		velocity.y = 0.f;
	}

	stage->Movement(velocity);
	
	player->Movement(GetInputVelocity());

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	stage->Draw();
	player->Draw();

	DrawFormatString(0, 0, 0x000000, "x%f y%f", InputControl::GetLeftStick().x, InputControl::GetLeftStick().y);
}

void GameMainScene::Finalize()
{
	delete stage;
	delete player;
}

// ���݂̃V�[�����擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

Vector2D GameMainScene::GetInputVelocity()
{
	Vector2D velocity;

	velocity = InputControl::GetLeftStick() * 10.f;

	if (fabsf(velocity.x) <= 0.1f)
	{
		velocity.x = 0.f;
	}

	if (fabsf(velocity.y) <= 0.1f)
	{
		velocity.y = 0.f;
	}

	return velocity;
}
