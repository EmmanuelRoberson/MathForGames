#pragma once
#include "Vector4.h"

class Matrix4
{

public:

	// works
	Matrix4();

	//works
	Matrix4(Vector4, Vector4, Vector4, Vector4);

	//works
	Matrix4(float, float, float, float, 
			float, float, float, float, 
			float, float, float, float, 
			float, float, float, float);

	//works
	Matrix4 operator* (Matrix4);

	//works
	Vector4 operator* (Vector4);

	//works
	Vector4& operator[] (int);

	//works
	operator float*();

	// rotates this matrix by x, y, or z axis, argument in radians
	
	//works
	void setRotateX(float);
	
	//works
	void setRotateY(float);
	
	//works
	void setRotateZ(float);



private:

	//this represent the the values in the matrix
	float matrixData[4][4];

	//identity matrix values
	float identityMatrixData[4][4];

};