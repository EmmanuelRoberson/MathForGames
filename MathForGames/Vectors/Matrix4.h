#pragma once
#include "Vector4.h"

class matrix_4
{

public:

	matrix_4();
	matrix_4(vector4, vector4, vector4, vector4);

	matrix_4 operator* (matrix_4);
	vector4 operator* (vector4);

	vector4& operator[] (int);

	// rotates this matrix by x, y, or z axis, argument in radians
	void set_rotate_x(float);
	void set_rotate_y(float);
	void set_rotate_z(float);

private:

	//this represent the the values in the matrix
	float matrix_data_[4][4];

};