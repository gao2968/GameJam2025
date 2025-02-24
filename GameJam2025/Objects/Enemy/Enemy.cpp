#include "Enemy.h"
#include "../../Utility/QTESystem.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"
#include "../TimeLimitCircle.h"

Enemy::Enemy() 
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	//location = Vector2D(960.f, 540.f);
	location = Vector2D((float)GetRand(1720) + 100, (float)GetRand(880) + 100);
	local_location = (location - Vector2D(1920 / 2, 1080 / 2)) + Vector2D(1280 / 2, 720 / 2);
	box_size = Vector2D(128.f);
	color = 0x0000ff;
	state = 0;
	battle_phase = 0;
	phase_two_timer = 1200.f;
	battle_count = 0;
	phase_one_cnt = 0;
	phase_one_enemy_size = 0;
	timecard_size = 0.f;

	pattern.resize(3);
	for (int i = 0; i < 3; i++)
	{
		//for (int j = 0; j < 5; j++)
		for (int j = 0; j < GetRand(4) + 3; j++)
		{
			//pattern.push_back(GetRand(3));
			pattern[i].push_back(GetRand(3));
		}
		pattern_num.push_back(pattern[i].size() - 1);
		pattern_cnt = i;
	}
	
	/*pattern_num = pattern.size() - 1;*/
	
	ResourceManager* rm = ResourceManager::GetInstance();
	timecard = rm->GetImages("Resource/Images/time_card.png")[0];

	circle.TimeLimitCircleInit();
}

void Enemy::Update()
{
	if (battle_phase == 1)
	{
		switch (state)
		{
		case 0:
			break;

		case 1:
			if (!timecard_flg)
			{
				InBattlePhaseOne();
			}
			break;

		case 2:
			if (!timecard_flg)
			{
				EndBattlePhaseOne();
			}
			break;

		default:
			break;
		}

		if (timecard_flg)
		{
			if (++timecard_cnt > 30)
			{
				timecard_flg = false;
				timecard_cnt = 0;
			}

			timecard_size += 0.1f;
		}
	}

	if (battle_phase == 2)
	{
		phase_two_timer--;

		switch (state)
		{
		case 0:
			StartBattlePhaseTwo();
			break;

		case 1:
			InBattlePhaseTwo();
			circle.TimeLimitCircleUpdate(1200);
			break;

		case 2:
			EndBattlePhaseTwo();
			break;

		default:
			break;
		}
	}
}

void Enemy::Draw() const
{
	//親クラスで画像の描画
	__super::Draw();

	//フェーズ1の敵の描画
	Vector2D draw_location;
	Vector2D draw_box_size = Vector2D(phase_one_enemy_size);
	Vector2D upper_left;
	Vector2D lower_right;
	if (battle_phase == 1)
	{
		switch (QTESystem::GetButtonPhaseOne())
		{
		case 0:	//A
			draw_location = Vector2D(640.f, 480.f);
			break;
		case 1: //B
			draw_location = Vector2D(960.f, 360.f);
			break;
		case 2: //X
			draw_location = Vector2D(320.f, 360.f);
			break;
		case 3: //Y
			draw_location = Vector2D(640.f, 180.f);
			break;
		default:
			break;
		}

		upper_left = draw_location - (draw_box_size / 2.f);
		lower_right = draw_location + (draw_box_size / 2.f);
		DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, image, TRUE);
	}

	if (timecard_flg)
	{
		switch (timecard_button)
		{
		case 0:	//A
			draw_location = Vector2D(640.f, 480.f);
			break;
		case 1: //B
			draw_location = Vector2D(960.f, 360.f);
			break;
		case 2: //X
			draw_location = Vector2D(320.f, 360.f);
			break;
		case 3: //Y
			draw_location = Vector2D(640.f, 180.f);
			break;
		default:
			break;
		}

		draw_box_size = Vector2D(140.f, 240.f);
		upper_left = draw_location - (draw_box_size / 2.f);
		lower_right = draw_location + (draw_box_size / 2.f);
		DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, timecard, TRUE);
	}


	if (battle_phase == 2)
	{
		circle.BattleSquareDraw(pattern[pattern_cnt].size(), pattern[pattern_cnt], pattern_num[pattern_cnt]);
		circle.TimeLimitCircleDraw();
	}


	//DrawFormatString(local_location.x, local_location.y - 30, 0xff00ff, "num%d", pattern_num);
	//DrawFormatString(local_location.x, local_location.y - 70, 0xff00ff, "phase%d", battle_phase);
	/*DrawFormatString(local_location.x, local_location.y - 90, 0xff00ff, "time%d", phase_two_timer);
	for (int i = 0; i < pattern.size(); i++)
	{
		for (int j = 0; j < pattern[i].size(); j++)
		{
			DrawFormatString(local_location.x - 20 * j, local_location.y - i * 20, font, "%d", pattern[i][j]);
		}
	}*/

	QTESystem::Draw();
}

