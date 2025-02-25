#include "Vector2D.h"
#include "UserTemplate.h"
#include <cmath> 

Vector2D::Vector2D() : x(0.f), y(0.f)
{
}

Vector2D::Vector2D(float scalar) : x(scalar), y(scalar)
{
}

Vector2D::Vector2D(float mx, float my) : x(mx), y(my)
{
}

Vector2D::~Vector2D()
{
}

Vector2D& Vector2D::operator=(const Vector2D& location)
{
	this->x = location.x;
	this->y = location.y;

	return *this;
}

const Vector2D Vector2D::operator+(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;
}

const Vector2D Vector2D::operator-(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.f);

	result.x = this->x - location.x;
	result.y = this->y - location.y;

	return result;
}

Vector2D& Vector2D::operator-=(const Vector2D& location)
{
	this->x -= location.x;
	this->y -= location.y;

	return *this;
}

const Vector2D Vector2D::operator*(const float& scalar) const
{
	Vector2D result = Vector2D(0.f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}

const Vector2D Vector2D::operator*(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}

Vector2D& Vector2D::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x *= location.x;
	this->y *= location.y;

	return *this;
}

const Vector2D Vector2D::operator/(const float& scalar) const
{
	if (Abs(scalar) < 1e-6f)
	{
		return Vector2D(0.f);
	}

	return Vector2D(this->x / scalar, this->y / scalar);
}

const Vector2D Vector2D::operator/(const Vector2D& location) const
{
	if ((Abs(location.x) < 1e-6f) || (Abs(location.y) < 1e-6f))
	{
		return Vector2D(0.f);
	}
	return Vector2D(this->x / location.x, this->y / location.y);
}

Vector2D& Vector2D::operator/=(const float& scalar)
{
	if (Abs(scalar) < 1e-6f)
	{
		this->x = 0.f;
		this->y = 0.f;
	}
	else 
	{
		this->x /= scalar;
		this->y /= scalar;
	}
	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	if ((Abs(location.x) < 1e-6f) || (Abs(location.y) < 1e-6f))
	{
		this->x = 0.f;
		this->y = 0.f;
	}
	else
	{
		this->x /= location.x;
		this->y /= location.y;
	}
	return *this;
}

void Vector2D::ToInt(int* x, int* y) const
{
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}

float Vector2D::length() const
{
	return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalized() const
{
	float len = length();
	if (len > 0.00001f) {
		return Vector2D(x / len, y / len);
	}
	return Vector2D(0, 0);
}
