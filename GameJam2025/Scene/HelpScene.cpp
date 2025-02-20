#include "HelpScene.h"

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
	return GetNowScene();
}

//�`�揈��
void HelpScene::Draw() const
{
	
	
}

//�I������
void HelpScene::Finalize()
{

}

//���݂̃V�[�����擾
eSceneType HelpScene::GetNowScene() const
{
	return eSceneType::E_HELP;
}