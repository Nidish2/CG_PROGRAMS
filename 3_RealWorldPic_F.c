#include <GL/glut.h>

float angle = 0.0f; // Angle for rotating the scene

void drawGround()
{
	glColor3f(0.2, 0.8, 0.4); // Green
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glScalef(150, 1, 150);
	glutSolidCube(1);
	glPopMatrix();
}

void drawHouse(float x, float z) {
	// Base of the house (3D cube)
	glColor3f(0.8f, 0.4f, 0.1f); // Brown
	glPushMatrix();
	glTranslatef(x, 0.5, z);
	glScalef(2, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.4, 0.2, 0.1);
	glPushMatrix();
	glTranslatef(x, 0, z);
	glBegin(GL_QUADS);
	glVertex3f(-0.2, 0, 1.01);
	glVertex3f(0.2, 0, 1.01);
	glVertex3f(0.2, 0.7, 1.01);
	glVertex3f(-0.2, 0.7, 1.01);
	glEnd();
	glPopMatrix();

	// Roof of the house (3D pyramid)
	glColor3f(0.9f, 0.1f, 0.1f); // Red
	glPushMatrix();
	glTranslatef(x, 1, z);
	glScalef(1.8, 1, 1.8);
	glRotatef(45, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1, 1, 4, 1);
	glPopMatrix();
}

void drawSun() {
	// Sun (sphere approximation using quads)
	glColor3f(1.0f, 0.5f, 0.0f); // Yellow
	glPushMatrix();
	glTranslatef(-4.0f, 4.0f, -2.0f); // Position the sun
	glutSolidSphere(0.5, 20, 20); // Centered at (0,0,0)
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Reset the model-view matrix

	gluLookAt(0.0, 5.0, 12.0, // Eye position
		0.0, 0.0, 0.0,  // Look-at point
		0.0, 1.0, 0.0); // Up vector

	// Rotate the scene for better 3D visualization
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	drawGround();
	drawHouse(0, 0);
	drawSun();
	glFlush();
}

void idle()
{
	angle += 0.01f; // Rotate the scene slowly
	if (angle > 360.0f)
		angle -= 360.0f;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("3D Scene with Primitives");

	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
	glClearColor(0.6f, 0.8f, 1.0f, 1.0f); // Sky blue background
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.0, 1.0, 100.0); // Perspective projection
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}