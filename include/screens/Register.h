#ifndef REGISTER_H
#define REGISTER_H

#include "../raylib.h"

#include "../../include/core/Renderer.h"
#include "../../include/components/Markers.h"
#include "../../include/core/Pokemon.h"
#include "./Register.h"

#include <math.h>
#include <stdio.h>

void DrawDataBox(Texture2D, char*, FILE*, Pokemon*);
void DrawTypes(Markers, Pokemon);
void DrawWeaknesses(Markers, Pokemon);
void DrawStats(Texture2D, Pokemon);
CurrentScreen Register(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Markers, char*, FILE*, FILE*, FILE*);

#endif