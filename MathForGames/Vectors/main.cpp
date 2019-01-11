#include "Matrix3.h"

int main()
{

	Vector3 vect1 = Vector3(1.1, 2.2, 3.3);
	Vector3 vect2 = Vector3(1.1, 2.2, 3.3);
	Vector3 vect3 = Vector3(1.1, 2.2, 3.3);

	matrix_3 mat = matrix_3(vect1, vect2, vect3);
	mat.set_rotate_x(3.14);
}
