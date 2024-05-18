#include <GL/glut.h>
#include <SOIL/SOIL.h> // Include SOIL for texture loading
#include <cmath>

struct Planet {
    int id;
    GLfloat radius;
    GLfloat distance;
    // GLfloat color[3];
    GLfloat orbitSpeed; // New field for orbit speed
    GLfloat rotationSpeed; // New field for rotation speed (day and night)
};

GLuint textures[10]; // Array to store texture IDs for each planet

GLUquadric *quad;

void loadTextures() {
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

Planet mercury = { 0, 0.05, 0.4, 1.0 / 88.0, 1.0 }; // 1/88 of Earth's orbit speed, 1000 times faster
Planet venus = { 1, 0.12, 0.7, 1.0 / 225.0, 1.0 }; // 1/225 of Earth's orbit speed, 1000 times faster
Planet earth = { 2, 0.13, 1.0, 1.0 / 1000.0, 1.0 }; // Earth's orbit speed, 1000 times faster
Planet mars = { 3, 0.07, 1.5, 1.0 / 687.0, 1.0 }; // 1/687 of Earth's orbit speed, 1000 times faster
Planet jupiter = { 4, 0.3, 2.5, 1.0 / 4333.0, 1.0 }; // 1/4333 of Earth's orbit speed, 1000 times faster
Planet saturn = { 5, 0.25, 3.5, 1.0 / 10759.0, 1.0 }; // 1/10759 of Earth's orbit speed, 1000 times faster
Planet uranus = { 6, 0.2, 4.5, 1.0 / 30685.0, 1.0 }; // 1/30685 of Earth's orbit speed, 1000 times faster
Planet neptune = { 7, 0.18, 5.5, 1.0 / 60190.0, 1.0 }; // 1/60190 of Earth's orbit speed, 1000 times faster
Planet sun = { 8, 0.3, 0, 0.0, 0.0 }; // The sun doesn't move

GLfloat light_position[] = { 0.0, 0.0, 5.0, 0.0 }; // Adjust light position
GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // Ambient light color
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // Diffuse light color
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular light color

GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 }; // Ambient material color
GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // Diffuse material color
GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular material color
GLfloat material_shininess[] = { 50.0 }; // Material shininess

void init(void) {
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


void drawPlanet(Planet planet, GLfloat angle, GLfloat rotationAngle) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[planet.id]); // Bind the texture for the current planet

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0); // Rotate around the sun
    glTranslatef(planet.distance, 0.0, 0.0); // Move along x-axis
    glRotatef(rotationAngle, 0.0, 0.0, 1.0); // Rotate around its own axis (day and night)
    
    gluQuadricTexture(quad,1);
    gluSphere(quad, planet.radius, 20, 20);
    
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void drawOrbit(Planet planet) {
    glDisable(GL_LIGHTING); // Disable lighting
    glColor3f(0.3, 0.3, 0.3); // Set color without material properties
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i) {
        GLfloat angle = i * M_PI / 180.0;
        GLfloat x = planet.distance * cos(angle);
        GLfloat y = planet.distance * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING); // Re-enable lighting
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    gluLookAt(8, 0, 5, 2.5, 0, 0, 0, 1, 5);

    // Draw background star texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[9]); // Bind the stars texture

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -20.0f, 2.0f); // Bottom-left corner
    glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, -10.0f, -1.0f); // Bottom-right corner
    glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 10.0f, -1.0f); // Top-right corner
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f, 10.0f, -1.0f); // Top-left corner
    glEnd();

    glDisable(GL_TEXTURE_2D); // Disable texture after drawing the background

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



    // Draw orbits first
    drawOrbit(mercury);
    drawOrbit(venus);
    drawOrbit(earth);
    drawOrbit(mars);
    drawOrbit(jupiter);
    drawOrbit(saturn);
    drawOrbit(uranus);
    drawOrbit(neptune);

    // Draw planets with updated rotation angles
    drawPlanet(sun, 0.0, 0.0);
    drawPlanet(mercury, mercuryAngle, mercuryRotationAngle);
    drawPlanet(venus, venusAngle, venusRotationAngle);
    drawPlanet(earth, earthAngle, earthRotationAngle);
    drawPlanet(mars, marsAngle, marsRotationAngle);
    drawPlanet(jupiter, jupiterAngle, jupiterRotationAngle);
    drawPlanet(saturn, saturnAngle, saturnRotationAngle);
    drawPlanet(uranus, uranusAngle, uranusRotationAngle);
    drawPlanet(neptune, neptuneAngle, neptuneRotationAngle);

    glutSwapBuffers();
    glutPostRedisplay(); // Redraw the scene continuously
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutCreateWindow("Solar System");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}