#include "../../include/core/App.h"
#include "../../include/screens/Presentation.h"

//Initialize the App.
void App(int WIDTH, int HEIGHT, const char* TITLE, bool FULLSCREEN){
    InitWindow(WIDTH, HEIGHT, TITLE);
    if(FULLSCREEN)
        ToggleFullscreen();
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
    CloseWindow();
}