void Enemy::Finalize()
{

}

void Enemy::StartBattlePhaseOne()
{
	//フェーズ1の秒数の調整をするならここ
	if (QTESystem::StartQTE(300) == success)
	{
		state = 1;
		battle_phase = 1;
		color = 0x0ff00f;
	}
}

void Enemy::StartBattlePhaseTwo()
{
	//秒数はこっちで管理
	if (QTESystem::StartQTEPhaseTwo(phase_two_timer,pattern[pattern_cnt][pattern_num[pattern_cnt]]) == success)
	{
		state = 1;
	}
}

void Enemy::InBattlePhaseOne()
{
	phase_one_enemy_size += 3; //だんだん近づかせる
	int result = QTESystem::InQTE();
	if (result == success)
	{
		phase_one_enemy_size = 0;

		timecard_flg = true;

		add_score = 10;
		if (++phase_one_cnt > 3)
		{
			state = 2;
			color = 0xff0000;
			timecard_button = QTESystem::GetButtonPhaseOne();
		}
		else
		{
			timecard_button = QTESystem::GetButtonPhaseOne();
			StartBattlePhaseOne();
		}
	}
	else if (result == faild)
	{
		/*state = 0;*/
		StartBattlePhaseOne();
		miss = true;
	}
}

void Enemy::InBattlePhaseTwo()
{
	int res = QTESystem::InQTE();
	if (res == success)
	{
		add_score = 10;
		//一定回数こなしたら終わり
		if (pattern_cnt == 0 && pattern_num[pattern_cnt] == 0)
		{
			state = 2;
			color = 0x0000ff;
			result = true; //成功
			add_score = 100;
		}
		else
		{
			//pattern_num--;
			if (pattern_num[pattern_cnt]-- == 0)	//このタイミングで一行終了
			{
				pattern_cnt--;
				font += 255;
				add_score = 50;
				//phase_two_timer = 1200.f;
			}
			state = 0;
		}
		
	}
	else if (res == input_faild)
	{
		miss = true;
	}
	else if (res == faild)
	{
		state = 0;
		battle_phase = 0;
		color = 0x00ff00;
		result = false;	//失敗
		InitializationForRestart();
	}
}

void Enemy::EndBattlePhaseOne()
{
	battle_phase = 2;
	state = 0;
	QTESystem::SetPhase(2);//いらんかも
}

void Enemy::EndBattlePhaseTwo()
{
	battle_phase = 99;
	state = 0;
}

void Enemy::InitializationForRestart()
{
	state = 0;
	battle_phase = 0;
	phase_two_timer = 1200.f;
	battle_count = 0;
	phase_one_cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		pattern_num.push_back(pattern[i].size() - 1);
		pattern_cnt = i;
	}
}

bool Enemy::SetEnemyType(int type)
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();
	switch (type)
	{
	case arai:
		image = rm->GetImages("Resource/Images/arai_512.png")[0];
		break;

	case maesiro:
		image = rm->GetImages("Resource/Images/maesiro_512.png")[0];
		break;

	case maetu:
		image = rm->GetImages("Resource/Images/maetu_512.png")[0];
		break;

	case ryouka:
		image = rm->GetImages("Resource/Images/ryouka_512.png")[0];
		break;

	case toubaru:
		image = rm->GetImages("Resource/Images/toubaru_512.png")[0];
		break;

	default:
		break;
	}

	if (image != -1) return true;
	return false;
}
