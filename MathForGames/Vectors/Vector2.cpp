#include "Vector2.h"
#include "cmath"

vector2::vector2()
{
	x_pos_, y_pos_ = 0.0f;
}

vector2::vector2(float x, float y)
{
	x_pos_ = x;
	y_pos_ = y;
}

float vector2::get_x()
{
	return x_pos_;
}

float vector2::get_y()
{
	return y_pos_;
}

vector2 vector2::operator+(vector2 & rhs)
{
	vector2 temp = vector2(x_pos_ + rhs.x_pos_, y_pos_ + rhs.y_pos_);
	return temp;
}

vector2 vector2::operator-(vector2 & rhs)
{
	vector2 temp = vector2(x_pos_ - rhs.x_pos_, y_pos_ - rhs.y_pos_);
	return temp;
}

vector2 vector2::operator*(float& rhs)
{
	x_pos_ *= rhs;
	y_pos_ *= rhs;

	return *this;
}

bool vector2::operator==(vector2& rhs)
{
	return (x_pos_ == rhs.x_pos_ && 
			y_pos_ == rhs.y_pos_);
}

bool vector2::operator!=(vector2& rhs)
{
	return (x_pos_ != rhs.x_pos_ ||
			y_pos_ != rhs.y_pos_);
}

float vector2::magnitude()
{
	return sqrt((x_pos_*x_pos_) + (y_pos_*y_pos_));
}

vector2 vector2::normalize()
{
	float mag = magnitude();
	x_pos_ /= mag;
	y_pos_ /= mag;

	return *this;
}

float vector2::distance(vector2 other)
{
	return (*this - other).magnitude();
}

float vector2::dot_product(vector2 other)
{
	return (x_pos_ * other.x_pos_ + y_pos_ * other.y_pos_);
}

float vector2::operator[](int index)
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
