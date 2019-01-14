#pragma once

class vector3
{
public:

	//default constructor that sets all values to 0.0
	vector3();

	//custom constructor that sets x, y, z
	vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float GetZ();

	// addition and subtraction of vector3s
	vector3 operator + (vector3& rhs);
	vector3 operator - (vector3& rhs);

	//scaling vector3s
	vector3 operator * (float& rhs);

	// comparison operations for vector3s
	bool operator == (vector3& rhs);
	bool operator != (vector3& rhs);

	//returns the magnitude of this vector3
	float magnitude();

	//normalizes this vector3
	vector3 normalize();

	//Distance between two points
	float distance(vector3 other);

	//dot product
	float dot_product(vector3 other);

	//cross product
	vector3 cross_product(vector3 other);

	//index of the vector, where the first value is at index 0
	float& operator[] (int index);

private:

	//x position, y position, and z position
	float x_pos_;
	float y_pos_;
	float z_pos_;

};
