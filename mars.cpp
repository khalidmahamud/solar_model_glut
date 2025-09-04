#include <iostream>
// #include <windows.h>  // for MS Windows
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float _move = 0.0f;//car1
float _move1 = 0.0f;//car2
float _move2 = 0.0f;//marsPlane
float _move3 = 0.0f;//marsTrain
float _move4 = 0.0f;//marsTrain
float _move5 = 0.0f;//car3
float _move6 = 0.0f;//car3

void car1()
{

    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);
    glBegin(GL_POLYGON);     //Car
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-44.0f, -25.0f);
	glVertex2f(-36.0f, -25.0f);
	glVertex2f(-36.0f, -23.0f);
	glVertex2f(-44.0f, -23.0f);

	glVertex2f(-42.5f, -23.0f);
	glVertex2f(-37.0f, -23.0f);
	glVertex2f(-38.5f, -21.0f);
	glVertex2f(-41.0f, -21.0f);



	glEnd();


	glPopMatrix();

}
void chakka11()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
glTranslatef(-0.84f, -0.63f, 0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


	glPopMatrix();


}

void chakka12()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
glTranslatef(-0.75f, -0.63f, 0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


	glPopMatrix();


}


void car2()
{
    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move1, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);
    glBegin(GL_QUADS);      //Another Car
	glColor3f(0.0f, 0.70f, 0.58f);
	glVertex2f(31.0f, -35.0f);
	glVertex2f(39.0f, -35.0f);
	glVertex2f(39.0f, -33.0f);
	glVertex2f(31.0f, -33.0f);



	glEnd();

	glBegin(GL_QUADS);      //Another Car
	glColor3f(0.0f, 0.70f, 0.58f);
	glVertex2f(32.0f, -33.0f);
	glVertex2f(38.0f, -33.0f);
	glVertex2f(37.0f, -31.0f);
	glVertex2f(33.0f, -31.0f);

	glEnd();
	glPopMatrix();


}

void chakka21()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move1, 0.0f, 0.0f);
glTranslatef(0.66f, -0.88f, 0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


	glPopMatrix();


}

void chakka22()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move1, 0.0f, 0.0f);
glTranslatef(0.75f, -0.88f, 0.0f);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


	glPopMatrix();


}

void car3()
{
    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move5, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);

glBegin(GL_QUADS);//Car
	glColor3f(1.0f, 1.0f, 0.40f);
	glVertex2f(-44.0f, -25.0f);
	glVertex2f(-36.0f, -25.0f);
	glVertex2f(-36.0f, -23.0f);
	glVertex2f(-44.0f, -23.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.40f);
	glVertex2f(-42.5f, -23.0f);
	glVertex2f(-37.0f, -23.0f);
	glVertex2f(-38.5f, -21.0f);
	glVertex2f(-41.0f, -21.0f);



	glEnd();
	 glPopMatrix();

}

void chakka41()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move5, 0.0f, 0.0f);
glTranslatef(-0.84f, -0.63f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}

void chakka42()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move5, 0.0f, 0.0f);
glTranslatef(-0.75f, -0.63f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}

void car4()
{
     glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move6, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);

 glBegin(GL_QUADS);      //Another Car
	glColor3f(0.67f, 0.15f, 0.31f);
	glVertex2f(31.0f, -35.0f);
	glVertex2f(39.0f, -35.0f);
	glVertex2f(39.0f, -33.0f);
	glVertex2f(31.0f, -33.0f);

	glEnd();


	glBegin(GL_QUADS);      //Another Car
	glColor3f(0.67f, 0.15f, 0.31f);
	glVertex2f(32.0f, -33.0f);
	glVertex2f(38.0f, -33.0f);
	glVertex2f(37.0f, -31.0f);
	glVertex2f(33.0f, -31.0f);

	glEnd();

	glPopMatrix();

}

void chakka51()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move6, 0.0f, 0.0f);
glTranslatef(0.66f, -0.88f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();
}

void chakka52()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move6, 0.0f, 0.0f);
glTranslatef(0.75f, -0.88f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}

