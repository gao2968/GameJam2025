#include "Ui.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

Ui::Ui()
	: stopwatch_image(NULL)
	, meibo_image(NULL)
{

}

Ui::~Ui()
{

}

void Ui::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	stopwatch_image = rm->GetImages("Resource/Images/stopwatch.png")[0];

	meibo_image = rm->GetImages("Resource/Images/meibo.png")[0];
}

void Ui::Update()
{

}

void Ui::Draw()
{
	

	// ストップウォッチ画像の描画
	DrawRotaGraph(140, 620, 0.5, 0.0, stopwatch_image, TRUE);

	// 名簿画像の描画
	DrawRotaGraph(140, 120, 0.37, 0.0, meibo_image, TRUE);

	DrawFormatString(115, 532, 0x000000, "TIME\n%d", hp / 60);
	DrawFormatString(50, 82, 0xff0000, "score %d", score);
	DrawFormatString(150, 82, 0xff0000, "enemy %d", enemy_cnt);

}

void Ui::Finalize()
{
}

void Ui::SetHp(int hp_ui)
{
	hp = hp_ui;
}

void Ui::SetScore(int score_ui)
{
	score = score_ui;
}

void Ui::Setenemy_cnt(int enemy_cnt_ui)
{
	enemy_cnt = enemy_cnt_ui;
}

