#include <GL/glut.h> 
GLsizei winWidth = 500, winHeight = 500; // Initial display-window size. 
static void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}
// Set display-window color. 
static void wireQuadSurfs(void)

{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window. 
	glColor3f(0.0, 0.0, 1.0); // Set line-color to blue. 
	/* Set viewing parameters with world z axis as view-up direction. */
	gluLookAt(2.0, 2.0, 2.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 1.0);
	/* Position and display GLUT wire-frame sphere. */
	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireSphere(0.8, 8, 6);
	glPopMatrix();
	/* Position and display GLUT wire-frame cone. */
	glPushMatrix();
	glTranslatef(1.0, -0.5, 0.5);
	glutWireCone(0.8, 2, 8, 6);
	glPopMatrix();
	/* Position and display GLU wire-frame cylinder. */
	GLUquadricObj* cylinder; // Set name for GLU quadric object. 
	glPushMatrix();
	glTranslatef(-0.4, 1.2, 0.8);
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 0.8, 0.8, 1.5, 8, 4);
	glPopMatrix();
	glFlush();
}
static void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	//glClear(GL_COLOR_BUFFER_BIT);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Wire-Frame Quadric Surfaces");
	init();
	glutDisplayFunc(wireQuadSurfs);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}