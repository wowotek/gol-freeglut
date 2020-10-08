#pragma once

#ifndef CELL_HH
#define CELL_HH

#include <vector>
#include "types.hh"

class Cell {
public:
    coord2d * pos;
    double size;
    
    bool currentState = false;
    bool nextState = this->nextState;

    Cell(double, double, double);
    ~Cell();

    void draw();
    void checkNeighbours(std::vector<Cell*>*, unsigned int, int, int);
    void step();

    bool isInside(int, int);
};

#endif // CELL_HH