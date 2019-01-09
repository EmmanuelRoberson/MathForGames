#pragma once
#include "Vector3.h"

class matrix_3
{
	
private:

	float data_[3][3];

public:

	matrix_3();
	void set(matrix_3);

	matrix_3 operator * (const matrix_3) const;

};