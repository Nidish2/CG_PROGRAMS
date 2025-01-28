#include <GL/glut.h>
void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.5f); // Top vertex
	glVertex2f(-0.5f, -0.5f); // Bottom left vertex
	glVertex2f(0.5f, -0.5f); // Bottom right vertex
	glEnd();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw triangle rotated about the origin
	glPushMatrix();
	glRotatef(135.0f, 0.0f, 0.0f, 1.0f); // Rotate 135 degrees about the Z-axis
	glColor3f(1.0f, 0.0f, 0.0f); // Red color
	drawTriangle();
	glPopMatrix();
	// Draw triangle rotated about a fixed point (1, 0)
	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f); // Move to (1, 0)
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Rotate 45 degrees about the Z-axis
	glColor3f(0.0f, 0.0f, 1.0f); // Blue color
	drawTriangle();
	glPopMatrix();
	glFlush(); // Render the above drawing
}
void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0); // Set the coordinate system
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Rotated Triangle Example");
	init();
	glutDisplayFunc(display);
	glutMainLoop(); // Enter the GLUT event processing loop
	return 0;
}