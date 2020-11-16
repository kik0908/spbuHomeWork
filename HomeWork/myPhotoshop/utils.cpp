#include "utils.h"
#include <iostream>

int random(int a, int b)
{
    return a + (rand() % (b - a));
}
