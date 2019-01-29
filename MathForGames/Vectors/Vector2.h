#pragma once

class Vector2
{
public:

	//default constructor that sets all values to 0.0
	Vector2();

	//custom constructor that sets x, y values
	Vector2(float x, float y);

	// returns the x or y values
	float get_x();
	float get_y();

	//addition and subtraction of Vector2s
	Vector2 operator + (Vector2& rhs);
	Vector2 operator - (Vector2& rhs);

	//scaling Vector2s
	Vector2 operator * (float rhs);
	
	//comparing Vector2s
	bool operator == (Vector2& rhs);
	bool operator != (Vector2& rhs);

	//returns the magnitude of this Vector2
	float magnitude();

	//normalizes this Vector2
	Vector2 normalise();

	//distance between two points
	float distance(Vector2 other);

	//dot product
	float dot(Vector2 other);

	//index of the vector, where the first value is at index 0
	float operator [](int index);

	// casting the vector as a float pointer
	operator float* ();

private:

	//x position and y position
	float x_pos_;
	float y_pos_;

};

Vector2 operator * (float, Vector2);