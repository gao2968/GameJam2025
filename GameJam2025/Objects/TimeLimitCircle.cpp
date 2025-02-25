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

//�퓬���o�̏�����
void TimeLimitCircle::TimeLimitCircleInit(void)
{
	//�摜�̓ǂݍ���
	timelimit_circle_image = LoadGraph("Resource/Images/simple_frame_01_circle_red.png");
	cursor_aura = LoadGraph("Resource/Images/command_aura.png");

	button_images[0] = LoadGraph("Resource/Images/xbox_button_color_a.png");
	button_images[1] = LoadGraph("Resource/Images/xbox_button_color_b.png");
	button_images[2] = LoadGraph("Resource/Images/xbox_button_color_x.png");
	button_images[3] = LoadGraph("Resource/Images/xbox_button_color_y.png");

	button_images_outline[0] = LoadGraph("Resource/Images/xbox_button_color_a_outline.png");
	button_images_outline[1] = LoadGraph("Resource/Images/xbox_button_color_b_outline.png");
	button_images_outline[2] = LoadGraph("Resource/Images/xbox_button_color_x_outline.png");
	button_images_outline[3] = LoadGraph("Resource/Images/xbox_button_color_y_outline.png");
}

//�������Ԃ̉~�^�Q�[�W�̕`��
void TimeLimitCircle::TimeLimitCircleDraw(void) const
{
	//�~�̃O���t�̕`��
	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
}

//�퓬���̃R�}���h��ʂ̕`��
int TimeLimitCircle::BattleSquareDraw(int square, std::vector<int> button, int num) const
{
	//�}�`�̒l�n��
	int i = square;
	num += 1;

	int SlideX = 0;
	int SlideY = 0;

	//�O�p�`�̕`��
	if (i == 3)
	{
		//�}�`�̕`��
		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);

		//�{�^���̕`��
		if (num == 3) {
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images[button[2]], TRUE);

			if (miss_flg)
			{
				SlideX = GetRand(6) - 3;
				SlideY = GetRand(6) - 3;	

				DrawGraph(580 + SlideX, 125 + SlideY, cursor_aura, TRUE);

			}
			else
			{
				DrawGraph(580, 125, cursor_aura, TRUE);
			}
		}
		else if (num == 2)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);

			DrawGraph(720, 370, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);

			DrawGraph(440, 370, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(440, 370, button_images_outline[button[0]], TRUE);
			DrawGraph(720, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);
		}
	}

	//�l�p�`�̕`��
	if (i == 4)
	{
		//�}�`�̕`��
		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);

		//�{�^���̕`��
		if (num == 4) 
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images[button[3]], TRUE);

			DrawGraph(580, 120, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(740, 280, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(580, 450, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images_outline[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(420, 280, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 280, button_images_outline[button[0]], TRUE);
			DrawGraph(580, 450, button_images_outline[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);
		}
	}

	//�܊p�`�̕`��
	if (i == 5)
	{
		//�}�`�̕`��
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);

		//�{�^���̕`��
		if (num == 5)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images[button[4]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(740, 230, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(690, 440, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(480, 440, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images_outline[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(420, 230, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 230, button_images_outline[button[0]], TRUE);
			DrawGraph(480, 440, button_images_outline[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
	}

	//�Z�p�`�̕`��
	if (i == 6)
	{
		//�}�`�̕`��
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);

		//�{�^���̕`��
		if (num == 6)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images[button[5]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 5)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(740, 210, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(740, 370, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(580, 460, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(420, 370, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(420, 210, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 210, button_images_outline[button[0]], TRUE);
			DrawGraph(420, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
	}

	//���p�`�̕`��
	if (i == 7)
	{
		//�}�`�̕`��
		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);

		//�{�^���̕`��
		if (num == 7)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images[button[5]], TRUE);
			DrawGraph(580, 115, button_images[button[6]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 6)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(740, 200, cursor_aura, TRUE);
		}
		else if (num == 5)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(760, 340, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(680, 460, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(500, 460, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(400, 340, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images_outline[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(420, 200, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 200, button_images_outline[button[0]], TRUE);
			DrawGraph(400, 340, button_images_outline[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);
		}
	}

	return i;
}

//�������Ԃ̍X�V
void TimeLimitCircle::TimeLimitCircleUpdate(float time, bool miss)
{
	miss_flg = miss;

	//360�t���[���ň������悤�Ɋp�x���̒l�����Z
	AnglePercent += 100.0 / time;

	//100%�𒴂�����0%�ɖ߂�
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}
