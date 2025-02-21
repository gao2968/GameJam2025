#pragma once
#include "../GameObject.h"

//ステージの大きさ
#define STAGE_HEIGHT 1080.f
#define STAGE_WIDHT 1920.f

class Stage : public GameObject
{
private:
	Vector2D velocity;

public:
	Stage();
	virtual ~Stage();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

};
