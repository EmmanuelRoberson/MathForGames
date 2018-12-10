#include "Vector2.h"
#include "Vector3.h"

int main()
{
	float five = 5.0f;

	Vector2 test_vec2_1 = Vector2(6, 9);
	Vector2 test_vec2_2 = Vector2(1, 9);
	test_vec2_1.GetX();
	test_vec2_1.GetY();

	Vector3 test_vec3_1 = Vector3(1.0, 1.0, 1.0);
	Vector3 test_vec3_2 = Vector3(1.0, 1.0, 10);

	float distance = test_vec2_1.Distance(test_vec2_2);
	float distance2 = test_vec3_1.Distance(test_vec3_2);
}