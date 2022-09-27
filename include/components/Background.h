#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../raylib.h"

//Background component.
//The "file" argument must contain the file way referenced to cwd.
Texture2D BackgroundComponent(const char* file);

#endif