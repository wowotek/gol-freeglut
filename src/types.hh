#pragma once

#ifndef TYPES_HH
#define TYPES_HH

template <typename T>
struct t_coordinate{
    T x;
    T y;

    t_coordinate(T initX, T initY): x(initX), y(initY) {
        this->x = initX;
        this->y = initY;
    }
};

typedef t_coordinate<double> coord2d;

#endif // TYPES_HH