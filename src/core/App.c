#include "../../include/core/App.h"
#include "../../include/screens/Presentation.h"
#include "../../include/core/Assets_Constants.h"

//Initialize the App.
void App(int WIDTH, int HEIGHT, const char* TITLE, bool FULLSCREEN){
    InitWindow(WIDTH, HEIGHT, TITLE);
    Image icon = LoadImage(WIN_ICON);
    SetWindowIcon(icon);
    if(FULLSCREEN)
        ToggleFullscreen();
    InitAudioDevice();
}

//Initialize the App lifecicle.
void Run(void){
    if(IsWindowReady()){
        bool isRendered = false;
        while (!WindowShouldClose())
        {
            if(!isRendered){
                Presentation(ANIMATION);
                isRendered = true;
            }
            else if(isRendered){
                Presentation(STATIC);
            }
            //BeginDrawing();
                //ClearBackground(RAYWHITE);
                //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            //EndDrawing();
        }
    }
    else{
        printf("ERROR!");
    }
}

void Exit(void){
    CloseAudioDevice();
    CloseWindow();
}