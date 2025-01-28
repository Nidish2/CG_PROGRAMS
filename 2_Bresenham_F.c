#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
	glColor3f(1.0, 0.0, 0.0);           // Set line color to white
	glPointSize(2.0);                   // Set point size
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system for
}

void bresenhamLine(int x0, int y0, int x1, int y1) {
	int x = x0, y = y0;
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int p = 2 * dy - dx;

	glBegin(GL_POINTS);

	while (x <= x1) {
		x++;
		if (p < 0)
			p += 2 * dy;
		else {
			p += 2 * dy - 2 * dx;
			y++;
		}
		glVertex2i(x, y);
	}

	glEnd();
	glFlush();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the display
	bresenhamLine(100, 100, 400, 400);        // Draw a line with user input
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Line Drawing Algorithm ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}