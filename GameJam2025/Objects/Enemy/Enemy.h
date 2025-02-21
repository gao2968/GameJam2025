#pragma once
#include "../GameObject.h"
#include <vector>

class Enemy : public GameObject
{
private:
	std::vector<int> pattern;	//QTEパターン
	int pattern_num; //パターンの添え字
	int state;
	int phase_two_timer;	//フェーズ2の時間制限
	int battle_count;	//
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

	int battle_phase;	//現在のフェーズ

};

