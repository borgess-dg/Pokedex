#ifndef REGISTER_H
#define REGISTER_H

#include "../raylib.h"

#include "../../include/core/Renderer.h"
#include "../../include/components/Markers.h"

#include <math.h>

void DrawDataBox(Texture2D);
void DrawTypes(Markers);
void DrawWeaknesses(Markers);
void DrawStats(Texture2D);
CurrentScreen Register(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Markers, char*);

#endif