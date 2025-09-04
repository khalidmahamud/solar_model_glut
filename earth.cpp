/*  
    Click 'n'/'N' for change day and night view
*/

#include <GL/glut.h>
#include <math.h>

float drawEarthCarPosX = -40.0f;
float drawEarthBoatPosX = 40.0f;
float drawEarthCloudPosX = -40.0f;
float drawEarthFlagWaveAngle = 0.0f;
bool drawEarthFlagWaveDirection = true; // true: forward, false: backward
bool isNight = false;
float drawEarthPlanePosX = 40.0f;

void drawQuad(float centerX, float centerY, float width, float height) {
    float halfWidth = width / 2.0;
    float halfHeight = height / 2.0;

    glBegin(GL_POLYGON);
    glVertex2f(centerX - halfWidth, centerY + halfHeight);
    glVertex2f(centerX + halfWidth, centerY + halfHeight);
    glVertex2f(centerX + halfWidth, centerY - halfHeight);
    glVertex2f(centerX - halfWidth, centerY - halfHeight);
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawPolygon(float vertices[][2], int points) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < points; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void drawOutline(float vertices[][2], int points) {
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < points; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void drawCircle(float x_shift, float y_shift, float r) {
    glBegin(GL_POLYGON);
    int iterations = 1000;
    for (int i = 0; i <= iterations; ++i)
    {
        float A = (i * 2 * M_PI) / iterations;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + x_shift, y + y_shift);
    }
    glEnd();
}
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawRectangle(float x, float y, float width, float height) {
    float halfWidth = width / 2.0;
    float halfHeight = height / 2.0;

    glBegin(GL_QUADS);
    glVertex2f(x - halfWidth, y + halfHeight); // Top left corner
    glVertex2f(x + halfWidth, y + halfHeight); // Top right corner
    glVertex2f(x + halfWidth, y - halfHeight); // Bottom right corner
    glVertex2f(x - halfWidth, y - halfHeight); // Bottom left corner
    glEnd();
}
// drawEarthHouse 1,..U1
// drawEarthHouse 1,..U1
void drawEarthHouse1()
{
    glColor3ub(72, 61, 139);
    drawRectangle(-30, 13, 10, 24);

    // window inside drawEarthHouse1
    glColor3ub(0, 255, 0);
    drawRectangle(-32, 23, 3, 3); // left 1
    drawRectangle(-28, 23, 3, 3); // right 1
    drawRectangle(-32, 19, 3, 3); // left 2
    drawRectangle(-28, 19, 3, 3); // right 2
    drawRectangle(-32, 15, 3, 3); // left 3
    drawRectangle(-28, 15, 3, 3); // right 3
    drawRectangle(-32, 11, 3, 3); // left 4
    drawRectangle(-28, 11, 3, 3); // right 4
    drawRectangle(-32, 7, 3, 3);  // left 5
    drawRectangle(-28, 7, 3, 3);  // right 5
}

// drawEarthHouse 2....U2
void drawEarthHouse2()
{
    glColor3ub(128, 0, 128);
    drawRectangle(-18, 14, 10, 26);

    // window inside drawEarthHouse2
    glColor3ub(0, 128, 0);
    drawRectangle(-20, 25, 3, 3); // left 1
    drawRectangle(-16, 25, 3, 3); // right 1
    drawRectangle(-20, 21, 3, 3); // left 2
    drawRectangle(-16, 21, 3, 3); // right 2
    drawRectangle(-20, 17, 3, 3); // left 3
    drawRectangle(-16, 17, 3, 3); // right 3
    drawRectangle(-20, 13, 3, 3); // left 4
    drawRectangle(-16, 13, 3, 3); // right 4
    drawRectangle(-20, 9, 3, 3);  // left 5
    drawRectangle(-16, 9, 3, 3);  // right 5
    drawRectangle(-20, 5, 3, 3);  // left 5
    drawRectangle(-16, 5, 3, 3);  // right 5
}
// drawEarthHouse 4
void drawEarthHouse4()
{
    glColor3ub(165, 42, 42);
    drawRectangle(-7, 14, 10, 26);

    // window inside drawEarthHouse2
    glColor3ub(0, 0, 205);
    drawRectangle(-9, 25, 3, 3); // left 1
    drawRectangle(-5, 25, 3, 3); // right 1
    drawRectangle(-9, 21, 3, 3); // left 2
    drawRectangle(-5, 21, 3, 3); // right 2
    drawRectangle(-9, 17, 3, 3); // left 3
    drawRectangle(-5, 17, 3, 3); // right 3
    drawRectangle(-9, 13, 3, 3); // left 4
    drawRectangle(-5, 13, 3, 3); // right 4
    drawRectangle(-9, 9, 3, 3);  // left 5
    drawRectangle(-5, 9, 3, 3);  // right 5
    drawRectangle(-9, 5, 3, 3);  // left 5
    drawRectangle(-5, 5, 3, 3);  // right 5
}
// drawEarthHouse 3 right ....U3
void drawEarthHouse3()
{
    glColor3ub(238, 232, 170);
    drawRectangle(30, 14, 10, 26);

    // window inside drawEarthHouse3
    glColor3ub(50, 205, 50);
    drawRectangle(32, 25, 3, 3); // left 1
    drawRectangle(28, 25, 3, 3); // right 1
    drawRectangle(32, 21, 3, 3); // left 2
    drawRectangle(28, 21, 3, 3); // right 2
    drawRectangle(32, 17, 3, 3); // left 3
    drawRectangle(28, 17, 3, 3); // right 3
    drawRectangle(32, 13, 3, 3); // left 4
    drawRectangle(28, 13, 3, 3); // right 4
    drawRectangle(32, 9, 3, 3);  // left 5
    drawRectangle(28, 9, 3, 3);  // right 5
    drawRectangle(32, 5, 3, 3);  // left 5
    drawRectangle(28, 5, 3, 3);  // right 5
}
// drawEarthRoad rectangle ..U4
void drawEarthRoad()
{
    glColor3ub(105, 105, 105);
    drawRectangle(-32, -7, 150, 17); // bottom rectangle create to make drawEarthRoad,big one
    // drawRectangle(-7,8,10,15);//up recatangle create to make drawEarthRoad,small one
}

// river...U5
void river()
{
    glColor3ub(30, 144, 255);
    drawRectangle(-32, -28, 150, 15); // river bottom
}

// drawEarthBoat...U6
void drawEarthBoat()
{

    // drawEarthBoat1 body
    glColor3ub(139, 69, 19); // drawEarthBoat body colour
    float polygon1[][2] = {
        {-32.36682, -24.99767},
        {-20, -25},
        {-22.8427, -27.98361},
        {-29.07199, -27.98361}};
    drawPolygon(polygon1, 4);
    // drawEarthBoat1 pal
    glColor3ub(128, 0, 128); // drawEarthBoat body colour
    float polygon2[][2] = {
        {-27.52754, -24.37989},
        {-21.6663, -20.79007},
        {-21.68, -24.45},
        {-21.6787, -24.96787}};
    drawPolygon(polygon2, 4);
    // drawEarthBoat2 body
    glColor3ub(255, 140, 0); // drawEarthBoat body colour
    float polygon3[][2] = {
        {-10, -28},
        {0, -28},
        {-2.49112, -30.11484},
        {-6.61024, -30.11484}};
    drawPolygon(polygon3, 4);
    glColor3ub(128, 0, 128); // drawEarthBoat body colour
    float polygon4[][2] = {
        {-5.37465, -27.10787},
        {-1.48868, -25.01282},
        {-1.51, -27.07},
        {-1.52, -28}};
    drawPolygon(polygon4, 4);
}
// drawEarthSun...U7
void drawEarthSun()
{
    glColor3ub(255, 255, 0);
    drawCircle(-35, 34, 3);
}

// drawEarthCloud...U8
void drawEarthCloud()
{
    // left drawEarthCloud
    glColor3ub(224, 255, 255);
    drawCircle(-25, 34, 2);
    drawCircle(-25, 32, 2);
    drawCircle(-21, 31, 2);
    drawCircle(-20, 34, 2);
    drawCircle(-23, 33, 2);
    drawCircle(-23, 34, 2);

    // middle drawEarthCloud
    glColor3ub(224, 255, 255);
    drawCircle(1, 34, 2);
    drawCircle(-1, 32, 2);
    drawCircle(2, 31, 2);
    drawCircle(2, 34, 2);
    drawCircle(3, 33, 2);
    drawCircle(3, 34, 2);

    // right drawEarthCloud
    glColor3ub(224, 255, 255);
    drawCircle(30, 34, 2);
    drawCircle(31, 32, 2);
    drawCircle(32, 31, 2);
    drawCircle(32, 34, 2);
    drawCircle(33, 33, 2);
    drawCircle(33, 34, 2);
}

// drawEarthMoon....U9
void drawEarthMoon()
{
    glColor3ub(176, 196, 222);
    drawCircle(15, 36, 3);
    glColor3f(0.0f, 0.0f, 0.2f);
    drawCircle(16, 36, 3);
}
// drawEarthPlane...U10
void drawEarthPlane()
{

    glColor3ub(123, 104, 238); // drawEarthCar body colour
    float polygon1[][2] = {
        {26.63889, 32.08346},
        {30, 35},
        {38.21757, 34.90753},
        {38.16109, 30.21958},
        {30, 30},
    };
    drawPolygon(polygon1, 5);
    // drawEarthPlane wings left
    glColor3ub(123, 104, 238); // drawEarthCar body colour
    float polygon2[][2] = {
        {31.04, 34.99},
        {31.97, 37.39},
        {33.28, 37.39},
        {32.51, 34.97},

    };
    drawPolygon(polygon2, 4);

    // drawEarthPlane wings lright
    glColor3ub(123, 104, 238); // drawEarthCar body colour
    float polygon3[][2] = {
        {36.18, 34.93},
        {36.25318, 36.30933},
        {37.21762, 36.34791},
        {37.21762, 34.92},

    };
    drawPolygon(polygon3, 4);

    // drawEarthPlane wings bottom
    glColor3ub(123, 104, 238); // drawEarthCar body colour
    float polygon4[][2] = {
        {30.7, 30.02},
        {32, 30.05},
        {32.47258, 28.40093},
        {31.27668, 28.43951},

    };
    drawPolygon(polygon4, 4);
}
// star....U11
void earthStar()
{
    glColor3ub(255, 250, 205);
    drawCircle(-35, 36, .25);
    drawCircle(-30, 30, .25);
    drawCircle(-25, 32, .25);
    drawCircle(-20, 31, .25);
    drawCircle(-15, 28, .25);
    drawCircle(-10, 29, .20);
    drawCircle(-5, 26, .20);
    drawCircle(0, 30, .20);
    drawCircle(5, 36, .20);
    drawCircle(10, 37, .20);
    drawCircle(15, 33, .20);
    drawCircle(20, 30, .20);
    drawCircle(25, 32, .20);
    drawCircle(30, 29, .20);
    drawCircle(35, 37, .20);
    drawCircle(40, 31, .20);
}
// drawErathTrafficLight....U12
void drawErathTrafficLight()
{

    // lampost pole
    glColor3ub(0, 0, 0);
    drawRectangle(1, 6.5, 1.5, 12); // bottom
    drawRectangle(1, 12.5, 2.5, 7); // light box
    // light colour red
    glColor3ub(255, 0, 0);
    drawCircle(1, 14.5, 1);
    // light colour yellow
    glColor3ub(255, 255, 0);
    drawCircle(1, 12.25, 1);
    // light colour green
    glColor3ub(0, 128, 0);
    drawCircle(1, 10, 1);
}

// drawEarthTree...U13
void drawEarthTree()
{

    // drawEarthTree body
    glColor3ub(184, 134, 11);
    drawRectangle(3.5, 7, 1.5, 13); // left 1

    glColor3ub(0, 128, 0);
    drawCircle(3.5, 20.5, 2);
    // drawEarthTree leaf
    glColor3ub(0, 128, 0);
    drawCircle(4.5, 18.25, 2);
    // drawEarthTree leaf
    glColor3ub(0, 128, 0);
    drawCircle(5.5, 16, 2);
    glColor3ub(0, 128, 0);
    drawCircle(2, 20.5, 2);
    // drawEarthTree leaf
    glColor3ub(0, 128, 0);
    drawCircle(1, 18.25, 2);
    // drawEarthTree leaf
    glColor3ub(0, 128, 0);
    drawCircle(1.5, 16, 2);
    glColor3ub(0, 128, 0);
    drawCircle(0.5, 14, 2);
    glColor3ub(0, 128, 0);
    drawCircle(4, 15, 2);
    glColor3ub(0, 128, 0);
    drawCircle(4.5, 20.5, 2);
}

// drawEarthCar....U14
void drawEarthCar()
{
    // drawEarthCar1 wheel
    glColor3ub(0, 0, 0);
    drawCircle(-11.39, -5.33, 0.86); // left wheel
    drawCircle(-7.55, -5.33, 0.86);  // right wheel

    // drawEarthCar1 body
    glColor3ub(123, 104, 238); // drawEarthCar body colour
    float polygon1[][2] = {
        {-14, -4}, {-5.16, -3.9}, {-5.16, -5.21}, {-14.02, -5.38}};
    drawPolygon(polygon1, 4);

    float polygon2[][2] = {
        {-12, -4}, {-11, -2}, {-7.85, -1.94}, {-6.9, -3.9}};
    drawPolygon(polygon2, 4);

    // drawEarthCar2 wheel
    glColor3ub(0, 0, 0);
    drawCircle(10.3, -5.41, 0.86); // left wheel
    drawCircle(15.36, -5.4, 0.86); // right wheel

    // drawEarthCar2 body
    glColor3ub(176, 224, 230); // drawEarthCar body colour
    float polygon3[][2] = {
        {8.77358, -4.07339}, {17.20193, -4.03572}, {17.19057, -5.39118}, {8.77715, -5.41532}};
    drawPolygon(polygon3, 4);

    float polygon4[][2] = {
        {10, -4.07}, {10.84696, -2.59336}, {14.65208, -2.58251}, {16.35, -4.04}};
    drawPolygon(polygon4, 4);
}
// drawEarthBench...U15
void drawEarthBench()
{
    glColor3ub(0, 0, 0);
    drawRectangle(7.5, 3, 1.5, 5);  // bottom rectangle create to make drawEarthBench,big one
    drawRectangle(12.5, 3, 1.5, 5); // up recatangle create to make drawEarthBench,small one
    glColor3ub(189, 183, 107);
    drawRectangle(10, 6, 10.5, 3);
}

// drawEarthFlag...U16
void drawEarthFlag(float angle)
{
    // Calculate wave offset...UA1
    float waveOffset = sin(angle) * 2.0f;

    // DrawEarthFlag top rectangle with waving effect
    glColor3ub(0, 128, 0);
    glBegin(GL_QUADS);
    glVertex2f(18, 17.5);
    glVertex2f(21 + 6, 17.5 + waveOffset);
    glVertex2f(21 + 6, 23);
    glVertex2f(18, 23);
    glEnd();

    // DrawEarthFlag circle
    glColor3ub(255, 0, 0);
    drawCircle(21.45, 20.25 + waveOffset / 2.0f, 2); // Adjust circle position based on wave offset

    // DrawEarthFlag pole
    glColor3ub(0, 0, 0);
    drawRectangle(18, 11.5, 1, 23);
}
// drawEarthSky...U17
void drawEarthSky(bool isNight)
{
    if (isNight)
    {
        glColor3f(0.0f, 0.0f, 0.2f); // Dark blue for night
    }
    else
    {
        glColor3f(0.5f, 0.8f, 1.0f); // Light blue for day
    }
    drawRectangle(-32, 17, 150, 48); // top  rectangle create to make drawEarthSky
}

void displayEarthScene()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-40, 40, -40, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (isNight)
    {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue for night
    }
    else
    {
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Light blue for day
    }
    glClear(GL_COLOR_BUFFER_BIT);
    drawEarthSky(isNight);
    drawEarthHouse1();
    drawEarthHouse2();
    drawEarthHouse3();
    drawEarthHouse4();
    drawEarthBench();

    if (isNight)
        earthStar();
    drawEarthTree();
    drawEarthRoad();
    glPushMatrix();
    glTranslatef(drawEarthPlanePosX, 0, 0);
    drawEarthPlane();
    glPopMatrix();

    river();
    if (isNight)
    {
        drawEarthMoon();
    }
    else
    {
        drawEarthSun();
    }

    glPushMatrix();
    glTranslatef(drawEarthCloudPosX, 0, 0.0f); // Example: drawEarthClouds are drawn at y = 20.0f
    if (!isNight)
    {
        drawEarthCloud();
    }
    glPopMatrix();

    drawEarthTree();
    drawErathTrafficLight();

    glPushMatrix();
    glTranslatef(drawEarthCarPosX, 0.0f, 0.5f);
    drawEarthCar();
    glPopMatrix();

    drawEarthFlag(drawEarthFlagWaveAngle);

    glPushMatrix();
    glTranslatef(drawEarthBoatPosX, 0.0f, 0.0f);
    drawEarthBoat();
    glPopMatrix();

    glutSwapBuffers();
}

