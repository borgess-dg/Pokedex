#include "../../include/core/App.h"

#include "../../include/core/Assets_Constants.h"
#include "../../include/core/Renderer.h"

//Initialize app window and audio device.
void App(int WIDTH, int HEIGHT, const char* TITLE, bool FULLSCREEN){
    InitWindow(WIDTH, HEIGHT, TITLE);
    //Define and load the app icon image.
    Image icon = LoadImage(WIN_ICON);
    SetWindowIcon(icon);
    SetTargetFPS(60);
    //Set fullscreen mode if FULLSCREEN == true.
    if(FULLSCREEN)
        ToggleFullscreen();
    InitAudioDevice();
}

//Initialize the App lifecicle.
void Run(void){
    if(IsWindowReady()){
        Renderer();
    }
}

//Close window and Audio Device.
void Exit(void){
    CloseAudioDevice();
    CloseWindow();
}