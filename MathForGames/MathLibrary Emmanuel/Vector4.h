#pragma once
class Vector4
{
public:

	//default constructor that sets all values to 0.0
	Vector4();

	//custom constructor that sets x, y, z, w
	Vector4(float x, float y, float z, float w);

	// returns the x, y, z, or w values
	float get_x();
	float get_y();
	float get_z();
	float get_w();

	// addition and subtraction of vector4s
	Vector4 operator + (Vector4& rhs);
	Vector4 operator - (Vector4& rhs);

	//scaling vector4s
	Vector4 operator * (float rhs);

	// comparison operations for vector4s
	bool operator == (Vector4& rhs);
	bool operator != (Vector4& rhs);

	//returns the magnitude of this Vector4
	float magnitude();

	//normalizes this Vector4
	Vector4 normalise();

	//cross product
	Vector4 cross(Vector4 other);

	//distance between this and the argument Vector4
	float distance(Vector4 other);

	//returns dot product of this and the argument Vector4
	float dot(Vector4 other);

	//index of the vector, where the first value is at index 0
	float& operator[] (int index);

	//overloaded casting operator as a float*
	operator float* ();

private:

	//    x       y       z       w       positions
	float x_pos_, y_pos_, z_pos_, w_pos_;

};

Vector4 operator * (float, Vector4);