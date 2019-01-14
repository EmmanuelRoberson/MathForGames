#include "Vector4.h"
#include "cmath"

vector4::vector4()
{
	x_pos_, y_pos_, z_pos_, w_pos_ = 0.0f;
}

vector4::vector4(float x, float y, float z, float w)
{
	x_pos_ = x;
	y_pos_ = y;
	z_pos_ = z;
	w_pos_ = w;
}

float vector4::get_x()
{
	return x_pos_;
}

float vector4::get_y()
{
	return y_pos_;
}

float vector4::get_z()
{
	return z_pos_;
}

float vector4::get_w()
{
	return w_pos_;
}

vector4 vector4::operator+(vector4 & rhs)
{
	return vector4( x_pos_ + rhs.x_pos_,
					y_pos_ + rhs.y_pos_,
					z_pos_ + rhs.z_pos_, 
					w_pos_ + rhs.w_pos_);
}

vector4 vector4::operator-(vector4 & rhs)
{
	return vector4( x_pos_ - rhs.x_pos_,
					y_pos_ - rhs.y_pos_,
					z_pos_ - rhs.z_pos_, 
					w_pos_ - rhs.w_pos_);
}

vector4 vector4::operator*(float& rhs)
{
	x_pos_ *= rhs;
	y_pos_ *= rhs;
	z_pos_ *= rhs;
	w_pos_ *= rhs;

	return *this;
}

bool vector4::operator==(vector4& rhs)
{
	return (x_pos_ == rhs.x_pos_ &&
			y_pos_ == rhs.y_pos_ &&
			z_pos_ == rhs.z_pos_ &&
			w_pos_ == rhs.w_pos_);
}

bool vector4::operator!=(vector4& rhs)
{
	return (x_pos_ != rhs.x_pos_ ||
			y_pos_ != rhs.y_pos_ ||
			z_pos_ != rhs.z_pos_ ||
			w_pos_ != rhs.w_pos_);
}

float vector4::magnitude()
{
	return sqrt((x_pos_*x_pos_) + 
				(y_pos_*y_pos_) +
				(z_pos_*z_pos_) + 
				(w_pos_*w_pos_));
}

vector4 vector4::normalize()
{
	float mag = magnitude();
	x_pos_ /= mag;
	y_pos_ /= mag;

	return *this;
}

float vector4::distance(vector4 other)
{
	return (*this - other).magnitude();
}

float vector4::dot_product(vector4 other)
{
	return (x_pos_ * other.x_pos_ + 
			y_pos_ * other.y_pos_ +
			z_pos_ * other.z_pos_ +
			w_pos_ * other.w_pos_);
}

float& vector4::operator[](int index)
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
	case 3:
		return w_pos_;
	default:
		return zero;
	}
}

