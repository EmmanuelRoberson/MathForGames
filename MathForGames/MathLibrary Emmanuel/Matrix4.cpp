#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4(
	float xx, float xy, float xz, float xw, 
	float yx, float yy, float yz, float yw,
	float zx, float zy, float zz, float zw, 
	float wx, float wy, float wz, float ww)
{
	float* iter = &xx;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixData[j][i] = *iter;
			identityMatrixData[j][i] = *iter++;
		}
	}
}

void Matrix4::setRotateX(float radians)
{
	Matrix4 x_rotation_matrix = Matrix4(
		1.0f, 0.0, 0.0, 0.0, 
		0.0, cos(radians), sin(radians), 0.0,
		0.0, -sin(radians), cos(radians), 0.0, 
		0.0, 0.0, 0.0, 1.0);

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			matrixData[c][r] =
				identityMatrixData[0][r] * x_rotation_matrix.matrixData[c][0] +
				identityMatrixData[1][r] * x_rotation_matrix.matrixData[c][1] +
				identityMatrixData[2][r] * x_rotation_matrix.matrixData[c][2] +
				identityMatrixData[3][r] * x_rotation_matrix.matrixData[c][3];
		}
	}
}

void Matrix4::setRotateY(float radians)
{
	Matrix4 y_rotation_matrix = Matrix4(
		cos(radians), 0.0, -sin(radians), 0.0, 
		0.0, 1.0, 0.0, 0.0, 
		sin(radians), 0.0, cos(radians), 0.0, 
		0.0, 0.0, 0.0, 1.0);

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			matrixData[c][r] =
				identityMatrixData[0][r] * y_rotation_matrix.matrixData[c][0] +
				identityMatrixData[1][r] * y_rotation_matrix.matrixData[c][1] +
				identityMatrixData[2][r] * y_rotation_matrix.matrixData[c][2] +
				identityMatrixData[3][r] * y_rotation_matrix.matrixData[c][3];
		}
	}
}

void Matrix4::setRotateZ(float radians)
{
	Matrix4 z_rotation_matrix = Matrix4(
		cos(radians), sin(radians), 0.0, 0.0, 
		-sin(radians), cos(radians), 0.0, 0.0, 
		0.0, 0.0, 1.0, 0.0, 
		0.0, 0.0, 0.0, 1.0);

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			matrixData[c][r] =
				identityMatrixData[0][r] * z_rotation_matrix.matrixData[c][0] +
				identityMatrixData[1][r] * z_rotation_matrix.matrixData[c][1] +
				identityMatrixData[2][r] * z_rotation_matrix.matrixData[c][2] +
				identityMatrixData[3][r] * z_rotation_matrix.matrixData[c][3];
		}
	}
}

Matrix4::operator float*()
{
	return matrixData[0];
}

Vector4& Matrix4::operator[](int index)
{
	Vector4 vec4 = Vector4(matrixData[0][index],
		matrixData[1][index],
		matrixData[2][index],
		matrixData[3][index]);

	return vec4;
}

Vector4 Matrix4::operator*(Vector4 vec)
{
	Vector4 result;

	for (int r = 0; r < 4; r++)
	{
		result[r] = matrixData[0][r] * vec[r] +
			matrixData[1][r] * vec[r] +
			matrixData[2][r] * vec[r] +
			matrixData[3][r] * vec[r];
	}

	return result;
}

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixData[j][i] = (i == j) ? 1.0f : 0.0f;
			identityMatrixData[j][i] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

Matrix4 Matrix4::operator*(Matrix4 other)
{
	Matrix4 result;

	float value = 0.0f;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				value += matrixData[i][k] * other.matrixData[k][j];
			}
			result.matrixData[i][j] = value;
			value = 0.0f;
		}
	}

	return result;
}

Matrix4::Matrix4(Vector4 x_vec, Vector4 y_vec, Vector4 z_vec, Vector4 w_vec)
{
	for (int i = 0; i < 4; i++)
	{
		matrixData[i][0] = x_vec[i];
		identityMatrixData[i][0] = x_vec[i];
	}

	for (int i = 0; i < 4; i++)
	{
		matrixData[i][1] = y_vec[i];
		identityMatrixData[i][1] = y_vec[i];
	}

	for (int i = 0; i < 4; i++)
	{
		matrixData[i][2] = z_vec[i];
		identityMatrixData[i][2] = z_vec[i];
	}

	for (int i = 0; i < 4; i++)
	{
		matrixData[i][3] = z_vec[i];
		identityMatrixData[i][3] = z_vec[i];
	}
}

 