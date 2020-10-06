#include <iostream>
#include <stdlib.h>
#include <GL/freeglut.h>

#include "cell"
#include "types"

Cell::Cell(double x, double y, double size){
    this->pos = new coord2d(x, y);
    this->size = size;
}

Cell::~Cell(){
    free(this->pos);    
}

void
Cell::draw(){
    glLineWidth(1);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_LINES);
    {
        glVertex2f(this->pos->x, this->pos->y);
        glVertex2f(this->pos->x + this->size, this->pos->y);

        glVertex2f(this->pos->x + this->size, this->pos->y);
        glVertex2f(this->pos->x + this->size, this->pos->y + this->size);

        glVertex2f(this->pos->x + this->size, this->pos->y + this->size);
        glVertex2f(this->pos->x, this->pos->y + this->size);

        glVertex2f(this->pos->x, this->pos->y + this->size);
        glVertex2f(this->pos->x, this->pos->y);
    }
    glEnd();

    if(this->isCurrentlyActive) {
        glColor3f(0, 0, 0);
        glBegin(GL_POLYGON);
        {
            glVertex2f(this->pos->x, this->pos->y);
            glVertex2f(this->pos->x + this->size, this->pos->y);
            glVertex2f(this->pos->x + this->size, this->pos->y + this->size);
            glVertex2f(this->pos->x, this->pos->y + this->size);
        }
        glEnd();
    }
}

void
Cell::checkNeighbours(std::vector<Cell*> * cells, unsigned int myIndex, int rowSize, int ceilSize){
    int neigh[8] = {
        myIndex - rowSize - 1,  myIndex - rowSize,  myIndex - rowSize + 1
    ,   myIndex           - 1,                      myIndex           + 1
    ,   myIndex + rowSize - 1,  myIndex + rowSize,  myIndex + rowSize + 1
    };
    for(int i=0 ; i<8; i++){
        if(neigh[i] < 0){
            neigh[i] = -1;
        }
        if(neigh[i] > cells->size()-1){
            neigh[i] = -1;
        }
    }

    int friendActives = 0;

    for(int i=0 ; i<8; i++){
        if(neigh[i] == -1) continue;

        bool friendActive = false;
        friendActive = cells->at(neigh[i])->isCurrentlyActive;

        if(friendActive){
            friendActives++;
        }
    }

    if(this->isCurrentlyActive){
        if(friendActives < 2) this->nextState = false;
        if(friendActives == 2 || friendActives == 3) this->nextState = true;
        if(friendActives > 3) this->nextState = false;
    } else {
        if(friendActives == 3) this->nextState = true;
    }
}

void
Cell::step(){
    this->isCurrentlyActive = this->nextState;
}

bool
Cell::isInside(int mouseX, int mouseY){
    bool xInside = false;
    bool yInside = false;

    if(mouseX >= this->pos->x && mouseX <= this->pos->x + this->size){
        xInside = true;
    }
        
    if(mouseY >= this->pos->y && mouseY <= this->pos->y + this->size) {
        yInside = true;
    }

    return (xInside && yInside);
}