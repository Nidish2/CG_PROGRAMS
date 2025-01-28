#include <GL/glut.h>
// Transformation variables
float manualTranslationX = -2.0f; // Manual translation on the X-axis
float manualScale = 1.0f; // Manual scale factor
float translationSpeed = 0.01f; // Speed of translation
float finalTranslationX = 2.0f; // Final translation position for animation
int operation = -1; // Operation type (translation, scaling, etc.)
// Manually transform the vertex with scaling and translation
void transformedVertex(float x, float y, float z) {
	x *= manualScale; // Scale along x-axis
	y *= manualScale; // Scale along y-axis
	z *= manualScale; // Scale along z-axis
	x += manualTranslationX; // Translate along x-axis
	glVertex3f(x, y, z); // Pass the transformed vertex to OpenGL
}
// Draw the cube with manual transformations
void drawCubeManual() {
	glBegin(GL_QUADS);
	// Front face (Red)
	glColor3f(1.0f, 0.0f, 0.0f);
	transformedVertex(-0.5f, -0.5f, 0.5f);
	transformedVertex(0.5f, -0.5f, 0.5f);
	transformedVertex(0.5f, 0.5f, 0.5f);
	transformedVertex(-0.5f, 0.5f, 0.5f);
	// Back face (Green)
	glColor3f(0.0f, 1.0f, 0.0f);
	transformedVertex(-0.5f, -0.5f, -0.5f);
	transformedVertex(0.5f, -0.5f, -0.5f);
	transformedVertex(0.5f, 0.5f, -0.5f);
	transformedVertex(-0.5f, 0.5f, -0.5f);
	// Left face (Blue)
	glColor3f(0.0f, 0.0f, 1.0f);
	transformedVertex(-0.5f, -0.5f, -0.5f);
	transformedVertex(-0.5f, -0.5f, 0.5f);
	transformedVertex(-0.5f, 0.5f, 0.5f);
	transformedVertex(-0.5f, 0.5f, -0.5f);
	// Right face (Yellow)
	glColor3f(1.0f, 1.0f, 0.0f);
	transformedVertex(0.5f, -0.5f, -0.5f);
	transformedVertex(0.5f, -0.5f, 0.5f);
	transformedVertex(0.5f, 0.5f, 0.5f);
	transformedVertex(0.5f, 0.5f, -0.5f);
	// Top face (Magenta)
	glColor3f(1.0f, 0.0f, 1.0f);
	transformedVertex(-0.5f, 0.5f, -0.5f);
	transformedVertex(0.5f, 0.5f, -0.5f);
	transformedVertex(0.5f, 0.5f, 0.5f);
	transformedVertex(-0.5f, 0.5f, 0.5f);
	// Bottom face (Cyan)
	glColor3f(0.0f, 1.0f, 1.0f);
	transformedVertex(-0.5f, -0.5f, -0.5f);
	transformedVertex(0.5f, -0.5f, -0.5f);
	transformedVertex(0.5f, -0.5f, 0.5f);
	transformedVertex(-0.5f, -0.5f, 0.5f);
	glEnd();
}
// Display function to render the scene
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	// Draw the cube manually transformed
	drawCubeManual();
	glPopMatrix();
	glutSwapBuffers();
}
// Timer function to update transformations
void timer(int value) {
	// Handle translation operation
	if (operation == 0) {
		if (manualTranslationX < finalTranslationX) {
			manualTranslationX += translationSpeed; // Translate incrementally
		}
	}
	// Handle scaling operation
	else if (operation == 1) {
		manualScale += 0.01f; // Increase scale incrementally
		if (manualScale > 1.5f)
			manualScale = 1.0f; // Reset scale once it exceeds 1.5
	}
	glutPostRedisplay(); // Redraw the screen
	glutTimerFunc(16, timer, 0); // Call timer every 16 ms for animation (60 FPS)
}
// Menu handler function to select transformation operation
void menuHandler(int option) {
	operation = option; // Set operation type based on menu selection
}
// Create the transformation menu
void createMenu() {
	glutCreateMenu(menuHandler);
	glutAddMenuEntry("Translate (Manual)", 0);
	glutAddMenuEntry("Scale (Manual)", 1);
	glutAddMenuEntry("Stop", -1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// Main function to initialize OpenGL, create window and enter the rendering loop
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("3D Cube - Manual Transformation");
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 800.0 / 600.0, 1, 10); // Set perspective projection
	gluLookAt(2.0, 2.0, 2.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0); // Set camera position
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(display); // Register display callback function
	glutTimerFunc(16, timer, 0); // Register timer function for animation
	createMenu(); // Create the operation menu
	glutMainLoop(); // Start the main rendering loop
	return 0;
}