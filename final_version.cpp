/*
    Press 'e' for naviagting to Earth,
    Press 'j' for naviagting to Jupiter,
    Press 'v' for naviagting to Venus,
    Press 'm' for naviagting to Mars
*/

#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

// Structs and global variables and function prototypes
struct Planet
{
    int id;
    GLfloat radius;
    GLfloat distance;
    GLfloat orbitSpeed;
    GLfloat rotationSpeed;
};

GLfloat textPos[][2] = {
    {-5, 6}, 
    {-4, 6},
    {-3, 6},
    {-2, 6}
};

// Text descriptions
std::vector<std::string> textList = {
    "Press 'e' for naviagting to Earth",
    "Press 'j' for naviagting to Jupiter",
    "Press 'v' for naviagting to Venus",
    "Press 'm' for naviagting to Mars"
};

void renderBitmapString(float x, float y, void *font, const std::string &text)
{
    glRasterPos2f(x, y);
    for (char c : text)
    {
        glutBitmapCharacter(font, c);
    }
}

// Function declarations
void displaySolarModel();
void displayDestinationPlanet();
void loadTextures();
void init(void);
void drawRectangle(float x, float y, float width, float height);
void drawCircle(float x, float y, float radius);
void drawSquare(float centerX, float centerY, float sideLength);
void drawEllipse(float x, float y, float xRadius, float yRadius, int segments);
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
void drawStar(float x, float y, float outerRadius, float innerRadius, int points, int rotate);
void drawPlanet(Planet planet, GLfloat angle, GLfloat rotationAngle);
void drawOrbit(Planet planet);
void star();
void moon();
void dayNight();
void ufo();
void enemyUfo();
void newEnemyUfo();
void updateVenusScene(int value);
void keyboard(unsigned char key, int x, int y);
void handleMouseClick(int button, int state, int x, int y);
void handleSpecialKeypress(int key, int x, int y);
void displayVenusScene();
void displayJupyterScene();
void updateJupiterScene(int value);
void displayEarthScene();

GLuint textures[10]; // Array to store texture IDs for each planet
GLUquadric *quad;
Planet mercury = {0, 0.05, 0.4, 1.0 / 88.0, 1.0};
Planet venus = {1, 0.12, 0.7, 1.0 / 225.0, 1.0};
Planet earth = {2, 0.13, 1.0, 1.0 / 365.0, 1.0};
Planet mars = {3, 0.07, 1.5, 1.0 / 687.0, 1.0};
Planet jupiter = {4, 0.3, 2.5, 1.0 / 4333.0, 1.0};
Planet saturn = {5, 0.25, 3.5, 1.0 / 10759.0, 1.0};
Planet uranus = {6, 0.2, 4.5, 1.0 / 30685.0, 1.0};
Planet neptune = {7, 0.18, 5.5, 1.0 / 60190.0, 1.0};
Planet sun = {8, 0.3, 0, 0.0, 0.0};

GLfloat light_position[] = {0.0, 0.0, 5.0, 0.0};
GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};

GLfloat material_shininess[] = {50.0};

bool lockDisplaySolarModel1 = false;
Planet destinationPlanet;
bool isRotating = true;

// Venus scene variables
float ufoX = 0.0f;
float ufoY = 0.0f;
float ufoSpeed = 1.5f;
bool isFiring = false;
float bulletX = 0.0f;
float bulletY = 0.0f;
float bulletSpeed = 0.5f;
float enemyUfoX = 0.0f;
float enemyUfoY = 30.0f;
bool enemyUfoHit = false;
float enemyUfoSpeed = 0.2f;
float newEnemyUfoX = -50.0f;
float newEnemyUfoY = 30.0f;
bool newEnemyUfoHit = false;
float enemyUfo2X = 50.0f;
float enemyUfo2Y = 37.0f;
bool enemyUfo2Hit = false;
float enemyUfo2Speed = -0.2f;
int score = 0;
bool showIntro = true;
int introEndTime = 0;
float posterX = 0.0f;
float posterY = 10.0f;
float posterSpeed = 0.3f;
float ufoScale = 1.0f;
bool showLayer = false;
bool showStar = false;

// Angles and rotation speeds for planets
static GLfloat mercuryAngle = 0.0;
static GLfloat venusAngle = 0.0;
static GLfloat earthAngle = 0.0;
static GLfloat marsAngle = 0.0;
static GLfloat jupiterAngle = 0.0;
static GLfloat saturnAngle = 0.0;
static GLfloat uranusAngle = 0.0;
static GLfloat neptuneAngle = 0.0;
static GLfloat mercuryRotationAngle = 0.0;
static GLfloat venusRotationAngle = 0.0;
static GLfloat earthRotationAngle = 0.0;
static GLfloat marsRotationAngle = 0.0;
static GLfloat jupiterRotationAngle = 0.0;
static GLfloat saturnRotationAngle = 0.0;
static GLfloat uranusRotationAngle = 0.0;
static GLfloat neptuneRotationAngle = 0.0;
GLfloat scaleFactor = 0.0;

// variables for jupiter scene
float roverPosX = 0.0;
float roverPosY = 0.0;
float roverSpeed = 1.0;
float flameScaleFactor = 0.0;
bool isSpaceShipStarted = false;
float jupiterSpaceShipPosX = 0.0f;
float jupiterSpaceShipPosY = 0.0f;
void updateJupiterScene(int value);

// variable for earth scene
float drawEarthCarPosX = -40.0f;
float drawEarthBoatPosX = 40.0f;
float drawEarthCloudPosX = -40.0f;
float drawEarthFlagWaveAngle = 0.0f;
bool drawEarthFlagWaveDirection = true; // true: forward, false: backward
bool isNight = false;
float drawEarthPlanePosX = 40.0f;

