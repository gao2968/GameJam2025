#pragma once
#include "../GameObject.h"

class Player : public GameObject
{
private:
	bool camera_stop_x;
	bool camera_stop_y;

	Vector2D oval_radius;
	bool oval_flg;
	float speed;

	int cursor;

	int cursor_se[3];
public:
	Player();
	virtual ~Player();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

public:
	void Movement(Vector2D velocity) override;

	bool GetCameraStopX();
	bool GetCameraStopY();

	float nearest_enemy_length = 9999.f;

	float ObjectLength(GameObject* object) override;
};

