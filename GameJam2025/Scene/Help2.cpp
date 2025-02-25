#include "Help2.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

Help2::Help2()
	: help_image(NULL)
{

}

Help2::~Help2()
{

}

//����������
void Help2::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	help_image = rm->GetImages("Resource/Images/Help2.png")[0];
}
//�X�V����
eSceneType Help2::Update()
{
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		return eSceneType::E_HELP3;
	}
	return GetNowScene();
}

//�`�揈��
void Help2::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, help_image, TRUE);

}

//�I������
void Help2::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

//���݂̃V�[�����擾
eSceneType Help2::GetNowScene() const
{
	return eSceneType::E_HELP2;
}
