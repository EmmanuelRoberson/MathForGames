#pragma once
#include "Vector4.h" 

class lolmat
{

public:
	lolmat(
		float xx, float xy, float xz, float xw,
		float yx, float yy, float yz, float yw,
		float zx, float zy, float zz, float zw,
		float wx, float wy, float wz, float ww);


	void setRotateX(float);
	void setRotateY(float);
	void setRotateZ(float);

	operator float*();

	Vector4& operator[] (int);

	Vector4 operator* (Vector4);

	lolmat();

	lolmat operator* (lolmat);

	lolmat(Vector4, Vector4, Vector4, Vector4);

private:
	//this represent the the values in the matrix
	float matrixData[4][4];

	//identity matrix values
	float identityMatrixData[4][4];
};