// UpdateEarthScene function to move the drawEarthCar, drawEarthBoat, drawEarthCloud, and wave the drawEarthFlag...UA2
void updateEarthScene(int value)
{
    // UpdateEarthScene drawEarthCar position
    drawEarthCarPosX += 0.1f;
    if (drawEarthCarPosX > 40.0f)
    {
        drawEarthCarPosX = -40.0f; // Reset position if it goes out of bounds
    }

    // UpdateEarthScene drawEarthBoat position...UA3
    drawEarthBoatPosX -= 0.1f;
    if (drawEarthBoatPosX < -40.0f)
    {
        drawEarthBoatPosX = 40.0f; // Reset position if it goes out of bounds
    }

    // UpdateEarthScene drawEarthCloud position...UA4
    drawEarthCloudPosX += 0.05f;
    if (drawEarthCloudPosX > 40.0f)
    {
        drawEarthCloudPosX = -40.0f; // Reset position if it goes out of bounds
    }

    // UpdateEarthScene drawEarthFlag wave angle using a sine wave
    drawEarthFlagWaveAngle += 0.1f;
    if (drawEarthFlagWaveAngle > 360.0f)
    {
        drawEarthFlagWaveAngle -= 360.0f; // Keep angle within 0-360 range
    }

    drawEarthPlanePosX -= 0.1f; // updateEarthScene drawEarthPlane ...UA5
    if (drawEarthPlanePosX < -40)
    {
        drawEarthPlanePosX = 40.0f;
    }

    // Redisplay the scene with updateEarthScened positions
    glutPostRedisplay();

    // Register the timer callback again
    glutTimerFunc(16, updateEarthScene, 0); // approximately 60 frames per second
}

// Keyboard event handler to toggle day and night..UA6
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        isNight = !isNight;
        glutPostRedisplay(); // Request a redraw of the window
    }
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    // Window for building
    glutInitWindowSize(screenWidth, screenHeight); // Set the window's initial width & height

    glutCreateWindow("DrawEarthPlanet Scene"); // Create a window with the given title
    glutInitWindowPosition(0, 0);
    glutDisplayFunc(displayEarthScene); // Register display callback handler for window re-paint
    glutKeyboardFunc(handleKeypress); // Register keyboard event handler

    glutTimerFunc(16, updateEarthScene, 0); // Start the timer with a delay of 16 ms
    glutMainLoop(); // Enter the event-processing loop

    return 0;
}