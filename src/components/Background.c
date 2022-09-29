#include "../../include/components/Background.h"

Texture2D BackgroundComponent(const char* file){
    Image background = LoadImage(file);
    ImageResize(&background, GetScreenWidth(), GetScreenHeight());
    Texture2D t_background = LoadTextureFromImage(background);
    UnloadImage(background);
    return t_background;
}

Texture2D RegisterMenuBackground(const char* file){
    Image BackgroundComponent = LoadImage(file);
    ImageResize(&BackgroundComponent, floor(GetScreenWidth()/1.05), floor((GetScreenWidth()/1.9)));
    Texture2D Background = LoadTextureFromImage(BackgroundComponent);
    UnloadImage(BackgroundComponent);

    return Background;
}