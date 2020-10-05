#include "rendering.hh"
#include <GL/freeglut.h>

int WIDTH;
int HEIGHT;

void
RenderDisplay(void){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void
UpdateScreen(int time){
    WIDTH = glutGet(GLUT_WINDOW_WIDTH);
    HEIGHT = glutGet(GLUT_WINDOW_HEIGHT);

    glutPostRedisplay();
    glutSwapBuffers();
    gluOrtho2D(0, WIDTH, HEIGHT, 0);

    glutTimerFunc(time, UpdateScreen, time);
}