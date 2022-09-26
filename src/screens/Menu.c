#include "../../include/screens/Menu.h"

void Menu(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello!", 0, 0, 12, BLUE);
    EndDrawing();
}