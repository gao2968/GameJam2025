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
		for (int j = 0; j < GetRand(4) + 3; j++)
		{
			pattern[i].push_back(GetRand(3));
		}
		pattern_num.push_back(pattern[i].size() - 1);
		pattern_cnt = i;
	}
	
	ResourceManager* rm = ResourceManager::GetInstance();
	timecard = rm->GetImages("Resource/Images/time_card.png")[0];
	tai_image = rm->GetImages("Resource/Images/tai_128.png")[0];
	sya_image = rm->GetImages("Resource/Images/sya_128.png")[0];
	taisya_image = rm->GetImages("Resource/Images/taisya_fonts_200.png")[0];

	lose_se = rm->GetSounds("Resource/SE/Tekinosi.mp3");
	attack_se[0] = rm->GetSounds("Resource/SE/Kougeki_1.mp3");
	attack_se[1] = rm->GetSounds("Resource/SE/Kougeki_2.mp3");
	damage_se = rm->GetSounds("Resource/SE/Damage.mp3");
	taisya_se = rm->GetSounds("Resource/SE/Combo.mp3");

	anim_len = 500.f;
	anim_state = 0;
	anim_rate = 512.f;

	circle.TimeLimitCircleInit();
}

void Enemy::Update()
{
	if (battle_phase == 1)
	{
		switch (state)
		{
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
		switch (state)
		{
		case 0:
			StartBattlePhaseTwo();
			break;

		case 1:
			InBattlePhaseTwo();
			circle.TimeLimitCircleUpdate(1200, miss);
			break;

		case 2:
			if (anim_state == 0)
			{
				EndBattlePhaseTwo();
			}
			break;

		default:
			break;
		}
		if (anim_state != 0)
		{
			PhaseTwoAnimUpdate();
		}
		else
		{
			phase_two_timer--;
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
		DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, image_original, TRUE);

		draw_location = Vector2D(640.f, 360.f);
		draw_box_size = Vector2D(256.f);
		upper_left = draw_location - (draw_box_size / 2.f);
		lower_right = draw_location + (draw_box_size / 2.f);
		DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, image_original, TRUE);
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
		if (pattern_cnt == -1)
		{
			circle.BattleSquareDraw(pattern[0].size(), pattern[0], pattern_num[0]);
		}
		else
		{
			circle.BattleSquareDraw(pattern[pattern_cnt].size(), pattern[pattern_cnt], pattern_num[pattern_cnt]);
		}
		circle.TimeLimitCircleDraw();
	}

	if (anim_state != 0)
	{
		PhaseTwoAnimDraw();
	}

}

void Enemy::Finalize()
{

}

void Enemy::StartBattlePhaseOne()
{
	//フェーズ1の秒数の調整をするならここ
	if (QTESystem::StartQTE(180) == success)
	{
		state = 1;
		battle_phase = 1;
		color = 0x0ff00f;
	}
}

void Enemy::StartBattlePhaseTwo()
{
	if (anim_state == 0) 
	{
		//秒数はこっちで管理
		if (QTESystem::StartQTEPhaseTwo(phase_two_timer, pattern[pattern_cnt][pattern_num[pattern_cnt]]) == success)
		{
			state = 1;
		}
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

		PlaySoundMem(attack_se[0], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (result == faild)
	{
		/*state = 0;*/
		StartBattlePhaseOne();
		miss = true;
		phase_one_enemy_size = 0;
		PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, TRUE);
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
			pattern_cnt = -1;
			anim_state = 1;
		}
		else
		{
			if (pattern_num[pattern_cnt]-- == 0)	//このタイミングで一行終了
			{
				pattern_cnt--;
				font += 255;
				add_score = 50;
				anim_state = 1;

			}
			state = 0;
		}
		PlaySoundMem(attack_se[1], DX_PLAYTYPE_BACK, TRUE);
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
	PlaySoundMem(lose_se, DX_PLAYTYPE_BACK, TRUE);
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
		pattern_num[i] = (pattern[i].size() - 1);
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
		image_original = rm->GetImages("Resource/Images/arai_aura.png")[0];
		break;

	case maesiro:
		image = rm->GetImages("Resource/Images/maesiro_512.png")[0];
		image_original = rm->GetImages("Resource/Images/maesiro_aura.png")[0];
		break;

	case maetu:
		image = rm->GetImages("Resource/Images/maetu_512.png")[0];
		image_original = rm->GetImages("Resource/Images/maetu_aura.png")[0];
		break;

	case ryouka:
		image = rm->GetImages("Resource/Images/ryouka_512.png")[0];
		image_original = rm->GetImages("Resource/Images/ryouka_aura.png")[0];
		break;

	case toubaru:
		image = rm->GetImages("Resource/Images/toubaru_512.png")[0];
		image_original = rm->GetImages("Resource/Images/toubaru_aura.png")[0];
		break;

	default:
		break;
	}

	if (image != -1) return true;
	return false;
}

