#pragma once

#ifndef CONTROL_HH
#define CONTROL_HH

#include <vector>

extern std::vector<unsigned char> standardKeyPress;
extern std::vector<int> specialKeyPress;

void KeyboardStandardDownEventHandler(unsigned char, int, int);
void KeyboardStandardUpEventHandler(unsigned char, int, int);

void KeyboardSpecialDownEventHandler(int, int, int);
void KeyboardSpecialUpEventHandler(int, int, int);

void MouseEventHandler(int, int, int, int);

#endif // CONTROL_HH