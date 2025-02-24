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
	//stage = new Stage;
	//player = new Player;
	//enemy = new Enemy;

	//stage->Initialize();
	//player->Initialize();
	//enemy->Initialize();

	object.push_back(new Player);
	object.push_back(new Stage);
	for (int i = 0; i < 3; i++)
	{
		object.push_back(new Enemy);
	}

	for (int i = 0; i < object.size(); i++)
	{
		object[i]->Initialize();
	}
	for (int i = 0; i < 3; i++)
	{
		if (Enemy* e = dynamic_cast<Enemy*>(object[enemy_num[i]]))
		{
			e->SetEnemyType(i);
		}
	}


	SetFontSize(24);

	state = SearchPhase;
}

eSceneType GameMainScene::Update()
{
	CalculationHp();

	if (nearest_enemy !=  nullptr && nearest_enemy->add_score > 0)
	{
		score += nearest_enemy->add_score;
		nearest_enemy->add_score = 0;
	}

	Vector2D velocity(GetInputVelocity());
	switch (state)
	{
	case SearchPhase:

		for (int i = 0; i < object.size(); i++)
		{
			if (object[i] == nullptr) continue;
			object[i]->Update();
		}
		
		if (Player* p = dynamic_cast<Player*>(object[player_num]))
		{
			if (p->GetCameraStopX())
			{
				velocity.x = 0.f;
			}

			if (p->GetCameraStopY())
			{
				velocity.y = 0.f;
			}
		}
		
		for (int i = 1; i < object.size(); i++)
		{
			if (object[i] == nullptr) continue;
			object[i]->Movement(velocity);
		}
		//stage->Movement(velocity);
		//enemy->Movement(velocity);

		//player->Movement(GetInputVelocity());
		//player->nearest_enemy_length = player->ObjectLength(enemy);//game objectに変更するかも 敵の数ループして最も近い敵との距離を入れる

		if (Player* p = dynamic_cast<Player*>(object[player_num]))
		{
			p->Movement(GetInputVelocity());
			//p->nearest_enemy_length = 9999.f;//game objectに変更するかも 敵の数ループして最も近い敵との距離を入れる
			//for (int i = 2; i < object.size(); i++) //enemyが入ってる部分
			//{
			//	p->ObjectLength(object[i]);
			//}
			
			SearchNearestEnemy();


			if (nearest_enemy != nullptr && p->ObjectLength(nearest_enemy) <= 100.f 
				&& InputControl::GetButtonDown(XINPUT_BUTTON_A) && nearest_enemy->battle_phase == 0)
			{
				nearest_enemy->StartBattlePhaseOne();
				state = BattlePhaseOne;
			}
		}

		
		break;

	case BattlePhaseOne:
		/*enemy->Update();
		state = enemy->battle_phase;*/

		nearest_enemy->Update();
		state = nearest_enemy->battle_phase;
		break;

	case BattlePhaseTwo:
		//enemy->Update();
		//state = enemy->battle_phase;

		nearest_enemy->Update();
		state = nearest_enemy->battle_phase;
		break;

	case EndPhase:
		state = SearchPhase;
		nearest_enemy = nullptr;
		if (nearest_enemy_num != -1)
		{
			object[nearest_enemy_num] = nullptr;
		}
		break;

	default:
		break;
	}

	//残りの敵を数える
	enemy_cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (object[enemy_num[i]] != nullptr)
		{
			enemy_cnt++;
		}
	}

	//シーンチェンジ
	if (hp < 0 || enemy_cnt == 0/*(object[enemy_num[0]] == nullptr && object[enemy_num[1]] == nullptr && object[enemy_num[2]] == nullptr)*/)
	{
		return E_TITLE;
	}

	if (InputControl::GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER))
	{
		return eSceneType::E_END;
	}

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	for (int i = 1; i < object.size(); i++)
	{
		if (object[i] == nullptr) continue;
		object[i]->Draw();
	}
	object[player_num]->Draw();

	DrawFormatString(0, 0, 0x000000, "x%f y%f", InputControl::GetLeftStick().x, InputControl::GetLeftStick().y);
	DrawFormatString(0, 40, 0x000000, "hp %d", hp);
	DrawFormatString(0, 80, 0xff0000, "score %d", score);
	//DrawFormatString(0, 20, 0x000000, "length%f", player->ObjectLength(enemy));

	switch (state)
	{
	case SearchPhase:

		break;

	case BattlePhaseOne:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		break;

	case BattlePhaseTwo:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(0, 0, 1280, 720, 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		break;

	case EndPhase:
		break;

	default:
		break;
	}
}

void GameMainScene::Finalize()
{
	for (int i = 0; i < object.size(); i++)
	{
		delete object[i];
	}
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

void GameMainScene::SearchNearestEnemy()
{
	if (Player* p = dynamic_cast<Player*>(object[player_num]))
	{
		float length = 9999.f;
		float tmp = 0.f;
		//p->nearest_enemy_length = 9999.f;//game objectに変更するかも 敵の数ループして最も近い敵との距離を入れる

		p->nearest_enemy_length = 9999.f;

		for (int i = 2; i < object.size(); i++) //enemyが入ってる部分
		{
			if (object[i] == nullptr) continue;
			tmp = p->ObjectLength(object[i]);
			if (length > tmp)
			{
				length = tmp;
				if (Enemy* e = dynamic_cast<Enemy*>(object[i]))
				{
					nearest_enemy = e;
				}
				nearest_enemy_num = i;
			}
		}
	}
}

void GameMainScene::CalculationHp()
{
	switch (state)
	{
	case SearchPhase:
		hp -= 1; //通常時は時間経過で減少
		break;

	case BattlePhaseOne:
		if (nearest_enemy->miss)	//入力ミスで減少
		{
			hp -= 100;
			nearest_enemy->miss = false;
		}
		hp -= 1;
		break;

	case BattlePhaseTwo:
		if (nearest_enemy->miss)
		{
			hp -= 100;
			nearest_enemy->miss = false;
		}
		hp -= 1;
		break;

	case EndPhase:
		if (nearest_enemy->result)
		{
			hp += 1000;	//除霊で回復
		}
		break;

	default:
		break;
	}
}
