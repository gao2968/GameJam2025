//#include "Player.h"
//#include "../../Utility/InputControl.h"
//#include "../../Utility/UserTemplate.h"
//#include "DxLib.h"
//
//Player::Player() : velocity(0.f)
//{
//}
//
//Player::~Player()
//{
//}
//
//void Player::Initialize()
//{
//	color = GetColor(255, 255, 255);
//
//	box_size = Vector2D(32.f);
//
//	location = Vector2D(320.f, 240.f);
//}
//
//void Player::Update()
//{
//	Movement();
//}
//
//void Player::Draw() const
//{
//	__super::Draw();
//}
//
//void Player::Finalize()
//{
//}
//
//void Player::Movement()
//{
//	float direction = 0.f;
//	if (InputControl::GetKey(KEY_INPUT_LEFT))
//	{
//		direction = -1.f;
//	}
//	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
//	{
//		direction = 1.f;
//	}
//
//	if (direction != 0.0f)
//	{
//		float max_speed = Abs<float>((5.f * 5.f * direction));
//		velocity.x += 0.5 * direction;
//		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
//	}
//	else
//	{
//		if (velocity.x < -1e-6f)
//		{
//			float calc_speed = velocity.x + 0.1f;
//			velocity.x = Min<float>(calc_speed, 0.f);
//		}
//		else if (1e-6f < velocity.x)
//		{
//			float calc_speed = velocity.x - 0.1f;
//			velocity.x = Max<float>(calc_speed, 0.f);
//		}
//	}
//
//	if (location.x < (box_size.x / 2.f))
//	{
//		velocity.x = 0.f;
//		location.x = box_size.x / 2.f;
//	}
//	else if ((640.f - (box_size.x / 2.f)) < location.x)
//	{
//		velocity.x = 0.f;
//		location.x = 640.f - (box_size.x / 2.f);
//	}
//
//	location += velocity;
//}