void loadTextures()
{
    // Load textures for each planet
    textures[0] = SOIL_load_OGL_texture("textures/mercury_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[1] = SOIL_load_OGL_texture("textures/venus_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[2] = SOIL_load_OGL_texture("textures/earth_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[3] = SOIL_load_OGL_texture("textures/mars_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[4] = SOIL_load_OGL_texture("textures/jupiter_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[5] = SOIL_load_OGL_texture("textures/saturn_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[6] = SOIL_load_OGL_texture("textures/uranus_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[7] = SOIL_load_OGL_texture("textures/neptune_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[8] = SOIL_load_OGL_texture("textures/sun_texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    textures[9] = SOIL_load_OGL_texture("textures/stars.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void init(void)
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    loadTextures();
    quad = gluNewQuadric();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1 * 1.7, 1 * 1.7, -1, 1, 2, 15);
    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}

void drawQuad(float centerX, float centerY, float width, float height)
{
    float halfWidth = width / 2.0;
    float halfHeight = height / 2.0;

    glBegin(GL_POLYGON);
    glVertex2f(centerX - halfWidth, centerY + halfHeight);
    glVertex2f(centerX + halfWidth, centerY + halfHeight);
    glVertex2f(centerX + halfWidth, centerY - halfHeight);
    glVertex2f(centerX - halfWidth, centerY - halfHeight);
    glEnd();
}

void drawRectangle(float x, float y, float width, float height)
{
    if (destinationPlanet.id == 2) {
        float halfWidth = width / 2.0;
        float halfHeight = height / 2.0;
    }
    
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw multiple lines
void drawLines(float vertices[][2], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        drawLine(vertices[i][0], vertices[i][1], vertices[i + 1][0], vertices[i + 1][1]);
    }
}

void drawPolygon(float vertices[][2], int points)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < points; i++)
    {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void drawPolygonOutline(float vertices[][2], int points)
{
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < points; i++)
    {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void drawCircle(float r, float x_shift, float y_shift, float startAngle, float endAngle)
{
    glBegin(GL_POLYGON);
    int iterations = 1000;
    for (int i = 0; i <= iterations; ++i)
    {
        float A = startAngle + (i * (endAngle - startAngle)) / iterations;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + x_shift, y + y_shift);
    }
    glEnd();
}

void drawCircle(float x, float y, float radius)
{
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; ++i)
    {
        float angle = i * 2.0f * M_PI / segments;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void drawSquare(float centerX, float centerY, float sideLength)
{
    float halfSide = sideLength / 2.0;

    glBegin(GL_POLYGON);
    glVertex2f(centerX - halfSide, centerY + halfSide);
    glVertex2f(centerX + halfSide, centerY + halfSide);
    glVertex2f(centerX + halfSide, centerY - halfSide);
    glVertex2f(centerX - halfSide, centerY - halfSide);
    glEnd();
}

void drawEllipse(float x, float y, float xRadius, float yRadius, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; ++i)
    {
        float angle = i * 2.0f * M_PI / segments;
        float xPosition = x + xRadius * cos(angle);
        float yPosition = y + yRadius * sin(angle);
        glVertex2f(xPosition, yPosition);
    }
    glEnd();
}
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawStar(float x, float y, float outerRadius, float innerRadius, int points, int rotate = 0)
{
    float angle = M_PI / points;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 2 * points; ++i)
    {
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        float currentAngle = i * angle + rotate;
        glVertex2f(x + radius * cos(currentAngle), y + radius * sin(currentAngle));
    }
    glEnd();
}

void drawPlanet(Planet planet, GLfloat angle, GLfloat rotationAngle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[planet.id]);

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(planet.distance, 0.0, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);
    gluQuadricTexture(quad, 1);
    gluSphere(quad, planet.radius, 20, 20);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void drawOrbit(Planet planet)
{
    glDisable(GL_LIGHTING);
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(1);
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i)
    {
        GLfloat angle = i * M_PI / 180.0;
        GLfloat x = planet.distance * cos(angle);
        GLfloat y = planet.distance * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void updateSolarPlanetsRotation() {
        mercuryAngle += mercury.orbitSpeed * 1000.0;
        venusAngle += venus.orbitSpeed * 1000.0;
        earthAngle += earth.orbitSpeed * 1000.0;
        marsAngle += mars.orbitSpeed * 1000.0;
        jupiterAngle += jupiter.orbitSpeed * 1000.0;
        saturnAngle += saturn.orbitSpeed * 1000.0;
        uranusAngle += uranus.orbitSpeed * 1000.0;
        neptuneAngle += neptune.orbitSpeed * 1000.0;

        mercuryRotationAngle += mercury.rotationSpeed;
        venusRotationAngle += venus.rotationSpeed;
        earthRotationAngle += earth.rotationSpeed;
        marsRotationAngle += mars.rotationSpeed;
        jupiterRotationAngle += jupiter.rotationSpeed;
        saturnRotationAngle += saturn.rotationSpeed;
        uranusRotationAngle += uranus.rotationSpeed;
        neptuneRotationAngle += neptune.rotationSpeed;
}

void displaySolarModel()
{
    glEnable(GL_DEPTH_TEST); // Re-enable depth test
    glEnable(GL_LIGHTING);   // Re-enable lighting
    glEnable(GL_LIGHT0);     // Re-enable light0

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glLoadIdentity();

    // Set perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0, 800.0 / 600.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(8, 0, 5, 2.5, 0, 0, 0, 1, 5);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[9]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-10.0f, -20.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10.0f, -10.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10.0f, 10.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-10.0f, 10.0f, -1.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    if (isRotating)
    {
        updateSolarPlanetsRotation();
    }

    drawOrbit(mercury);
    drawOrbit(venus);
    drawOrbit(earth);
    drawOrbit(mars);
    drawOrbit(jupiter);
    drawOrbit(saturn);
    drawOrbit(uranus);
    drawOrbit(neptune);

    drawPlanet(sun, 0.0, 0.0);
    drawPlanet(mercury, mercuryAngle, mercuryRotationAngle);
    drawPlanet(venus, venusAngle, venusRotationAngle);
    drawPlanet(earth, earthAngle, earthRotationAngle);
    drawPlanet(mars, marsAngle, marsRotationAngle);
    drawPlanet(jupiter, jupiterAngle, jupiterRotationAngle);
    drawPlanet(saturn, saturnAngle, saturnRotationAngle);
    drawPlanet(uranus, uranusAngle, uranusRotationAngle);
    drawPlanet(neptune, neptuneAngle, neptuneRotationAngle);

    // Render the current displayed text
    for (size_t i = 0; i < textList.size(); ++i) {
        renderBitmapString(textPos[i][0], textPos[i][1], GLUT_BITMAP_HELVETICA_18, textList[i]);
    }

    glutSwapBuffers();
    glutPostRedisplay();
}

void displayDestinationPlanet()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[destinationPlanet.id]);

    glPushMatrix();
    glScalef(0 + (scaleFactor += 0.1), 0 + (scaleFactor += 0.1), 0);
    gluQuadricTexture(quad, 1);
    gluSphere(quad, destinationPlanet.radius, 20, 20);
    glPopMatrix();

    if (scaleFactor >= 100)
    {
        if (destinationPlanet.id == 1)
            glutDisplayFunc(displayVenusScene);
        else if (destinationPlanet.id == 4)
            glutDisplayFunc(displayJupyterScene);
        else if (destinationPlanet.id == 2)
            glutDisplayFunc(displayEarthScene);
    }

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
    glutPostRedisplay();
}

void star()
{
    if (showStar)
    {
        glColor3ub(255, 255, 255);
        drawStar(-38, 30, 1, 0.3, 5, 0);
        drawStar(-30, 30, 1, 0.3, 5, 0);
        drawStar(-20, 30, 1, 0.3, 5, 0);
        drawStar(-10, 30, 1, 0.3, 5, 0);
        drawStar(0, 30, 1, 0.3, 5, 0);
        drawStar(10, 30, 1, 0.3, 5, 0);
        drawStar(20, 30, 1, 0.3, 5, 0);
        drawStar(30, 30, 1, 0.3, 5, 0);
        drawStar(38, 30, 1, 0.3, 5, 0);

        drawStar(-32, 38, 1, 0.3, 5, 0);
        drawStar(-25, 38, 1, 0.3, 5, 0);
        drawStar(-15, 38, 1, 0.3, 5, 0);
        drawStar(-5, 38, 1, 0.3, 5, 0);
        drawStar(5, 38, 1, 0.3, 5, 0);
        drawStar(15, 38, 1, 0.3, 5, 0);
        drawStar(25, 38, 1, 0.3, 5, 0);
        drawStar(35, 38, 1, 0.3, 5, 0);
    }
}

void moon()
{
    // left moon
    glColor3ub(219, 179, 179);
    drawCircle(-27, 30, 6);
    // degin moon
    glColor3ub(219, 179, 160);
    drawCircle(-28, 31, 4);
    glColor3ub(219, 179, 150);
    drawCircle(-27, 31, 4);

    // middle moon
    glColor3ub(239, 123, 76);
    drawCircle(-0.7, 19.54, 4);
    // degin moon
    glColor3ub(239, 123, 56);
    drawCircle(-0.5, 20.54, 3);
    glColor3ub(239, 123, 46);
    drawCircle(-0.6, 20.54, 3);

    // right moon
    glColor3ub(225, 175, 234);
    drawCircle(25.36, 20.38, 10);
    // right moon
    glColor3ub(225, 175, 223);
    drawCircle(26.36, 19.38, 7);
    glColor3ub(225, 175, 213);
    drawCircle(24.36, 19.38, 7);

    // Draw ellipse
    glColor3ub(0, 175, 234);
    glPushMatrix();
    glTranslatef(24.36, 19.38, 0); // Translate to ellipse center
    glRotatef(40, 0, 0, 1);        // Rotate 45 degrees around z-axis
    drawEllipse(0, 0, 18, 1.5, 100);
    glPopMatrix();
}

void DayNight()
{
    if (showLayer)
    {
        // Enable blending for alpha transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Draw a semi-transparent black layer to cover the entire viewport
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // Set color to black with 50% opacity
        drawRectangle(-40, -20, 80, 60);   // Cover entire viewport

        // Disable blending after drawing
        glDisable(GL_BLEND);
    }
}

void ufo()
{
    glPushMatrix();                     // Save the current matrix state
    glScalef(ufoScale, ufoScale, 1.0f); // Apply scaling transformation

    glColor3ub(168, 204, 215);
    drawCircle(ufoX, ufoY, 4);
    glColor3ub(255, 69, 0);
    drawEllipse(ufoX, ufoY, 7, 1, 100);
    glColor3ub(255, 255, 0.5);
    drawSquare(ufoX + 3, ufoY, 1);
    drawSquare(ufoX, ufoY, 1);
    drawSquare(ufoX - 3, ufoY, 1);

    if (isFiring)
    {
        glColor3ub(255, 0, 0);
        drawCircle(bulletX, bulletY, 0.5f);
    }

    glPopMatrix(); // Restore the saved matrix state
}

void enemyUfo()
{
    if (enemyUfoHit)
    {
        return; // Invisible when hit
    }

    else
    {
        glColor3ub(168, 204, 215);
        drawCircle(enemyUfoX, enemyUfoY, 4);
        glColor3ub(128, 128, 128);
        drawEllipse(enemyUfoX, enemyUfoY, 7, 1, 100);
        glColor3ub(255, 255, 0.5);
        drawSquare(enemyUfoX + 3, enemyUfoY, 1);
        drawSquare(enemyUfoX, enemyUfoY, 1);
        drawSquare(enemyUfoX - 3, enemyUfoY, 1);
    }
}

void newEnemyUfo()
{
    if (newEnemyUfoHit)
    {
        // Invisible when hit
        return;
    }
    else
    {
        glColor3ub(168, 204, 215);
        drawCircle(newEnemyUfoX, newEnemyUfoY, 4);
        glColor3ub(0, 128, 128);
        drawEllipse(newEnemyUfoX, newEnemyUfoY, 7, 1, 100);
        glColor3ub(255, 255, 0.5);
        drawSquare(newEnemyUfoX + 3, newEnemyUfoY, 1);
        drawSquare(newEnemyUfoX, newEnemyUfoY, 1);
        drawSquare(newEnemyUfoX - 3, newEnemyUfoY, 1);
    }
}

void enemyUfo2()
{
    if (enemyUfo2Hit)
    {
        // Invisible when hit
        return;
    }
    else
    {
        glColor3ub(168, 204, 215);
        drawCircle(enemyUfo2X, enemyUfo2Y, 2); // Small size for enemyUfo2
        glColor3ub(255, 0, 255);
        drawEllipse(enemyUfo2X, enemyUfo2Y, 4, 0.5, 100); // Adjusted ellipse size for enemyUfo2
        glColor3ub(255, 255, 0.5);
        drawSquare(enemyUfo2X + 1.5, enemyUfo2Y, 0.5); // Adjusted square size for enemyUfo2
        drawSquare(enemyUfo2X, enemyUfo2Y, 0.5);       // Adjusted square size for enemyUfo2
        drawSquare(enemyUfo2X - 1.5, enemyUfo2Y, 0.5); // Adjusted square size for enemyUfo2
    }
}

void Poster(float x, float y)
{
    glColor3ub(168, 204, 215);
    drawCircle(x, y, 8);
    glColor3ub(128, 128, 128);
    drawEllipse(x, y, 17, 3, 100);
    glColor3ub(255, 255, 0.5);
    drawSquare(x + 7, y, 2);
    drawSquare(x, y, 2);
    drawSquare(x - 7, y, 2);

    glColor3ub(135, 206, 250);
    drawRectangle(-20, 20, 3, 0.5);
    drawRectangle(-19, 20.5, 3, 0.5);

    drawRectangle(20, 20, 3, 0.5);
    drawRectangle(19, 20.5, 3, 0.5);

    drawRectangle(-10, 23, 3, 0.5);
    drawRectangle(-11, 23.5, 3, 0.5);
    drawRectangle(10, 23, 3, 0.5);
    drawRectangle(11, 23.5, 3, 0.5);

    drawRectangle(20, 10, 3, 0.5);
    drawRectangle(19, 10.5, 3, 0.5);

    drawRectangle(10, 15, 3, 0.5);
    drawRectangle(11, 15.5, 3, 0.5);

    drawRectangle(15, 0, 3, 0.5);
    drawRectangle(16, 0.5, 3, 0.5);

    drawRectangle(25, -10, 3, 0.5);
    drawRectangle(24, -10.5, 3, 0.5);
}

void updateVenusScenePosterPosition()
{
    posterX += posterSpeed;
    if (posterX > 40.0f)
    {
        posterX = -40.0f; // Reset position when it reaches the right boundary
    }
}

void ground()
{
    // ground
    glColor3ub(0, 100, 0);
    drawRectangle(-40, -1, 80, 1);

    // building
    glColor3ub(47, 79, 79);
    drawRectangle(-40, 0, 5, 8);
    drawRectangle(-33, 0, 6, 10);
    drawRectangle(-25, 0, 4, 7);
    drawRectangle(-19, 0, 5, 12);
    drawRectangle(-8, 0, 5, 8);
    drawRectangle(0, 0, 10, 5);
    drawRectangle(15, 0, 5, 8);

    glColor3ub(25, 25, 112);
    drawRectangle(15, 0, 10, 5);
    drawRectangle(30, 0, 5, 8);
    drawRectangle(-38, 0, 5, 8);
    drawRectangle(-18, 0, 6, 10);
    drawRectangle(-10, 0, 4, 7);
    drawRectangle(-4, 0, 5, 12);
    drawRectangle(7, 0, 5, 8);

    // river
    glColor3ub(0, 191, 255);
    drawRectangle(-40, -5, 80, 4);

    // ground
    glColor3ub(105, 105, 105);
    drawRectangle(-40, -6, 80, 1);

    // road
    glColor3ub(128, 128, 128);
    drawRectangle(-40, -11, 80, 5);
    // road divider
    glColor3ub(255, 255, 255);
    drawRectangle(-40, -9, 2, 1);
    // Draw road divider 10 times with an x-offset
    for (int i = 0; i < 22; ++i)
    {
        drawRectangle(-40 + i * 4, -9, 2, 1); // Adjust x-coordinate
    }

    // Draw road light 20 times with an x-offset
    glColor3ub(0, 0, 0);
    for (int i = 0; i < 20; ++i)
    {
        drawRectangle(-38 + i * 10, -5.5, 0.5, 3); // Adjust x-coordinate
        glColor3ub(255, 255, 0);
        drawRectangle(-38.80 + i * 10, -3, 2, 0.5); // Adjust x-coordinate
        glColor3ub(0, 0, 0);                        // Reset color
    }

    // ground
    glColor3ub(105, 105, 105);
    drawRectangle(-40, -12, 80, 1);

    // mud ground for rail
    glColor3ub(139, 69, 19);
    drawRectangle(-40, -20, 80, 8);
    glColor3ub(160, 82, 45);
    for (int i = 0; i < 40; ++i)
    {
        drawRectangle(-40 + i * 3, -18, 2, 1); // Adjust x-coordinate
    }

    for (int i = 0; i < 4; ++i)
    {
        glColor3ub(169, 169, 169);
        drawRectangle(-20 + i * 8, -17, 7, 3); // Adjust x-coordinate
        glColor3ub(0, 0, 0);
        for (int i = 0; i < 4; ++i)
        {
            drawCircle(-18 + i * 8, -17, 1);
            drawCircle(-15 + i * 8, -17, 1);
        }
    }

    ufo();
}

void Intro()
{
    if (showIntro)
    {
        // Display intro screen
        glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glRasterPos2f(-15.0f, 0.0f);
        Poster(posterX, posterY); // Draw Poster at updateVenusScened position
        std::string introText = "Welcome to Planet War!";
        for (char const &c : introText)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }

        // Start the game after 2 seconds
        int currentTime = glutGet(GLUT_ELAPSED_TIME);
        if (currentTime - introEndTime > 1000)
        {
            showIntro = false;
        }
    }
    else
    {
        // Display the score
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(-38.0f, 38.0f);
        std::string scoreText = "Score: " + std::to_string(score);
        for (char const &c : scoreText)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        // Display game elements
        star();
        moon();
        DayNight();
        enemyUfo();
        newEnemyUfo();
        enemyUfo2();
        ground();
    }
}

void displayVenusScene()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-40, 40, -20, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(1.0f, 0.8f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Intro();

    glutSwapBuffers();

    glutPostRedisplay();
}

void handleSpecialKeypress(int key, int x, int y)
{
    if (destinationPlanet.id == 1)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            ufoY += ufoSpeed;
            break;
        case GLUT_KEY_DOWN:
            ufoY -= ufoSpeed;
            break;
        case GLUT_KEY_LEFT:
            ufoX -= ufoSpeed;
            break;
        case GLUT_KEY_RIGHT:
            ufoX += ufoSpeed;
            break;
        }
    }
    if (destinationPlanet.id == 4)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            roverPosY <= 10 ? roverPosY += roverSpeed : roverPosY;
            break;
        case GLUT_KEY_DOWN:
            roverPosY >= -26 ? roverPosY -= roverSpeed : roverPosY;
            break;
        case GLUT_KEY_LEFT:
            roverPosX <= -135 ? roverPosX = 35 : roverPosX -= roverSpeed;
            break;
        case GLUT_KEY_RIGHT:
            roverPosX >= 35 ? roverPosX = -135 : roverPosX += roverSpeed;
            break;
        }
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'e' && !lockDisplaySolarModel1)
    {
        // Switch to displayDestinationPlanet when 'e' is pressed and not in lockDisplaySolarModel1
        lockDisplaySolarModel1 = true;
        destinationPlanet = earth;
        scaleFactor = 0;
        glutDisplayFunc(displayDestinationPlanet);
    }
    else if (key == 'm' && !lockDisplaySolarModel1)
    {
        // Switch to displayDestinationPlanet when 'm' is pressed and not in lockDisplaySolarModel1
        lockDisplaySolarModel1 = true;
        destinationPlanet = mars;
        scaleFactor = 0;
        glutDisplayFunc(displayDestinationPlanet);
    }
    else if (key == 'v' && !lockDisplaySolarModel1)
    {
        // Switch to displayDestinationPlanet when 'm' is pressed and not in lockDisplaySolarModel1
        lockDisplaySolarModel1 = true;
        destinationPlanet = venus;
        scaleFactor = 0;
        glutDisplayFunc(displayDestinationPlanet);
    }
    else if (key == 'j' && !lockDisplaySolarModel1)
    {
        // Switch to displayDestinationPlanet when 'm' is pressed and not in lockDisplaySolarModel1
        lockDisplaySolarModel1 = true;
        destinationPlanet = jupiter;
        scaleFactor = 0;
        glutDisplayFunc(displayDestinationPlanet);
    }
    else if (key == 27 && lockDisplaySolarModel1)
    {
        // Switch back to displaySolarModel when 'Escape' is pressed and in lockDisplaySolarModel1
        lockDisplaySolarModel1 = false;
        glutDisplayFunc(displaySolarModel);
    }
    else if (key == 'n' || key == 'N')
    {
        isNight = !isNight;
        glutPostRedisplay(); // Request a redraw of the window
    }

    switch (key)
    {
    case 'f':
    case 'F':
        isFiring = true;
        bulletX = ufoX + 2.5f;
        bulletY = ufoY + 5.5f;
        break;

    case 'k':
    case 'K':
        // Move UFO diagonally up
        ufoX += ufoSpeed;
        ufoY += ufoSpeed;
        ufoScale -= 0.01f; // Adjust the scaling factor as needed
        break;
    case 'l':
    case 'L':
        // Shrink UFO until it disappears
        ufoX -= ufoSpeed;
        ufoY -= ufoSpeed;
        // Decrease UFO size (scaling)
        ufoScale += 0.01f; // Adjust the scaling factor as needed
        break;
    }
}

