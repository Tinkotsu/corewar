#include "game.h"

int     check_pos(int pos)
{
    if (pos < 0)
        return (MEM_SIZE - ((-pos) % MEM_SIZE));
    else if (pos >= MEM_SIZE)
        return (pos % MEM_SIZE);
    return (pos);
}