#include <iostream>
#include <vector>
#include <chrono>
#include <GL/freeglut.h>

#include "rendering"
#include "cell"

int WIDTH = 1920;
int HEIGHT = 1080;
int cell_size = 8;

std::vector<Cell*> * cells = new std::vector<Cell*>();

void
InitGame(){
    // Free last Object
    for(unsigned int i=0; i<cells->size(); i++){
        free(cells->at(i));
    }
    free(cells);
    cells = new std::vector<Cell*>();


    srand(time(NULL));
    int populationSize = (rand() % 101 + 1) - 1;
    srand(time(NULL));
    for(unsigned int y=0; y<1080; y+=cell_size){
        for(unsigned int x=0; x<1920; x+=cell_size){
            Cell * nc = new Cell(x, y, cell_size);
            
            int probs = (rand() % 101 + 1) - 1;
            if(probs >= 40) nc->nextState = true;

            cells->push_back(nc);
        }
    }

    std::cout << "Game Resetted with population density : " << populationSize << std::endl;
}

void
RenderDisplay(void){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    for(unsigned int i=0; i<cells->size(); i++){
        cells->at(i)->draw();
    }

    glutSwapBuffers();
    glFlush();
}

std::vector<int> activeCellslog;
int lastAverage = 0;
int cycles = 0;
double count = 0;

void
UpdateScreen(int time){
    for(unsigned int i=0; i<cells->size(); i++){
        cells->at(i)->checkNeighbours(cells, i, WIDTH/cell_size, HEIGHT/cell_size);
    }
    for(unsigned int i=0; i<cells->size(); i++){
        cells->at(i)->step();
    }

    int activeCells = 0;
    for(unsigned int i = 0; i<cells->size(); i++){
        if(cells->at(i)->isCurrentlyActive) activeCells++;
    }
    activeCellslog.push_back(activeCells);

    int avg = 0;
    if(count >= 1000){
        count = 0;
        cycles++;
        for(unsigned int i = 0; i<activeCellslog.size(); i++){
            avg += activeCellslog.at(i);
        }
        avg = avg/activeCellslog.size();
        activeCellslog = std::vector<int>();
    }
    count += (std::chrono::high_resolution_clock::now() - std::chrono::high_resolution_clock::now()).count();

    if(cycles >= 3){
        std::cout << "Current Average : " << avg << " | Last Average : " << lastAverage << std::endl;
        cycles = 0;
        if(avg >= lastAverage - 3 && avg <= lastAverage + 3){
            activeCellslog = std::vector<int>();
            count = 0;
            lastAverage = 0;
            InitGame();
        }
        lastAverage = avg;
    }

    glutPostRedisplay();
    glutSwapBuffers();
    glutTimerFunc(time, UpdateScreen, time);
}

void
MouseClickEvent(int mouseX, int mouseY){
    for(unsigned int i=0; i<cells->size(); i++){
        if(cells->at(i)->isInside(mouseX, mouseY)) cells->at(i)->isCurrentlyActive = true;
    }
}