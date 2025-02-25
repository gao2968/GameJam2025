#pragma once
#include "SceneBase.h"
#include "../Utility/Vector2D.h"

class RankingScene : public SceneBase
{
private:
	int ranking_image;
	
public:
	RankingScene();
	virtual ~RankingScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

