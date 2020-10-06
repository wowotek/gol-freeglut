#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "control"
#include "rendering"

int
Main(int argc, char** argv){
    char mode_string[20];
    sprintf(mode_string, "%dx%d:32@144", WIDTH, HEIGHT);

    // Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Test Window");

    // Configuration
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_POINT_SMOOTH);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
    glutGameModeString(mode_string);
    glutFullScreen();

    // Control Functions
    glutKeyboardFunc(KeyboardStandardDownEventHandler);
    glutKeyboardUpFunc(KeyboardStandardUpEventHandler);
    glutSpecialFunc(KeyboardSpecialDownEventHandler);
    glutSpecialUpFunc(KeyboardSpecialUpEventHandler);
    glutMouseFunc(MouseEventHandler);

    // Game Functinos
    glutDisplayFunc(RenderDisplay);
    glutTimerFunc(9, UpdateScreen, 9);

    // Go
    InitGame();
    glutMainLoop();

    return 0;
}




int main(int argc, char** argv){return(Main(argc, argv));}
