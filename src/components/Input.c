#include "../../include/components/Input.h"

#include "../../include/core/EventHandler.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void InputComponent(char* input, int SizeX, int SizeY, int POS_X, int POS_Y){
    static bool isFocused;
    static int counter;
    SetTargetFPS(10);
    DrawRectangle(POS_X, POS_Y, SizeX, SizeY, WHITE);
    if(IsMouseHover(SizeX, SizeY, POS_X, POS_Y)){
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        isFocused = true;
        int key = GetCharPressed();
        while(key > 0){
            if(((key >= 32) && (key <= 125)) && (counter < 100)){
                input[counter] = (char) key;
                input[counter + 1] = '\0';
                counter++;
            }
            key = GetCharPressed();  
            if(IsKeyPressed(KEY_BACKSPACE)){
                counter--;
                if(counter < 0)
                    counter = 0;
                input[counter] = '\0';
            }
            if(!(IsMouseHover(SizeX, SizeY, POS_X, POS_Y))){
                break;
            }
            DrawText(input, 15, 15, 16, RED);     
        }
    }
    else{
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    DrawText(input, 30, 30, 16, RED);
}