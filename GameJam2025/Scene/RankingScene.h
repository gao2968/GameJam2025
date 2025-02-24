#pragma once
#include "SceneBase.h"
#include "../Utility/Vector2D.h"

class RankingScene : SceneBase
{
private:
	
public:
	RankingScene();
	virtual ~RankingScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

