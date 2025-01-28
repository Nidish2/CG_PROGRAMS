#include <GL/glut.h>
#include <stdlib.h>
float scale = 1.0f; // Initial scale factor
// Function to initialize the OpenGL settings
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
	glColor3f(1.0, 1.0, 1.0); // White color for the polygon
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}
// Function to handle keyboard input for scaling
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '+': // Increase scale
		scale += 0.1f;
		break;
	case '-': // Decrease scale
		if (scale > 0.1f) scale -= 0.1f; // Prevent scale from going 
		negative or zero
			break;
	case 27: // Escape key to exit
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
// Function to display the polygon with scaling applied
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	// Apply scaling
	glPushMatrix();
	glScalef(scale, scale, 1.0f);
	// Draw a simple polygon (triangle here)
	glBegin(GL_POLYGON);
	glVertex2f(-3.0f, -3.0f);
	glVertex2f(3.0f, -3.0f);
	glVertex2f(0.0f, 3.0f);
	glEnd();
	glPopMatrix();
	glFlush();
}
// Main function to set up OpenGL and run the program
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Polygon Scaling Example");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}