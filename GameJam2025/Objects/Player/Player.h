#pragma once
#include "../GameObject.h"

class Player : public GameObject
{
private:
	Vector2D velocity;

public:
	Player();
	virtual ~Player();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

private:
	void Movement();
};