void handleMouseClick(int button, int state, int x, int y)
{
    if (destinationPlanet.id == 1) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            isFiring = true;
            bulletX = ufoX + 2.5f;
            bulletY = ufoY + 5.5f;
        }
        glutPostRedisplay();
    }

    if (destinationPlanet.id == 4) {
        if (!isSpaceShipStarted && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            isSpaceShipStarted = true;
            glutTimerFunc(10, updateJupiterScene, 0);
        }
        glutPostRedisplay();
    }
}

void updateVenusScene(int value)
{
    // Move enemy UFO left to right
    enemyUfoX += enemyUfoSpeed;
    if (enemyUfoX > 40.0f || enemyUfoX < -40.0f)
    {
        enemyUfoSpeed *= -1; // Change direction when hitting boundaries

        // Reset the position of the enemy UFO
        enemyUfoX = -40.0f;
        enemyUfoY = 30.0f;
        enemyUfoHit = false;
    }

    // Move enemyUfo2 from right to left
    enemyUfo2X += enemyUfo2Speed;
    if (enemyUfo2X < -40.0f || enemyUfo2X > 40.0f)
    {
        enemyUfo2Speed *= -1; // Change direction when hitting boundaries
        enemyUfo2X = 40.0f;   // Reset the x position when reaching the boundary
        enemyUfo2Y = 37.0f;   // Reset the y position
        enemyUfo2Hit = false; // Reset hit status
    }

    if (isFiring)
    {
        bulletY += bulletSpeed;

        // Check for collision with enemy UFO
        if (bulletX >= enemyUfoX && bulletX <= enemyUfoX + 5 &&
            bulletY >= enemyUfoY && bulletY <= enemyUfoY + 5)
        {
            enemyUfoHit = true; // Enemy UFO hit
            isFiring = false;   // Stop firing
            score++;            // Increment the score when an enemyUfo is hit
        }

        // Check for collision with enemyUfo2
        if (bulletX >= enemyUfo2X && bulletX <= enemyUfo2X + 5 &&
            bulletY >= enemyUfo2Y && bulletY <= enemyUfo2Y + 5)
        {
            enemyUfo2Hit = true; // enemyUfo2 hit
            isFiring = false;    // Stop firing
            score++;             // Increment the score when an enemyUfo is hit
        }

        if (bulletY > 100.0f)
        {
            isFiring = false;
        }
    }

    // UpdateVenusScene Poster position
    updateVenusScenePosterPosition();

    glutPostRedisplay();
    glutTimerFunc(10, updateVenusScene, 0);
}

