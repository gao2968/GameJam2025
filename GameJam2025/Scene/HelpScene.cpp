#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

HelpScene::HelpScene() 
	: help_image(NULL)
{

}

HelpScene::~HelpScene()
{

}

//����������
void HelpScene::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	help_image = rm->GetImages("Resource/Images/Help.png")[0];
}
//�X�V����
eSceneType HelpScene::Update()
{
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//�`�揈��
void HelpScene::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, help_image, TRUE);
	
}

//�I������
void HelpScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

//���݂̃V�[�����擾
eSceneType HelpScene::GetNowScene() const
{
	return eSceneType::E_HELP;
}