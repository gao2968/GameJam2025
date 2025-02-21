#pragma once
enum QTEState
{
	success,
	faild,
	midway
};
class QTESystem
{
private:
	static float elapsed_time;
	static int button;
	static int phase; //1 フェーズ1   2 フェーズ2

public:
	//ランダムにQTEを発生　初期値の設定に成功すればtrue
	//引数はフレーム単位で
	static QTEState StartQTE(float second);

	//ランダムにQTEを発生　初期値の設定に成功すればtrue
	//引数はフレーム単位で
	static QTEState StartQTEPhaseTwo(float second, int target_button);

	//QTE中の処理
	static QTEState InQTE();

	static void SetPhase(int n);

	void Update();

	static void Draw();
};

