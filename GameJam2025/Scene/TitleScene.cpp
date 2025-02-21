#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

TitleScene::TitleScene()
	: title_image(NULL)
	, title_sound(NULL)
	, tamesi(NULL)
	, select(TitleSelect::InGame)
	, end_flg(false)
{

}

TitleScene::~TitleScene()
{

}

//����������
void TitleScene::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	title_image = rm->GetImages("Resource/Images/title.png")[0];
	
	SetFontSize(64);
}

eSceneType TitleScene::Update()
{
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		if (select == TitleSelect::EXIT)
		{
			select = TitleSelect::InGame;
		}
		else if (select == TitleSelect::InGame)
		{
			select = TitleSelect::Help;
		}
		else if (select == TitleSelect::Help)
		{
			select = TitleSelect::Ranking;
		}
		else
		{
			select = TitleSelect::EXIT;
		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		if (select == TitleSelect::InGame)
		{
			select = TitleSelect::EXIT;
		}
		else if (select == TitleSelect::EXIT)
		{
			select = TitleSelect::Ranking;
		}
		else if (select == TitleSelect::Ranking)
		{
			select = TitleSelect::Help;
		}
		else
		{
			select = TitleSelect::InGame;
		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		if (select == TitleSelect::EXIT)
		{
			return eSceneType::E_END;
		}
		if (select == TitleSelect::InGame)
		{
			return eSceneType::E_MAIN;
		}
		else if (select == TitleSelect::Help)
		{
			return eSceneType::E_HELP;
		}
		else if (select == TitleSelect::Ranking)
		{
			return eSceneType::E_RANKING;
		}
	}
	return GetNowScene();
}

//�`�揈��
void TitleScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, title_image, TRUE);

	switch (select)
	{
	case InGame:
		DrawString(DRAW_SET_X - 80, DRAW_SET_Y - 3, "→", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y, "スタート", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 67, "ヘルプ", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 137, "ランキング", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y +207, "終了", WHITE);
		break;
	case Help:
		DrawString(DRAW_SET_X - 80, DRAW_SET_Y + 67, "→", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y, "スタート", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 67, "ヘルプ", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 137, "ランキング", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 207, "終了", WHITE);
		break;
	case Ranking:
		DrawString(DRAW_SET_X - 80, DRAW_SET_Y + 137, "→", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y, "スタート", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 67, "ヘルプ", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 137, "ランキング", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 207, "終了", WHITE);
		break;
	case EXIT:
		DrawString(DRAW_SET_X - 80, DRAW_SET_Y + 207, "→", RED);
		DrawString(DRAW_SET_X, DRAW_SET_Y, "スタート", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 67, "ヘルプ", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 137, "ランキング", WHITE);
		DrawString(DRAW_SET_X, DRAW_SET_Y + 207, "終了", RED);
		break;
	}

}

//�I��������
void TitleScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}

bool TitleScene::GetEndFlag()
{
	return end_flg;
}