#include "RankingScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "../Scene/GameMainScene.h"
#include "DxLib.h"

RankingScene::RankingScene() :
	ranking_image(NULL)
	, ranking(nullptr)
{

}

RankingScene::~RankingScene()
{
}

void RankingScene::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	ranking_image = rm->GetImages("Resource/Images/ranking_image.png")[0];

	// ランキング情報を取得
	ranking = new RankingDate;
	ranking->Initialize();
}

eSceneType RankingScene::Update()
{
	
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	
	return GetNowScene();

}

void RankingScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, ranking_image, TRUE);

	//　取得したランキングデータを描画する
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d", ranking->GetScore(i));
	}

}

void RankingScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();

	// 動的メモリの解放
	ranking->Finalize();
	delete ranking;
}

eSceneType RankingScene::GetNowScene() const
{
	return eSceneType::E_RANKING;
}
