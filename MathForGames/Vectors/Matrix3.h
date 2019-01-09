#pragma once
#include "Vector3.h"

class matrix_3
{
	


public:

	matrix_3();
	void set(matrix_3);

	matrix_3 operator * (const matrix_3) const;

private:

	// these represent the the values in the matrix
	Vector3 x_col_, y_col_, z_col_;
	Vector3 x_row_, y_row, z_row_;

};