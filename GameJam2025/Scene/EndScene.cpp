#include "EndScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

EndScene::EndScene() :
	end_image(NULL),
	title(NULL),
	ran(NULL),
	title_red(NULL),
	ran_red(NULL),
	kao(NULL),
	sel(EndSelect::Title)
	,kasoru(NULL)
	,kakutei(NULL)
	,gameclear_sound(NULL)
{
	
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	end_image = rm->GetImages("Resource/Images/end_image.png")[0];
	title = rm->GetImages("Resource/Images/title_font.png")[0];
	title_red = rm->GetImages("Resource/Images/title_font_red.png")[0];
	ran = rm->GetImages("Resource/Images/ranking.png")[0];
	ran_red = rm->GetImages("Resource/Images/ranking_red.png")[0];
	kao = rm->GetImages("Resource/Images/point.png")[0];

	kasoru = rm->GetSounds("Resource/SE/ka-soru.mp3");
	kakutei = rm->GetSounds("Resource/SE/kakutei.mp3");

	gameclear_sound = rm->GetSounds("Resource/BGM/Sentou_2.mp3");

	ChangeVolumeSoundMem(230, gameclear_sound); // ここで音量を設定

	PlaySoundMem(gameclear_sound, DX_PLAYTYPE_LOOP); // 効果音を再生

	// ランキング情報を取得
	result = new RankingDate;
	result->Initialize();

	SetFontSize(95);

	//リザルトデータの読込
	FILE* fp = nullptr;
	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/result.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result_data.csvが開けません\n");
	}

	char buffer[64]; // 一時バッファ

	if (fgets(buffer, sizeof(buffer), fp) == nullptr)
	{
		throw("fgetsが失敗しました\n");
	}

	// UTF-8 BOMの削除
	if ((unsigned char)buffer[0] == 0xEF && (unsigned char)buffer[1] == 0xBB && (unsigned char)buffer[2] == 0xBF)
	{
		memmove(buffer, buffer + 3, strlen(buffer) - 2);  // BOMを削除
	}

	sscanf_s(buffer, "%6d,\n", &score);

	//ファイルクローズ
	fclose(fp);
}

eSceneType EndScene::Update()
{
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		PlaySoundMem(kasoru, DX_PLAYTYPE_BACK);
		if (sel == EndSelect::Ran)
		{
			sel = EndSelect::Title;
		}
		else
		{
			sel = EndSelect::Ran;
		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		PlaySoundMem(kasoru, DX_PLAYTYPE_BACK);
		if (sel == EndSelect::Title)
		{
			sel = EndSelect::Ran;
		}
		else
		{
			sel = EndSelect::Title;
		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		PlaySoundMem(kakutei, DX_PLAYTYPE_BACK);
		if (sel == EndSelect::Ran)
		{
			result->SetRankingDate(score);
			return eSceneType::E_RANKING;
		}
		else {

			result->SetRankingDate(score);
			return eSceneType::E_TITLE;
		}
	}

	return GetNowScene();

}

void EndScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, end_image, TRUE);

	switch (sel)
	{
	case EndSelect::Title:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y - 3, 0.3, 0.0, kao, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, title_red, TRUE);
		DrawRotaGraph(680, DRAW_SET_Y + 110, 1.0, 0.0, ran, TRUE);
		break;
	case EndSelect::Ran:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y + 110, 0.3, 0.0, kao, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, title, TRUE);
		DrawRotaGraph(680, DRAW_SET_Y + 110, 1.0, 0.0, ran_red, TRUE);
		break;
	}

	////�@�擾���������L���O�f�[�^��`�悷��
	//for (int i = 0; i < 1; i++)
	//{
	//	DrawFormatString(620, 180, 0xffffff, "%6d", result->GetScore(i));
	//}

	//DrawFormatString(620, 180, 0xffffff, "%6d", result->GetScore(5));
	DrawFormatString(620, 180, 0xffffff, "%6d", score);

}

void EndScene::Finalize()
{
	// 音楽を止める
	StopSoundMem(gameclear_sound);

	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

eSceneType EndScene::GetNowScene() const
{
	return eSceneType::E_END;
}


