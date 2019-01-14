#include "Matrix3.h"
#include <cmath>

matrix_3::matrix_3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_data_[i][j] = 0.0;
		}
	}
}

matrix_3::matrix_3(vector3 x_vec, vector3 y_vec, vector3 z_vec)
{

	for (int i = 0; i < 3; i++)
		matrix_data_[i][0] = x_vec[i];

	for (int i = 0; i < 3; i++)
		matrix_data_[i][1] = y_vec[i];

	for (int i = 0; i < 3; i++)
		matrix_data_[i][2] = z_vec[i];

}

//𝐶𝑐𝑟 = 𝐴.0𝑟 𝐵.𝑐0 + 𝐴.1𝑟 𝐵.𝑐1 + 𝐴.2𝑟 𝐵.𝑐2
matrix_3 matrix_3::operator*(matrix_3 other) 
{
	matrix_3 result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.matrix_data_[c][r] =
				matrix_data_[0][r] * other.matrix_data_[c][0] +
				matrix_data_[1][r] * other.matrix_data_[c][1] +
				matrix_data_[2][r] * other.matrix_data_[c][2];
										
		}
	}

	return result;
}

//Cr = M.0r V.r + M.1r V.r + M.2r V.r
vector3 matrix_3::operator*( vector3 vec)
{
	vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result[r] = matrix_data_[0][r] * vec[r] +
					matrix_data_[1][r] * vec[r] +
					matrix_data_[2][r] * vec[r];
	}

	return result;
}

vector3& matrix_3::operator[]( int) 
{
	vector3 vec3 = vector3( matrix_data_[0][0],
							matrix_data_[1][0],
							matrix_data_[2][0]);

	return vec3;
}

void matrix_3::set_rotate_z(float radians)
{
	auto rotation_x_col = vector3(cos(radians), sin(radians), 0.0);
	auto rotation_y_col = vector3(-sin(radians), cos(radians), 0);
	auto rotation_z_col = vector3(0.0, 0.0, 1.0);

	matrix_3 z_rotation_matrix = matrix_3(rotation_x_col,
										  rotation_y_col,
										  rotation_y_col);

	*this = (*this * z_rotation_matrix);
}

