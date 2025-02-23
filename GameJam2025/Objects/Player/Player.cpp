#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"

Player::Player() :camera_stop_x(false), camera_stop_y(false)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	color = GetColor(0, 255, 0);

	box_size = Vector2D(32.f);

	location = Vector2D(1920 / 2, 1080 / 2);

	local_location = Vector2D(1280 / 2, 720 / 2);
}

void Player::Update()
{
	if (nearest_enemy_length > 300) { color = 0x00ff00; }

	if (nearest_enemy_length < 100) { color = 0x0000ff; }
	else if (nearest_enemy_length < 200) { color = 0x00ffff; }
	else if (nearest_enemy_length < 300) { color = 0xffff00; }
}

void Player::Draw() const
{
	__super::Draw();

	DrawFormatString(local_location.x, local_location.y, 0x0000ff, "x%f y%f", location.x, location.y);
	DrawFormatString(local_location.x, local_location.y + 20, 0x0000ff, "x%f y%f", local_location.x, local_location.y);

	DrawLine(640, 0, 640, 1280, 0xff0000);
	DrawLine(0, 360, 1280, 360, 0xff0000);
}

void Player::Finalize()
{
}

void Player::Movement(Vector2D velocity)
{
	location.x += velocity.x;
	location.y -= velocity.y;

	//ステージ端ならカーソル自体移動　そうではないなら、カーソルは常に画面中央に来るように
	//左上座標　右下座標
	if (location.x >= 540.f && location.y >= 260.f &&
		location.x <= 1380.f && location.y <= 820.f)
	{
		camera_stop_x = false;
		camera_stop_y = false;

		if ((int)local_location.x != 640)
		{
			local_location.x = 640.f;
		}
		if ((int)local_location.y != 360)
		{
			local_location.y = 360.f;
		}
	}
	else
	{
		//制限
		if (location.x <= 0.f) { location.x = 0.f; }
		if (location.x >= 1920.f) { location.x = 1920.f; }
		if (location.y <= 0.f) { location.y = 0.f; }
		if (location.y >= 1080.f) { location.y = 1080.f; }

		if (local_location.x <= 100.f) { local_location.x = 100.f; }
		if (local_location.x >= 1180.f) { local_location.x = 1180.f; }
		if (local_location.y <= 100.f) { local_location.y = 100.f; }
		if (local_location.y >= 620.f) { local_location.y = 620.f; }

		local_location.x += velocity.x;
		local_location.y -= velocity.y;

		if (location.x <= 540.f || location.x >= 1380.f)
		{
			camera_stop_x = true;
		}
		else
		{
			camera_stop_x = false;
			if ((int)local_location.x != 640)
			{
				local_location.x = 640.f;
			}
		}

		if (location.y <= 260.f || location.y >= 820.f)
		{
			camera_stop_y = true;
		}
		else
		{
			camera_stop_y = false;
			if ((int)local_location.y != 360)
			{
				local_location.y = 360.f;
			}
		}
	}
}

bool Player::GetCameraStopX()
{
	return camera_stop_x;
}

bool Player::GetCameraStopY()
{
	return camera_stop_y;
}

float Player::ObjectLength(GameObject* object)
{
	float length = __super::ObjectLength(object);

	if (length < nearest_enemy_length)
	{
		nearest_enemy_length = length;
	}

	return length;
}

