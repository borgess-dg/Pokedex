#include "../../include/screens/Register.h"

#include "../../include/core/Window_Utils.h"

#include "../../include/components/Input.h"
#include "../../include/components/Button.h"

CurrentScreen Register(Texture2D Background, Texture2D RegisterScreenBackground, Texture2D Small_Button, Texture2D Button, char* input){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    DrawTextureEx(RegisterScreenBackground, CentralizeObject(RegisterScreenBackground.width, RegisterScreenBackground.height), 0.f, 1.f, WHITE);
    DrawTextureEx(Small_Button, (Vector2){ScreenXRelatedSize(20), ScreenYRelatedSize(20)}, 0.f, 1.f, WHITE);
    DrawTextureEx(Button, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25)}, 0.f, 1.f, WHITE);
    DrawText("Nome do Pokémon:", ScreenXRelatedSize(5), ScreenYRelatedSize(8), 24, BLACK);
    InputComponent(input, 200, 50, ScreenXRelatedSize(5), ScreenYRelatedSize(6));
    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return REGISTER;
}