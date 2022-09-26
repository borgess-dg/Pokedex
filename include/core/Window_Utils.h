#ifndef WINDOW_UTILS_H
#define WINDOW_UTILS_H

#include "../raylib.h"

typedef struct
{
    int x;
    int y;
}Coordinates;

Coordinates WindowCenter(void);

#endif