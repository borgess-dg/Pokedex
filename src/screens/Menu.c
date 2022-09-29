#include "../../include/screens/Menu.h"

#include "../../include/components/Background.h"

#include "../../include/core/EventHandler.h"

#include <math.h>

CurrentScreen Menu(Texture2D Background, Texture2D Button, Texture2D HoveredButton){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    int X_POS = floor(GetScreenWidth()/2 - floor(ScreenXRelatedSize(4)/2));
    int POS_Y = floor(GetScreenHeight()/2) - floor(ScreenYRelatedSize(4)/2);
    int MARGIN = floor(ScreenYRelatedSize(4)) + floor(ScreenYRelatedSize(3)/3);

    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), X_POS, POS_Y)){
        //DrawRectangle(0,0, ScreenXRelatedSize(4), ScreenYRelatedSize(9), GREEN);
        DrawTextureEx(HoveredButton, (Vector2){X_POS, POS_Y}, 0.f, 1.f, WHITE);
        DrawText("Cadastrar Pokémon", X_POS + floor(((HoveredButton.width/2) - MeasureText("Cadastrar Pokémon", 25)/2)), floor(POS_Y + (HoveredButton.height/2 - 25/2)), 25, BLACK);
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return REGISTER;
        }
    }
    else{
        //DrawRectangle(REGISTER_POS_X, REGISTER_POS_Y, ScreenXRelatedSize(4), ScreenYRelatedSize(9), BLUE);
        DrawTextureEx(Button, (Vector2){X_POS, POS_Y}, 0.f, 1.f, WHITE);
        DrawText("Cadastrar Pokémon", X_POS + floor(((HoveredButton.width/2) - MeasureText("Cadastrar Pokémon", 25)/2)), floor(POS_Y + (HoveredButton.height/2 - 25/2)), 25, (Color){174, 150, 180, 255});
    }

    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), X_POS, MARGIN + ScreenYRelatedSize(6))){
        DrawTextureEx(HoveredButton, (Vector2){X_POS, MARGIN + ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
        DrawText("Pokémons Capturados", X_POS + ((HoveredButton.width/2) - MeasureText("Pokémons Capturados", 25)/2), floor(MARGIN + ScreenYRelatedSize(6) + (HoveredButton.height/2 - 25/2)), 25, BLACK);
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return INVENTORY;
        }
    }
    else{
        DrawTextureEx(Button, (Vector2){X_POS, MARGIN + ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
        DrawText("Pokémons Capturados", X_POS + ((HoveredButton.width/2) - MeasureText("Pokémons Capturados", 25)/2), floor(MARGIN + ScreenYRelatedSize(6) + (HoveredButton.height/2 - 25/2)), 25, (Color){174, 150, 180, 255});
    }

    MARGIN += ScreenYRelatedSize(3);
    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), X_POS, MARGIN)){
        DrawTextureEx(HoveredButton, (Vector2){X_POS, MARGIN}, 0.f, 1.f, WHITE);
        DrawText("Sair", X_POS + ((HoveredButton.width/2) - MeasureText("Sair", 25)/2), floor(MARGIN + (HoveredButton.height/2 - 25/2)), 25, BLACK);
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return EXIT;
        }
    }
    else{
        DrawTextureEx(Button, (Vector2){X_POS, MARGIN}, 0.f, 1.f, WHITE);
        DrawText("Sair", X_POS + ((HoveredButton.width/2) - MeasureText("Sair", 25)/2), floor(MARGIN + (HoveredButton.height/2 - 25/2)), 25, (Color){174, 150, 180, 255});
    }
    EndDrawing();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    return MENU;
}