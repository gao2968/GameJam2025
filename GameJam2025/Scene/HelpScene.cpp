#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

HelpScene::HelpScene()
{

}

HelpScene::~HelpScene()
{

}

//����������
void HelpScene::Initialize()
{
	
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

	/*DrawString(100, 100, "Bボタンで戻る", GetColor(255, 255, 255));*/
	
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