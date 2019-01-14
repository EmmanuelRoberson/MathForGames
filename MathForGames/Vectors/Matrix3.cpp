#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_data_[i][j] = 0.0;
		}
	}
}

Matrix3::Matrix3(Vector3 x_vec, Vector3 y_vec, Vector3 z_vec)
{

	for (int i = 0; i < 3; i++)
		matrix_data_[i][0] = x_vec[i];

	for (int i = 0; i < 3; i++)
		matrix_data_[i][1] = y_vec[i];

	for (int i = 0; i < 3; i++)
		matrix_data_[i][2] = z_vec[i];

}

//𝐶𝑐𝑟 = 𝐴.0𝑟 𝐵.𝑐0 + 𝐴.1𝑟 𝐵.𝑐1 + 𝐴.2𝑟 𝐵.𝑐2
Matrix3 Matrix3::operator*(Matrix3 other) 
{
	Matrix3 result;

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
Vector3 Matrix3::operator*( Vector3 vec)
{
	Vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result[r] = matrix_data_[0][r] * vec[r] +
					matrix_data_[1][r] * vec[r] +
					matrix_data_[2][r] * vec[r];
	}

	return result;
}

Vector3& Matrix3::operator[]( int) 
{
	Vector3 vec3 = Vector3( matrix_data_[0][0],
							matrix_data_[1][0],
							matrix_data_[2][0]);

	return vec3;
}

void Matrix3::setRotateZ(float radians)
{
	auto rotation_x_col = Vector3(cos(radians), sin(radians), 0.0);
	auto rotation_y_col = Vector3(-sin(radians), cos(radians), 0);
	auto rotation_z_col = Vector3(0.0, 0.0, 1.0);

	Matrix3 z_rotation_matrix = Matrix3(rotation_x_col,
										  rotation_y_col,
										  rotation_y_col);

	*this = (*this * z_rotation_matrix);
}

