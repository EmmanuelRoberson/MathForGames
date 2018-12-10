#include "Vector2.h"
#include "Vector3.h"

int main()
{
	float five = 5.0f;
	Vector2 test_vec2_1 = Vector2(6, 9);
	test_vec2_1.GetX();
	test_vec2_1.GetY();

	test_vec2_1.Normalize();

	Vector3 test_vec3_1 = Vector3(1.0, 1.0, 1.0);
	test_vec3_1.Normalize();
}