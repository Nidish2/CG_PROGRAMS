#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
	glColor3f(1.0, 0.0, 0.0);           // Set line color to red
	glPointSize(2.0);                   // Set point size
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system
}

void ddaLine(int x0, int y0, int x1, int y1) {
	int dx = x1 - x0;
	int dy = y1 - y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Determine the

	float xIncrement = dx / (float)steps; // Calculate the increment in
	float yIncrement = dy / (float)steps;

	float x = x0;
	float y = y0;

	glBegin(GL_POINTS);
	for (int i = 0; i <= steps; i++) {
		glVertex2i((int)x, (int)y); // Plot the point
		x += xIncrement;            // Update x and y
		y += yIncrement;
	}
	glEnd();
	glFlush();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);    // Clear the display
	ddaLine(100, 100, 500, 400);     // Draw line from (100, 100)
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA Line Drawing Algorithm in C");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}