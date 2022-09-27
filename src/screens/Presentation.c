#include "../../include/screens/Presentation.h"
#include "../../include/core/Audio.h"
#include "../../include/core/Window_Utils.h"
#include "../../include/core/Renderer.h"

#include <stdbool.h>
#include <string.h>

CurrentScreen Presentation(const char* type, Sound Coin, Sound Powerup){
    char NAMES[49];
    char S_NAMES[49];
    Coordinates Window = WindowCenter();
    static int exeCount;
    strcpy(NAMES, "Eduardo J. Borges\nIago Melo\nLaidson Costa Loiola");
    if(!strcmp(type, ANIMATION)){
        for(int i = 0;  i < 3; i++){
            if(i == 0){
                strncpy(S_NAMES, NAMES, 17);
            }
            else if(i == 1){
                strncpy(S_NAMES, NAMES, 28);
            }
            else{
                strncpy(S_NAMES, NAMES, 47);
            }
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText(S_NAMES, Window.x - 80, Window.y - 50, 18, RAYWHITE);
            WaitTime(1);
            PlayRefSound(Coin);
            EndDrawing();
        }
    }
    else{
        ClearBackground(BLACK);
        DrawText("Not Working!", 0, 0, 24, RAYWHITE);
        DrawText(NAMES, Window.x - 90, Window.y - 60, 24, RAYWHITE);
        if(!exeCount){
            WaitTime(1);
            PlayRefSound(Powerup);
        }
        exeCount++;
        WaitTime(3);
        EndDrawing();
        return MENU;
    }
    return PRESENTATION;
}
