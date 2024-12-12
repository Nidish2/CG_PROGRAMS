//#include <GL/glut.h> 
//// Camera parameters 
//float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f; // Camera position 
//float angleX = 0.0f, angleY = 0.0f;
//// Camera rotation 
//// Function to draw a color cube 
//void drawCube() {
//	glBegin(GL_QUADS);
//	// Front face (red) 
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	// Back face (green) 
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	// Top face (blue) 
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	// Bottom face (yellow) 
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	// Right face (magenta) 
//	glColor3f(1.0, 0.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	// Left face (cyan) 
//	glColor3f(0.0, 1.0, 1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glEnd();
//}
//// Function to handle keyboard inputs 
//void keyboard(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'w': cameraZ -= 0.2f; break; // Move forward 
//	case 's': cameraZ += 0.2f; break; // Move backward 
//	case 'a': cameraX -= 0.2f; break; // Move left 
//	case 'd': cameraX += 0.2f; break; // Move right 
//	case 'q': cameraY += 0.2f; break; // Move up 
//	case 'e': cameraY -= 0.2f; break; // Move down 
//	case 27: exit(0); break;
//		// Exit on ’Esc' 
//	}
//	glutPostRedisplay();
//}
//// Function to handle special keys for rotation 
//void specialKeys(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_LEFT: angleY -= 2.0f; break; // Rotate left 
//	case GLUT_KEY_RIGHT: angleY += 2.0f; break; // Rotate right 
//	case GLUT_KEY_UP: angleX -= 2.0f; break; // Rotate up 
//	case GLUT_KEY_DOWN: angleX += 2.0f; break; // Rotate down 
//	}
//	glutPostRedisplay();
//}
//// Display function 
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	// Apply camera transformations 
//	glTranslatef(-cameraX, -cameraY, -cameraZ);
//	glRotatef(angleX, 1.0, 0.0, 0.0);
//	glRotatef(angleY, 0.0, 1.0, 0.0);
//	// Draw the cube 
//	drawCube();
//	glutSwapBuffers();
//}
//// Reshape function 
//void reshape(int w, int h) {
//	if (h == 0) h = 1;
//	float aspect = (float)w / (float)h;
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, aspect, 1.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//// Main function 
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Color Cube with Perspective Viewing");
//	glEnable(GL_DEPTH_TEST);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(specialKeys);
//
//	glutMainLoop();
//	return 0;
//}