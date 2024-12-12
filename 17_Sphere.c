//#include <GL/glut.h> 
//// Rotation variables 
//float xRotate = 0.0, yRotate = 0.0;
//// Mode variable: 0 for wireframe, 1 for solid sphere 
//int sphereMode = 0;
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix();
//	// Apply rotations 
//	glRotatef(xRotate, 1.0, 0.0, 0.0);
//	glRotatef(yRotate, 0.0, 1.0, 0.0);
//	// Render based on sphereMode 
//	if (sphereMode == 0) {
//		glutWireSphere(1.0, 30, 30); // Wireframe sphere 
//	}
//	else {
//		glutSolidSphere(1.0, 30, 30); // Solid sphere 
//	}
//	glPopMatrix();
//	glutSwapBuffers();
//}
//void specialKeys(int key, int x, int y) {
//	// Rotation controls 
//	if (key == GLUT_KEY_UP) xRotate += 5.0;
//	if (key == GLUT_KEY_DOWN) xRotate -= 5.0;
//	if (key == GLUT_KEY_LEFT) yRotate -= 5.0;
//	if (key == GLUT_KEY_RIGHT) yRotate += 5.0;
//	glutPostRedisplay();
//}
//void normalKeys(unsigned char key, int x, int y) {
//	// Toggle between wireframe and solid sphere 
//	if (key == 't' || key == 'T') {
//		sphereMode = (sphereMode + 1) % 2; // Toggle between 0 and 1 
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutCreateWindow("Wireframe and Solid Sphere Toggle");
//	glEnable(GL_DEPTH_TEST);
//	// Set up callback functions 
//	glutDisplayFunc(display);
//	glutSpecialFunc(specialKeys); // For arrow key controls 
//	glutKeyboardFunc(normalKeys); // For normal key controls 
//	glutMainLoop();
//	return 0;
//}