void Enemy::PhaseTwoAnimDraw() const
{
	if (anim_state == 1)	//四方から来るほう
	{
		if (!CheckSoundMem(taisya_se))
		{
			PlaySoundMem(taisya_se, DX_PLAYTYPE_BACK, TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 210);

		for (int i = 0; i < 4; i++)
		{
			Vector2D draw_location = anim_location[i];
			Vector2D draw_box_size = Vector2D(anim_rate);

			if (pattern_cnt == -1)
			{
				draw_box_size = Vector2D(anim_rate * 1.5f);
			}

			Vector2D upper_left = draw_location - (draw_box_size / 2.f);
			Vector2D lower_right = draw_location + (draw_box_size / 2.f);
			if (pattern_cnt == 1)
			{
				DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, tai_image, TRUE);
			}
			else if(pattern_cnt == 0)
			{
				DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, sya_image, TRUE);
			}
			else 
			{
				DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, taisya_image, TRUE);
			}
		}
	}
	else if (anim_state == 2)
	{
		int blend = (int)(255.f - ((anim_rate - 300.f) / 700.f) * 255.f);
		if (blend < 0)
		{
			blend = 0;
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);

		Vector2D draw_location(640.f, 360.f);
		Vector2D draw_box_size = Vector2D(anim_rate);

		if (pattern_cnt == -1)
		{
			draw_box_size = Vector2D(anim_rate * 1.5f);
		}

		Vector2D upper_left = draw_location - (draw_box_size / 2.f);
		Vector2D lower_right = draw_location + (draw_box_size / 2.f);
		if (pattern_cnt == 1)
		{
			DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, tai_image, TRUE);
		}
		else if (pattern_cnt == 0)
		{
			DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, sya_image, TRUE);
		}
		else
		{
			DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, taisya_image, TRUE);
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}

void Enemy::PhaseTwoAnimUpdate()
{
	if (anim_state == 1)
	{
		Vector2D loc[4];
		Vector2D center(640.f, 360.f);
		Vector2D vec[4];

		vec[0] = Vector2D(Vector2D(0,0) - center).normalized();
		vec[1] = Vector2D(Vector2D(1280, 0) - center).normalized();
		vec[2] = Vector2D(Vector2D(1280, 720) - center).normalized();
		vec[3] = Vector2D(Vector2D(0, 720) - center).normalized();

		for (int i = 0; i < 4; i++)
		{
			loc[i] = center + vec[i] * anim_len;
			anim_location[i] = loc[i];
		}

		anim_len -= 10.f;

		float length;
		length = powf(powf(center.x - loc[0].x, 2.f) + powf(center.y - loc[0].y, 2.f), 0.5f);

		anim_rate -= 4.f;

		if (anim_rate < 0.f)
		{
			anim_rate = 0.f;
		}

		if (length <= 0.f)
		{
			anim_state = 2;
		}
	}
	else if (anim_state == 2)
	{
		anim_rate += 16.f;

		if (anim_rate >= 1024.f)
		{
			anim_rate = 512.f;
			anim_state = 0;
			anim_len = 500.f;
		}
	}
}