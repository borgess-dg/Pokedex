#include "../../include/components/Button.h"

#include "../../include/core/Window_Utils.h"

Texture2D Button(const char* file){
    Image I_Button = LoadImage(file);
    ImageResize(&I_Button, ScreenXRelatedSize(4), ScreenYRelatedSize(9));
    Texture2D T_Button = LoadTextureFromImage(I_Button);
    UnloadImage(I_Button);
    return T_Button;
}

Texture2D HoverButton(const char* file){
    Image I_HButton = LoadImage(file);
    ImageResize(&I_HButton, ScreenXRelatedSize(4), ScreenYRelatedSize(9));
    Texture2D T_HButton = LoadTextureFromImage(I_HButton);
    UnloadImage(I_HButton);
    return T_HButton;
}