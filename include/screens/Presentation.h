#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "../raylib.h"
#include "../../include/core/Renderer.h"

#include <stdlib.h>
#include <string.h>

#define STATIC "static"
#define ANIMATION "animation"

CurrentScreen Presentation(const char*, Sound, Sound);

#endif