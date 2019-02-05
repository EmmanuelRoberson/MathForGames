#pragma once
#include "Vector3.h"

class Matrix3
{

public:

	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);

	Matrix3(float, float, float,
			float, float, float,
			float, float, float);

	Matrix3 operator* (Matrix3);
	Vector3 operator* (Vector3);

	operator float*();

	Vector3& operator[] (int);

	//rotates this matrix by x, y, z axis
	void setRotateX(float);
	void setRotateY(float);
	void setRotateZ(float);

private:

	//this represent the  values in the matrix
	float matrixData[3][3];

	//identity of this matrix
	float identityMatrixData[3][3];

};