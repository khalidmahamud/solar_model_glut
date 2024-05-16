#include <GL/glut.h>
#include <math.h>
#include <string>
#include <iostream>
#include "trial2.h"

/*
                            ==============================
                            ||    Name: Md Adlul Islam  ||
                            ||    Id: 22-46598-1        ||
                            ||    Computer graphics     ||
                            ==============================

button for this game:
for moving = up/down/left/right arrow
firring= Mouse left key or (keyboard "F" key)
flying UFO: K and L
Day-Night view: N

*/

void handleMouseClick(int button, int state, int x, int y);
void updateVenusScene(int value);
void handleSpecialKeypress(int key, int x, int y);
void handleKeypress(unsigned char key, int x, int y);

// Global variables
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

int score = 0; // Variable to hold the score

// Variables for intro
bool showIntro = true;
int introEndTime = 0;


float posterX = 0.0f; // Initial x position of the Poster
float posterY = 10.0f;   // Y position of the Poster (you can adjust this as needed)
float posterSpeed = 0.3f; // Speed of the Poster movement


bool showLayer = false;
bool showStar = false;


void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawCircle(float x, float y, float radius) {
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0f * M_PI / segments;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void drawSquare(float centerX, float centerY, float sideLength) {
    float halfSide = sideLength / 2.0;

    glBegin(GL_POLYGON);
    glVertex2f(centerX - halfSide, centerY + halfSide);
    glVertex2f(centerX + halfSide, centerY + halfSide);
    glVertex2f(centerX + halfSide, centerY - halfSide);
    glVertex2f(centerX - halfSide, centerY - halfSide);
    glEnd();
}


void drawEllipse(float x, float y, float xRadius, float yRadius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0f * M_PI / segments;
        float xPosition = x + xRadius * cos(angle);
        float yPosition = y + yRadius * sin(angle);
        glVertex2f(xPosition, yPosition);
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


void drawStar(float x, float y, float outerRadius, float innerRadius, int points, int rotate = 0) {
    float angle = M_PI / points;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 2 * points; ++i) {
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        float currentAngle = i * angle + rotate;
        glVertex2f(x + radius * cos(currentAngle), y + radius * sin(currentAngle));
    }
    glEnd();
}



float ufoScale = 1.0f; // Global variable to control UFO scaling

void star() {
    if (showStar) {
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

void moon() {
    // left moon
    glColor3ub(219, 179, 179);
    drawCircle(-27, 30, 6);
    //degin moon
    glColor3ub(219, 179, 160);
    drawCircle(-28, 31, 4);
    glColor3ub(219, 179, 150);
    drawCircle(-27, 31, 4);

    //middle moon
    glColor3ub(239, 123, 76);
    drawCircle(-0.7, 19.54, 4);
    //degin moon
    glColor3ub(239, 123, 56);
    drawCircle(-0.5, 20.54, 3);
    glColor3ub(239, 123, 46);
    drawCircle(-0.6, 20.54, 3);

    //right moon
    glColor3ub(225, 175, 234);
    drawCircle(25.36, 20.38, 10);
    //right moon
    glColor3ub(225, 175, 223);
    drawCircle(26.36, 19.38, 7);
    glColor3ub(225, 175, 213);
    drawCircle(24.36, 19.38, 7);



    // Draw ellipse
    glColor3ub(0, 175, 234);
    glPushMatrix();
    glTranslatef(24.36, 19.38, 0); // Translate to ellipse center
    glRotatef(40, 0, 0, 1); // Rotate 45 degrees around z-axis
    drawEllipse(0, 0, 18, 1.5, 100);
    glPopMatrix();

}


void DayNight()
{
    if (showLayer) {
        // Enable blending for alpha transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Draw a semi-transparent black layer to cover the entire viewport
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // Set color to black with 50% opacity
        drawRectangle(-40, -20, 80, 60); // Cover entire viewport

        // Disable blending after drawing
        glDisable(GL_BLEND);
    }
}




void ufo() {
    glPushMatrix(); // Save the current matrix state
    glScalef(ufoScale, ufoScale, 1.0f); // Apply scaling transformation

    glColor3ub(168, 204, 215);
    drawCircle(ufoX, ufoY, 4);
    glColor3ub(255,69,0);
    drawEllipse(ufoX, ufoY, 7, 1, 100);
    glColor3ub(255, 255, 0.5);
    drawSquare(ufoX + 3, ufoY, 1);
    drawSquare(ufoX, ufoY, 1);
    drawSquare(ufoX - 3, ufoY, 1);

    if (isFiring) {
        glColor3ub(255, 0, 0);
        drawCircle(bulletX, bulletY, 0.5f);
    }

    glPopMatrix(); // Restore the saved matrix state
}


void enemyUfo() {
    if (enemyUfoHit) {
        return;// Invisible when hit
    }
        
     else {
        glColor3ub(168,204,215);
        drawCircle(enemyUfoX, enemyUfoY, 4);
        glColor3ub(128,128,128);
        drawEllipse(enemyUfoX, enemyUfoY, 7, 1, 100);
        glColor3ub(255,255,0.5);
        drawSquare(enemyUfoX+3, enemyUfoY,1);
        drawSquare(enemyUfoX, enemyUfoY,1);
        drawSquare(enemyUfoX-3, enemyUfoY,1);
    }
}

void newEnemyUfo() {
    if (newEnemyUfoHit) {
        // Invisible when hit
        return;
    } else {
        glColor3ub(168,204,215);
        drawCircle(newEnemyUfoX, newEnemyUfoY, 4);
        glColor3ub(0,128,128);
        drawEllipse(newEnemyUfoX, newEnemyUfoY, 7, 1, 100);
        glColor3ub(255,255,0.5);
        drawSquare(newEnemyUfoX+3, newEnemyUfoY,1);
        drawSquare(newEnemyUfoX, newEnemyUfoY,1);
        drawSquare(newEnemyUfoX-3, newEnemyUfoY,1);
    }
}

void enemyUfo2() {
    if (enemyUfo2Hit) {
        // Invisible when hit
        return;
    } else {
        glColor3ub(168,204,215);
        drawCircle(enemyUfo2X, enemyUfo2Y, 2); // Small size for enemyUfo2
        glColor3ub(255,0,255);
        drawEllipse(enemyUfo2X, enemyUfo2Y, 4, 0.5, 100); // Adjusted ellipse size for enemyUfo2
        glColor3ub(255,255,0.5);
        drawSquare(enemyUfo2X+1.5, enemyUfo2Y,0.5); // Adjusted square size for enemyUfo2
        drawSquare(enemyUfo2X, enemyUfo2Y,0.5); // Adjusted square size for enemyUfo2
        drawSquare(enemyUfo2X-1.5, enemyUfo2Y,0.5); // Adjusted square size for enemyUfo2
    }
}

void Poster(float x, float y) {
    glColor3ub(168,204,215);
    drawCircle(x, y, 8);
    glColor3ub(128,128,128);
    drawEllipse(x, y, 17, 3, 100);
    glColor3ub(255,255,0.5);
    drawSquare(x+7, y,2);
    drawSquare(x, y,2);
    drawSquare(x-7, y,2);

    glColor3ub(135,206,250);
    drawRectangle(-20,20,3,0.5);
    drawRectangle(-19,20.5,3,0.5);

    drawRectangle(20,20,3,0.5);
    drawRectangle(19,20.5,3,0.5);

    drawRectangle(-10,23,3,0.5);
    drawRectangle(-11,23.5,3,0.5);
    drawRectangle(10,23,3,0.5);
    drawRectangle(11,23.5,3,0.5);

    drawRectangle(20,10,3,0.5);
    drawRectangle(19,10.5,3,0.5);

    drawRectangle(10,15,3,0.5);
    drawRectangle(11,15.5,3,0.5);

    drawRectangle(15,0,3,0.5);
    drawRectangle(16,0.5,3,0.5);

    drawRectangle(25,-10,3,0.5);
    drawRectangle(24,-10.5,3,0.5);





}
void updateVenusScenePosterPosition() {
    posterX += posterSpeed;
    if (posterX > 40.0f) {
        posterX = -40.0f; // Reset position when it reaches the right boundary
    }
}
void ground() {
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
    for (int i = 0; i < 22; ++i) {
        drawRectangle(-40 + i * 4, -9, 2, 1); // Adjust x-coordinate
    }

    // Draw road light 20 times with an x-offset
    glColor3ub(0, 0, 0);
    for (int i = 0; i < 20; ++i) {
        drawRectangle(-38 + i * 10, -5.5, 0.5, 3); // Adjust x-coordinate
        glColor3ub(255, 255, 0);
        drawRectangle(-38.80 + i * 10, -3, 2, 0.5); // Adjust x-coordinate
        glColor3ub(0, 0, 0); // Reset color
    }

    // ground
    glColor3ub(105, 105, 105);
    drawRectangle(-40, -12, 80, 1);

    // mud ground for rail
    glColor3ub(139, 69, 19);
    drawRectangle(-40, -20, 80, 8);
    glColor3ub(160, 82, 45);
    for (int i = 0; i < 40; ++i) {
        drawRectangle(-40 + i * 3, -18, 2, 1); // Adjust x-coordinate
    }

    for (int i = 0; i < 4; ++i) {
        glColor3ub(169, 169, 169);
        drawRectangle(-20 + i * 8, -17, 7, 3); // Adjust x-coordinate
        glColor3ub(0, 0, 0);
        for (int i = 0; i < 4; ++i) {
            drawCircle(-18 + i * 8, -17, 1);
            drawCircle(-15 + i * 8, -17, 1);
        }
    
    }

    
    ufo();
    glFlush();
}


void Intro()
{
    if (showIntro) {
        // Display intro screen
        glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glRasterPos2f(-15.0f, 0.0f);
         Poster(posterX, posterY); // Draw Poster at updateVenusScened position
        std::string introText = "Welcome to Planet War!";
        for (char const &c: introText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }

        // Start the game after 2 seconds
        int currentTime = glutGet(GLUT_ELAPSED_TIME);
        if (currentTime - introEndTime > 1000) {
            showIntro = false;
        }
    } else {
         // Display the score
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(-38.0f, 38.0f);
        std::string scoreText = "Score: " + std::to_string(score);
        for (char const &c: scoreText) {
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


void displayPlanetScene() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-40, 40, -20, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.5f, 1.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);
    glutMouseFunc(handleMouseClick);

    // Start intro timer

    Intro();

    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
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

        case 'N':
        case 'n':
            showLayer = !showLayer; // Toggle the transparent black layer
            showStar = !showStar; // Toggle the visibility of the star
            glutPostRedisplay(); // Request a redraw to updateVenusScene the display
            break;
    }
    glutPostRedisplay();
}



void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
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
    glutPostRedisplay();
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isFiring = true;
        bulletX = ufoX + 2.5f;
        bulletY = ufoY + 5.5f;
    }
    glutPostRedisplay();
}

void updateVenusScene(int value) {
    // Move enemy UFO left to right
    enemyUfoX += enemyUfoSpeed;
    if (enemyUfoX > 40.0f || enemyUfoX < -40.0f) {
        enemyUfoSpeed *= -1; // Change direction when hitting boundaries
        
        // Reset the position of the enemy UFO
        enemyUfoX = -40.0f;
        enemyUfoY = 30.0f;
        enemyUfoHit = false;      
    }
    
    // Move enemyUfo2 from right to left
    enemyUfo2X += enemyUfo2Speed;
    if (enemyUfo2X < -40.0f || enemyUfo2X > 40.0f) {
        enemyUfo2Speed *= -1; // Change direction when hitting boundaries
        enemyUfo2X = 40.0f; // Reset the x position when reaching the boundary
        enemyUfo2Y = 37.0f; // Reset the y position
        enemyUfo2Hit = false; // Reset hit status
    }

    if (isFiring) {
        bulletY += bulletSpeed;
        
        // Check for collision with enemy UFO
        if (bulletX >= enemyUfoX && bulletX <= enemyUfoX + 5 &&
            bulletY >= enemyUfoY && bulletY <= enemyUfoY + 5) {
            enemyUfoHit = true; // Enemy UFO hit
            isFiring = false; // Stop firing
            score++; // Increment the score when an enemyUfo is hit
        }

        // Check for collision with enemyUfo2
        if (bulletX >= enemyUfo2X && bulletX <= enemyUfo2X + 5 &&
            bulletY >= enemyUfo2Y && bulletY <= enemyUfo2Y + 5) {
            enemyUfo2Hit = true; // enemyUfo2 hit
            isFiring = false; // Stop firing
            score++; // Increment the score when an enemyUfo is hit
        }
        
        if (bulletY > 100.0f) {
            isFiring = false;
        }
    }

    
    // UpdateVenusScene Poster position
    updateVenusScenePosterPosition();
    
    glutPostRedisplay();
    glutTimerFunc(10, updateVenusScene, 0);
     }



// int main(int argc, char** argv) {
//     glutInit(&argc, argv);
//     int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//     int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//     glutInitWindowSize(screenWidth, screenHeight);
//     glutCreateWindow("Planet Scene");
//     glutInitWindowPosition(0, 0);
//     glutDisplayFunc(displayPlanetScene);
//     glutKeyboardFunc(handleKeypress);
//     glutSpecialFunc(handleSpecialKeypress);
//     glutMouseFunc(handleMouseClick);


//     // Start intro timer
//     introEndTime = glutGet(GLUT_ELAPSED_TIME);
//     glutTimerFunc(10, updateVenusScene, 0);
//     glutMainLoop();
//     return 0;
// }