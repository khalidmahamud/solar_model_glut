/*  Use left mouse button for starting the spaceship
    Use the arrowkeys for controlling the rover
*/

#include <SOIL/SOIL.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

float roverPosX = 0.0;
float roverPosY = 0.0;
float roverSpeed = 1.0;
float flameScaleFactor = 0.0;
bool isSpaceShipStarted = false;
float jupiterSpaceShipPosX = 0.0f;
float jupiterSpaceShipPosY = 0.0f;
void updateJupiterScene(int value);


void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw multiple lines
void drawLines(float vertices[][2], int n) {
    for (int i = 0; i < n - 1; ++i) {
        drawLine(vertices[i][0], vertices[i][1], vertices[i + 1][0], vertices[i + 1][1]);
    }
}

void drawPolygon(float vertices[][2], int points) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < points; i++) {
            glVertex2f(vertices[i][0], vertices[i][1]);
        }
    glEnd();
}

void drawPolygonOutline(float vertices[][2], int points) {
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < points; i++) {
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

void drawJupiterSuns() {
    glColor3ub(188,115,146);
    drawCircle(7.07, -35, 45, 0.0f, 2 * M_PI);
}

void drawJupiterPyramids() {
    GLfloat pyramidV[][4][2] = {
        {{-45, 15}, {-37.72, 43.97}, {-35.56, 13.78}},
        {{-15, 50}, {-15, 7.8}, {-30, 10}}
    };

    glColor3ub(129,88,120);
    int numPyramids = sizeof(pyramidV) / sizeof(pyramidV[0]);
    for (int i = 0; i < numPyramids; i++) {
        drawPolygon(pyramidV[i], 3);
    }

    GLfloat pyramidShadeV[][4][2] = {
        {{-15, 50}, {-2.61, 11.27}, {-15, 7.8}},
        {{-37.72, 43.97}, {-32, 15}, {-35.56, 13.78}}
    };

    glColor3ub(46,62,47);
    int numPyramidShades = sizeof(pyramidShadeV) / sizeof(pyramidShadeV[0]);
    for (int i = 0; i < numPyramidShades; i++) {
        drawPolygon(pyramidShadeV[i], 3);
    }
}

void drawJupiterDomes() {
    glColor3ub(129,88,120);
    
    drawCircle(15.5, 25, 0.0, 0.0f, M_PI);
    glColor3ub(255,255,255);
    drawCircle(15, 25, 0.0, 0.0f, M_PI);

    glColor3ub(129,88,120);
    drawCircle(15.5, 45, 0.0, 0.0f, M_PI);
    glColor3ub(255,255,255);
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
    for (int i = 0; i < numStructures; i++) {
        int numVertices = sizeof(domeStructuresLInes[i]) / sizeof(domeStructuresLInes[i][0]);
        glLineWidth(6);
        drawLines(domeStructuresLInes[i], numVertices);
    }

    GLfloat domeStructuresPolygon[][4][2] = {
        {{6.78, -1.8}, {10, 0}, {38, 0}, {42.81, -2.06}},
        {{41.3, -1.28}, {38.0, 0}, {60, 0}, {61.16, -1.28}}
    };

    int numDomeStructurePoly = sizeof(domeStructuresPolygon) / sizeof(domeStructuresPolygon[0]);
    for (int i = 0; i < numDomeStructurePoly; i++) {
        drawPolygon(domeStructuresPolygon[i], 4);
    }
}

void drawJupiterPillars() {
    GLfloat pillarV[][4][2] = {
        {{30, 10}, {30, 30}, {40, 30}, {40, 10}},
        {{45, 11.7}, {45, 25}, {55, 25}, {55, 11.7}}, 
        {{-5, 40}, {5, 40}, {5, 0}, {-5, 0}}
    };

    glColor3ub(129,88,120);
    int numPillars = sizeof(pillarV) / sizeof(pillarV[0]);
    for (int i = 0; i < numPillars; i++) {
        drawPolygon(pillarV[i], 4);
    }

    for (int i = 0; i < numPillars; i++) {
        drawPolygonOutline(pillarV[i], 4);
    }

    glColor3ub(129,88,120);
    GLfloat pillarStructure[][2] = {{28, 32}, {42, 32}, {42, 30}, {28, 30}};
    drawPolygon(pillarStructure, 4); 

    GLfloat pillarShade[][4][2] = {
        {{-5, 40}, {-2, 42}, {8, 42}, {5, 40}},
        {{5, 40}, {8, 42}, {8, 2.3}, {5, 0}}
    };

    glColor3ub(46,62,47);
    int numPillarShade = sizeof(pillarShade) / sizeof(pillarShade[0]);
    for (int i = 0; i < numPillarShade; i++) {
        drawPolygon(pillarShade[i], 4);
    }
}

void drawJupiterHexagonalBuildings() {
    GLfloat hexagonV[][7][2] = {
        {{30, 32}, {24, 40}, {30, 48}, {35, 50}, {40, 48}, {46, 40}, {40, 32}},
        {{45, 25}, {40, 30}, {40, 32}, {46.19, 40}, {55, 40}, {60, 32}, {55, 25}}
    };

    glColor3ub(151,181,220);
    int numHexagons = sizeof(hexagonV) / sizeof(hexagonV[0]);
    for (int i = 0; i < numHexagons; i++) {
        drawPolygon(hexagonV[i], 7);
    }

    glColor3ub(129,88,120);
    for (int i = 0; i < numHexagons; i++) {
        drawPolygonOutline(hexagonV[i], 7);
    }

    GLfloat structures[][6][2] = {
        {{24.74, 39}, {24, 40}, {24.74, 41}, {45.26, 41}, {46, 40}, {45.18, 39}},
        {{30, 48}, {34, 50}, {40, 48}, {34, 48}, {35, 48}, {34, 48}},
        {{42, 32}, { 46.44, 32.}, {58.36, 32}, {60, 32}, {60, 30}, {42, 30}}
    };

    int numStructures = sizeof(structures) / sizeof(structures[0]);
    for (int i = 0; i < numStructures; i++) {
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

void drawJupiterRover() {
    GLfloat polygon1[][2] = {
        {20, -20}, {46, -22}, {46, -30}, {20, -30}
    };
    glColor3ub(173,170,159);
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
        {17, -20}, {17, -18}, {17.5, -18}, {17.5, -19}, {18.5, -19}, {18.5, -18}, {19, -18}, {19, -20}
    };

    drawPolygon(polygon2, 8);

    drawLine(21.98, -20.15, 22, -17);
    drawCircle(1, 22, -17, 0.0f, 2 * M_PI);
    drawCircle(2, 22, -17, 0, M_PI);

    glColor3ub(77,121,166);
    GLfloat polygon3[][2] = {
        {29, -13}, {35, -13}, {35, -16}, {29, -16}
    };
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
    drawJupiterSuns();
    drawJupiterPyramids();
    drawJupiterHexagonalBuildings();
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

void handleSpecialKeypress(int key, int x, int y)
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
    glutPostRedisplay();
}

void handleMouseClick(int button, int state, int x, int y)
{
    if (!isSpaceShipStarted && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        isSpaceShipStarted = true;
        glutTimerFunc(10, updateJupiterScene, 0);
    }
    glutPostRedisplay();
}

void updateJupiterScene(int value) {
    if (isSpaceShipStarted && jupiterSpaceShipPosY <= 45) {
        jupiterSpaceShipPosY += 0.1;
    }
    if (jupiterSpaceShipPosY >= 45) {
        jupiterSpaceShipPosX += 0.1;
        if (jupiterSpaceShipPosX >= 90) {
            jupiterSpaceShipPosX = -102;
        }
    }

    glutTimerFunc(10, updateJupiterScene, 0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutCreateWindow("Solar System");
    glutDisplayFunc(displayJupyterScene);

    glutSpecialFunc(handleSpecialKeypress);
    glutMouseFunc(handleMouseClick);

    glutMainLoop(); 
    return 0;
}