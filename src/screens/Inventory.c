#include "../../include/screens/Inventory.h"

CurrentScreen Inventory(Texture2D Background, Texture2D RegisterScreenBackground){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    DrawTextureEx(RegisterScreenBackground, CentralizeObject(RegisterScreenBackground.width, RegisterScreenBackground.height), 0.f, 1.f, WHITE);
    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return INVENTORY;
}