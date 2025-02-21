#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

TitleScene::TitleScene()
	: title_image(NULL)
	, title_sound(NULL)
	, tamesi(NULL)
	, select(TitleSelect::InGame)
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

	title_image = rm->GetImages("Resource/Images/stage.png")[0];
	tamesi = rm->GetImages("Resource/Images/ryouka.png")[0];
	
}

eSceneType TitleScene::Update()
{
	/*if (InputControl::GetKey())
	{
		if (select == TitleSelect::EXIT)
		{
			select = TitleSelect::NEXT_STAGE;
		}
		else
		{
			select = TitleSelect::EXIT;
		}
	}
	if (IM->GetKeyDown(KEY_INPUT_UP))
	{
		if (select == TitleSelect::NEXT_STAGE)
		{
			select = TitleSelect::EXIT;
		}
		else
		{
			select = TitleSelect::NEXT_STAGE;
		}
	}
	if (IM->GetKeyDown(KEY_INPUT_RETURN))
	{
		if (select == TitleSelect::EXIT)
		{
			end_flg = true;
		}
		else {

			return eSceneType::eInGame;
		}
	}*/
	return GetNowScene();
}

//�`�揈��
void TitleScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	DrawString(100, 100, "title", WHITE);

	// 背景画像の描画
	DrawRotaGraph(640, 400, 0.33, 0.0, title_image, TRUE);

	// 背景画像の描画
	DrawRotaGraph(640, 400, 0.2, 0.0, tamesi, TRUE);
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