#include "../../include/screens/Inventory.h"

CurrentScreen Inventory(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Invetory Page!", 0, 0, 12, BLUE);
    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return INVENTORY;
}