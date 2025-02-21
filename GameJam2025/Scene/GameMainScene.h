#pragma once
#include "SceneBase.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Stage/Stage.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/GameObject.h"

class GameMainScene:public SceneBase
{
private:
	Stage* stage;
	Player* player;
	Enemy* enemy;

	int player_num;
	int enemy_num[3];
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

};

