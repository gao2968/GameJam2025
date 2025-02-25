#include "Stage.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	location = Vector2D(STAGE_WIDHT / 2, STAGE_HEIGHT / 2);
	box_size = Vector2D(STAGE_WIDHT, STAGE_HEIGHT);
	local_location = Vector2D(1280 / 2, 720 / 2);
	color = GetColor(255, 255, 255);

	//インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();
	image = rm->GetImages("Resource/Images/stage.png")[0];
	frame = rm->GetImages("Resource/Images/frame.png")[0];
}

void Stage::Update()
{

}

void Stage::Draw() const
{
	DrawBoxAA(0.f, 0.f, 1280.f, 720.f, 0x000000, TRUE);

	__super::Draw();

	Vector2D upper_left = local_location - (box_size / 2.f);
	Vector2D lower_right = local_location + (box_size / 2.f);
	DrawExtendGraphF(upper_left.x, upper_left.y, lower_right.x, lower_right.y, frame, TRUE);

	//DrawFormatString(local_location.x, local_location.y, 0xff0000, "x%f y%f", location.x, location.y);
}

void Stage::Finalize()
{

}
