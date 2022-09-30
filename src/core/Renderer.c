#include "../../include/core/Renderer.h"

#include "../../include/screens/Presentation.h"
#include "../../include/screens/Menu.h"
#include "../../include/screens/Register.h"
#include "../../include/screens/Inventory.h"

#include "../../include/components/Background.h"
#include "../../include/components/Button.h"
#include "../../include/components/Input.h"
#include "../../include/core/Audio.h"

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
    Texture2D Background = BackgroundComponent("./assets/Images/Menu_Background_2.png");
    Texture2D MenuButton = Button("./assets/Images/Button.png");
    Texture2D HoveredMenuButton = HoverButton("./assets/Images/HoverButton.png");
    Texture2D RegisterMenu = RegisterMenuBackground("./assets/Images/RegisterMenuBackground.png");
    Texture2D SmallWindowButton = SmallButton("./assets/Images/Small_Window_Buttons.png");
    Texture2D InputArea = LoadInput("./assets/Images/Input.png", ScreenXRelatedSize(4), ScreenYRelatedSize(12));
    char* Input = calloc(100, sizeof(char));

    //Execution Loop
    while (currentScreen != EXIT)
    {
        //Navigate between pages.
        switch(currentScreen){
            case PRESENTATION:
                currentScreen = Presentation(ANIMATION, CoinSound, PowerUpSound);
                break;
            case MENU:
                currentScreen = Menu(Background, MenuButton, HoveredMenuButton);
                break;
            case REGISTER:
                currentScreen = Register(Background, RegisterMenu, SmallWindowButton, MenuButton, InputArea, Input);
                break;
            case INVENTORY:
                currentScreen = Inventory();
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
    free(Input);
}