void drawJupiterSun()
{
    glColor3ub(188, 115, 146);
    drawCircle(7.07, -35, 45, 0.0f, 2 * M_PI);
}

void drawJupiterPyramid()
{
    GLfloat pyramidV[][4][2] = {
        {{-45, 15}, {-37.72, 43.97}, {-35.56, 13.78}},
        {{-15, 50}, {-15, 7.8}, {-30, 10}}};

    glColor3ub(129, 88, 120);
    int numPyramids = sizeof(pyramidV) / sizeof(pyramidV[0]);
    for (int i = 0; i < numPyramids; i++)
    {
        drawPolygon(pyramidV[i], 3);
    }

    GLfloat pyramidShadeV[][4][2] = {
        {{-15, 50}, {-2.61, 11.27}, {-15, 7.8}},
        {{-37.72, 43.97}, {-32, 15}, {-35.56, 13.78}}};

    glColor3ub(46, 62, 47);
    int numPyramidShades = sizeof(pyramidShadeV) / sizeof(pyramidShadeV[0]);
    for (int i = 0; i < numPyramidShades; i++)
    {
        drawPolygon(pyramidShadeV[i], 3);
    }
}

void drawJupiterDomes()
{
    glColor3ub(129, 88, 120);

    drawCircle(15.5, 25, 0.0, 0.0f, M_PI);
    glColor3ub(255, 255, 255);
    drawCircle(15, 25, 0.0, 0.0f, M_PI);

    glColor3ub(129, 88, 120);
    drawCircle(15.5, 45, 0.0, 0.0f, M_PI);
    glColor3ub(255, 255, 255);
    drawCircle(15, 45, 0.0, 0.0f, M_PI);

    GLfloat domeStructuresLInes[][4][2] = {
        {{25, 15}, {20, 10}, {18, 6}, {17.88, 0}},
        {{25, 15}, {25, 10}, {25, 5}, {25, 0}},
        {{25, 15}, {28, 12}, {30, 10}, {31.9, 7.3}},
        {{45, 15}, {40, 10}, {38, 6}, {38, 0}},
        {{45, 15}, {45, 10}, {45, 5}, {45, 0}},
        {{45, 15}, {50, 10}, {52, 6}, {52, 0}},
    };
    int numStructures = sizeof(domeStructuresLInes) / sizeof(domeStructuresLInes[0]);

    glColor3ub(129, 88, 120);
    for (int i = 0; i < numStructures; i++)
    {
        int numVertices = sizeof(domeStructuresLInes[i]) / sizeof(domeStructuresLInes[i][0]);
        glLineWidth(6);
        drawLines(domeStructuresLInes[i], numVertices);
    }

    GLfloat domeStructuresPolygon[][4][2] = {
        {{6.78, -1.8}, {10, 0}, {38, 0}, {42.81, -2.06}},
        {{41.3, -1.28}, {38.0, 0}, {60, 0}, {61.16, -1.28}}};

    int numDomeStructurePoly = sizeof(domeStructuresPolygon) / sizeof(domeStructuresPolygon[0]);
    for (int i = 0; i < numDomeStructurePoly; i++)
    {
        drawPolygon(domeStructuresPolygon[i], 4);
    }
}

