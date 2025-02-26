#include "RankingDate.h"
#include <stdio.h>
#include <string.h>

RankingDate::RankingDate()
{
	for (int i = 0; i < 6; i++)
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

	int a;
	char buffer[64]; // 一時バッファ
	// �Ώۃt�@�C������ǂݍ���
	for (int i = 0; i < 5; i++)
	{
		if (fgets(buffer, sizeof(buffer), fp) == nullptr) {
			break;
		}

		// UTF-8 BOMの削除
		if (i == 0 && (unsigned char)buffer[0] == 0xEF && (unsigned char)buffer[1] == 0xBB && (unsigned char)buffer[2] == 0xBF) {
			memmove(buffer, buffer + 3, strlen(buffer) - 2);  // BOMを削除
		}

		sscanf_s(buffer, "%6d,\n", &score[i]);
	}

	

	// �t�@�C���N���[�Y
	fclose(fp);

	// �����f�[�^�̐ݒ�
	score[5] = 0;
}

// �I������
void RankingDate::Finalize()
{

}

// �f�[�^�ݒ菈��
void RankingDate::SetRankingDate(int score, const char* name)
{
	this->score[5] = score;

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
	// �I��@�\�[�g��g�p���A�~���œ���ւ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
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
	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d,\n", score[i]);
	}

	// �t�@�C���N���[�Y
	fclose(fp);
}
