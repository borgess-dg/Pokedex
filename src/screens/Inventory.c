#include "../../include/screens/Inventory.h"
#include "../../include/core/Pokemon.h"

#include <string.h>

void DrawCard(int POS_X, int POS_Y, int ID, Texture2D Button, Pokemon* Data){
    Pokemon Poke = *Data;
    DrawTextureEx(Button, (Vector2){POS_X, POS_Y}, 0.f, 1.f, WHITE);
    DrawText(Data[ID].PokemonData.name, POS_X + floor(MeasureText(Data[ID].PokemonData.name, 24)/2 - ScreenXRelatedSize(4)), POS_Y + floor(ScreenYRelatedSize(9)/2 - 24/2), 24, BLACK);
    //
    //DrawText(Data[ID].PokemonData.name, POS_X + floor(MeasureText(Data[ID].PokemonData.name, 24)/2 - ScreenXRelatedSize(4)), POS_Y + floor(ScreenYRelatedSize(9)/2 - 24/2), 24, BLACK);
}

CurrentScreen Inventory(Texture2D Background, Texture2D RegisterScreenBackground, Texture2D Cards, Texture2D ExitButton, Texture2D HoveredExitButton, FILE* SaveFile, FILE* IDsFile){
    char ID[4];
    int PokemonCounter;
    static int i;
    int POS_X, POS_Y;
    fread(ID, sizeof(char), 4, IDsFile);
    if(!(strcmp(ID, "\0"))){
        PokemonCounter = 0;
    }
    else{
        PokemonCounter = atoi(ID);
    }
    Pokemon Poke[PokemonCounter];
    BeginDrawing();
    ClearBackground(RAYWHITE);
    fread(&Poke, sizeof(Poke), 1, SaveFile);
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    DrawTextureEx(RegisterScreenBackground, CentralizeObject(RegisterScreenBackground.width, RegisterScreenBackground.height), 0.f, 1.f, WHITE);
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            //DrawRectangle(50 * i, 50 * j, 50, 50, WHITE);
            DrawCard(ScreenXRelatedSize(22) + (Cards.width * (i - 1) + ScreenXRelatedSize(10)), ScreenYRelatedSize(60) + (ScreenYRelatedSize(10) * (j)), 1, Cards, Poke);
            //DrawCard(ScreenXRelatedSize(22) + (Cards.width * (i - 1)) + ScreenXRelatedSize(35) * (j - 1), Cards.height * i, 1, Cards, Poke);
        }
    }
    /**for(i = 1; i <= PokemonCounter; i++){
        
        if(i == 1){
            POS_X = ScreenXRelatedSize(22);
            POS_Y = ScreenYRelatedSize(19);
        }
        else if(i == 5){
            POS_X = ScreenXRelatedSize(22);
            POS_Y = 50;
        }
        else{
            POS_X = ScreenXRelatedSize(22) + (Cards.width * (i - 1)) + ScreenXRelatedSize(35) * (i - 1);
        }

        DrawCard(POS_X, POS_Y, i - 1, Cards, Poke);
    }**/
    DrawText(TextFormat("%d", PokemonCounter), 0, 0, 24, RED);
    DrawText(Poke[0].PokemonData.name, 0, 100, 24, RED);

    //Save Button
    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25))){
        DrawTextureEx(HoveredButton, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.28)}, 0.f, 1.f, WHITE);
        DrawText("Voltar ao Menu", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Voltar ao Menu", 24)/2), ScreenYRelatedSize(1.28) + floor(Button.height/2 - 24/2), 24, (Color){174, 150, 180, 255});
        SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return MENU;
         }
    }
    else{
        DrawTextureEx(Button, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.28)}, 0.f, 1.f, WHITE);
        DrawText("Voltar ao Menu", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Voltar ao Menu", 24)/2), ScreenYRelatedSize(1.28) + floor(Button.height/2 - 24/2), 24, (Color){174, 150, 180, 255});
        //SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    if(IsKeyPressed(KEY_ESCAPE)){
        return EXIT;
    }
    EndDrawing();
    return INVENTORY;
}