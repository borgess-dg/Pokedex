#ifndef INVENTORY_H
#define INVENTORY_H

#include "../raylib.h"

#include "../../include/core/Renderer.h"
#include "../../include/core/Window_Utils.h"
#include "../../include/core/Pokemon.h"

#include <stdio.h>
#include <stdlib.h>

void DrawCard(int, int, int, Texture2D, Pokemon*);
CurrentScreen Inventory(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, FILE*, FILE*);

#endif