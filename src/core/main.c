#include <stdlib.h>

#include "../../include/raylib.h"
#include "../../include/core/App.h"

int main(void)
{
    App(600, 600, "PokeDex!", NULL);
    Run();
    Exit();

    return 0;
}