#include "Matrix4.h"
#include "cmath"

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixData[i][j] = 0.0;
			identityMatrixData[i][j] = 0.0;
		}
	}
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

//Matrix4::Matrix4(int xx, int xy, int xz, int xw, int yx, int yy, int yz, int yw, int zx, int zy, int zz, int zw, int wx, int wy, int wz, int ww)
//{
//	int* iter = &xx;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			matrixData[i][j] = *iter;
//			identityMatrixData[i][j] = *iter++;
//		}
//	}
//}

Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy, float zz, float zw, float wx, float wy, float wz, float ww)
{
	float* iter = &xx;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixData[i][j] = *iter;
			identityMatrixData[i][j] = *iter++;
		}
	}
}

Matrix4 Matrix4::operator*(Matrix4 other)
{
	Matrix4 result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.matrixData[c][r] =
				matrixData[0][r] * other.matrixData[c][0] +
				matrixData[1][r] * other.matrixData[c][1] +
				matrixData[2][r] * other.matrixData[c][2] +
				matrixData[3][r] * other.matrixData[c][3];
		}
	}

	return result;
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

Vector4& Matrix4::operator[](int)
{
	Vector4 vec4 = Vector4( matrixData[0][0],
							matrixData[1][0],
							matrixData[2][0],
							matrixData[3][0]);

	return vec4;
}

Matrix4::operator float*()
{
	return matrixData[0];
}

void Matrix4::setRotateX(float radians)
{
	Matrix4 x_rotation_matrix = Matrix4(1.0f, 0.0, 0.0, 0.0, 0.0, cos(radians), sin(radians), 0.0, 0.0, -sin(radians), cos(radians), 0.0, 0.0, 0.0, 0.0, 1.0);

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
	Matrix4 y_rotation_matrix = Matrix4(cos(radians), 0.0, -sin(radians), 0.0, 0.0, 1.0, 0.0, 0.0, sin(radians), 0.0, cos(radians), 0.0, 0.0, 0.0, 0.0, 1.0);

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
	Matrix4 z_rotation_matrix = Matrix4(cos(radians), sin(radians), 0.0, 0.0, -sin(radians), cos(radians), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);

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
