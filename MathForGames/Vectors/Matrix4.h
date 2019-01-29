#pragma once
#include "Vector4.h"

class Matrix4
{

public:

	Matrix4();
	Matrix4(Vector4, Vector4, Vector4, Vector4);

	Matrix4(float, float, float, float, 
			float, float, float, float, 
			float, float, float, float, 
			float, float, float, float);

	Matrix4 operator* (Matrix4);
	Vector4 operator* (Vector4);

	Vector4& operator[] (int);
	
	operator float*();

	// rotates this matrix by x, y, or z axis, argument in radians
	void setRotateX(float);
	void setRotateY(float);
	void setRotateZ(float);

private:

	//this represent the the values in the matrix
	float matrixData[4][4];

	//identity matrix values
	float identityMatrixData[4][4];

};