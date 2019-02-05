#pragma once

class Vector3
{
public:

	//default constructor that sets all values to 0.0
	Vector3();

	//custom constructor that sets x, y, z
	Vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float GetZ();

	// addition and subtraction of vector3s
	Vector3 operator + (Vector3& rhs);
	Vector3 operator - (Vector3& rhs);

	//scaling vector3s
	Vector3 operator * (float rhs);

	// comparison operations for vector3s
	bool operator == (Vector3& rhs);
	bool operator != (Vector3& rhs);

	//returns the magnitude of this Vector3
	float magnitude();

	//normalizes this Vector3
	Vector3 normalise();

	//Distance between two points
	float distance(Vector3 other);

	//dot product
	float dot(Vector3 other);

	//cross product
	Vector3 cross(Vector3 other);

	//index of the vector, where the first value is at index 0
	float& operator[] (int index);

	// overloaded casting as a float*
	operator float* ();

private:

	//x position, y position, and z position
	float x_pos_;
	float y_pos_;
	float z_pos_;

};

Vector3 operator * (float, Vector3);
