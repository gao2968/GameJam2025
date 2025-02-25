#pragma once
#include "SceneBase.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Stage/Stage.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/GameObject.h"
#include "../Utility/Ui.h"

#define INITHP 10800

enum MainState
{
	SearchPhase,
	BattlePhaseOne,
	BattlePhaseTwo,
	EndPhase = 99
};

class GameMainScene:public SceneBase
{
private:
	Stage* stage;
	Player* player;
	Enemy* enemy;
	Ui* ui;

	std::vector<GameObject*> object;
	Enemy* nearest_enemy;
	int nearest_enemy_num = -1;

	int player_num = 0;
	int enemy_num[5] = { 2,3,4,5,6 };

	int state;

	int hp = INITHP;	//hp兼timer
	int score = 0;
	int enemy_cnt;	//残りの敵

	int gamemain_sound;
	int tekinosi_sound;
	int damage_sound;

	bool result;

	int frame;

	int contact_se;

public:
	GameMainScene();
	~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw()const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

public:
	void DrawResult() const;

	Vector2D GetInputVelocity();

	//プレイヤーに近い敵を見つける
	void SearchNearestEnemy();

	void CalculationHp();

	int GetHp() { return hp; }
	int GetScore();
	int GetEnemyCount(){ return enemy_cnt; }
};

