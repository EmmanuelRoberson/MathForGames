#include "Vector3.h"
#include <cmath>

vector3::vector3()
{
	x_pos_, y_pos_, z_pos_ = 0.0f;
}

vector3::vector3(float x, float y, float z)
{
	x_pos_ = x;
	y_pos_ = y;
	z_pos_ = z;
}

float vector3::GetX()
{
	return x_pos_;
}

float vector3::GetY()
{
	return y_pos_;
}

float vector3::GetZ()
{
	return z_pos_;
}

vector3 vector3::operator+(vector3& rhs)
{
	return vector3( x_pos_ += rhs.x_pos_,
					y_pos_ += rhs.y_pos_,
					z_pos_ += rhs.z_pos_);
}

vector3 vector3::operator-(vector3& rhs)
{
	return vector3( x_pos_ -= rhs.x_pos_,
					y_pos_ -= rhs.y_pos_,
					z_pos_ -= rhs.z_pos_);
}

vector3 vector3::operator*(float& rhs)
{
	x_pos_ *= rhs;
	y_pos_ *= rhs;
	z_pos_ *= rhs;

	return *this;
}

bool vector3::operator==(vector3& rhs)
{
	return (x_pos_ == rhs.x_pos_ &&
			y_pos_ == rhs.y_pos_ &&
			z_pos_ == rhs.z_pos_);
}

bool vector3::operator!=(vector3& rhs)
{
	return (x_pos_ != rhs.x_pos_ ||
			y_pos_ != rhs.y_pos_ ||
			z_pos_ != rhs.z_pos_);
}

float vector3::magnitude()
{
	return sqrt((x_pos_*x_pos_) + 
				(y_pos_*y_pos_) + 
				(z_pos_*z_pos_));
}

vector3 vector3::normalize()
{
	float mag = magnitude();
	x_pos_ /= mag;
	y_pos_ /= mag;
	z_pos_ /= mag;

	return *this;
}

float vector3::distance(vector3 other)
{
	return (*this - other).magnitude();
}

float vector3::dot_product(vector3 other)
{
	return (x_pos_ * other.x_pos_ + 
			y_pos_ * other.y_pos_ + 
			z_pos_ * other.z_pos_);
}

vector3 vector3::cross_product(vector3 other)
{
	return vector3(y_pos_ * other.z_pos_ - z_pos_ * other.y_pos_,
				   z_pos_ * other.x_pos_ - x_pos_ * other.z_pos_,
				   x_pos_ * other.y_pos_ - y_pos_ * other.x_pos_);
}

float& vector3::operator[](int index)
{
	//this is in case an index is passed in that is beyond the number vectors indexes
	float zero = 0.0;

	switch (index)
	{
	case 0:
		return x_pos_;
	case 1:
		return y_pos_;
	case 2:
		return z_pos_;
	default:
		return zero;
	}
}
