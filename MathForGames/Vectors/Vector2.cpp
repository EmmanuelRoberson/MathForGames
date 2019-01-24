#include "Vector2.h"
#include "cmath"

Vector2::Vector2()
{
	x_pos_, y_pos_ = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	x_pos_ = x;
	y_pos_ = y;
}

float Vector2::get_x()
{
	return x_pos_;
}

float Vector2::get_y()
{
	return y_pos_;
}

Vector2 Vector2::operator+(Vector2 & rhs)
{
	return Vector2( x_pos_ + rhs.x_pos_,
					y_pos_ + rhs.y_pos_);
}

Vector2 Vector2::operator-(Vector2 & rhs)
{
	Vector2 temp = Vector2(x_pos_ - rhs.x_pos_, y_pos_ - rhs.y_pos_);
	return temp;
}

Vector2 Vector2::operator*(float& rhs)
{
	x_pos_ *= rhs;
	y_pos_ *= rhs;

	return *this;
}

bool Vector2::operator==(Vector2& rhs)
{
	return (x_pos_ == rhs.x_pos_ && 
			y_pos_ == rhs.y_pos_);
}

bool Vector2::operator!=(Vector2& rhs)
{
	return (x_pos_ != rhs.x_pos_ ||
			y_pos_ != rhs.y_pos_);
}

float Vector2::magnitude()
{
	return sqrt((x_pos_*x_pos_) + (y_pos_*y_pos_));
}

Vector2 Vector2::normalise()
{
	float mag = magnitude();
	x_pos_ /= mag;
	y_pos_ /= mag;

	return *this;
}

float Vector2::distance(Vector2 other)
{
	return (*this - other).magnitude();
}

float Vector2::dot(Vector2 other)
{
	return (x_pos_ * other.x_pos_ + y_pos_ * other.y_pos_);
}

float Vector2::operator[](int index)
{
	switch (index)
	{
	case 0:
		return x_pos_;
	case 1:
		return y_pos_;
	default:
		return 0.0;
	}
}

Vector2::operator float*()
{

	float temp[2] = { x_pos_, y_pos_ };

	return &temp[0];

}
