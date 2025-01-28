//implement a program to show (built in functions) translation and scaling using menu functions
#include <GL/glut.h>

// Transformation variables
float translationX = -2.0f, translationY = 0.0f, translationZ = 0.0f;
float scale = 1.0f;

int operation = -1;  // Operation type (translate, scale, etc.)

float finalTranslationX = 2.0f;  // Final translation position for animation
float translationspeed = 0.01f;  // Speed of translation

// Draw the cube using built-in transformations
void drawCube() {
	glBegin(GL_QUADS);

	// Front face (Red)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// Back face (Green)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	// Left face (Blue)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	// Right face (Yellow)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	// Top face (Magenta)
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// Bottom face (Cyan)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glEnd();
}

// Display function to render the scene
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	// Apply transformation based on selected operation
	if (operation == 0) {
		glTranslatef(translationX, translationY, translationZ);  // Translate the cube
	}
	else if (operation == 1) {
		glScalef(scale, scale, scale);  // Scale the cube
	}

	// Draw the cube with transformations applied
	drawCube();

	glPopMatrix();
	glutSwapBuffers();
}

// Timer function to update transformations
void timer(int value) {
	// Handle translation operation
	if (operation == 0) {
		if (translationX < finalTranslationX) {
			translationX += translationspeed;  // Translate incrementally
		}
	}
	// Handle scaling operation
	else if (operation == 1) {
		scale += 0.01f;  // Increase scale incrementally
		if (scale > 1.5f)
			scale = 1.0f;  // Reset scale once it exceeds 1.5
	}

	glutPostRedisplay();  // Redraw the screen
	glutTimerFunc(16, timer, 0);  // Call timer every 16 ms for animation (60 FPS)
}

// Menu handler function to select transformation operation
void menuHandler(int option) {
	operation = option;  // Set operation type based on menu selection
}

// Create the transformation menu
void createMenu() {
	glutCreateMenu(menuHandler);
	glutAddMenuEntry("Translate (Built-in)", 0);
	glutAddMenuEntry("Scale (Built-in)", 1);
	glutAddMenuEntry("Stop", -1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Main function to initialize OpenGL, create window and enter the rendering loop
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("3D Cube - Built-in Transformation");
	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background color to white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, 800.0 / 600.0, 1, 10);  // Set perspective projection
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Set camera position
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(display);  // Register display callback function
	glutTimerFunc(16, timer, 0);  // Register timer function for animation
	createMenu();  // Create the operation menu

	glutMainLoop();  // Start the main rendering loop
	return 0;
}