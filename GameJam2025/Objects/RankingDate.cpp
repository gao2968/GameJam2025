#include "RankingDate.h"
#include <stdio.h>
#include <string.h>

RankingDate::RankingDate()
{
	for (int i = 0; i < 4; i++)
	{
		score[i] = NULL;
	}
}

RankingDate::~RankingDate()
{

}

// ����������
void RankingDate::Initialize()
{
	// ���C���L���O�f�[�^�̓ǂݍ���
	FILE* fp = nullptr;

	// �t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/ranking.csv", "r");

	// �G���[�`�F�b�N
	if (result != 0)
	{
		throw ("Resource/ranking.csv���J���܂���ł���\n");
	}

	// �Ώۃt�@�C������ǂݍ���
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%6d\n", &score[i]);
	}

	// �t�@�C���N���[�Y
	fclose(fp);

	// �����f�[�^�̐ݒ�
	score[3] = 0;
}

// �I������
void RankingDate::Finalize()
{

}

// �f�[�^�ݒ菈��
void RankingDate::SetRankingDate(int score, const char* name)
{
	this->score[3] = score;

	SortData();
}

// �X�R�A�擾����
int RankingDate::GetScore(int value) const
{
	return score[value];
}


// �f�[�^����ւ�����
void RankingDate::SortData()
{
	// �I��@�\�[�g���g�p���A�~���œ���ւ���
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (score[i] <= score[j])
			{
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;

			}
		}
	}

	

	// �����L���O�f�[�^�̏�������
	FILE* fp = nullptr;

	// �t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/ranking.csv", "w");

	// �G���[�`�F�b�N
	if (result != 0)
	{
		throw ("Resource/ranking.csv���J���܂���ł���\n");
	}

	// �Ώۃt�@�C���ɏ�������
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d\n", score[i]);
	}

	// �t�@�C���N���[�Y
	fclose(fp);
}
