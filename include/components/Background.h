#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../raylib.h"
#include <math.h>
//Background component.
//The "file" argument must contain the file way referenced to cwd.
Texture2D BackgroundComponent(const char*);
Texture2D RegisterMenuBackground(const char*);
#endif