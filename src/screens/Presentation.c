#include "../../include/screens/Presentation.h"
#include "../../include/core/Audio.h"
#include "../../include/core/Window_Utils.h"

#include <stdbool.h>
#include <string.h>

void Presentation(const char* type){
    char* NAMES = (char*) calloc(49, sizeof(char));
    char* S_NAMES = (char*) calloc(49, sizeof(char));
    Coordinates Window = WindowCenter();
    static int exeCount;
    strcpy(NAMES, "Eduardo J. Borges\nIago Melo\nLaidson Costa Loiola");
    if(!strcmp(type, ANIMATION)){
        for(int i = 0;  i < 3; i++){
            if(i == 0){
                strncpy(S_NAMES, NAMES, 18);
            }
            else if(i == 1){
                strncpy(S_NAMES, NAMES, 28);
            }
            else{
                strncpy(S_NAMES, NAMES, 48);
            }
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText(S_NAMES, Window.x - 80, Window.y - 50, 18, RAYWHITE);
            WaitTime(1);
            PlayCoinSound();
            EndDrawing();
        }
    }
    else{
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(NAMES, Window.x - 90, Window.y - 60, 24, RAYWHITE);
        if(!exeCount){
            WaitTime(1);
            PlayPowerUpSound();
        }
        EndDrawing();
        exeCount++;
    }
}
