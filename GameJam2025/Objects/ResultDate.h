#pragma once
class ResultDate
{
private:
	int score[6];  //�X�R�A�f�[�^

public:
	ResultDate();
	~ResultDate();

	void Initialize();  //��������
	void Finalize();  //�I������

public:
	//�����L���O�f�[�^�̐ݒ�
	void SetResultDate(int score, const char* name);
	//�X�R�A�擾����
	int GetScore(int value) const;

private:
	//�f�[�^����ւ�����
	void SortData();
};

