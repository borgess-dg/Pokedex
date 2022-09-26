#include <stdlib.h>

#include "../../include/raylib.h"
#include "../../include/core/App.h"

int main(void)
{
    App(GetScreenWidth(), GetScreenHeight(), "PokeDex!", true);
    Run();
    Exit();

    return 0;
}