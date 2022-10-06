#ifndef MARKERS_H
#define MARKERS_H

#include "../raylib.h"

typedef struct{
    Texture2D Undefined;
    Texture2D Bug;
    Texture2D Rock;
    Texture2D Fada;
    Texture2D Water;
    Texture2D Psychic;
    Texture2D Ground;
    Texture2D Ghost;
    Texture2D Dragon;
    Texture2D Steel;
    Texture2D Planta;
    Texture2D Dark;
    Texture2D Poison;
    Texture2D Flying;
    Texture2D Luta;
    Texture2D Electric;
    Texture2D Fire;
    Texture2D Ice;
}Markers;

Texture2D LoadMarker(const char* file, int SizeX, int SizeY);
Markers MarkerSet(Markers Types);

#endif