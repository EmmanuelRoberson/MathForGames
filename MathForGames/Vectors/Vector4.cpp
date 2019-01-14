#include "Vector4.h"
#include "cmath"

Vector4::Vector4()
{
	x_pos_, y_pos_, z_pos_, w_pos_ = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	x_pos_ = x;
	y_pos_ = y;
	z_pos_ = z;
	w_pos_ = w;
}

float Vector4::get_x()
{
	return x_pos_;
}

float Vector4::get_y()
{
	return y_pos_;
}

float Vector4::get_z()
{
	return z_pos_;
}

float Vector4::get_w()
{
	return w_pos_;
}

Vector4 Vector4::operator+(Vector4 & rhs)
{
	return Vector4( x_pos_ + rhs.x_pos_,
					y_pos_ + rhs.y_pos_,
					z_pos_ + rhs.z_pos_, 
					w_pos_ + rhs.w_pos_);
}

Vector4 Vector4::operator-(Vector4 & rhs)
{
	return Vector4( x_pos_ - rhs.x_pos_,
					y_pos_ - rhs.y_pos_,
					z_pos_ - rhs.z_pos_, 
					w_pos_ - rhs.w_pos_);
}

Vector4 Vector4::operator*(float& rhs)
{
	x_pos_ *= rhs;
	y_pos_ *= rhs;
	z_pos_ *= rhs;
	w_pos_ *= rhs;

	return *this;
}

bool Vector4::operator==(Vector4& rhs)
{
	return (x_pos_ == rhs.x_pos_ &&
			y_pos_ == rhs.y_pos_ &&
			z_pos_ == rhs.z_pos_ &&
			w_pos_ == rhs.w_pos_);
}

bool Vector4::operator!=(Vector4& rhs)
{
	return (x_pos_ != rhs.x_pos_ ||
			y_pos_ != rhs.y_pos_ ||
			z_pos_ != rhs.z_pos_ ||
			w_pos_ != rhs.w_pos_);
}

float Vector4::magnitude()
{
	return sqrt((x_pos_*x_pos_) + 
				(y_pos_*y_pos_) +
				(z_pos_*z_pos_) + 
				(w_pos_*w_pos_));
}

Vector4 Vector4::normalise()
{
	float mag = magnitude();
	x_pos_ /= mag;
	y_pos_ /= mag;

	return *this;
}

Vector4 Vector4::cross(Vector4 other)
{
	return Vector4( y_pos_ * other.z_pos_ - z_pos_ * other.y_pos_,
					z_pos_ * other.x_pos_ - x_pos_ * other.z_pos_,
					x_pos_ * other.y_pos_ - y_pos_ * other.x_pos_,
					0.0);
}

float Vector4::distance(Vector4 other)
{
	return (*this - other).magnitude();
}

float Vector4::dot(Vector4 other)
{
	return (x_pos_ * other.x_pos_ + 
			y_pos_ * other.y_pos_ +
			z_pos_ * other.z_pos_ +
			w_pos_ * other.w_pos_);
}

float& Vector4::operator[](int index)
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

