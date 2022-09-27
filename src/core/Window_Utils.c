#include "../../include/core/Window_Utils.h"

#include <math.h>

Coordinates WindowCenter(void){
    Coordinates Window;

    Window.x = floor(GetRenderWidth()/2);
    Window.y = floor(GetRenderHeight()/2);

    return Window;
}

int ScreenXRelatedSize(int parts){
    return floor(GetScreenWidth()/parts);
}

int ScreenYRelatedSize(int parts){
    return floor(GetScreenHeight()/parts);
}