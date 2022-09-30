#ifndef INPUT_H
#define INPUT_H

#include "../raylib.h"

typedef struct{
    Rectangle props;
    char data[1024];
}Input;


Texture2D LoadInput(const char*, int, int);
void InputComponent(Texture2D, char*, int, int);

#endif