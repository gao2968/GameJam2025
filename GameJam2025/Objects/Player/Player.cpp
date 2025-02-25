#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

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

	oval_radius = Vector2D(32.f);

	oval_flg = true;

	speed = 1.f;

	ResourceManager* rm = ResourceManager::GetInstance();
	cursor = rm->GetImages("Resource/Images/cursor.png")[0];

	cursor_se[0] = rm->GetSounds("Resource/SE/Teki_search_1.mp3");
	cursor_se[1] = rm->GetSounds("Resource/SE/Teki_search_2.mp3");
	cursor_se[2] = rm->GetSounds("Resource/SE/Teki_search_3.mp3");

	ChangeVolumeSoundMem(160, cursor_se[2]);
}

void Player::Update()
{
	//色の変化
	int r, g, b;
	float step = (nearest_enemy_length - 50.0) / (300.0 - 50.0);
	if (step > 1.f)
	{
		step = 1.f;
	}
	if (step < 0)
	{
		step = 0.f;
	}
	r = static_cast<int>(255 * (1 - step));
	g = static_cast<int>(255 * step);
	b = 0;
	color = GetColor(r, g, b);
	speed = (1 - step) * 5.f + 1.f;

	if (oval_flg)
	{
		oval_radius.x -= speed;
		if (oval_radius.x < 0)
		{
			oval_flg = !oval_flg;
		}
	}
	else
	{
		oval_radius.x += speed;
		if (oval_radius.x > 32)
		{
			oval_flg = !oval_flg;
		}
	}

	if (nearest_enemy_length >= 200.f)
	{
		if (!CheckSoundMem(cursor_se[0]))
		{
			PlaySoundMem(cursor_se[0], DX_PLAYTYPE_BACK, TRUE);
		}
	}
	else if (nearest_enemy_length < 100.f)
	{
		if (!CheckSoundMem(cursor_se[2])) 
		{
			PlaySoundMem(cursor_se[2], DX_PLAYTYPE_BACK, TRUE);
		}
	}
	else if (nearest_enemy_length < 200.f)
	{
		if (!CheckSoundMem(cursor_se[1]))
		{
			PlaySoundMem(cursor_se[1], DX_PLAYTYPE_BACK, TRUE);
		}
	}
	
}

void Player::Draw() const
{
	__super::Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawOvalAA(local_location.x, local_location.y, oval_radius.x, oval_radius.y, 32, color, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	
	DrawRotaGraph(local_location.x + 5, local_location.y + 12, 0.2, 0.0, cursor, TRUE);

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