void drawJupiterPillars()
{
    GLfloat pillarV[][4][2] = {
        {{30, 10}, {30, 30}, {40, 30}, {40, 10}},
        {{45, 11.7}, {45, 25}, {55, 25}, {55, 11.7}},
        {{-5, 40}, {5, 40}, {5, 0}, {-5, 0}}};

    glColor3ub(129, 88, 120);
    int numPillars = sizeof(pillarV) / sizeof(pillarV[0]);
    for (int i = 0; i < numPillars; i++)
    {
        drawPolygon(pillarV[i], 4);
    }

    for (int i = 0; i < numPillars; i++)
    {
        drawPolygonOutline(pillarV[i], 4);
    }

    glColor3ub(129, 88, 120);
    GLfloat pillarStructure[][2] = {{28, 32}, {42, 32}, {42, 30}, {28, 30}};
    drawPolygon(pillarStructure, 4);

    GLfloat pillarShade[][4][2] = {
        {{-5, 40}, {-2, 42}, {8, 42}, {5, 40}},
        {{5, 40}, {8, 42}, {8, 2.3}, {5, 0}}};

    glColor3ub(46, 62, 47);
    int numPillarShade = sizeof(pillarShade) / sizeof(pillarShade[0]);
    for (int i = 0; i < numPillarShade; i++)
    {
        drawPolygon(pillarShade[i], 4);
    }
}

