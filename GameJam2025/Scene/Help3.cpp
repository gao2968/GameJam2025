#include "Help3.h"
#include "../Utility/InputControl.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

Help3::Help3()
	: help_image(NULL)
	, next(NULL)
{

}

Help3::~Help3()
{

}

//����������
void Help3::Initialize()
{
	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	help_image = rm->GetImages("Resource/Images/Help3.png")[0];
	next = rm->GetSounds("Resource/SE/kakutei.mp3");

}
//�X�V����
eSceneType Help3::Update()
{
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		PlaySoundMem(next, DX_PLAYTYPE_BACK);
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//�`�揈��
void Help3::Draw() const
{
	//親クラスのDrawを呼び出す。
	__super::Draw();

	// 背景画像の描画
	DrawRotaGraph(640, 360, 1.0, 0.0, help_image, TRUE);

}

//�I������
void Help3::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

//���݂̃V�[�����擾
eSceneType Help3::GetNowScene() const
{
	return eSceneType::E_HELP3;
}