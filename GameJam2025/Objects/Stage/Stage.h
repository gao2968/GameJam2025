#pragma once
#include "../GameObject.h"



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