void marsPlane()
{
    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move2, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);

	glBegin(GL_QUADS);      //Another Car
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-45.0f, 28.0f);
	glVertex2f(-37.0f, 29.0f);
	glVertex2f(-38.0f, 30.0f);
	glVertex2f(-43.0f, 30.0f);

	glEnd();

	glBegin(GL_QUADS);      //Another Car
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-43.0f, 30.0f);
	glVertex2f(-38.0f, 30.0f);
	glVertex2f(-38.0f, 31.0f);
	glVertex2f(-43.0f, 31.0f);

	glEnd();

	glBegin(GL_TRIANGLES);      //Another Car
	glColor3f(0.69f, 0.0f, 0.16f);
	glVertex2f(-43.0f, 29.0f);
	glVertex2f(-40.0f, 30.5f);
	glVertex2f(-45.0f, 31.0f);

	glEnd();

	glBegin(GL_TRIANGLES);      //Another Car
	glColor3f(0.69f, 0.0f, 0.16f);
	glVertex2f(-43.0f, 27.0f);
	glVertex2f(-40.0f, 29.0f);
	glVertex2f(-42.0f, 29.0f);

	glEnd();
	glPopMatrix();


}

void marsTrain()
{
    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(_move3, 0.0f, 0.0f);
 gluOrtho2D(-50,50,-40,40);

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-24.0f, 1.0f);    // x, y
	glVertex2f(-20.0f, 1.0f);    // x, y
	glVertex2f(-20.0f, 4.0f);
	glVertex2f(-24.0f, 4.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-27.0f, 1.0f);    // x, y
	glVertex2f(-24.0f, 1.0f);    // x, y
	glVertex2f(-24.0f, 6.0f);
	glVertex2f(-27.0f, 6.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-21.0f, 4.0f);    // x, y
	glVertex2f(-21.0f, 5.0f);    // x, y


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-21.0f, 5.0f);    // x, y
	glVertex2f(-21.0f, 5.5f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.40f, 0.20f, 0.0f);
	glVertex2f(-32.0f, 1.0f);    // x, y
	glVertex2f(-28.0f, 1.0f);    // x, y
	glVertex2f(-28.0f, 4.0f);
	glVertex2f(-32.0f, 4.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.40f, 0.20f, 0.0f);
	glVertex2f(-37.0f, 1.0f);    // x, y
	glVertex2f(-33.0f, 1.0f);    // x, y
	glVertex2f(-33.0f, 4.0f);
	glVertex2f(-37.0f, 4.0f);

	glEnd();

	glPopMatrix();

}

void chakka31()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move3, 0.0f, 0.0f);
glTranslatef(-0.51f, 0.03f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();


}

void chakka32()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move3, 0.0f, 0.0f);
glTranslatef(-0.6f, 0.03f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}

void chakka33()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move3, 0.0f, 0.0f);
glTranslatef(-0.7f, 0.03f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}

void marsMoon()
{
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(0.5f, 0.8f, 0.0f);
glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.08;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
glEnd();
glPopMatrix();
glutSwapBuffers();
}


void marsCloud1()
{
    glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);

 glPushMatrix();

 glTranslatef(_move4, 0.0f, 0.0f);

