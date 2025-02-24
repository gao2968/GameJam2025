#include "RankingScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

RankingScene::RankingScene()
{

}

RankingScene::~RankingScene()
{
}

void RankingScene::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();
}

eSceneType RankingScene::Update()
{
	return GetNowScene();

}

void RankingScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	DrawString(100, 100, "ranking", GetColor(255, 1, 1));
}

void RankingScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

eSceneType RankingScene::GetNowScene() const
{
	return eSceneType::E_RANKING;
}
