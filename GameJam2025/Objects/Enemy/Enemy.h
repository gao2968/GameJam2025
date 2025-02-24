#pragma once
#include "../GameObject.h"
#include <vector>
#include "../TimeLimitCircle.h"

enum Enemy_Type
{
	arai,
	maesiro,
	maetu,
	ryouka,
	toubaru
};

class Enemy : public GameObject
{
private:
	//std::vector<int> pattern;	//QTEパターン
	std::vector<std::vector <int>> pattern;	//QTEパターン
	//int pattern_num; //パターンの添え字
	std::vector<int> pattern_num; //パターンの添え字
	int pattern_cnt; //2重配列の一つ目
	int state;
	int phase_two_timer;	//フェーズ2の時間制限
	int battle_count;	//
	int phase_one_cnt;
	int phase_one_enemy_size;

	TimeLimitCircle circle;

	int timecard;
	int timecard_cnt;
	int timecard_button;
	bool timecard_flg;
	float timecard_size;

	int font = 0x000000;

	int tai_image;
	int sya_image;
	int taisya_image;

	int anim_state;	//0停止　1再生
	float anim_len;
public:
	Enemy();
	virtual ~Enemy();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

public:
	void StartBattlePhaseOne();	//始まる瞬間だけ呼び出す
	void StartBattlePhaseTwo();

	void InBattlePhaseOne();	//始まる瞬間だけ呼び出す
	void InBattlePhaseTwo();

	void EndBattlePhaseOne();	//始まる瞬間だけ呼び出す
	void EndBattlePhaseTwo();

	void InitializationForRestart();

	int battle_phase;	//現在のフェーズ

	bool miss;	//入力ミス
	bool result; //最終結果　除霊できたか
	int add_score; //成功回数 追加すべきスコア ゲームメインのスコアに追加したらゲームメインで0にする

	bool SetEnemyType(int type);

	void PhaseTwoAnimDraw() const;
	void PhaseTwoAnimUpdate();
};

