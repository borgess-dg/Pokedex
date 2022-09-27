#include "../../include/screens/Register.h"

CurrentScreen Register(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("REGISTRATION PAGE!", 0, 0, 12, BLUE);
    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return REGISTER;
}