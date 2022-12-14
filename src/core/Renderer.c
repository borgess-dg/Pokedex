#include "../../include/core/Renderer.h"

#include "../../include/screens/Presentation.h"
#include "../../include/screens/Menu.h"
#include "../../include/screens/Register.h"
#include "../../include/screens/Inventory.h"

#include "../../include/components/Background.h"
#include "../../include/components/Button.h"
#include "../../include/components/Input.h"
#include "../../include/components/DataBox.h"
#include "../../include/components/Markers.h"
#include "../../include/core/Audio.h"

#include <stdio.h>

//Render all app screens.
void Renderer(void){
    //This variable serves as control to alternate between ANIMATED and STATIC screen versions.
    bool isRendered = false;
    //Define the current Screen.
    CurrentScreen currentScreen = MENU;
    //Texture2D Background = BackgroundComponent("./assets/Images/Menu_Background_2.png");
    //Load Components
    Sound CoinSound = SoundLoad("./assets/Audio/pickupCoin.wav");
    Sound PowerUpSound = SoundLoad("./assets/Audio/powerUp.wav");
    Sound SelectButton = SoundLoad("./assets/Audio/click.wav");
    Texture2D Background = BackgroundComponent("./assets/Images/Menu_Background_2.png");
    Texture2D MenuButton = Button("./assets/Images/Button.png");
    Texture2D CardButton = LoadCardButton("./assets/Images/Button.png");
    Texture2D HoveredMenuButton = HoverButton("./assets/Images/HoverButton.png");
    Texture2D RegisterMenu = RegisterMenuBackground("./assets/Images/RegisterMenuBackground.png");
    Texture2D SmallWindowButton = SmallButton("./assets/Images/Small_Window_Buttons.png");
    Texture2D InputArea = LoadInput("./assets/Images/Input.png", ScreenXRelatedSize(4), ScreenYRelatedSize(12));
    Texture2D DataBox = LoadDataBox("./assets/Images/DataBox.png", ScreenXRelatedSize(3.5), ScreenYRelatedSize(3.2));
    Texture2D SmallWindowHoveredButton = SmallHoveredButton("./assets/Images/Small_Window_Buttons_Hovered.png");
    Markers allMarkers = MarkerSet(allMarkers);
    FILE* SaveFile = fopen("./data/Save.txt", "ab");
    FILE* ReadSaveFile = fopen("./data/Save.txt", "rb");
    FILE* ReadIDsFile = fopen("./data/IDs.txt", "rb");
    FILE* WriteIDsFile = fopen("./data/IDs.txt", "ab");
    char* PresentationText = calloc(60, sizeof(char));
    char* Input = calloc(25, sizeof(char));

    //Execution Loop
    while (currentScreen != EXIT)
    {
        //Navigate between pages.
        switch(currentScreen){
            case PRESENTATION:
                currentScreen = Presentation(ANIMATION, PresentationText, CoinSound, PowerUpSound);
                break;
            case MENU:
                currentScreen = Menu(Background, MenuButton, HoveredMenuButton, SelectButton);
                break;
            case REGISTER:
                currentScreen = Register(Background, RegisterMenu, SmallWindowButton, SmallWindowHoveredButton, MenuButton, HoveredMenuButton, InputArea, DataBox, allMarkers, Input, SaveFile, WriteIDsFile, ReadIDsFile);
                break;
            case INVENTORY:
                currentScreen = Inventory(Background, RegisterMenu, CardButton, MenuButton, HoveredMenuButton, ReadSaveFile, ReadIDsFile);
                break;
            case EXIT:
                break;
        }
    }
    //Unload
    UnloadTexture(Background);
    UnloadTexture(MenuButton);
    UnloadTexture(HoveredMenuButton);
    UnloadSound(CoinSound);
    UnloadSound(PowerUpSound);
    UnloadTexture(RegisterMenu);
    UnloadTexture(InputArea);
    fclose(SaveFile);
    fclose(ReadSaveFile);
    fclose(ReadIDsFile);
    fclose(WriteIDsFile);
    free(Input);
}