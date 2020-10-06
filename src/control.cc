#include <iostream>

#include "control"
#include "rendering"

std::vector<unsigned char> standardKeyPress;
std::vector<int> specialKeyPress;

// STANDARD KEYBOARD EVENTS -----
void
KeyboardStandardDownEventHandler(unsigned char key, int mouseX, int mouseY){

}

void
KeyboardStandardUpEventHandler(unsigned char key, int mouseX, int mouseY){

}

// SPECIAL KEYBOARD EVENTS -----
void
KeyboardSpecialDownEventHandler(int key, int mouseX, int mouseY){

}

void
KeyboardSpecialUpEventHandler(int key, int mouseX, int mouseY){

}


// MOUSE EVENTS -----
void
MouseEventHandler(int button, int state, int mouseX, int mouseY){
    if(button == 0 && state == 0){
        MouseClickEvent(mouseX, mouseY);
    }
}