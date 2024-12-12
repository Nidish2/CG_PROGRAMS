//#include <GL/glut.h>
//// Initialize OpenGL settings
//void init() {
//	glClearColor(0.95f, 0.95f, 0.95f, 1.0f); // Light pastel gray background
//	glEnable(GL_DEPTH_TEST); // Enable depth testing
//}
//// Display function to render the wireframe dodecahedron
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffers
//	glLoadIdentity();
//	// Transformations for perspective view
//	glTranslatef(0.0f, 0.0f, -5.0f); // Move the object into view
//	glRotatef(30.0f, 1.0f, 1.0f, 0.0f); // Rotate for a better 3D perspective
//	// Set color for the wireframe
//	glColor3f(0.3f, 0.4f, 0.6f); // Pastel blue color for the edges
//	// Draw the wireframe dodecahedron
//	glutWireDodecahedron(); // Draws the wireframe dodecahedron
//	glutSwapBuffers();
//}
//// Handle window resizing
//void reshape(int w, int h) {
//	if (h == 0) h = 1; // Prevent division by zero
//	float aspect = (float)w / h;
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, aspect, 1.0, 100.0); // Set perspective projection
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}// Main function
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Wireframe Polyhedron");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}