void drawJupiterHexagonalBuilding()
{
    GLfloat hexagonV[][7][2] = {
        {{30, 32}, {24, 40}, {30, 48}, {35, 50}, {40, 48}, {46, 40}, {40, 32}},
        {{45, 25}, {40, 30}, {40, 32}, {46.19, 40}, {55, 40}, {60, 32}, {55, 25}}};

    glColor3ub(151, 181, 220);
    int numHexagons = sizeof(hexagonV) / sizeof(hexagonV[0]);
    for (int i = 0; i < numHexagons; i++)
    {
        drawPolygon(hexagonV[i], 7);
    }

    glColor3ub(129, 88, 120);
    for (int i = 0; i < numHexagons; i++)
    {
        drawPolygonOutline(hexagonV[i], 7);
    }

    GLfloat structures[][6][2] = {
        {{24.74, 39}, {24, 40}, {24.74, 41}, {45.26, 41}, {46, 40}, {45.18, 39}},
        {{30, 48}, {34, 50}, {40, 48}, {34, 48}, {35, 48}, {34, 48}},
        {{42, 32}, {46.44, 32.}, {58.36, 32}, {60, 32}, {60, 30}, {42, 30}}};

    int numStructures = sizeof(structures) / sizeof(structures[0]);
    for (int i = 0; i < numStructures; i++)
    {
        drawPolygon(structures[i], 6);
    }

    drawLine(34, 48, 30, 41);
    drawLine(36, 48, 40, 41);
    drawLine(29, 41, 34, 32);
    drawLine(41, 41, 36, 32);
    drawLine(35, 48, 35, 32);
    drawLine(50, 40, 46.44, 32);
    drawLine(46.44, 32, 50, 25);
    drawLine(50, 25, 53.36, 32);
    drawLine(53.36, 32, 50, 40);
}

void drawJupiterRover()
{
    GLfloat polygon1[][2] = {
        {20, -20}, {46, -22}, {46, -30}, {20, -30}};
    glColor3ub(173, 170, 159);
    drawPolygon(polygon1, 4);

    glColor3f(1, 1, 1);
    drawCircle(3.62, 20, -30, 0.0f, 2 * M_PI);
    drawCircle(3.62, 33, -30, 0.0f, 2 * M_PI);
    drawCircle(3.62, 46, -30, 0.0f, 2 * M_PI);

    glColor3f(0, 0, 0);
    drawCircle(2.83, 20, -30, 0.0f, 2 * M_PI);
    drawCircle(2.83, 33, -30, 0.0f, 2 * M_PI);
    drawCircle(2.83, 46, -30, 0.0f, 2 * M_PI);

    drawLine(24, -24, 24, -22);
    drawLine(24, -22, 42, -23.5);
    drawLine(20, -22, 18, -22);
    drawLine(18, -22, 18, -20);
    drawLine(29.96, -20.7, 30, -18);
    drawLine(30, -18, 32, -16);

    GLfloat polygon2[][2] = {
        {17, -20}, {17, -18}, {17.5, -18}, {17.5, -19}, {18.5, -19}, {18.5, -18}, {19, -18}, {19, -20}};

    drawPolygon(polygon2, 8);

    drawLine(21.98, -20.15, 22, -17);
    drawCircle(1, 22, -17, 0.0f, 2 * M_PI);
    drawCircle(2, 22, -17, 0, M_PI);

    glColor3ub(77, 121, 166);
    GLfloat polygon3[][2] = {
        {29, -13}, {35, -13}, {35, -16}, {29, -16}};
    drawPolygon(polygon3, 4);
    glColor3f(0, 0, 0);
    drawPolygonOutline(polygon3, 4);
    drawLine(30.5, -13, 30.5, -16);
    drawLine(32, -13, 32, -16);
    drawLine(33.5, -13, 33.5, -16);

    drawLine(42.06, -21.7, 42, -16);
    drawLine(39, -16, 45, -16);
    drawCircle(1, 39, -16, 0.0f, 2 * M_PI);
    drawCircle(1, 42, -16, 0.0f, 2 * M_PI);
    drawCircle(1, 45, -16, 0.0f, 2 * M_PI);
}

