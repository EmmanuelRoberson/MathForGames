#include <iostream>

class vector2
{
public:

	//default constructor that sets all values to 0.0
	vector2();

	//custom constructor that sets x, y in the argument
	vector2(float x, float y);

	// returns the x or y values
	float get_x();
	float get_y();

	//addition and subtraction of Vector2s
	vector2 operator + (vector2& rhs);
	vector2 operator - (vector2& rhs);

	//scaling Vector2s
	vector2 operator * (float& rhs);

	//comparing Vector2s
	bool operator == (vector2& rhs);
	bool operator != (vector2& rhs);

	//returns the magnitude of this Vector2
	float magnitude();

	//normalizes this Vector2
	vector2 normalize();

	//distance between two points
	float distance(vector2 other);

	//dot product
	float dot_product(vector2 other);

	//index of the vector, where the first value is at index 0
	float operator [](int index);

private:

	//x position and y position
	float x_pos_;
	float y_pos_;

};