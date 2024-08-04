#define BLACK
#include <stdio.h>
#include <GL/glut.h>

GLfloat Triangle[3][3] = {
    {100.0, 250.0, 175.0},  // x-coordinates
    {100.0, 100.0, 300.0},  // y-coordinates
    {1.0, 1.0, 1.0}         // color (not used here)
};

GLfloat m = 0, n = 0;
GLfloat scaleX = 1.0, scaleY = 1.0;

void drawTriangle() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(Triangle[0][0], Triangle[1][0]);
    glVertex2f(Triangle[0][1], Triangle[1][1]);
    glVertex2f(Triangle[0][2], Triangle[1][2]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();

    glPushMatrix();
    glTranslatef(m, n, 0);
    glScalef(scaleX, scaleY, 1);
    glTranslatef(-m, -n, 0);
    drawTriangle();
    glPopMatrix();

    glFlush();
}

void myinit() {
    glClearColor(1, 1, 1, 1);
    glColor3f(1, 0, 0);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 449, 0, 499);
}

int main(int argc, char **argv) {
    int ch;
    printf("Enter choice\n 1: Scaling about origin \n 2: Scaling about a fixed point\n");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("Enter scaling factors (scaleX scaleY): ");
            scanf("%f %f", &scaleX, &scaleY);
            break;
        case 2:
            printf("Enter the fixed point (x y): ");
            scanf("%f %f", &m, &n);
            printf("Enter scaling factors (scaleX scaleY): ");
            scanf("%f %f", &scaleX, &scaleY);
            break;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Triangle Scaling");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

