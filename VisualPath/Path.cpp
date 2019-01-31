#include "Path.h"
#include "global.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void Path::loadPath(const char * filename)
{
	ifstream fin;
	fin.open(filename);
	string s;
	float x, y;
	fin >> s;
	if (s == "timescale")
		fin >> timescale;
	else
	{
		cout << "Format Error" << endl;
		return;
	}
	while (!fin.eof()) {
		getline(fin, s);
		if (s.size() == 0)
		{
			continue;
		}
		istringstream is(s);
		is >> x >> y;
		p.push_back(Point(x, y));
	}
	fin.close();
}

void Path::draw()
{
	glColor3f(color.r(), color.g(), color.b());
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < size(); i++)
		glVertex2f((*this)[i].x * pixels_per_meter, (*this)[i].y * pixels_per_meter);
	glEnd();
}
