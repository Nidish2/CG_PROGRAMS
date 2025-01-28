#include <GL/glut.h>
#include <stdio.h>
int polygonType = 0; // 0 for triangle, 1 for rectangle, 2 for pentagon
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system for 
}
void drawTriangle(float x, float y) {
	glColor3f(1.0, 0.0, 0.0); // Set color to red
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + 50, y);
	glVertex2f(x + 25, y + 50);
	glEnd();
}
void drawRectangle(float x, float y) {
	glColor3f(0.0, 1.0, 0.0); // Set color to green
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + 60, y);
	glVertex2f(x + 60, y + 40);
	glVertex2f(x, y + 40);
	glEnd();
}
void drawPentagon(float x, float y) {
	glColor3f(0.0, 0.0, 1.0); // Set color to blue
	glBegin(GL_POLYGON);
	glVertex2f(x + 25, y + 50);
	glVertex2f(x + 50, y + 30);
	glVertex2f(x + 40, y);
	glVertex2f(x + 10, y);
	glVertex2f(x, y + 30);
	glEnd();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float xf = x;
		float yf = 480 - y; // Convert y-coordinate to OpenGL's 
		if (polygonType == 0) {
			drawTriangle(xf, yf);
		}
		else if (polygonType == 1) {
			drawRectangle(xf, yf);
		}
		else if (polygonType == 2) {
			drawPentagon(xf, yf);
		}
		glFlush();
	}
}
void menu(int option) {
	polygonType = option;
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Menu-Driven Polygon Drawing");
	init();
	// Right-click menu
	glutCreateMenu(menu);
	glutAddMenuEntry("Draw Triangle", 0);
	glutAddMenuEntry("Draw Rectangle", 1);
	glutAddMenuEntry("Draw Pentagon", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}