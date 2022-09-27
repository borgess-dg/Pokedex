#include "../../include/components/Background.h"

Texture2D BackgroundComponent(const char* file){
    Image background = LoadImage(file);
    ImageResize(&background, GetScreenWidth(), GetScreenHeight());
    Texture2D t_background = LoadTextureFromImage(background);
    UnloadImage(background);
    return t_background;
}