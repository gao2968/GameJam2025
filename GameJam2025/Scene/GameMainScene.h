#pragma once
#include "SceneBase.h"

class GameMainScene:public SceneBase
{
private:

public:
	GameMainScene();
	~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw()const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

