  
#include <iostream>
#include "Path.h"
#include "Car.h"
using namespace std;



static GLfloat spin = 0.0;
static GLfloat x = 0.0, y = 0.0;
GLint width;
GLint height;
int index;

void init();
void drawOneLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void display();
void move();
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);

Path path1;
Path path2;
Car car1;
Car car2;
int main(int argc, char**argv)
{
	path1.loadPath("path1.txt");
	path1.setColor(Color::BLUE);
	car1.bind(path1);
	car1.setColor(Color::RED);
	path2.loadPath("path2.txt");
	path2.setColor(Color::RED);
	car2.bind(path2);
	car2.setColor(Color::BLUE);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 500);
	glutInitWindowPosition(0, 100);
	glutCreateWindow("Visual Path");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0 , 0.93, 0.0 , 1.0);
	glShadeModel(GL_FLAT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.5, 0.54, 0.53);
	//Horizontal road
	glRectf(-width / 2, -road_width * pixels_per_meter, width / 2, road_width * pixels_per_meter);
	//Vertical road
	glRectf(-road_width * pixels_per_meter, -height / 2, road_width * pixels_per_meter, height / 2);

	//°×É«ÐéÏß
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1.0, 1.0, 1.0);
	GLfloat lw = line_width * pixels_per_meter;
	glLineWidth(lw);
	glLineStipple(4, 0xFFF0);
	GLfloat white_pos = road_width / lane_num * pixels_per_meter;
	//horizontal
	drawOneLine(-width / 2.0, -white_pos, -lane_num * white_pos, - white_pos);
	drawOneLine(width / 2.0, -white_pos, lane_num * white_pos, -white_pos);
	drawOneLine(-width / 2.0, white_pos, -lane_num * white_pos, white_pos);
	drawOneLine(width / 2.0, white_pos, lane_num * white_pos, white_pos);

	//vertical
	drawOneLine(white_pos, lane_num * white_pos, white_pos, height / 2.0);
	drawOneLine(-white_pos, lane_num * white_pos, -white_pos, height / 2.0);
	drawOneLine(white_pos, -lane_num * white_pos, white_pos, -height / 2.0);
	drawOneLine(-white_pos, -lane_num * white_pos, -white_pos, -height / 2.0);

	//Ë«»ÆÏß
	GLfloat yellow_pos = lw;
	glDisable(GL_LINE_STIPPLE);
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(lw);
	//horizontal
	drawOneLine(-width / 2.0, -yellow_pos, -lane_num * white_pos, -yellow_pos);
	drawOneLine(-width / 2.0, yellow_pos, -lane_num * white_pos, yellow_pos);
	drawOneLine(width / 2.0, -yellow_pos, lane_num * white_pos, -yellow_pos);
	drawOneLine(width / 2.0, yellow_pos, lane_num * white_pos, yellow_pos);

	drawOneLine(yellow_pos, lane_num * white_pos, yellow_pos, height / 2.0);
	drawOneLine(-yellow_pos, lane_num * white_pos, -yellow_pos, height / 2.0);
	drawOneLine(yellow_pos, -lane_num * white_pos, yellow_pos, -height / 2.0);
	drawOneLine(-yellow_pos, -lane_num * white_pos, -yellow_pos, -height / 2.0);

	//»­³ö¹ì¼£
	path1.draw();
	path2.draw();
	car1.draw();
	car2.draw();

	glutSwapBuffers();
}

void drawOneLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void move()
{
	if (!car1.end())
		car1.next();
	if (!car2.end())
		car2.next();
	if (car1.end() && car2.end())
	{
		car1.reset();
		car2.reset();
	}
	glutPostRedisplay();
	Sleep(car1.timescale);
}
void reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2.0, w / 2.0, -h / 2.0, h / 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(move);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
		exit(0);
	default:
		break;
	}
}