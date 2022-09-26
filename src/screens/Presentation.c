#include "../../include/screens/Presentation.h"

#include <stdbool.h>
#include <string.h>

void Presentation(const char* type){
    char* NAMES = (char*) calloc(49, sizeof(char));
    char* S_NAMES = (char*) calloc(49, sizeof(char));
    strcpy(NAMES, "Eduardo J. Borges\nIago Melo\nLaidson Costa Loiola");

    if(!strcmp(type, ANIMATION)){
        for(int i = 0;  i < 49; i++){
            strncpy(S_NAMES, NAMES, i);
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(S_NAMES, 0, 0, 12, LIGHTGRAY);
            WaitTime(0.05);
            EndDrawing();
        }
    }
    else{
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(NAMES, 0, 0, 12, LIGHTGRAY);
        EndDrawing();
    }
}
