#pragma once
#include "Vector3.h"

class matrix_3
{

public:

	matrix_3();
	matrix_3(Vector3, Vector3, Vector3);

	matrix_3 operator* (matrix_3);
	Vector3 operator* (Vector3);

	Vector3& operator[] (int);

	//rotates this matrix by an axis, argument in radians
	void set_rotate_x(float);
	void set_rotate_y(float);
	void set_rotate_z(float);

private:

	//this represent the the values in the matrix
	float matrix_data_[3][3];

};