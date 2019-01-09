#include "Matrix3.h"

matrix_3::matrix_3()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			data_[i][j] = 0.0;
		}
	}
}

void matrix_3::set(matrix_3 other)
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}
}

//𝐶𝑐𝑟 = 𝐴.0𝑟 𝐵.𝑐0 + 𝐴.1𝑟 𝐵.𝑐1 + 𝐴.2𝑟 𝐵.𝑐2

matrix_3 matrix_3::operator*(const matrix_3 other) const
{
	matrix_3 result;
	for (int r = 0; r <= 2; r++)
	{
		for (int c = 0; c <= 2; c++)
		{
			result[c][r] = (data_[0][r] * other[c][0] +



		}
	}
}