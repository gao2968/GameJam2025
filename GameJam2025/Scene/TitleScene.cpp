#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

TitleScene::TitleScene()
	: title_image(NULL)
	, title_sound(NULL)
	,start(NULL)
	,help(NULL)
	,ranking(NULL)
	,end(NULL)
	, start_red(NULL)
	, help_red(NULL)
	, ranking_red(NULL)
	, end_red(NULL)
	,kao(NULL)
	, kao2(NULL)
	, kao3(NULL)
	, kao4(NULL)
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
	start = rm->GetImages("Resource/Images/start.png")[0];
	help = rm->GetImages("Resource/Images/H_font.png")[0];
	ranking = rm->GetImages("Resource/Images/ranking.png")[0];
	end = rm->GetImages("Resource/Images/end.png")[0];
	start_red = rm->GetImages("Resource/Images/start_red.png")[0];
	help_red = rm->GetImages("Resource/Images/H_font_red.png")[0];
	ranking_red = rm->GetImages("Resource/Images/ranking_red.png")[0];
	end_red = rm->GetImages("Resource/Images/end_red.png")[0];
	kao = rm->GetImages("Resource/Images/point.png")[0];
	kao2 = rm->GetImages("Resource/Images/point2.png")[0];
	kao3 = rm->GetImages("Resource/Images/point3.png")[0];
	kao4 = rm->GetImages("Resource/Images/point4.png")[0];
	
	SetFontSize(60);
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
			return eSceneType::E_OWARI;
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
	case TitleSelect::InGame:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y - 3, 0.3, 0.0, kao, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, start_red, TRUE);
		DrawRotaGraph(600, DRAW_SET_Y + 67, 1.0, 0.0, help, TRUE);
		DrawRotaGraph(670, DRAW_SET_Y + 137, 1.0, 0.0, ranking, TRUE);
		DrawRotaGraph(560, DRAW_SET_Y + 207, 0.9, 0.0, end, TRUE);
		break;
	case TitleSelect::Help:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y + 77, 0.23, 0.0, kao3, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, start, TRUE);
		DrawRotaGraph(600, DRAW_SET_Y + 67, 1.0, 0.0, help_red, TRUE);
		DrawRotaGraph(670, DRAW_SET_Y + 137, 1.0, 0.0, ranking, TRUE);
		DrawRotaGraph(560, DRAW_SET_Y + 207, 0.9, 0.0, end, TRUE);
		break;
	case TitleSelect::Ranking:
		DrawRotaGraph(DRAW_SET_X - 98, DRAW_SET_Y + 158, 0.18, 0.0, kao4, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, start, TRUE);
		DrawRotaGraph(600, DRAW_SET_Y + 67, 1.0, 0.0, help, TRUE);
		DrawRotaGraph(670, DRAW_SET_Y + 137, 1.0, 0.0, ranking_red, TRUE);
		DrawRotaGraph(560, DRAW_SET_Y + 207, 0.9, 0.0, end, TRUE);
		break;
	case TitleSelect::EXIT:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y + 220, 0.16, 0.0, kao2, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, start, TRUE);
		DrawRotaGraph(600, DRAW_SET_Y + 67, 1.0, 0.0, help, TRUE);
		DrawRotaGraph(670, DRAW_SET_Y + 137, 1.0, 0.0, ranking, TRUE);
		DrawRotaGraph(560, DRAW_SET_Y + 207, 0.9, 0.0, end_red, TRUE);
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