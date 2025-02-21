#include "GameObject.h"
#include"DxLib.h"
#include <math.h>

GameObject::GameObject() : color(0x0), location(0.f), box_size(0.f), local_location(0.f)
{
}

GameObject::~GameObject()
{
}

void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.f);

	location = box_size;
}

void GameObject::Update()
{
	//location.x += 1.f;

	//if (location.x >= 640.f)
	//{
	//	location.x = 0.f;
	//}
}

void GameObject::Draw() const
{
	Vector2D upper_left = local_location - (box_size / 2.f);
	Vector2D lower_right = local_location + (box_size / 2.f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
}

void GameObject::Finalize()
{
}

void GameObject::Movement(Vector2D velocity)
{
	local_location.x -= velocity.x;
	local_location.y += velocity.y;
}

void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

Vector2D GameObject::GetLocation() const
{
	return this->location;
}

Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

float GameObject::ObjectLength(GameObject* object)
{
	float length;
	
	length = powf(powf(local_location.x - object->local_location.x, 2) + powf(local_location.y - object->local_location.y, 2), 0.5);

	return length;
}


