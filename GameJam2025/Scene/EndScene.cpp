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
{
	
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
	//�C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	end_image = rm->GetImages("Resource/Images/end_image.png")[0];
	title = rm->GetImages("Resource/Images/title_font.png")[0];
	title_red = rm->GetImages("Resource/Images/title_font_red.png")[0];
	ran = rm->GetImages("Resource/Images/ranking.png")[0];
	ran_red = rm->GetImages("Resource/Images/ranking_red.png")[0];
	kao = rm->GetImages("Resource/Images/point.png")[0];

	kasoru = rm->GetSounds("Resource/SE/ka-soru.mp3");
	kakutei = rm->GetSounds("Resource/SE/kakutei.mp3");

	getscore = game->GetScore();
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
			return eSceneType::E_RANKING;
		}
		else {

			return eSceneType::E_TITLE;
		}
	}

	return GetNowScene();

}

void EndScene::Draw() const
{
	//�e�N���X��Draw���Ăяo���B
	__super::Draw();

	// �w�i�摜�̕`��
	DrawRotaGraph(640, 360, 1.0, 0.0, end_image, TRUE);

	DrawFormatString(640, 250, 0xffffff, "%d",getscore);

	switch (sel)
	{
	case EndSelect::Title:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y - 3, 0.3, 0.0, kao, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, title_red, TRUE);
		DrawRotaGraph(675, DRAW_SET_Y + 110, 1.0, 0.0, ran, TRUE);
		break;
	case EndSelect::Ran:
		DrawRotaGraph(DRAW_SET_X - 100, DRAW_SET_Y + 115, 0.3, 0.0, kao, TRUE);
		DrawRotaGraph(640, DRAW_SET_Y, 1.0, 0.0, title, TRUE);
		DrawRotaGraph(675, DRAW_SET_Y + 110, 1.0, 0.0, ran_red, TRUE);
		break;
	}
}

void EndScene::Finalize()
{
	// �e�N���X�̏I�����������Ăяo��
	__super::Finalize();
}

eSceneType EndScene::GetNowScene() const
{
	return eSceneType::E_END;
}


