#include "corewar.h"

void        set_int(char *arena, int start_pos, int num)
{
    arena[start_pos] = (num & 0xff000000) >> 24;
    arena[(start_pos + 1) % MEM_SIZE] = (num & 0x00ff0000) >> 16;
    arena[(start_pos + 2) % MEM_SIZE] = (num & 0x0000ff00) >> 8;
    arena[(start_pos + 3) % MEM_SIZE] = (num & 0x000000ff);
}

int         get_int(char *bytes, size_t size)
{
    int     i;
    short   number;
    short   d;
    int     shift;

    number = 0;
    i = 0;
    while (i < size)
    {
        d = (short)bytes[i];
        shift = 8 * ((size - 1) - i);
        number |= d << shift;
        ++i;
    }
    return (number);
}