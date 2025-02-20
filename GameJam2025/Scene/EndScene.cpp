#include "EndScene.h"
#include "DxLib.h"

EndScene::EndScene()
{
	
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
}

eSceneType EndScene::Update()
{
	return GetNowScene();
}

void EndScene::Draw() const
{
}

void EndScene::Finalize()
{
}

eSceneType EndScene::GetNowScene() const
{
	return eSceneType::E_END;
}
