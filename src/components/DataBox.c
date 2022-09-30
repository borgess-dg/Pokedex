#include "../../include/components/DataBox.h"

Texture2D LoadDataBox(const char* file, int SizeX, int SizeY){
    Image DataBoxImage = LoadImage(file);
    ImageResize(&DataBoxImage, SizeX, SizeY);
    Texture2D DataBox = LoadTextureFromImage(DataBoxImage);
    UnloadImage(DataBoxImage);
    return DataBox;
}