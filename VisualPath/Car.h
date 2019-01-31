#pragma once
#include "Color.h"
#include "global.h"
#include "Path.h"
using namespace std;

class Car
{
public:
	Car(float _width = 1.65, float _length = 4.2, Color _color = Color::RED) : width(_width), length(_length), color(_color)
	{

	}
	void setColor(const Color &c) 
	{ color = c; }

	//in pixel
	float wp() { return width * pixels_per_meter; }
	float lp() { return length * pixels_per_meter; }
	float xp() { return x * pixels_per_meter; }
	float yp() { return y * pixels_per_meter; }
	float hwp() { return width * pixels_per_meter/ 2.0; }
	float hlp() { return length * pixels_per_meter/ 2.0; }
	float angled() { return angle; }

	//in meter
	float wm() { return width; }
	float lm() { return length; }

	void bind(Path & _path);
	void calcAngle();
	void draw();
	void next();
	void reset();
	bool end() { return index == path.size() - 1; }
	int index;
	Color color;
	float timescale;
private:
	void set();

	float width;
	float length;
	//中心位置坐标
	float x;
	float y;
	//方向角(deg)
	float angle;

	vector<float> angles;
	Path path;
};
