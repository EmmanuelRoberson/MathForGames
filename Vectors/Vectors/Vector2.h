#include <iostream>

class Vector2
{
public:

	Vector2();

	//instantiate Vector2 with custom xPos and yPos 
	Vector2(float x, float y);

	float GetX();
	float GetY();

	//addition and subtraction of Vector2s
	Vector2 operator + (Vector2& rhs);
	Vector2 operator - (Vector2& rhs);

	//scaling Vector2s
	Vector2 operator * (float& rhs);

	//comparing Vector2s
	bool operator == (Vector2& rhs);
	bool operator != (Vector2& rhs);

	//returns the magnitude of this Vector2
	float Magnitude();

	//normalizes this Vector2
	Vector2 Normalize();

private:

	//x position and y position
	float xPos;
	float yPos;

};