glTranslatef(-0.30f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}
void marsCloud2()
{

   glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
glTranslatef(-0.50f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}
void marsCloud3()
{

   glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
glTranslatef(-0.40f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.08;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();


}
void marsCloud4() {

glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
glTranslatef(0.30f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}
void marsCloud5()
{

   glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
glTranslatef(0.50f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();

}
void marsCloud6()
{

   glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
glTranslatef(0.40f, 0.98f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.08;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
glPopMatrix();

}

void displayMarsScene() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);
	// Draw a Red 1x1 Square centered at origin

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-50.0f, -40.0f);    // x, y
	glVertex2f(-40.0f, -40.0f);    // x, y
	glVertex2f(-40.0f, -37.0f);
	glVertex2f(-50.0f, -37.0f);

	glEnd();


	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-30.0f, -40.0f);    // x, y
	glVertex2f(-20.0f, -40.0f);    // x, y
	glVertex2f(-20.0f, -37.0f);
	glVertex2f(-30.0f, -37.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-10.0f, -40.0f);    // x, y
	glVertex2f(0.0f, -40.0f);    // x, y
	glVertex2f(0.0f, -37.0f);
	glVertex2f(-10.0f, -37.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(10.0f, -40.0f);    // x, y
	glVertex2f(20.0f, -40.0f);    // x, y
	glVertex2f(20.0f, -37.0f);
	glVertex2f(10.0f, -37.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(30.0f, -40.0f);    // x, y
	glVertex2f(40.0f, -40.0f);    // x, y
	glVertex2f(40.0f, -37.0f);
	glVertex2f(30.0f, -37.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-45.0f, -20.0f);    // x, y
	glVertex2f(-35.0f, -20.0f);    // x, y
	glVertex2f(-35.0f, -18.0f);
	glVertex2f(-45.0f, -18.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-25.0f, -20.0f);    // x, y
	glVertex2f(-15.0f, -20.0f);    // x, y
	glVertex2f(-15.0f, -18.0f);
	glVertex2f(-25.0f, -18.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-5.0f, -20.0f);    // x, y
	glVertex2f(5.0f, -20.0f);    // x, y
	glVertex2f(5.0f, -18.0f);
	glVertex2f(-5.0f, -18.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(15.0f, -20.0f);    // x, y
	glVertex2f(25.0f, -20.0f);    // x, y
	glVertex2f(25.0f, -18.0f);
	glVertex2f(15.0f, -18.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(35.0f, -20.0f);    // x, y
	glVertex2f(45.0f, -20.0f);    // x, y
	glVertex2f(45.0f, -18.0f);
	glVertex2f(35.0f, -18.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2f(-50.0f, -37.0f);    // x, y
	glVertex2f(50.0f, -37.0f);    // x, y
	glVertex2f(50.0f, -20.0f);
	glVertex2f(-50.0f, -20.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-50.0f, -28.0f);    // x, y
	glVertex2f(-40.0f, -28.0f);    // x, y
	glVertex2f(-40.0f, -27.0f);
	glVertex2f(-50.0f, -27.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-25.0f, -28.0f);    // x, y
	glVertex2f(-15.0f, -28.0f);    // x, y
	glVertex2f(-15.0f, -27.0f);
	glVertex2f(-25.0f, -27.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(5.0f, -28.0f);    // x, y
	glVertex2f(15.0f, -28.0f);    // x, y
	glVertex2f(15.0f, -27.0f);
	glVertex2f(5.0f, -27.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(30.0f, -28.0f);    // x, y
	glVertex2f(40.0f, -28.0f);    // x, y
	glVertex2f(40.0f, -27.0f);
	glVertex2f(30.0f, -27.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-36.0f, -35.0f);    // x, y
	glVertex2f(-34.0f, -35.0f);    // x, y
	glVertex2f(-35.0f, -34.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-37.0f, -40.0f);    // x, y
	glVertex2f(-33.0f, -40.0f);    // x, y
	glVertex2f(-33.0f, -39.0f);
	glVertex2f(-37.0f, -39.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-36.0f, -39.0f);    // x, y
	glVertex2f(-34.0f, -39.0f);    // x, y
	glVertex2f(-34.0f, -35.0f);
	glVertex2f(-36.0f, -35.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-37.0f, -37.0f);    // x, y
	glVertex2f(-33.0f, -37.0f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.3f);
	glVertex2f(-50.0f, -18.0f);    // x, y
	glVertex2f(50.0f, -18.0f);    // x, y
	glVertex2f(50.0f, 0.0f);
	glVertex2f(-50.0f, 0.0f);

	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-50.0f, 0.0f);    // x, y
	glVertex2f(50.0f, 0.0f);    // x, y
	glVertex2f(50.0f, 1.0f);    // x, y
	glVertex2f(-50.0f, 1.0f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.6f, 1.0f);
	glVertex2f(-50.0f, 10.0f);    // x, y
	glVertex2f(50.0f, 10.0f);    // x, y
	glVertex2f(50.0f, 40.0f);
	glVertex2f(-50.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(-50.0f, 1.0f);    // x, y
	glVertex2f(50.0f, 1.0f);    // x, y
	glVertex2f(50.0f, 10.0f);
	glVertex2f(-50.0f, 10.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.1f, 0.5f);
	glVertex2f(-40.0f, 10.0f);    // x, y
	glVertex2f(-30.0f, 10.0f);    // x, y
	glVertex2f(-30.0f, 25.0f);
	glVertex2f(-40.0f, 25.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 0.3f);
	glVertex2f(-30.0f, 10.0f);    // x, y
	glVertex2f(-20.0f, 10.0f);    // x, y
	glVertex2f(-20.0f, 30.0f);
	glVertex2f(-30.0f, 30.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 0.3f);
	glVertex2f(-20.0f, 28.0f);    // x, y
	glVertex2f(-18.0f, 28.0f);    // x, y
	glVertex2f(-20.0f, 30.0f);


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 0.3f);
	glVertex2f(-20.0f, 10.0f);    // x, y
	glVertex2f(-18.0f, 10.0f);    // x, y
	glVertex2f(-18.0f, 28.0f);
	glVertex2f(-20.0f, 28.0f);


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-20.0f, 10.0f);    // x, y
	glVertex2f(-20.0f, 30.0f);    // x, y



	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.02f, 0.40f, 0.03f);
	glVertex2f(-15.0f, 20.0f);    // x, y
	glVertex2f(-11.0f, 20.0f);    // x, y
	glVertex2f(-13.0f, 23.0f);



	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.02f, 0.40f, 0.03f);
	glVertex2f(-15.0f, 18.0f);    // x, y
	glVertex2f(-11.0f, 18.0f);    // x, y
	glVertex2f(-13.0f, 21.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-13.0f, 10.0f);    // x, y
	glVertex2f(-13.0f, 18.0f);    // x, y




	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.30f, 0.0f, 0.20f);
	glVertex2f(-9.0f, 10.0f);    // x, y
	glVertex2f(1.0f, 10.0f);    // x, y
	glVertex2f(1.0f, 35.0f);
	glVertex2f(-9.0f, 35.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.49f, 0.0f);
	glVertex2f(1.0f, 10.0f);    // x, y
	glVertex2f(15.0f, 10.0f);    // x, y
	glVertex2f(15.0f, 25.0f);
	glVertex2f(1.0f, 25.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(19.0f, 10.0f);    // x, y
	glVertex2f(23.0f, 10.0f);    // x, y
	glVertex2f(22.0f, 12.0f);
	glVertex2f(20.0f, 12.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.f);
	glVertex2f(20.0f, 19.0f);    // x, y
	glVertex2f(22.0f, 19.0f);    // x, y
	glVertex2f(23.0f, 22.0f);
	glVertex2f(19.0f, 22.0f);



	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(19.0f, 22.0f);    // x, y
	glVertex2f(23.0f, 22.0f);    // x, y
	glVertex2f(21.0f, 24.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(21.0f, 12.0f);    // x, y
	glVertex2f(21.0f, 19.0f);    // x, y



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(20.9f, 19.0f);    // x, y
	glVertex2f(21.1f, 19.0f);    // x, y
	glVertex2f(21.1f, 24.0f);
	glVertex2f(20.9f, 24.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(19.0f, 22.0f);    // x, y
	glVertex2f(23.0f, 22.0f);    // x, y
	glVertex2f(23.0f, 22.2f);
	glVertex2f(19.0f, 22.2f);



	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.02f, 0.40f, 0.03f);
	glVertex2f(-15.0f, 22.0f);    // x, y
	glVertex2f(-11.0f, 22.0f);    // x, y
	glVertex2f(-13.0f, 25.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.80f, 0.40f);
	glVertex2f(30.0f, 10.0f);    // x, y
	glVertex2f(45.0f, 10.0f);    // x, y
	glVertex2f(45.0f, 20.0f);
	glVertex2f(30.0f, 20.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.42f, 0.50f);
	glVertex2f(30.0f, 20.0f);    // x, y
	glVertex2f(45.0f, 20.0f);    // x, y
	glVertex2f(43.0f, 24.0f);
	glVertex2f(32.0f, 24.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-40.0f, -15.0f);    // x, y
	glVertex2f(-40.0f, -10.0f);    // x, y




	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(-42.0f, -10.0f);    // x, y
	glVertex2f(-38.0f, -10.0f);    // x, y
	glVertex2f(-40.0f, -2.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-33.0f, -10.0f);    // x, y
	glVertex2f(-25.0f, -10.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-33.0f, -8.0f);    // x, y
	glVertex2f(-25.0f, -8.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-33.0f, -12.0f);    // x, y
	glVertex2f(-23.0f, -12.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-33.0f, -15.0f);    // x, y
	glVertex2f(-33.0f, -8.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-25.0f, -15.0f);    // x, y
	glVertex2f(-25.0f, -8.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-31.0f, -12.0f);    // x, y
	glVertex2f(-31.0f, -15.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-23.0f, -12.0f);    // x, y
	glVertex2f(-23.0f, -15.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-20.0f, -15.0f);    // x, y
	glVertex2f(-20.0f, -10.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-15.0f, -15.0f);    // x, y
	glVertex2f(-15.0f, -10.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-10.0f, -15.0f);    // x, y
	glVertex2f(-10.0f, -10.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(-22.0f, -10.0f);    // x, y
	glVertex2f(-18.0f, -10.0f);
	glVertex2f(-20.0f, -2.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(-17.0f, -10.0f);    // x, y
	glVertex2f(-13.0f, -10.0f);
	glVertex2f(-15.0f, -2.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(-12.0f, -10.0f);    // x, y
	glVertex2f(-8.0f, -10.0f);
	glVertex2f(-10.0f, -2.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(8.0f, -18.0f);    // x, y
	glVertex2f(13.0f, -18.0f);
	glVertex2f(13.0f, -17.0f);
	glVertex2f(8.0f, -17.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(9.0f, -17.0f);    // x, y
	glVertex2f(12.0f, -17.0f);
	glVertex2f(12.0f, -12.0f);
	glVertex2f(9.0f, -12.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(9.0f, -12.0f);    // x, y
	glVertex2f(12.0f, -12.0f);
	glVertex2f(11.0f, -11.0f);
	glVertex2f(10.0f, -11.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10.0f, -15.0f);    // x, y
	glVertex2f(11.0f, -15.0f);
	glVertex2f(11.0f, -14.0f);
	glVertex2f(10.0f, -14.0f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(-46.0f, -15.0f);    // x, y
	glVertex2f(-46.0f, -10.0f);

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(-48.0f, -10.0f);    // x, y
	glVertex2f(-44.0f, -10.0f);    // x, y
	glVertex2f(-46.0f, -2.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(10.0f, -13.0f);    // x, y
	glVertex2f(11.0f, -13.0f);    // x, y




	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(18.0f, -18.0f);    // x, y
	glVertex2f(22.0f, -18.0f);    // x, y
	glVertex2f(21.0f, -16.0f);
	glVertex2f(19.0f, -16.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(20.0f, -16.0f);    // x, y
	glVertex2f(20.0f, -10.0f);    // x, y

    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(19.0f, -10.0f);    // x, y
	glVertex2f(21.0f, -10.0f);    // x, y
	glVertex2f(22.0f, -7.0f);
	glVertex2f(20.0f, -6.0f);
	glVertex2f(18.0f, -7.0f);

    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(19.9f, -10.0f);    // x, y
	glVertex2f(20.1f, -10.0f);    // x, y
	glVertex2f(20.1f, -6.0f);
	glVertex2f(19.9f, -6.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(18.0f, -7.1f);    // x, y
	glVertex2f(22.0f, -7.1f);    // x, y
	glVertex2f(22.0f, -6.9f);
	glVertex2f(18.0f, -6.9f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(29.0f, -8.0f);    // x, y
	glVertex2f(43.0f, -8.0f);    // x, y
	glVertex2f(44.0f, -6.0f);
	glVertex2f(28.0f, -6.0f);



	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(28.0f, -12.0f);    // x, y
	glVertex2f(44.0f, -12.0f);    // x, y
	glVertex2f(43.0f, -10.0f);
	glVertex2f(29.0f, -10.0f);



	glEnd();

        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(28.0f, -13.0f);    // x, y
	glVertex2f(44.0f, -13.0f);    // x, y
	glVertex2f(44.0f, -12.0f);
	glVertex2f(28.0f, -12.0f);



	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(30.0f, -15.0f);    // x, y
	glVertex2f(32.0f, -15.0f);    // x, y
	glVertex2f(32.0f, -4.0f);
	glVertex2f(30.0f, -5.0f);



	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(40.0f, -15.0f);    // x, y
	glVertex2f(42.0f, -15.0f);    // x, y
	glVertex2f(42.0f, -5.0f);
	glVertex2f(40.0f, -4.0f);


	glEnd();

		glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.25f, 0.0f);
	glVertex2f(25.0f, -15.0f);    // x, y
	glVertex2f(25.0f, -10.0f);    // x, y

	glEnd();

	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.30f, 0.10f);
	glVertex2f(23.0f, -10.0f);    // x, y
	glVertex2f(27.0f, -10.0f);    // x, y
	glVertex2f(25.0f, -2.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-29.0f, 23.0f);    // x, y
	glVertex2f(-21.0f, 23.0f);    // x, y
	glVertex2f(-21.0f, 26.0f);
	glVertex2f(-29.0f, 26.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-29.0f, 17.0f);    // x, y
	glVertex2f(-21.0f, 17.0f);    // x, y
	glVertex2f(-21.0f, 20.0f);
	glVertex2f(-29.0f, 20.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.07f, 0.0f, 0.40f);
	glVertex2f(-25.0f, 17.0f);    // x, y
	glVertex2f(-25.0f, 26.0f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(3.0f, 17.0f);    // x, y
	glVertex2f(13.0f, 17.0f);    // x, y
	glVertex2f(13.0f, 21.0f);
	glVertex2f(3.0f, 21.0f);



	glEnd();

		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-39.0f, 17.0f);    // x, y
	glVertex2f(-31.0f, 17.0f);    // x, y
	glVertex2f(-31.0f, 21.0f);
	glVertex2f(-39.0f, 21.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.49f, 0.0f);
	glVertex2f(8.0f, 17.0f);    // x, y
	glVertex2f(8.0f, 21.0f);    // x, y


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.60f);
	glVertex2f(-35.0f, 17.0f);    // x, y
	glVertex2f(-35.0f, 21.0f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.70f, 0.52f, 0.75f);
	glVertex2f(35.0f, 10.0f);    // x, y
	glVertex2f(39.0f, 10.0f);    // x, y
	glVertex2f(39.0f, 15.0f);
	glVertex2f(35.0f, 15.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-8.0f, 17.0f);    // x, y
	glVertex2f(0.0f, 17.0f);    // x, y
	glVertex2f(0.0f, 21.0f);
	glVertex2f(-8.0f, 21.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-8.0f, 23.0f);    // x, y
	glVertex2f(0.0f, 23.0f);    // x, y
	glVertex2f(0.0f, 27.0f);
	glVertex2f(-8.0f, 27.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.60f);
	glVertex2f(-8.0f, 29.0f);    // x, y
	glVertex2f(0.0f, 29.0f);    // x, y
	glVertex2f(0.0f, 33.0f);
	glVertex2f(-8.0f, 33.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.30f, 0.0f, 0.20f);
	glVertex2f(-4.0f, 17.0f);    // x, y
	glVertex2f(-4.0f, 33.0f);    // x, y


	glEnd();



glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.79f, 1.0f, 0.90f);
	glVertex2f(-5.0f, -17.0f);    // x, y
	glVertex2f(5.0f, -17.0f);    // x, y
	glVertex2f(5.0f, -8.0f);
	glVertex2f(-5.0f, -8.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.10f, 0.07f, 0.0f);
	glVertex2f(-5.0f, -8.0f);    // x, y
	glVertex2f(5.0f, -8.0f);    // x, y
	glVertex2f(7.0f, -7.0f);
	glVertex2f(-7.0f, -7.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-7.0f, -6.5f);    // x, y
	glVertex2f(7.0f, -6.5f);    // x, y


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-4.0f, -15.0f);    // x, y
	glVertex2f(4.0f, -15.0f);    // x, y


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.10f, 0.07f, 0.0f);
	glVertex2f(-1.0f, -14.6f);    // x, y
	glVertex2f(1.0f, -14.6f);    // x, y
	glVertex2f(1.0f, -13.0f);
	glVertex2f(-1.0f, -13.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.10f, 0.07f, 0.0f);
	glVertex2f(2.0f, -14.6f);    // x, y
	glVertex2f(4.0f, -14.6f);    // x, y
	glVertex2f(4.0f, -13.0f);
	glVertex2f(2.0f, -13.0f);



	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.10f, 0.07f, 0.0f);
	glVertex2f(-2.0f, -14.6f);    // x, y
	glVertex2f(-4.0f, -14.6f);    // x, y
	glVertex2f(-4.0f, -13.0f);
	glVertex2f(-2.0f, -13.0f);



	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(-3.0f, -18.0f);    // x, y
	glVertex2f(-3.0f, -17.0f);    // x, y


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(3.0f, -18.0f);    // x, y
	glVertex2f(3.0f, -17.0f);    // x, y


	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.50f, 0.16f, 0.0f);
	glVertex2f(-45.0f, 10.0f);    // x, y
	glVertex2f(-45.0f, 15.0f);    // x, y


	glEnd();

	glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(-0.9f, 0.4f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.30,0.10);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();


 glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(-0.9f, 0.44f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.30,0.10);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();


 glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(-0.9f, 0.47f, 0.0f);

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.30,0.10);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();
glPopMatrix();







car1();
chakka11();
chakka12();
gluOrtho2D(-50,50,-40,40);

	car2();
	chakka21();
	chakka22();
	gluOrtho2D(-50,50,-40,40);

	car3();
	chakka41();
	chakka42();
	gluOrtho2D(-50,50,-40,40);

	car4();
	chakka51();
	chakka52();
	gluOrtho2D(-50,50,-40,40);


	marsTrain();
	chakka31();
	chakka32();
	chakka33();
	gluOrtho2D(-50,50,-40,40);


    marsMoon();
	gluOrtho2D(-50,50,-40,40);



	marsPlane();
	gluOrtho2D(-50,50,-40,40);

	marsCloud1();
	gluOrtho2D(-50,50,-40,40);

	marsCloud2();
	gluOrtho2D(-50,50,-40,40);

	marsCloud3();
	gluOrtho2D(-50,50,-40,40);

	marsCloud4();
	gluOrtho2D(-50,50,-40,40);

	marsCloud5();
	gluOrtho2D(-50,50,-40,40);

	marsCloud6();
	gluOrtho2D(-50,50,-40,40);

	glPopMatrix();


	glFlush();  // Render now
}


void updateMarsScene(int value)
{

    _move -= 0.02;
 if(_move < -1.8)
    {
        _move = 1.8;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, updateMarsScene, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}
void updateMarsScene1(int value)
{

    _move1 += 0.02;
 if(_move1 > 1.8)
    {
        _move1 = -1.8;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, updateMarsScene1, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void updateMarsScene2(int value)
{

    _move2 += 0.02;
 if(_move2 > 2)
    {
        _move2 = -1;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(120, updateMarsScene2, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void updateMarsScene3(int value)
{

    _move3 += 0.02;
 if(_move3 > 2)
    {
        _move3 = -1.6;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(80, updateMarsScene3, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void updateMarsScene4(int value)
{

    _move4 -= 0.02;
 if(_move4 < -1.8)
    {
        _move4 = 1.6;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(200, updateMarsScene4, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void updateMarsScene5(int value)
{

    _move5 += 0.02;
 if(_move5 > 2)
    {
        _move5 = -1.6;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, updateMarsScene5, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void updateMarsScene6(int value)
{

    _move6 -= 0.02;
 if(_move6 < -1.8)
    {
        _move6 = 1.8;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, updateMarsScene6, 0); //Notify GLUT to call updateMarsScene again in 25 milliseconds
}

void initMars() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50.0, 50, -40.0, 40.0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);              // Initialize GLUT
	glutCreateWindow("city scene"); // Create a window with the given title
	   // Set the window's initial width & height
	gluOrtho2D(-50,50,-40,40);
	glutDisplayFunc(displayMarsScene); // Register display callback handler for window re-paint
	 initMars();
	glutTimerFunc(30, updateMarsScene, 0);
	glutTimerFunc(30, updateMarsScene1, 0);
	glutTimerFunc(30, updateMarsScene5, 0);
	glutTimerFunc(30, updateMarsScene6, 0);
	glutTimerFunc(120, updateMarsScene2, 0);
	glutTimerFunc(80, updateMarsScene3, 0);
	glutTimerFunc(200, updateMarsScene4, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
