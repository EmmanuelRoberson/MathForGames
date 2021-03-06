﻿#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixData[i][j] = 0.0;
			identityMatrixData[i][j] = 0.0;
		}
	}
}

Matrix3::Matrix3(Vector3 x_vec, Vector3 y_vec, Vector3 z_vec)
{

	for (int i = 0; i < 3; i++)
	{
		matrixData[i][0] = x_vec[i];
		identityMatrixData[i][0] = x_vec[i];
	}

	for (int i = 0; i < 3; i++)
	{
		matrixData[i][1] = y_vec[i];
		identityMatrixData[i][0] = y_vec[i];
	}

	for (int i = 0; i < 3; i++)
	{
		matrixData[i][2] = z_vec[i];
		identityMatrixData[i][0] = z_vec[i];
	}

}

//Matrix3::Matrix3(int xx, int xy, int xz, int yx, int yy, int yz, int zx, int zy, int zz)
//{
//	int* iter = &xx;
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			matrixData[i][j] = *iter;
//			identityMatrixData[i][j] = *iter++;
//		}
//	}
//}

Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz)
{
	float* iter = &xx;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixData[i][j] = *iter;
			identityMatrixData[i][j] = *iter++;
		}
	}
}

//𝐶𝑐𝑟 = 𝐴.0𝑟 𝐵.𝑐0 + 𝐴.1𝑟 𝐵.𝑐1 + 𝐴.2𝑟 𝐵.𝑐2
Matrix3 Matrix3::operator*(Matrix3 other) 
{
	Matrix3 result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.matrixData[c][r] =
				matrixData[0][r] * other.matrixData[c][0] +
				matrixData[1][r] * other.matrixData[c][1] +
				matrixData[2][r] * other.matrixData[c][2];
										
		}
	}

	return result;
}

//Cr = M.0r V.r + M.1r V.r + M.2r V.r
Vector3 Matrix3::operator*( Vector3 vec)
{
	Vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result[r] = matrixData[0][r] * vec[r] +
					matrixData[1][r] * vec[r] +
					matrixData[2][r] * vec[r];
	}

	return result;
}

Matrix3::operator float*()
{
	return matrixData[0];
}

Vector3& Matrix3::operator[]( int) 
{
	Vector3 vec3 = Vector3( matrixData[0][0],
							matrixData[1][0],
							matrixData[2][0]);

	return vec3;
}

void Matrix3::setRotateX(float radians)
{
	Matrix3 x_rotation_matrix = Matrix3(cos(radians), sin(radians), 0.0, -sin(radians), cos(radians), 0.0, 0.0, 0.0, 1.0);

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			matrixData[c][r] =
				identityMatrixData[0][r] * x_rotation_matrix.matrixData[c][0] +
				identityMatrixData[1][r] * x_rotation_matrix.matrixData[c][1] +
				identityMatrixData[2][r] * x_rotation_matrix.matrixData[c][2];
		}
	}
}

void Matrix3::setRotateY(float radians)
{
	Matrix3 y_rotation_matrix = Matrix3(cos(radians), 0.0, -sin(radians), 0.0, 1.0, 0.0, sin(0), 0.0, cos(radians));

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			matrixData[c][r] =
				identityMatrixData[0][r] * y_rotation_matrix.matrixData[c][0] +
				identityMatrixData[1][r] * y_rotation_matrix.matrixData[c][1] +
				identityMatrixData[2][r] * y_rotation_matrix.matrixData[c][2];
		}
	}
}

void Matrix3::setRotateZ(float radians)
{
	Matrix3 z_rotation_matrix = Matrix3(1.0, 0.0, 0.0, 0.0, cos(radians), sin(radians), 0.0, -sin(radians), cos(radians));
	
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			matrixData[c][r] =
			identityMatrixData[0][r] * z_rotation_matrix.matrixData[c][0] +
			identityMatrixData[1][r] * z_rotation_matrix.matrixData[c][1] +
			identityMatrixData[2][r] * z_rotation_matrix.matrixData[c][2];
		}
	}
}

