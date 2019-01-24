#pragma once
#include "Vector3.h"

class Matrix3
{

public:

	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);

	Matrix3 operator* (Matrix3);
	Vector3 operator* (Vector3);

	operator float*();

	Vector3& operator[] (int);

	//rotates this matrix by z axis, argument in radians
	void setRotateZ(float);

private:

	//this represent the the values in the matrix
	float matrixData[3][3];

};