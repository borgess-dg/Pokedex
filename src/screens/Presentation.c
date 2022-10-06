#include "../../include/screens/Presentation.h"
#include "../../include/core/Audio.h"
#include "../../include/core/Window_Utils.h"
#include "../../include/core/Renderer.h"

#include <stdbool.h>
#include <string.h>

CurrentScreen Presentation(const char* type, char* PresentationText, Sound Coin, Sound Powerup){
    strcpy(PresentationText, "Eduardo Jose Borges\nIago Oliveira Melo\nLaidson Costa Loiola");
    char Names[60];
    int Positions[3] = {19, 38, 58};
    static int PresentationExecCounter;
    BeginDrawing();
    ClearBackground(BLACK);
    if(!PresentationExecCounter){
        DrawText("Eduardo José Borges", floor((GetScreenWidth()/2) - (MeasureText(PresentationText, 24)/2)), floor((GetScreenHeight()/2) - (24)), 24, WHITE);
        WaitTime(1);
        DrawText("Iago Oliveira Melo", floor((GetScreenWidth()/2) - (MeasureText(PresentationText, 24)/2)), floor((GetScreenHeight()/2) - (24)), 24, WHITE);
        WaitTime(1);
        DrawText("Laidson Costa Loiola", floor((GetScreenWidth()/2) - (MeasureText(PresentationText, 24)/2)), floor((GetScreenHeight()/2) - (24)), 24, WHITE);
        WaitTime(1);
    }
    else{
        DrawText(PresentationText, floor((GetScreenWidth()/2) - (MeasureText(PresentationText, 24)/2)), floor((GetScreenHeight()/2) - (24)), 24, WHITE);
    }
    EndDrawing();
    return PRESENTATION;
}
