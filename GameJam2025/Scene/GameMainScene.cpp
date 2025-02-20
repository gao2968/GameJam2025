//#include <afxwin.h>
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	
}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	
}

eSceneType GameMainScene::Update()
{

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	
}

void GameMainScene::Finalize()
{
	
}

// ���݂̃V�[�����擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}