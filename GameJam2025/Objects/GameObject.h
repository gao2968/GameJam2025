#pragma once

#include"../Utility/Vector2D.h"

//ステージの大きさ
#define STAGE_HEIGHT 1080.f
#define STAGE_WIDHT 1920.f

class GameObject
{
protected:
	unsigned int color;
	Vector2D location;
	Vector2D local_location;
	Vector2D box_size;
	int image;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

	virtual void Movement(Vector2D velocity);

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;

	virtual float ObjectLength(GameObject* object);
};

