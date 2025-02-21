#pragma once

#include "SceneBase.h"
#include "../Utility/Vector2D.h"

#define DRAW_SET_X 530
#define DRAW_SET_Y 380

#define WHITE 0xFFFFFF
#define RED 0xFF0000

enum TitleSelect {
	InGame,
	Help,
	Ranking,
	EXIT,
};

class TitleScene : public SceneBase
{
private:
	int title_image;
	int title_sound;
	int tamesi;
	bool end_flg;
	TitleSelect select;

public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

	virtual bool GetEndFlag() override;
};

