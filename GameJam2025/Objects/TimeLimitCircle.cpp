#include "DxLib.h"

//グローバル変数
int timelimit_circle_image;
double AnglePercent = 0.0;


//制限時間の円のグラフの初期化
void TimeLimitCircleInit(void)
{
	//画像の読み込み
	timelimit_circle_image = LoadGraph("Resource/timelimit_circle.png");
}


//制限時間の円のグラフの描画
void TimeLimitCircleDraw(void)
{
	//円のグラフの描画
	DrawCircleGauge(300, 200, 100.0, timelimit_circle_image, AnglePercent);
}

//制限時間の円のグラフの更新
void TimeLimitCircleUpdate(void)
{
	//360フレームで一周するように角度％の値を加算
	AnglePercent += 100.0 / 360.0;

	//100%を超えたら0%に戻す
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}