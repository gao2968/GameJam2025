#pragma once
#include "SceneBase.h"
#include "../Utility/Vector2D.h"

#define DRAW_SET_X 540
#define DRAW_SET_Y 500

enum EndSelect {
	Title,
	Ran
};

class EndScene : public SceneBase
{
private:
	int end_image;
	int title;
	int title_red;
	int ran;
	int ran_red;
	int kao;
	EndSelect sel;
public:
	EndScene();
	~EndScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw()const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

