#pragma once
#include "Vector4.h"

class Matrix4
{

public:

	Matrix4();
	Matrix4(Vector4, Vector4, Vector4, Vector4);

	Matrix4 operator* (Matrix4);
	Vector4 operator* (Vector4);

	Vector4& operator[] (int);

	// rotates this matrix by x, y, or z axis, argument in radians
	void setRotateX(float);
	void setRotateY(float);
	void setRotateZ(float);

private:

	//this represent the the values in the matrix
	float matrix_data_[4][4];

};