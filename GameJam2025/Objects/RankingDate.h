#pragma once

class RankingDate
{
private:
	int score[6];  //�X�R�A�f�[�^

public:
	RankingDate();
	~RankingDate();

	void Initialize();  //��������
	void Finalize();  //�I������

public:
	//�����L���O�f�[�^�̐ݒ�
	void SetRankingDate(int score);
	//�X�R�A�擾����
	int GetScore(int value) const;

private:
	//�f�[�^����ւ�����
	void SortData();
};

