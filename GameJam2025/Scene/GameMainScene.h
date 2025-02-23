#pragma once
#include "SceneBase.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Stage/Stage.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/GameObject.h"

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

	std::vector<GameObject*> object;
	Enemy* nearest_enemy;
	int nearest_enemy_num = -1;

	int player_num = 0;
	int enemy_num[3] = { 2,3,4 };

	int state;

	int hp = 10800;	//hp兼timer
	int score = 0;
public:
	GameMainScene();
	~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw()const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

public:
	Vector2D GetInputVelocity();

	//プレイヤーに近い敵を見つける
	void SearchNearestEnemy();

	void CalculationHp();
};

