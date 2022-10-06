#ifndef RENDERER_H
#define RENDERER_H

#include "../../include/core/Assets_Constants.h"
#include "./Pokemon.h"

#include <stdbool.h>

typedef enum{
    PRESENTATION = 0,
    MENU,
    REGISTER,
    INVENTORY,
    EXIT,
    //OTHERS
}CurrentScreen;

void Renderer();

#endif