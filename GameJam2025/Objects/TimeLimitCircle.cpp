#include "DxLib.h"

//�O���[�o���ϐ�
int timelimit_circle_image;
double AnglePercent = 0.0;


//�������Ԃ̉~�̃O���t�̏�����
void TimeLimitCircleInit(void)
{
	//�摜�̓ǂݍ���
	timelimit_circle_image = LoadGraph("Resource/timelimit_circle.png");
}


//�������Ԃ̉~�̃O���t�̕`��
void TimeLimitCircleDraw(void)
{
	//�~�̃O���t�̕`��
	DrawCircleGauge(300, 200, 100.0, timelimit_circle_image, AnglePercent);
}

//�������Ԃ̉~�̃O���t�̍X�V
void TimeLimitCircleUpdate(void)
{
	//360�t���[���ň������悤�Ɋp�x���̒l�����Z
	AnglePercent += 100.0 / 360.0;

	//100%�𒴂�����0%�ɖ߂�
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}