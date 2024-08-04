#include <stdio.h>
#include <GL/glut.h>

int x1, y1, x2, y2;

void draw_pixel(int x, int y) {
    glColor3f(0.0, 0.0, 1.0); // Blue color for the pixel
    glPointSize(5); // Set point size
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;

    incx = (x2 < x1) ? -1 : 1;
    incy = (y2 < y1) ? -1 : 1;

    x = x1;
    y = y1;

    if (dx > dy) { // Slope less than 1
        draw_pixel(x, y);
        e = 2 * dy - dx; // Initial decision parameter
        inc1 = 2 * (dy - dx); // Upper pixel
        inc2 = 2 * dy; // Lower pixel

        for (i = 0; i < dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1; // Selection of upper pixel
            } else {
                e += inc2; // Selection of lower pixel
            }
            x += incx;
            draw_pixel(x, y);
        }
    } else { // Slope greater than 1
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i < dy; i++) {
            if (e >= 0) {
                x += incx; // Upper pixel
                e += inc1;
            } else {
                e += inc2;
            }
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void Bresenham() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    draw_line(x1, y1, x2, y2); // Draw the line
    glColor3f(1.0, 0.0, 0.0); // Set color for the actual line
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    printf("Enter the endpoints of the line segment: ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Algorithm");
    glutDisplayFunc(Bresenham);
    myinit();
    glutMainLoop();
    return 0;
}

