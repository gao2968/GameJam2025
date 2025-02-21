#include "Enemy.h"
#include "../../Utility/QTESystem.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

Enemy::Enemy() 
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	location = Vector2D(1280.f, 400.f);
	local_location = (location - Vector2D(1280 / 2, 720 / 2)) + Vector2D(1280 / 2, 720 / 2);
	box_size = Vector2D(32.f);
	color = 0x0000ff;
	state = 0;
	battle_phase = 0;
	phase_two_timer = 1200.f;
	battle_count = 0;

	for (int i = 0; i < 5; i++)
	{
		pattern.push_back(GetRand(3));
	}
	pattern_num = pattern.size() - 1;
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
			InBattlePhaseOne();
			break;

		case 2:
			EndBattlePhaseOne();
			break;

		default:
			break;
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
	__super::Draw();
	DrawFormatString(local_location.x, local_location.y - 30, 0xff00ff, "num%d", pattern_num);
	DrawFormatString(local_location.x, local_location.y - 70, 0xff00ff, "phase%d", battle_phase);
	DrawFormatString(local_location.x, local_location.y - 90, 0xff00ff, "time%d", phase_two_timer);
	for (int i = 0; i < pattern.size(); i++)
	{
		DrawFormatString(local_location.x - 20 * i, local_location.y - 50, 0xff00ff, "%d", pattern[i]);
	}

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
	if (QTESystem::StartQTEPhaseTwo(phase_two_timer,pattern[pattern_num]) == success)
	{
		state = 1;
	}
}

void Enemy::InBattlePhaseOne()
{
	int result = QTESystem::InQTE();
	if (result == success)
	{
		state = 2;
		color = 0xff0000;
	}
	else if (result == faild)
	{
		state = 0;
	}
}

void Enemy::InBattlePhaseTwo()
{
	int result = QTESystem::InQTE();
	if (result == success)
	{
		//一定回数こなしたら終わり
		//if (++battle_count >= pattern.size())
		if (pattern_num == 0)
		{
			state = 2;
			color = 0x0000ff;
		}
		else
		{
			pattern_num--;
			state = 0;
		}
		
	}
	else if (result == faild)
	{
		state = 0;
		battle_phase = 0;
		color = 0x00ff00;
	}
}

void Enemy::EndBattlePhaseOne()
{
	//決まられた回数こなしたらフェーズ移動
	battle_phase = 2;
	state = 0;
	QTESystem::SetPhase(2);
}

void Enemy::EndBattlePhaseTwo()
{
	battle_phase = 0;
	state = 0;
}
