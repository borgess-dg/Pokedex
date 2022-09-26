#include "../../include/core/Renderer.h"

//Render all app screens.
void Renderer(void){
    //This variable serves as control to alternate between ANIMATED and STATIC screen versions.
    bool isRendered = false;
    //Define the current Screen.
    currentScreen = PRESENTATION;
    //Execution Loop
    while (!WindowShouldClose())
    {
        //Navigate between pages.
        switch(currentScreen){
            case PRESENTATION:
                if(!isRendered){
                    Presentation(ANIMATION);
                    isRendered = true;
                }
                else if(isRendered){
                    Presentation(STATIC);
                    WaitTime(3);
                    currentScreen = MENU;
                }
                break;
            case MENU:
                Menu();
        }
    }
}