#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
double xmin = 50, ymin = 50, xmax = 100, ymax = 100; // Clipping window coordinates
double xvmin = 200, yvmin = 200, xvmax = 300, yvmax = 300; // Viewport coordinates
const int RIGHT = 8, LEFT = 2, TOP = 4, BOTTOM = 1;
// Function to compute outcode
int ComputeOutCode(double x, double y) {
	int code = 0;
	if (y > ymax) code |= TOP;
	else if (y < ymin) code |= BOTTOM;
	if (x > xmax) code |= RIGHT;
	else if (x < xmin) code |= LEFT;
	return code;
}
// Cohen-Sutherland Line Clipping
void CohenSutherland(double x0, double y0, double x1, double y1) {
	int outcode0, outcode1, outcodeOut;
	int accept = 0, done = 0;
	outcode0 = ComputeOutCode(x0, y0);
	outcode1 = ComputeOutCode(x1, y1);
	do {
		if (!(outcode0 | outcode1)) { // Trivially accept
			accept = 1; done = 1;
		}
		else if (outcode0 & outcode1) { // Trivially reject
			done = 1;
		}
		else {
			double x, y;
			outcodeOut = outcode0 ? outcode0 : outcode1;
			if (outcodeOut & TOP) { // Clip to top edge
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM) { // Clip to bottom edge
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT) { // Clip to right edge
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else { // Clip to left edge
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}
			if (outcodeOut == outcode0) {
				x0 = x; y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			}
			else {
				x1 = x; y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}
	} while (!done);
	if (accept) {
		double sx = (xvmax - xvmin) / (xmax - xmin);
		double sy = (yvmax - yvmin) / (ymax - ymin);
		double vx0 = xvmin + (x0 - xmin) * sx;
		double vy0 = yvmin + (y0 - ymin) * sy;
		double vx1 = xvmin + (x1 - xmin) * sx;
		double vy1 = yvmin + (y1 - ymin) * sy;
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin, yvmin);
		glVertex2f(xvmax, yvmin);
		glVertex2f(xvmax, yvmax);
		glVertex2f(xvmin, yvmax);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2d(vx0, vy0);
		glVertex2d(vx1, vy1);
		glEnd();
	}
}
// Display function
void display() {
	// List of lines to clip
	double lines[][4] = {
	{60, 20, 80, 120}, // Line 1
	{30, 40, 120, 60}, // Line 2
	{70, 150, 90, 10} // Line 3
	};
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw original lines
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < 3; i++) {
		glBegin(GL_LINES);
		glVertex2d(lines[i][0], lines[i][1]);
		glVertex2d(lines[i][2], lines[i][3]);
		glEnd();
	}
	// Draw clipping rectangle
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();
	// Clip and draw lines
	for (int i = 0; i < 3; i++) {
		CohenSutherland(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
	}
	glFlush();
}
// Initialize OpenGL
void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
// Main function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm - Multiple Lines");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}