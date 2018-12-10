#include "Vector3.h"

Vector3::Vector3()
{
	xPos, yPos, zPos = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}

float Vector3::GetX()
{
	return xPos;
}

float Vector3::GetY()
{
	return yPos;
}

float Vector3::GetZ()
{
	return zPos;
}

Vector3 Vector3::operator+(Vector3& rhs)
{
	xPos += rhs.xPos;
	yPos += rhs.yPos;
	zPos += rhs.zPos;

	return *this;
}

Vector3 Vector3::operator-(Vector3& rhs)
{
	xPos -= rhs.xPos;
	yPos -= rhs.yPos;
	zPos -= rhs.zPos;

	return *this;
}

Vector3 Vector3::operator*(float& rhs)
{
	xPos *= rhs;
	yPos *= rhs;
	zPos *= rhs;

	return *this;
}

bool Vector3::operator==(Vector3& rhs)
{
	return (xPos == rhs.xPos &&
			yPos == rhs.yPos &&
			zPos == rhs.zPos);
}

bool Vector3::operator!=(Vector3& rhs)
{
	return (xPos != rhs.xPos ||
			yPos != rhs.yPos ||
			zPos != rhs.zPos);
}