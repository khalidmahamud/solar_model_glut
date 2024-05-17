#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.75, 0.6, 1.0); // Background color similar to the image
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCylinder(float radius, float height) {
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, radius, radius, height, 32, 32);
    gluDisk(quad, 0.0, radius, 32, 1);  // Draw the base
    glTranslatef(0.0, 0.0, height);
    gluDisk(quad, 0.0, radius, 32, 1);  // Draw the top
    gluDeleteQuadric(quad);
}

void drawSphere(float radius) {
    glutSolidSphere(radius, 32, 32);
}

void drawDome(float radius) {
    GLUquadric* quad = gluNewQuadric();
    gluPartialDisk(quad, 0.0, radius, 32, 1, 0.0, 180.0);
    gluDeleteQuadric(quad);
}

void drawPyramid(float base, float height) {
    glBegin(GL_TRIANGLES);
    // Front
    glVertex3f(0.0, height, 0.0);
    glVertex3f(-base, 0.0, base);
    glVertex3f(base, 0.0, base);
    // Right
    glVertex3f(0.0, height, 0.0);
    glVertex3f(base, 0.0, base);
    glVertex3f(base, 0.0, -base);
    // Back
    glVertex3f(0.0, height, 0.0);
    glVertex3f(base, 0.0, -base);
    glVertex3f(-base, 0.0, -base);
    // Left
    glVertex3f(0.0, height, 0.0);
    glVertex3f(-base, 0.0, -base);
    glVertex3f(-base, 0.0, base);
    glEnd();
    glBegin(GL_QUADS);
    // Base
    glVertex3f(-base, 0.0, base);
    glVertex3f(base, 0.0, base);
    glVertex3f(base, 0.0, -base);
    glVertex3f(-base, 0.0, -base);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Position the camera
    gluLookAt(0.0, 15.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Set the color
    glColor3f(1.0, 0.5, 1.0); // Similar to the structures in the image

    // Draw spheres
    glPushMatrix();
    glTranslatef(-10.0, 0.0, -10.0);
    drawSphere(2.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0, 5.0, -15.0);
    drawSphere(1.5);
    glPopMatrix();

    // Draw domes
    glPushMatrix();
    glTranslatef(-5.0, 0.0, -5.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    drawDome(3.0);
    glPopMatrix();

    // Draw pyramids
    glPushMatrix();
    glTranslatef(0.0, 0.0, -20.0);
    drawPyramid(3.0, 7.0);
    glPopMatrix();

    // Draw cylinders
    glPushMatrix();
    glTranslatef(10.0, 0.0, -10.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    drawCylinder(1.0, 5.0);
    glPopMatrix();

    // Draw additional shapes to match the image better
    glPushMatrix();
    glTranslatef(-7.0, 0.0, -7.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    drawCylinder(0.5, 2.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12.0, 0.0, -2.0);
    drawSphere(0.75);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.0, 0.0, -18.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    drawCylinder(0.75, 3.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0, 0.0, -12.0);
    drawSphere(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simplistic Alien Cityscape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
