#include "../../include/core/EventHandler.h"

bool IsMouseHover(int sizeX, int sizeY, int X, int Y){
    return (GetMouseX() >= X && GetMouseX() <= (X + sizeX)) && (GetMouseY() >= Y && GetMouseY() <= (Y + sizeY));
}