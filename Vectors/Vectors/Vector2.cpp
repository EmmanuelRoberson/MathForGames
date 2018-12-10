#include "Vector2.h"
#include "cmath"

Vector2::Vector2()
{
	xPos, yPos = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	xPos = x;
	yPos = y;
}

float Vector2::GetX()
{
	return xPos;
}

float Vector2::GetY()
{
	return yPos;
}

Vector2 Vector2::operator+(Vector2 & rhs)
{
	xPos += rhs.xPos;
	yPos += rhs.yPos;

	return *this;
}

Vector2 Vector2::operator-(Vector2 & rhs)
{
	xPos -= rhs.xPos;
	yPos -= rhs.yPos;

	return *this;
}

Vector2 Vector2::operator*(float& rhs)
{
	xPos *= rhs;
	yPos *= rhs;

	return *this;
}

bool Vector2::operator==(Vector2& rhs)
{
	return (xPos == rhs.xPos && 
			yPos == rhs.yPos);
}

bool Vector2::operator!=(Vector2& rhs)
{
	return (xPos != rhs.xPos ||
			yPos != rhs.yPos);
}

float Vector2::Magnitude()
{
	return sqrt((xPos*xPos) + (yPos*yPos));
}

Vector2 Vector2::Normalize()
{
	float mag = Magnitude();
	xPos /= mag;
	yPos /= mag;

	return *this;
}
