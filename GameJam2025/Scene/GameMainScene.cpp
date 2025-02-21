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
	enemy = new Enemy;

	stage->Initialize();
	player->Initialize();
	enemy->Initialize();

	SetFontSize(24);

	state = SearchPhase;
}

eSceneType GameMainScene::Update()
{
	Vector2D velocity(GetInputVelocity());
	switch (state)
	{
	case SearchPhase:

		stage->Update();
		player->Update();
		enemy->Update();

		
		if (player->GetCameraStopX())
		{
			velocity.x = 0.f;
		}

		if (player->GetCameraStopY())
		{
			velocity.y = 0.f;
		}

		stage->Movement(velocity);
		enemy->Movement(velocity);

		player->Movement(GetInputVelocity());
		player->nearest_enemy_length = player->ObjectLength(enemy);//game objectに変更するかも 敵の数ループして最も近い敵との距離を入れる

		if (player->ObjectLength(enemy) <= 100.f && InputControl::GetButtonDown(XINPUT_BUTTON_B) && enemy->battle_phase == 0)
		{
			enemy->StartBattlePhaseOne();
			state = BattlePhaseOne;
		}
		break;

	case BattlePhaseOne:
		enemy->Update();
		enemy->battle_phase = state;
		break;

	case BattlePhaseTwo:
		enemy->Update();
		enemy->battle_phase = state;
		break;

	case EndPhase:
		break;

	default:
		break;
	}


	return GetNowScene();
}

void GameMainScene::Draw() const
{
	stage->Draw();
	player->Draw();
	enemy->Draw();

	DrawFormatString(0, 0, 0x000000, "x%f y%f", InputControl::GetLeftStick().x, InputControl::GetLeftStick().y);
	DrawFormatString(0, 20, 0x000000, "length%f", player->ObjectLength(enemy));
}

void GameMainScene::Finalize()
{
	delete stage;
	delete player;
	delete enemy;
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
