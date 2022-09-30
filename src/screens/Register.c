#include "../../include/screens/Register.h"

#include "../../include/core/Window_Utils.h"

#include "../../include/components/Input.h"
#include "../../include/components/Button.h"

#include "../../include/core/EventHandler.h"

void DrawDataBox(Texture2D DataBox){
    DrawText("Dados:", ScreenXRelatedSize(5), ScreenYRelatedSize(3.7), 24, BLACK);
    DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
    DrawText("Altura", ScreenXRelatedSize(4.8), ScreenYRelatedSize(3), 20, BLACK);
    DrawText("--", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.75), 20, BLACK);
    DrawText("Peso", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.55), 20, BLACK);
    DrawText("-- kg", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.40), 20, BLACK);
    DrawText("Categoria", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.20), 20, BLACK);
    DrawText("Undefined", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.05), 20, BLACK);
    DrawText("Gênero", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.90), 20, BLACK);
    DrawText("F/M", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.80), 20, BLACK);
    DrawText("Categoria", ScreenXRelatedSize(2.9), ScreenYRelatedSize(3), 20, BLACK);
    DrawText("Undefined", ScreenXRelatedSize(2.9), ScreenYRelatedSize(2.75), 20, BLACK);
    DrawText("Habilidades", ScreenXRelatedSize(2.9), ScreenYRelatedSize(2.55), 20, BLACK);
    DrawText("Undefined", ScreenXRelatedSize(2.9), ScreenYRelatedSize(2.40), 20, BLACK);
}

void DrawTypes(Markers AllMarkers){
    DrawText("Tipo:", ScreenXRelatedSize(5), ScreenYRelatedSize(1.55), 24, BLACK);
    DrawTextureEx(AllMarkers.Undefined, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(1.45)}, 0.f, 1.f, WHITE);
}

void DrawWeaknesses(Markers AllMarkers){
    DrawText("Fraquezas: ", ScreenXRelatedSize(1.8), ScreenYRelatedSize(8), 24, BLACK);
    DrawTextureEx(AllMarkers.Undefined, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
}

void DrawStats(Texture2D DataBox){
    DrawText("Stats:", ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.7), 24, BLACK);
    DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
    DrawText("HP", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.92), 20, BLACK);
    DrawText("Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.62), 20, BLACK);
    DrawText("Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.40), 20, BLACK);
    DrawText("S. Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.20), 20, BLACK);
    DrawText("S. Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.03), 20, BLACK);
    DrawText("Speed", ScreenXRelatedSize(1.78), ScreenYRelatedSize(1.88), 20, BLACK);
}

CurrentScreen Register(Texture2D Background, Texture2D RegisterScreenBackground, Texture2D Small_Button, Texture2D Button, Texture2D HoveredButton, Texture2D Input, Texture2D DataBox, Markers AllMarkers, char* input){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    //Draw Background
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    DrawTextureEx(RegisterScreenBackground, CentralizeObject(RegisterScreenBackground.width, RegisterScreenBackground.height), 0.f, 1.f, WHITE);
    //Draw Exit Button.
    if(IsMouseHover(ScreenXRelatedSize(25), ScreenYRelatedSize(15), ScreenXRelatedSize(1.11), ScreenYRelatedSize(20))){
        DrawTextureEx(Small_Button, (Vector2){ScreenXRelatedSize(1.11), ScreenYRelatedSize(20)}, 0.f, 1.f, WHITE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return MENU;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else{
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        DrawTextureEx(Small_Button, (Vector2){ScreenXRelatedSize(1.11), ScreenYRelatedSize(20)}, 0.f, 1.f, WHITE);
    }
    //Draw Input Part.
    DrawText("Nome do Pokémon:", ScreenXRelatedSize(5), ScreenYRelatedSize(8), 24, BLACK);
    InputComponent(Input, input, ScreenXRelatedSize(5), ScreenYRelatedSize(6));
    //Draw DataBox.
    DrawDataBox(DataBox);
    //Draw Pokémon Type Section
    DrawTypes(AllMarkers);
    //Draw Pokémon Weaknesses.
    DrawWeaknesses(AllMarkers);
    //Draw Pokémon Stats Box.
    DrawStats(DataBox);
    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25))){
        DrawTextureEx(HoveredButton, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25)}, 0.f, 1.f, WHITE);
        DrawText("Salvar Pokémon", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Salvar Pokémon", 24)/2), ScreenYRelatedSize(1.25) + floor(Button.height/2 - 24/2), 24, BLACK);
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else{
        DrawTextureEx(Button, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25)}, 0.f, 1.f, WHITE);
        DrawText("Salvar Pokémon", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Salvar Pokémon", 24)/2), ScreenYRelatedSize(1.25) + floor(Button.height/2 - 24/2), 24, (Color){174, 150, 180, 255});
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return REGISTER;
}