#pragma once
#include <vector>
using namespace std;

class Color
{
public:
	Color(float r = 0.0, float g = 0.0, float b = 0.0)
	{
		RGB[0] = r;
		RGB[1] = g;
		RGB[2] = b;
	}
	static Color RED;
	static Color BLUE;
	float r() { return RGB[0]; }
	float g() { return RGB[1]; }
	float b() { return RGB[2]; }
private:
	float RGB[3];
};