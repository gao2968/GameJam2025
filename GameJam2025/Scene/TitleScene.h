#pragma once

#include "SceneBase.h"
#include "../Utility/Vector2D.h"

#define DRAW_SET_X 540
#define DRAW_SET_Y 400

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
	int start;
	int help;
	int ranking;
	int end;
	int start_red;
	int help_red;
	int ranking_red;
	int end_red;
	int kao;
	int kao2;
	int kao3;
	int kao4;
	int kasoru;
	int kakutei;
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

