#pragma once
class ResultDate
{
private:
	int score[6];  //スコアデータ

public:
	ResultDate();
	~ResultDate();

	void Initialize();  //初期処理
	void Finalize();  //終了処理

public:
	//ランキングデータの設定
	void SetResultDate(int score, const char* name);
	//スコア取得処理
	int GetScore(int value) const;

private:
	//データ入れ替え処理
	void SortData();
};

