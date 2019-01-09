#pragma once

class vector4
{
public:

	//default constructor that sets all values to 0.0
	vector4();

	//custom constructor that sets x, y, z, w in the argument
	vector4(float x, float y, float z, float w);

	// returns the x, y, z, or w values
	float get_x();
	float get_y();
	float get_z();
	float get_w();

	// addition and subtraction of vector4s
	vector4 operator + (vector4& rhs);
	vector4 operator - (vector4& rhs);

	//scaling vector4s
	vector4 operator * (float& rhs);

	// inequality and equality operator for vector4s
	bool operator == (vector4& rhs);
	bool operator != (vector4& rhs);

	//returns the magnitude of this vector2
	float magnitude();

	//normalizes this vector2
	vector4 normalize();

	//distance between this and the argument vector4
	float distance(vector4 other);

	//returns dot product of this and the argument vector4
	float dot_product(vector4 other);

	//index of the vector, where the first value is at index 0
	float operator[] (int index);

	//index of the vector, where first value is at index 0
	/*float* operator[] (int index);*/

private:

	//    x       y       z       w       positions
	float x_pos_, y_pos_, z_pos_, w_pos_;

};