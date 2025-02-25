#include "RankingScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "../Scene/GameMainScene.h"
#include "DxLib.h"

RankingScene::RankingScene() :
	ranking_image(NULL)
{

}

RankingScene::~RankingScene()
{
}

void RankingScene::Initialize()
{
	//�C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	ranking_image = rm->GetImages("Resource/Images/ranking_image.png")[0];
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
	//�e�N���X��Draw���Ăяo���B
	__super::Draw();

	// �w�i�摜�̕`��
	DrawRotaGraph(640, 360, 1.0, 0.0, ranking_image, TRUE);

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
