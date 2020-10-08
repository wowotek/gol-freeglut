#pragma once

#ifndef RENDERING_HH
#define RENDERING_HH

extern int WIDTH;
extern int HEIGHT;

#include "cell.hh"

extern std::vector<Cell*> * cells;

void InitGame();
void RenderDisplay(void);
void UpdateScreen(int);

void KeyboardDownEvent(unsigned char, int, int);
void KeyboardUpEvent(unsigned char, int, int);
void MouseClickEvent(int, int, int, int);
void MouseDragEvent(int, int);

#endif // RENDERING_HH
