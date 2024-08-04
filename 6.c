#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;
GLsizei winWidth = 500, winHeight = 500; // Window size.
GLuint regHex; // Display list for the hexagon.
static GLfloat rotTheta = 0.0; // Rotation angle.

// Initialize OpenGL settings and create the hexagon display list.
void init(void) {
    GLfloat hexVertex[2];
    GLdouble hexTheta;
    regHex = glGenLists(1);
    glNewList(regHex, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0); // Set color to red.
    glBegin(GL_POLYGON);
    for (int k = 0; k < 6; ++k) {
        hexTheta = TWO_PI * k / 6;
        hexVertex[0] = 150 + 100 * cos(hexTheta);
        hexVertex[1] = 150 + 100 * sin(hexTheta);
        glVertex2f(hexVertex[0], hexVertex[1]);
    }
    glEnd();
    glEndList();
}

// Display function to draw the hexagon.
void displayHex(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotTheta, 0.0, 0.0, 1.0); // Apply rotation.
    glCallList(regHex); // Draw the hexagon.
    glPopMatrix();
    glutSwapBuffers();
}

// Update rotation angle and request redraw.
void rotateHex(void) {
    rotTheta += 3.0;
    if (rotTheta > 360.0) rotTheta -= 360.0;
    glutPostRedisplay();
}

// Set up the 2D projection.
void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -320.0, 320.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Start or stop rotation based on mouse button.
void mouseFcn(GLint button, GLint action, GLint x, GLint y) {
    if (button == GLUT_MIDDLE_BUTTON && action == GLUT_DOWN)
        glutIdleFunc(rotateHex); // Start rotation.
    if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN)
        glutIdleFunc(NULL); // Stop rotation.
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Simple Rotation Example");
    init();
    glutDisplayFunc(displayHex);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(mouseFcn);
    glutMainLoop();
    return 0;
}

