#include "Stage.h"
#include "DxLib.h"

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
}

void Stage::Update()
{

}

void Stage::Draw() const
{
	__super::Draw();
	DrawFormatString(local_location.x, local_location.y, 0xff0000, "x%f y%f", local_location.x, local_location.y);
}

void Stage::Finalize()
{

}
