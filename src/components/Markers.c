#include "../../include/components/Markers.h"

#include "../../include/core/Window_Utils.h"

Texture2D LoadMarker(const char* file, int SizeX, int SizeY){
    Image MarkerImage = LoadImage(file);
    ImageResize(&MarkerImage, SizeX, SizeY);
    Texture2D Marker = LoadTextureFromImage(MarkerImage);
    return Marker;
}

Markers MarkerSet(Markers Types){
    Types.Undefined = LoadMarker("./assets/Images/UndefinedType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    return Types;
}