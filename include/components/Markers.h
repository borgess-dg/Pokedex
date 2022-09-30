#ifndef MARKERS_H
#define MARKERS_H

#include "../raylib.h"

typedef struct{
    Texture2D Undefined;
}Markers;

Texture2D LoadMarker(const char* file, int SizeX, int SizeY);
Markers MarkerSet(Markers Types);

#endif