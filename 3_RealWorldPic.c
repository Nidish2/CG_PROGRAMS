//#include <GL/glut.h>
//
//// Function to draw the house
//void drawHouse() {
//    // Draw base (rectangular part)
//    glColor3f(0.7, 0.4, 0.2);
//    glBegin(GL_POLYGON);
//    glVertex2f(-0.6, -0.3); glVertex2f(-0.1, -0.3);
//    glVertex2f(-0.1, 0.1); glVertex2f(-0.6, 0.1);
//    glEnd();
//
//    // Draw roof (triangle)
//    glColor3f(1.0, 0.0, 0.0);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-0.7, 0.1); glVertex2f(-0.35, 0.4); glVertex2f(0.0, 0.1);
//    glEnd();
//
//    // Draw door
//    glColor3f(0.4, 0.2, 0.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(-0.45, -0.3); glVertex2f(-0.25, -0.3);
//    glVertex2f(-0.25, 0.0); glVertex2f(-0.45, 0.0);
//    glEnd();
//}
//
//// Display function to render the scene
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//        drawHouse();
//    glFlush();
//}
//
//// Initialization function
//void init() {
//    glClearColor(0.5, 0.8, 1.0, 1.0);  // Sky color
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set 2D view
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("OpenGL Natural Scenery");
//    init();
//
//    glutDisplayFunc(display);  // Register display callback
//    glutMainLoop();            // Enter the main loop
//
//    return 0;
//}