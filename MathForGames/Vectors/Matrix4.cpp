#include "Matrix4.h"
#include "cmath"
#include "Matrix3.h"


matrix_4::matrix_4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix_data_[i][j] = 0.0;
		}
	}
}

matrix_4::matrix_4(vector4 x_vec, vector4 y_vec, vector4 z_vec, vector4 w_vec)
{
	for (int i = 0; i < 4; i++)
		matrix_data_[i][0] = x_vec[i];

	for (int i = 0; i < 4; i++)
		matrix_data_[i][1] = y_vec[i];

	for (int i = 0; i < 4; i++)
		matrix_data_[i][2] = z_vec[i];

	for (int i = 0; i < 4; i++)
		matrix_data_[i][3] = z_vec[i];
}

matrix_4 matrix_4::operator*(matrix_4 other)
{
	matrix_4 result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.matrix_data_[c][r] =
				matrix_data_[0][r] * other.matrix_data_[c][0] +
				matrix_data_[1][r] * other.matrix_data_[c][1] +
				matrix_data_[2][r] * other.matrix_data_[c][2] +
				matrix_data_[3][r] * other.matrix_data_[c][3];

		}
	}

	return result;
}

vector4 matrix_4::operator*(vector4 vec)
{
	vector4 result;

	for (int r = 0; r < 4; r++)
	{
		result[r] = matrix_data_[0][r] * vec[r] +
					matrix_data_[1][r] * vec[r] +
					matrix_data_[2][r] * vec[r] +
					matrix_data_[3][r] * vec[r];
	}

	return result;
}

vector4& matrix_4::operator[](int)
{
	vector4 vec4 = vector4( matrix_data_[0][0],
							matrix_data_[1][0],
							matrix_data_[2][0],
							matrix_data_[3][0]);

	return vec4;
}

void matrix_4::set_rotate_x(float radians)
{
	auto rotation_x_col = vector4(1, 0.0, 0.0, 0.0);
	auto rotation_y_col = vector4(0.0, cos(radians), sin(radians), 0.0);
	auto rotation_z_col = vector4(0.0, -sin(radians), cos(radians), 0.0);
	auto rotation_w_col = vector4(0.0, 0.0, 0.0, 1.0);

	matrix_4 x_rotation_matrix = matrix_4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * x_rotation_matrix);
}

void matrix_4::set_rotate_y(float radians)
{
	auto rotation_x_col = vector4(cos(radians), 0.0, -sin(radians), 0.0);
	auto rotation_y_col = vector4(0.0, 1.0, 0.0, 0.0);
	auto rotation_z_col = vector4(sin(radians), 0.0, cos(radians), 0.0);
	auto rotation_w_col = vector4(0.0, 0.0, 0.0, 1.0);

	matrix_4 y_rotation_matrix = matrix_4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * y_rotation_matrix);
}

void matrix_4::set_rotate_z(float radians)
{
	auto rotation_x_col = vector4(cos(radians), sin(radians), 0.0, 0.0);
	auto rotation_y_col = vector4(-sin(radians), cos(radians), 0.0, 0.0);
	auto rotation_z_col = vector4(0.0, 0.0, 1.0, 0.0);
	auto rotation_w_col = vector4(0.0, 0.0, 0.0, 1.0);

	matrix_4 z_rotation_matrix = matrix_4(rotation_x_col,
										  rotation_y_col,
										  rotation_z_col,
										  rotation_w_col);

	*this = (*this * z_rotation_matrix);
}
