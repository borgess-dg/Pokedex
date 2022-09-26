#ifndef RENDERER_H
#define RENDERER_H

#include "../../include/core/Assets_Constants.h"

#include "../../include/screens/Presentation.h"
#include "../../include/screens/Menu.h"

#include <stdbool.h>

typedef enum{
    PRESENTATION = 0,
    MENU,
    //OTHERS
}Screen;

static Screen currentScreen;

void Renderer();

#endif