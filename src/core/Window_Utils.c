#include "../../include/core/Window_Utils.h"

#include <math.h>

Coordinates WindowCenter(void){
    Coordinates Window;

    Window.x = floor(GetRenderWidth()/2);
    Window.y = floor(GetRenderHeight()/2);

    return Window;
}