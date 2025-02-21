#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

TitleScene::TitleScene()
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
}

eSceneType TitleScene::Update()
{
	return GetNowScene();
}

//�`�揈��
void TitleScene::Draw() const
{
	
}

//�I��������
void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}