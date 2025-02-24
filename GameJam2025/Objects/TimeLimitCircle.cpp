#include "DxLib.h"
#include "TimeLimitCircle.h"

////�O���[�o���ϐ�
//int timelimit_circle_image;
//double AnglePercent = 0.0;
//
//
////�������Ԃ̉~�̃O���t�̏�����
//void TimeLimitCircleInit(void)
//{
//	//�摜�̓ǂݍ���
//	timelimit_circle_image = LoadGraph("Resource/simple_frame_01_circle_red.png");
//}
//
//
////�������Ԃ̉~�̃O���t�̕`��
//void TimeLimitCircleDraw(void)
//{
//	//�~�̃O���t�̕`��
//	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
//}
//
////�퓬���̃R�}���h���̓G�t�F�N�g�̕`��
//int BattleSquareDraw(int square)
//{
//	//�}�`�̒l�n��
//	int i = square;
//
//	//�O�p�`�̕`��
//	if (i == 3)
//	{
//		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);
//	}
//
//	//�l�p�`�̕`��
//	if (i == 4)
//	{
//		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);
//	}
//
//	//�܊p�`�̕`��
//	if (i == 5)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//	}
//
//	//�Z�p�`�̕`��
//	if (i == 6)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);
//	}
//
//	//���p�`�̕`��
//	if (i == 7)
//	{
//		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);
//	}
//
//	return i;
//}
//
////�������Ԃ̉~�̃O���t�̍X�V
//void TimeLimitCircleUpdate(float time)
//{
//	//360�t���[���ň������悤�Ɋp�x���̒l�����Z
//	AnglePercent += 100.0 / time;
//
//	//100%�𒴂�����0%�ɖ߂�
//	if (AnglePercent >= 100.0)
//	{
//		AnglePercent = 0.0;
//	}
//}

void TimeLimitCircle::TimeLimitCircleInit(void)
{
	//�摜�̓ǂݍ���
	timelimit_circle_image = LoadGraph("Resource/Images/simple_frame_01_circle_red.png");

	button_images[0] = LoadGraph("Resource/Images/xbox_button_color_a.png");
	button_images[1] = LoadGraph("Resource/Images/xbox_button_color_b.png");
	button_images[2] = LoadGraph("Resource/Images/xbox_button_color_x.png");
	button_images[3] = LoadGraph("Resource/Images/xbox_button_color_y.png");
}

void TimeLimitCircle::TimeLimitCircleDraw(void) const
{
	//�~�̃O���t�̕`��
	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
}

int TimeLimitCircle::BattleSquareDraw(int square, std::vector<int> button) const
{
	//�}�`�̒l�n��
	int i = square;

	//�O�p�`�̕`��
	if (i == 3)
	{
		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);
		DrawGraph(645, 125, button_images[button[0]], TRUE);
		DrawGraph(830, 475, button_images[button[1]], TRUE);
		DrawGraph(460, 475, button_images[button[2]], TRUE);
	}

	//�l�p�`�̕`��
	if (i == 4)
	{
		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);
	}

	//�܊p�`�̕`��
	if (i == 5)
	{
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);
	}

	//�Z�p�`�̕`��
	if (i == 6)
	{
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);
	}

	//���p�`�̕`��
	if (i == 7)
	{
		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);
	}

	return i;
}

void TimeLimitCircle::TimeLimitCircleUpdate(float time)
{
	//360�t���[���ň������悤�Ɋp�x���̒l�����Z
	AnglePercent += 100.0 / time;

	//100%�𒴂�����0%�ɖ߂�
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}
