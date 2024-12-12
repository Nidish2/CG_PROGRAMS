//#include <GL/glut.h>
//#include <math.h>
//
//#define PI 3.14159265359
//
//void drawCircle(float radius, int segments) {
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(0.0f, 0.0f);  // Center of the circle
//    for (int i = 0; i <= segments; i++) {
//        float angle = 2 * PI * i / segments;
//        float x = radius * cos(angle);
//        float y = radius * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(1.0f, 0.0f, 0.0f);  // Set the color to red
//    drawCircle(100.0f, 100);  // Draw a circle with radius 100 and 100 segments
//
//    glFlush();
//}
//
//void init() {
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set the background color to white
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-200, 200, -200, 200);  // Set the coordinate system to be 2D
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 400);
//    glutCreateWindow("OpenGL Circle Example");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
