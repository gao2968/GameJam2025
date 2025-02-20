#include "TitleScene.h"
#include "../Utility/InputControl.h"
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