#pragma once

#include"../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;
	Vector2D location;
	Vector2D box_size;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;
};

