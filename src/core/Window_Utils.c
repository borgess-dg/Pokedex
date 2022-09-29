#include "../../include/core/Window_Utils.h"


#include <math.h>

Coordinates WindowCenter(void){
    Coordinates Window;

    Window.x = floor(GetRenderWidth()/2);
    Window.y = floor(GetRenderHeight()/2);

    return Window;
}

int ScreenXRelatedSize(double parts){
    return floor(GetScreenWidth()/parts);
}

int ScreenYRelatedSize(double parts){
    return floor(GetScreenHeight()/parts);
}

Vector2 CentralizeObject(int SizeX, int SizeY){
    Vector2 Centralize;

    Centralize.x = floor(GetScreenWidth()/2) - floor(SizeX/2);
    Centralize.y = floor(GetScreenHeight()/2) - floor(SizeY/2);

    return Centralize;
}