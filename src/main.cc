#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "control.hh"
#include "rendering.hh"

int
Main(int argc, char** argv){
    char mode_string[20];
    sprintf(mode_string, "%dx%d:32@144", WIDTH, HEIGHT);

    // Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Test Window");

    // Configuration
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_POINT_SMOOTH);

    // Control Functions
    glutKeyboardFunc(KeyboardStandardDownEventHandler);
    glutKeyboardUpFunc(KeyboardStandardUpEventHandler);
    glutSpecialFunc(KeyboardSpecialDownEventHandler);
    glutSpecialUpFunc(KeyboardSpecialUpEventHandler);
    glutMouseFunc(MouseEventHandler);
    // Game Functinos
    glutDisplayFunc(RenderDisplay);
    glutTimerFunc(7, UpdateScreen, 7);

    // Go
    glutGameModeString(mode_string);
    glutFullScreen();
    glutMainLoop();

    return 0;
}




int main(int argc, char** argv){return(Main(argc, argv));}
