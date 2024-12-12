//#include <GL/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//int numVertices = 0; // Number of vertices
//float vertices[100][2]; // Array to store the vertices of the polygon
//// Function to draw the filled polygon
//void drawPolygon() {
//	glBegin(GL_POLYGON);
//	for (int i = 0; i < numVertices; i++) {
//		glVertex2f(vertices[i][0], vertices[i][1]);
//	}
//	glEnd();
//}
//// Scan-line fill algorithm (dummy implementation for illustration)
//void scanLineFill() {
//	glColor3f(1.0, 0.0, 0.0); // Set fill color to red
//	drawPolygon();
//	glFlush();
//}
//// Function to handle menu actions
//void menu(int option) {
//	switch (option) {
//	case 1: { // Add vertex
//		if (numVertices < 100) {
//			int count;
//			printf("How many vertices do you want to add? ");
//			scanf_s("%d", &count);
//			for (int i = 0; i < count; i++) {
//				float x, y;
//				printf("Enter vertex %d (x y): ", numVertices + 1);
//				scanf_s("%f %f", &x, &y);
//				vertices[numVertices][0] = x;
//				vertices[numVertices][1] = y;
//				numVertices++;
//				printf("Vertex %d added: (%.2f, %.2f)\n", numVertices, x,
//					y);
//			}
//		}
//		else {
//			printf("Maximum vertices reached.\n");
//		}
//		break;
//	}
//	case 2: // Fill the polygon
//		if (numVertices >= 3) {
//			glClear(GL_COLOR_BUFFER_BIT);
//			scanLineFill();
//			// Output filled polygon information
//			printf("Polygon filled with the following vertices:\n");
//			for (int i = 0; i < numVertices; i++) {
//				printf("Vertex %d: (%.2f, %.2f)\n", i + 1,
//					vertices[i][0], vertices[i][1]);
//			}
//		}
//		else {
//			printf("At least 3 vertices are required to fill a polygon.\n");
//		}
//		break;
//	case 3: // Exit
//		exit(0);
//	default:
//		printf("Invalid option!\n");
//	}
//	glutPostRedisplay();
//}
//// Function to create the menu
//void createMenu() {
//	int menuId = glutCreateMenu(menu);
//	glutAddMenuEntry("Add Vertex", 1);
//	glutAddMenuEntry("Fill Polygon", 2);
//	glutAddMenuEntry("Exit", 3);
//	glutAttachMenu(GLUT_RIGHT_BUTTON); // Right-click to access menu
//}
//// Display function
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//// Main function
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Polygon Filling with Scan-Line Algorithm");
//	glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//	glColor3f(0.0, 0.0, 0.0); // Set initial drawing color to black
//	// Set up viewing
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//	createMenu();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
