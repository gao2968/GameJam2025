//#include "Dxlib.h"
//#include "Utility/InputControl.h"
//#include "Objects/Player/Player.h"
//
//int WINAPI WinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPSTR lpCmdLine,
//	_In_ int nShowCmd
//)
//{
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)
//	{
//		return -1;
//	}
//
//	GameObject* object[2] = { nullptr,nullptr };
//	object[0] = new GameObject();
//	object[1] = new Player();
//
//	for (int i = 0; i < 2; i++)
//	{
//		object[i]->Initialize();
//	}
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ProcessMessage() != -1)
//	{
//		InputControl::Update();
//
//		for (int i = 0; i < 2; i++)
//		{
//			object[i]->Update();
//		}
//
//		ClearDrawScreen();
//
//		for (int i = 0; i < 2; i++)
//		{
//			object[i]->Draw();
//		}
//
//		ScreenFlip();
//
//		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
//		{
//			break;
//		}
//	}
//
//	for (int i = 0; i < 2; i++)
//	{
//		object[i]->Finalize();
//		delete object[i];
//	}
//
//	DxLib_End();
//
//	return 0;
//}

#include "DxLib.h"
#include "Scene/SceneManager.h"

// ���C���֐��i�v���O�����͂�������n�܂�܂��B�j
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ��O�����i�ُ킪����������Acatch���ɔ�т܂��j
	try
	{
		// �V�[���}�l�[�W���[�@�\�̐���
		SceneManager manager;

		// �V�[���}�l�[�W���[�@�\�̏���������
		manager.Initialize();

		// �V�[���}�l�[�W���[�@�\�̍X�V����
		manager.Update();

		// �V�[���}�l�[�W���[�@�\�̏I��������
		manager.Finalize();
	}
	catch (const char* err_log)
	{
		// �G���[������e�̏o��
		OutputDebugString(err_log);

		// �G���[�I����ʒm
		return -1;
	}

	// ����I����ʒm
	return 0;
}