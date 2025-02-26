#pragma once

class RankingDate
{
private:
	int score[6];  //スコアデータ

public:
	RankingDate();
	~RankingDate();

	void Initialize();  //初期処理
	void Finalize();  //終了処理

public:
	//ランキングデータの設定
	void SetRankingDate(int score, const char* name);
	//スコア取得処理
	int GetScore(int value) const;

private:
	//データ入れ替え処理
	void SortData();
};

