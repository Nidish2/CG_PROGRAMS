//#include <GL/glut.h>
//void init() {
//	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system 
//}
//void drawLines() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	// Basic line using GL_LINES
//	glColor3f(1.0, 0.0, 0.0); // Red color
//	glLineWidth(1.0); // Line width of 1
//	glBegin(GL_LINES);
//	glVertex2i(50, 400);
//	glVertex2i(200, 400);
//	glEnd();
//	// Thick line using GL_LINES
//	glColor3f(0.0, 1.0, 0.0); // Green color
//	glLineWidth(5.0); // Line width of 5
//	glBegin(GL_LINES);
//	glVertex2i(50, 350);
//	glVertex2i(200, 350);
//	glEnd();
//	// Dotted line using stipple pattern
//	glColor3f(0.0, 0.0, 1.0); // Blue color
//	glEnable(GL_LINE_STIPPLE); // Enable line stippling
//	glLineStipple(1, 0x0101); // Dotted line pattern
//	glLineWidth(2.0);
//	glBegin(GL_LINES);
//	glVertex2i(50, 300);
//	glVertex2i(200, 300);
//	glEnd();
//	glDisable(GL_LINE_STIPPLE);
//	// Dashed line using stipple pattern
//	glColor3f(1.0, 1.0, 0.0); // Yellow color
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(1, 0x00FF); // Dashed line pattern
//	glLineWidth(2.0);
//	glBegin(GL_LINES);
//	glVertex2i(50, 250);
//	glVertex2i(200, 250);
//	glEnd();
//	glDisable(GL_LINE_STIPPLE);
//	// Continuous line with GL_LINE_STRIP
//	glColor3f(1.0, 0.0, 1.0); // Purple color
//	glLineWidth(2.0);
//	glBegin(GL_LINE_STRIP);
//	glVertex2i(300, 400);
//	glVertex2i(350, 350);
//	glVertex2i(400, 400);
//	glVertex2i(450, 350);
//	
//	glEnd();
//	glFlush();
//}
//void display() {
//	drawLines();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("OpenGL Line Attributes and Primitives");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}