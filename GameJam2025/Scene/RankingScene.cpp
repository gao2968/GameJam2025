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
	//�C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();
}

eSceneType RankingScene::Update()
{
	return GetNowScene();

}

void RankingScene::Draw() const
{
	//�e�N���X��Draw���Ăяo���B
	__super::Draw();

	DrawString(100, 100, "ranking", GetColor(255, 1, 1));
}

void RankingScene::Finalize()
{
	// �e�N���X�̏I�����������Ăяo��
	__super::Finalize();
}

eSceneType RankingScene::GetNowScene() const
{
	return eSceneType::E_RANKING;
}
