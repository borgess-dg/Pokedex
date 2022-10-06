#include "../../include/components/Button.h"

#include "../../include/core/Window_Utils.h"

Texture2D Button(const char* file){
    Image I_Button = LoadImage(file);
    ImageResize(&I_Button, ScreenXRelatedSize(4), ScreenYRelatedSize(9));
    Texture2D T_Button = LoadTextureFromImage(I_Button);
    UnloadImage(I_Button);
    return T_Button;
}

Texture2D LoadCardButton(const char* file){
    Image I_Button = LoadImage(file);
    ImageResize(&I_Button, ScreenXRelatedSize(6), ScreenYRelatedSize(12));
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

Texture2D SmallButton(const char* file){
    Image S_Button = LoadImage(file);
    ImageResize(&S_Button, ScreenXRelatedSize(26), ScreenYRelatedSize(16));
    Texture2D Button = LoadTextureFromImage(S_Button);
    UnloadImage(S_Button);
    return Button;
}
Texture2D SmallHoveredButton(const char* file){
    Image S_Button = LoadImage(file);
    ImageResize(&S_Button, ScreenXRelatedSize(26), ScreenYRelatedSize(16));
    Texture2D Button = LoadTextureFromImage(S_Button);
    UnloadImage(S_Button);
    return Button;
}