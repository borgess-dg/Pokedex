#ifndef INPUT_H
#define INPUT_H

#include "../raylib.h"

typedef struct{
    Rectangle props;
    char data[1024];
}Input;

void InputComponent(char*, int, int, int, int);

#endif