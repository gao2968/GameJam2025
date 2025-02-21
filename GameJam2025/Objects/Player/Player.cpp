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
	//Movement();
}

void Player::Draw() const
{
	__super::Draw();

	DrawFormatString(local_location.x, local_location.y, 0x0000ff, "x%f y%f", location.x, location.y);

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
	//if (location.x >= 540.f && location.y >= 260.f &&
	//	location.x <= 1820.f && location.y <= 980.f)
	//{
	//	/*location.x += velocity.x;
	//	location.y -= velocity.y;*/
	//	camera_stop_x = false;
	//	camera_stop_y = false;
	//}
	//else
	//{
	//	if (location.x <= 540.f || location.x >= 1820.f)
	//	{
	//		camera_stop_x = true;
	//	}
	//	if (location.y <= 260.f || location.y >= 980.f)
	//	{
	//		camera_stop_y = true;
	//	}

	//	//制限
	//	if (location.x <= 0.f)
	//	{
	//		location.x = 0.f;
	//	}
	//	if (location.x >= 1920.f)
	//	{
	//		location.x = 1920.f;
	//	}
	//	if (location.y <= 0.f)
	//	{
	//		location.y = 0.f;
	//	}
	//	if (location.y >= 1080.f)
	//	{
	//		location.y = 1080.f;
	//	}

	//	local_location.x += velocity.x;
	//	local_location.y -= velocity.y;
	//}
}

bool Player::GetCameraStopX()
{
	return camera_stop_x;
}

bool Player::GetCameraStopY()
{
	return camera_stop_y;
}
