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

// 初期化処理
void RankingDate::Initialize()
{
	// ラインキングデータの読み込み
	FILE* fp = nullptr;

	// ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/ranking.csv", "r");

	// エラーチェック
	if (result != 0)
	{
		throw ("Resource/ranking.csvが開けませんでした\n");
	}

	// 対象ファイルから読み込む
	for (int i = 0; i < 5; i++)
	{
		fscanf_s(fp, "%6d\n", &score[i]);
	}

	// ファイルクローズ
	fclose(fp);

	// 末尾データの設定
	score[5] = 0;
}

// 終了処理
void RankingDate::Finalize()
{

}

// データ設定処理
void RankingDate::SetRankingDate(int score, const char* name)
{
	this->score[5] = score;

	SortData();
}

// スコア取得処理
int RankingDate::GetScore(int value) const
{
	return score[value];
}


// データ入れ替え処理
void RankingDate::SortData()
{
	// 選択法ソートを使用し、降順で入れ替える
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

	

	// ランキングデータの書き込み
	FILE* fp = nullptr;

	// ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/ranking.csv", "w");

	// エラーチェック
	if (result != 0)
	{
		throw ("Resource/ranking.csvが開けませんでした\n");
	}

	// 対象ファイルに書き込み
	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d,%d,\n", score[i]);
	}

	// ファイルクローズ
	fclose(fp);
}
