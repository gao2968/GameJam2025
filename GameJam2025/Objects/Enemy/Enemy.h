#pragma once
#include "../GameObject.h"
#include <vector>
#include "../TimeLimitCircle.h"

#define PhaseTwoTimer 720.f

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
	std::vector<std::vector <int>> pattern;	//QTEパターン
	std::vector<int> pattern_num; //パターンの添え字
	std::vector<int> pattern_num_init; //パターンの添え字の初期値
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

	int teki_idou_sound;
	int combo_sound;
	int mojikannsei_sound;
	int kougeki_1_sound;
	int kougeki_2_sound;

	int anim_state;	//0停止　1再生
	float anim_len;
	Vector2D anim_location[4];
	float anim_rate = 1024.f;

	int image_original; //透過してない画像

	int lose_se;
	int attack_se[2];
	int damage_se;
	int taisya_se;

	int button_image[4];

	int transp;
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

