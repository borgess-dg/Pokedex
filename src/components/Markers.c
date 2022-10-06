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
    Types.Bug = LoadMarker("./assets/Images/BugType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Fire = LoadMarker("./assets/Images/FireType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Dragon = LoadMarker("./assets/Images/DragonType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Electric = LoadMarker("./assets/Images/ElectricType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Dark = LoadMarker("./assets/Images/DarkType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Ground = LoadMarker("./assets/Images/GroundType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Fada = LoadMarker("./assets/Images/FadaType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Steel = LoadMarker("./assets/Images/SteelType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Ghost = LoadMarker("./assets/Images/GhostType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Flying = LoadMarker("./assets/Images/FlyingType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Luta = LoadMarker("./assets/Images/LutaType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Rock = LoadMarker("./assets/Images/RockType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Water = LoadMarker("./assets/Images/WaterType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Psychic = LoadMarker("./assets/Images/PsychicType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Ice = LoadMarker("./assets/Images/IceType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    Types.Poison = LoadMarker("./assets/Images/PoisonType.png", ScreenXRelatedSize(15), ScreenYRelatedSize(30));
    return Types;
}