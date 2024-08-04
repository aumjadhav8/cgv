#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


GLfloat Triangle[3][3] = {
    {100.0, 250.0, 175.0},
    {100.0, 100.0, 300.0},
    {1.0, 1.0, 1.0}        
};

GLfloat theta; 
GLfloat m = 0, n = 0;

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
    
    glPushMatrix();
    drawTriangle();
    glPopMatrix();


    glTranslatef(m, n, 0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-m, -n, 0);

    
    glColor3f(0.0, 0.0, 1.0);
    drawTriangle();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    int choice;

    printf("Enter your choice \n1: Rotation about origin \n2: Rotation about a Fixed point\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the rotation angle in degrees: ");
            scanf("%f", &theta);
            theta = (M_PI * theta) / 180;
            break;

        case 2:
            printf("Enter the fixed point (x y): ");
            scanf("%f %f", &m, &n);
            printf("Enter the rotation angle in degrees: ");
            scanf("%f", &theta);
            theta = (M_PI * theta) / 180;
            break;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Triangle Rotation");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}

