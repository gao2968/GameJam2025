#pragma once

#include "SceneBase.h"
#include "../Utility/Vector2D.h"


class TitleScene : public SceneBase
{
private:
	int title_image;
	int title_sound;

public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

