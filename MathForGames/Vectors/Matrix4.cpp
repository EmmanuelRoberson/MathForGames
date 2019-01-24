#include "Matrix4.h"
#include "cmath"


Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixData[i][j] = 0.0;
		}
	}
}

Matrix4::Matrix4(Vector4 x_vec, Vector4 y_vec, Vector4 z_vec, Vector4 w_vec)
{
	for (int i = 0; i < 4; i++)
		matrixData[i][0] = x_vec[i];

	for (int i = 0; i < 4; i++)
		matrixData[i][1] = y_vec[i];

	for (int i = 0; i < 4; i++)
		matrixData[i][2] = z_vec[i];

	for (int i = 0; i < 4; i++)
		matrixData[i][3] = z_vec[i];
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
	auto rotation_x_col = Vector4(1, 0.0, 0.0, 0.0);
	auto rotation_y_col = Vector4(0.0, cos(radians), sin(radians), 0.0);
	auto rotation_z_col = Vector4(0.0, -sin(radians), cos(radians), 0.0);
	auto rotation_w_col = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 x_rotation_matrix = Matrix4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * x_rotation_matrix);
}

void Matrix4::setRotateY(float radians)
{
	auto rotation_x_col = Vector4(cos(radians), 0.0, -sin(radians), 0.0);
	auto rotation_y_col = Vector4(0.0, 1.0, 0.0, 0.0);
	auto rotation_z_col = Vector4(sin(radians), 0.0, cos(radians), 0.0);
	auto rotation_w_col = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 y_rotation_matrix = Matrix4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * y_rotation_matrix);
}

void Matrix4::setRotateZ(float radians)
{
	auto rotation_x_col = Vector4(cos(radians), sin(radians), 0.0, 0.0);
	auto rotation_y_col = Vector4(-sin(radians), cos(radians), 0.0, 0.0);
	auto rotation_z_col = Vector4(0.0, 0.0, 1.0, 0.0);
	auto rotation_w_col = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 z_rotation_matrix = Matrix4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * z_rotation_matrix);
}
