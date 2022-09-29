#ifndef WINDOW_UTILS_H
#define WINDOW_UTILS_H

#include "../raylib.h"

#include <math.h>

typedef struct{
    int x;
    int y;
}Coordinates;

Coordinates WindowCenter(void);
int ScreenXRelatedSize(double);
int ScreenYRelatedSize(double);
Vector2 CentralizeObject(int, int);

#endif