void drawJupiterStructure1() {
    glColor3ub(47,59,45);
    GLfloat polygons1[][4][2] = {
        {{-91.71945, 34.15045},{-77.69827, 34.15045}, {-73.86435, 9.94201}, {-96.53923, 10.05155}},
        {{-96.53923, 10.05155}, {-73.86435, 9.94201}, {-71.45446, 3.91728}, {-101.13993, 3.91728}},
        {{-101.13993, 3.91728}, {-71.45446, 3.91728}, {-71.3994, 1.94621}, {-101.24947, 1.72647}},
        {{-101.24947, 1.72647}, {-71.3994, 1.94621}, {-71.19118, -15.03215}, {-101.16544, -15.03215}}
    };
    for (int i = 0; i < 4; i++) {
        drawPolygon(polygons1[i], 4);
    }


    glColor3ub(149,101,135);
    GLfloat polygons2[][4][2] = {
        {{-91.71945, 34.15045}, {-77.69827, 34.15045}, {-77.69827, 9.83247}, {-92.04807, 10.16109}},
        {{-96.53923, 10.05155}, {-73.86435, 9.94201}, {-73.31665, 4.02682}, {-98.18234, 3.91728}},
        {{-98.08, 1.72647}, {-74.28, 1.72647}, {-74.17865, -14.93257}, {-98.07839, -14.93257}},
        {{-101.22, -3.98}, {-101.22, -15.02}, {-105, -15.02}, {-105.04915, -6.96599}},
        {{-98.08, -4.18}, {-98.07839, -15.02}, {-103.12066, -15.02}, {-103.07024, -6.98029}},
        {{-74.24, -4.33}, {-74.24, -15.02}, {-69.35571, -15.02}, {-69.35571, -7.0483}},
        {{-71.32, -4.19}, {-67.02176, -7.0483}, {-67.02176, -15.02}, {-71.32, -15.02}}
    };

    for (int i = 0; i < 7; i++) {
        drawPolygon(polygons2[i], 4);
    }

    glColor3ub(47,59,45);
    GLfloat polygons3[][4][2] = {
        {{-95, -5}, {-92, -5.01442}, {-92, -15.02}, {-95, -15.02}},
        {{-91, -5}, {-88, -5.01442}, {-88, -15.02}, {-91, -15.02}},
        {{-87, -5}, {-84, -5.01442}, {-84, -15.02}, {-87, -15.02}},
        {{-83, -5}, {-80, -5.01442}, {-80, -15.02}, {-83, -15.02}},
        {{-79, -5}, {-77, -5.01442}, {-77, -15.02}, {-79, -15.02}}
    };
    for (int i = 0; i < 5; i++) {
        drawPolygon(polygons3[i], 4);
    }
}

void drawJupiterStructure2() {
    GLfloat polygons1[][4][2] = {
        {{-72.22248, 17.67364}, {-66, 20}, {-62, 20}, {-55.12658, 17.67364}},
        {{-66, 24.03302}, {-62, 24.03302}, {-62, 20}, {-66, 20}},
        {{-72.22248, 17.67364}, {-55.12658, 17.67364}, {-55, -15}, {-72.22248, -15}}
    };
    glColor3ub(211,189,197);
    for (int i = 0; i < 3; i++) {
        drawPolygon(polygons1[i], 4);
    }
    glColor3ub(149,101,135);
    for (int i = 0; i < 3; i++) {
        drawPolygonOutline(polygons1[i], 4);
    }

    glColor3ub(47,59,45);
    drawCircle(1.91, -64, 12, 0.0f, 2 * M_PI);

    glColor3ub(149,101,135);
    GLfloat polygons2[][4][2] = {
        {{-64, 12}, {-44, 12}, {-44, 11}, {-64, 11}},
        {{-46, 11}, {-44, 11}, {-44, 6}, {-46, 6}}
    };
    for (int i = 0; i < 2; i++) {
        drawPolygon(polygons2[i], 4);
    }
    
    glColor3ub(149,101,135);
    GLfloat polygons3[][4][2] = {
        {{-47, 6}, {-43, 6}, {-43, 3}, {-47, 3}},
        {{-48, 3}, {-42, 3}, {-40, 0}, {-50, 0}}, 
        { {-40, 0}, {-50, 0}, {-50, -15}, {-40, -15}}
    };
    for (int i = 0; i < 3; i++) {
        drawPolygon(polygons3[i], 4);
    }
    glColor3ub(47,59,45);
    for (int i = 0; i < 3; i++) {
        drawPolygonOutline(polygons3[i], 4);
    }
}

void drawJupiterGround() {
    glColor3ub(135,118,132);
    GLfloat groundV[][2] = {
        {-102, 20}, {85, 20}, {85, -40}, {-102, -40}
    };

    drawPolygon(groundV, 4);
}

void drawJupiterSpaceShip() {
    GLfloat polygon1[][2] = {{75, 10}, {91, 10}, {95, 5}, {71, 5}};
    glColor3ub(149,104,137);
    drawPolygon(polygon1, 4);

    GLfloat polygon2[][2] = {{78, 10}, {78, 12}, {88, 12}, {88, 10}};
    glColor3ub(41,49,39);
    drawPolygon(polygon2, 4);

    GLfloat polygon3[][2] = {{71, 5}, {95, 5}, {92, 2}, {74, 2}};
    glColor3ub(131,99,127);
    drawPolygon(polygon3, 4);

    glColor3ub(175,127,149);
    drawCircle(9, 83, 12, 0.0, M_PI);
}

void addRandomVariation(GLfloat vertices[][2], int vertexCount, float variation) {
    for (int i = 0; i < vertexCount; i++) {
        vertices[i][0] += (static_cast<float>(rand()) / RAND_MAX - 0.5f) * variation;
        vertices[i][1] += (static_cast<float>(rand()) / RAND_MAX - 0.5f) * variation;
    }
}

