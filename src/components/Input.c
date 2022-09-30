#include "../../include/components/Input.h"

#include "../../include/core/EventHandler.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

static int GSizeX, GSizeY;

Texture2D LoadInput(const char* file, int SizeX, int SizeY){
    Image InputImage = LoadImage(file);
    ImageResize(&InputImage, SizeX, SizeY);
    GSizeX = SizeX;
    GSizeY = SizeY;
    Texture2D Input = LoadTextureFromImage(InputImage);
    UnloadImage(InputImage);
    return Input;
}

void InputComponent(Texture2D InputTexture, char* input, int POS_X, int POS_Y){
    static bool isFocused;
    static int counter;
    DrawTextureEx(InputTexture, (Vector2){POS_X, POS_Y}, 0.f, 1.f, WHITE);
    //DrawRectangle(POS_X, POS_Y, GSizeX, GSizeY, WHITE);
    if(IsMouseHover(GSizeX, GSizeY, POS_X, POS_Y)){
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
        }
        if(IsKeyPressed(KEY_BACKSPACE)){
                counter--;
                if(counter < 0){
                    counter = 0;
                }
                input[counter] = '\0';
        }
    }
    else{
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    DrawText(input, POS_X + 10, floor(POS_Y + (GSizeY/2 - 20/2)), 20, RED);
    DrawText("|", POS_X + MeasureText(input, 20) + 11, floor(POS_Y + (GSizeY/2 - 20/2)), 20, RED);
}