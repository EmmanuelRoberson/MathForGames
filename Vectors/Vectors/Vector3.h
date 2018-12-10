#include <iostream>

class Vector3
{
public:

	Vector3();

	//instantiate Vector3 with custom xPos and yPos 
	Vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float GetZ();

	//addition and subtraction of Vector3s
	Vector3 operator + (Vector3& rhs);
	Vector3 operator - (Vector3& rhs);

	//scaling Vector3s
	Vector3 operator * (float& rhs);

	//comparing Vector3s
	bool operator == (Vector3& rhs);
	bool operator != (Vector3& rhs);

private:

	//x position, y position, and z position
	float xPos;
	float yPos;
	float zPos;

};