void drawJupiterSpaceshipFlame() {
    GLfloat flames[][7][2] = {
        {{74, 2}, {79, 2}, {78.37425, -4.96967}, {77.64304, -2.09705}, {77.2252, -7.47669}, {76.28507, -2.04482}, {75.76277, -4.81298}},
        {{74 + 12, 2}, {79 + 12, 2}, {78.37425 + 12, -4.96967}, {77.64304 + 12, -2.09705}, {77.2252 + 12, -7.47669}, {76.28507 + 12, -2.04482}, {75.76277 + 12, -4.81298}},
    };

    for (int i = 0; i < 2; i++) {
        addRandomVariation(flames[i], 7, 1.0f); // Add some random variation for dynamic effect

        // Draw the inner flame (brighter)
        glColor3f(1.0, 0.5, 0.0); // Orange
        drawPolygon(flames[i], 7);

        // Draw the outer flame (darker)
        glColor3f(0.5, 0.0, 0.0); // Dark red
        drawPolygonOutline(flames[i], 7);
    }
}


void jupyterScene() {
    drawJupiterGround();
    drawJupiterSun();
    drawJupiterPyramid();
    drawJupiterHexagonalBuilding();
    drawJupiterPillars();
    drawJupiterDomes();

    glPushMatrix();
    glTranslatef(10, 10, 0);
    drawJupiterStructure2();
    drawJupiterStructure1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(roverPosX, roverPosY, 0);
    drawJupiterRover();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-95 + jupiterSpaceShipPosX, -10 + jupiterSpaceShipPosY, 0);
    drawJupiterSpaceShip();
    if (isSpaceShipStarted) drawJupiterSpaceshipFlame();
    glPopMatrix();
}


void displayJupyterScene() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-102 , 85, -40, 60);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(69/255.0, 173/255.0, 148/255.0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    jupyterScene();

    glutSwapBuffers();

    glutPostRedisplay();
}

void updateJupiterScene(int value) {
    if (isSpaceShipStarted && jupiterSpaceShipPosY <= 45) {
        jupiterSpaceShipPosY += 0.1;
    }
    if (jupiterSpaceShipPosY >= 45) {
        jupiterSpaceShipPosX += 0.2;
        if (jupiterSpaceShipPosX >= 90) {
            jupiterSpaceShipPosX = -102;
        }
    }

    glutTimerFunc(10, updateJupiterScene, 0);
    glutPostRedisplay();
}

// drawEarthHouse 1,..U1
void drawEarthHouse1()
{
    glColor3ub(72, 61, 139);
    glPushMatrix();
    glTranslatef(-10, -8, 0);
    drawRectangle(-30, 13, 10, 24);
    glPopMatrix();

    // window inside drawEarthHouse1
    glColor3ub(0, 255, 0);
        glPushMatrix();
    glTranslatef(-7, 0, 0);
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
        glPopMatrix();
}

// drawEarthHouse 2....U2
void drawEarthHouse2()
{
    glColor3ub(128, 0, 128);
        glPushMatrix();
    glTranslatef(-10, -9, 0);
    drawRectangle(-18, 14, 10, 26);
    glPopMatrix();

    // window inside drawEarthHouse2
        glPushMatrix();
    glTranslatef(-6.5, 0, 0);
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
    glPopMatrix();
}
// drawEarthHouse 4
void drawEarthHouse4()
{
    glColor3ub(165, 42, 42);
        glPushMatrix();
    glTranslatef(-5, -10, 0);
    drawRectangle(-7, 14, 10, 26);
    glPopMatrix();


    // window inside drawEarthHouse2

    glColor3ub(0, 0, 205);
        glPushMatrix();
    glTranslatef(-1.5, -0, 0);
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
    glPopMatrix();
}
// drawEarthHouse 3 right ....U3
void drawEarthHouse3()
{
    glColor3ub(238, 232, 170);
        glPushMatrix();
    glTranslatef(-2, -9, 0);
    drawRectangle(30, 14, 10, 26);
    glPopMatrix();

    // window inside drawEarthHouse3
    glColor3ub(50, 205, 50);
        glPushMatrix();
    glTranslatef(1.5, 0, 0);
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
    glPopMatrix();
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
        glPushMatrix();
    glTranslatef(.5, -2, 0);
        drawRectangle(1, 6.5, 1.5, 12); // bottom
    glPopMatrix();
        drawRectangle(1, 12.5, 2.5, 7); // light box

    // light colour red
    glPushMatrix();
    glTranslatef(1.2, 3.5, 0);
    glColor3ub(255, 0, 0);
    drawCircle(1, 14.5, 1);
    // light colour yellow
    glColor3ub(255, 255, 0);
    drawCircle(1, 12.25, 1);
    // light colour green
    glColor3ub(0, 128, 0);
    drawCircle(1, 10, 1);
    glPopMatrix();
}

// drawEarthTree...U13
void drawEarthTree()
{

    // drawEarthTree body
    glColor3ub(184, 134, 11);
    glPushMatrix();
    glTranslatef(0, -2, 0);
    drawRectangle(3.5, 7, 1.5, 13); // left 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 0);
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
    glPopMatrix();
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
    glPushMatrix();
    glTranslatef(-4.5, 2, 0);
    drawRectangle(10, 6, 10.5, 3);
    glPopMatrix();
}

// drawEarthFlag...U16
void drawEarthFlag(float angle)
{
    // Calculate wave offset...UA1
    float waveOffset = sin(angle) * 2.0f;

    // DrawEarthFlag top rectangle with waving effect
    glColor3ub(0, 128, 0);
    glPushMatrix();
    glTranslatef(0, 4, 0);
    glBegin(GL_QUADS);
    glVertex2f(18, 17.5);
    glVertex2f(21 + 6, 17.5 + waveOffset);
    glVertex2f(21 + 6, 23);
    glVertex2f(18, 23);
    glEnd();

    // DrawEarthFlag circle
    glColor3ub(255, 0, 0);
    drawCircle(21.45, 20.25 + waveOffset / 2.0f, 2); // Adjust circle position based on wave offset
    glPopMatrix();
    // DrawEarthFlag pole
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(0, -6.5, 0);
    drawRectangle(18, 11.5, 1, 23);
    glPopMatrix();
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

    glPushMatrix();
    glTranslatef(-8, -5, 0);
        drawEarthRoad();
        river();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(drawEarthPlanePosX, 0, 0);
    drawEarthPlane();
    glPopMatrix();

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

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutCreateWindow("Solar System");
    glutDisplayFunc(displaySolarModel);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(handleSpecialKeypress);
    glutMouseFunc(handleMouseClick);
    init();

    glutTimerFunc(10, updateVenusScene, 0);
    glutTimerFunc(16, updateEarthScene, 0); // Start the timer with a delay of 16 ms

    glutMainLoop();
    return 0;
}
