#include "Matrix3.h"
#define PI 3.14159265

int main()
{
	vector3 vect1 = vector3(1.0, 0.0, 0.0);
	vector3 vect2 = vector3(0.0, 1.0, 0.0);
	vector3 vect3 = vector3(0.0, 0.0, 1.0);

	matrix_3 mat = matrix_3(vect1, vect2, vect3);
	mat.set_rotate_z(PI/2);

	auto matrix_subscript_test = mat[0];
}