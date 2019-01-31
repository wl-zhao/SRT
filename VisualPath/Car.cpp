#include "Car.h"
#include <cmath>
#define PI 3.141592654

void Car::bind(Path & _path)
{
	path = _path;
	timescale = path.timescale;
	calcAngle();
	if (path.size() != 0)
	{
		index = 0;
		set();
	}
}

void Car::calcAngle()
{
	float deltax, deltay, angle;
	angles.clear();
	for (int i = 0; i < path.size() - 1; i++)
	{
		deltax = path[i + 1].x - path[i].x;
		deltay = path[i + 1].y - path[i].y;
		if (deltax == 0)
		{
			if (deltay > 0)
				angle = 90;
			else if (deltay < 0)
				angle = -90;
		}
		else
			angle = atan(deltay / deltax) * 180 / PI;
		angles.push_back(angle);
	}
	angles.push_back(angle);
}

void Car::draw()
{
	//¶¯»­
	glPushMatrix();
	glTranslatef(xp(), yp(), 0);
	glRotatef(angled(), 0.0, 0.0, 1.0);
	glColor3f(color.r(), color.g(), color.b());
	glRectf(-hlp(), -hwp(), hlp(), hwp());
	glPopMatrix();

	glColor3f(1.0 - color.r(), 1.0 - color.g(), 1.0 - color.b());
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(xp(), yp());
	glEnd();
}

void Car::next()
{
	index++;
	set();
}

void Car::reset()
{
	index = 0;
	set();
}

void Car::set()
{
	x = path[index].x;
	y = path[index].y;
	angle = angles[index];
}
