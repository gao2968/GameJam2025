#include "Ui.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

Ui::Ui()
	: stopwatch_image(NULL)
	, cursor_image(NULL)
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

	cursor_image = rm->GetImages("Resource/Images/cursor.png")[0];

	meibo_image = rm->GetImages("Resource/Images/meibo.png")[0];
}

void Ui::Update()
{

}

void Ui::Draw()
{
	

	// ストップウォッチ画像の描画
	DrawRotaGraph(120, 650, 0.5, 0.0, stopwatch_image, TRUE);

	// カーソル画像の描画
	DrawRotaGraph(644, 372, 0.2, 0.0, cursor_image, TRUE);

	// 名簿画像の描画
	DrawRotaGraph(120, 90, 0.37, 0.0, meibo_image, TRUE);

	DrawFormatString(76, 550, 0xff0000, "time limit\n %d", hp / 60);
	DrawFormatString(20, 360, 0xff0000, "score %d", score);
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

