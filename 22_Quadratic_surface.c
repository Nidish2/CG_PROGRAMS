#include <GL/glut.h>
#include<stdio.h>
void init(void) {
	GLfloat light_ambient[] = { 1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_position[] = { 1.0,1.0,1.0,0.2 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(20.0, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.7, 0.5, 0.0);
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.8, 2.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -0.5, 0.0);
	glRotatef(85, 1.0, 0.0, 0.0);
	glRotatef(-20, 0.0, 0.0, 1.0);
	glutSolidCube(1.7);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.0, 3.0);
	glutSolidSphere(1.0, 30, 30);
	glPopMatrix();

	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glTranslatef(0.7, 0.0, -4.5);
	glRotatef(90, 5.0, 0.0, 0.0);
	glRotatef(30, 0.0, 0.0, 5.0);
	gluCylinder(qobj, 0.85, 0.85, 3.0, 6, 6);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w,
			2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.5 * (GLfloat)w / (GLfloat)h, 2.5 * (GLfloat)w / (GLfloat)h, -2.5,
			-2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}