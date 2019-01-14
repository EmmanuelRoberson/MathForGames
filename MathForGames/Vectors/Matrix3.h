#pragma once
#include "vector3.h"

class matrix_3
{

public:

	matrix_3();
	matrix_3(vector3, vector3, vector3);

	matrix_3 operator* (matrix_3);
	vector3 operator* (vector3);

	vector3& operator[] (int);

	//rotates this matrix by z axis, argument in radians
	void set_rotate_z(float);

private:

	//this represent the the values in the matrix
	float matrix_data_[3][3];

};