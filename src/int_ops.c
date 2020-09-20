#include "corewar.h"
//использовал abs

void        set_int(char *arena, int start_pos, int num)
{
    if (start_pos < 0)
        start_pos = (MEM_SIZE - start_pos) % MEM_SIZE;
    arena[start_pos] = (num & 0xff000000) >> 24;
    arena[(start_pos + 1) % MEM_SIZE] = (num & 0x00ff0000) >> 16;
    arena[(start_pos + 2) % MEM_SIZE] = (num & 0x0000ff00) >> 8;
    arena[(start_pos + 3) % MEM_SIZE] = (num & 0x000000ff);
}

int         get_int(char *bytes, size_t size)
{
    int     i;
    short   number;
    int     shift;

    number = 0;
    i = 0;
    while (i < size)
    {
        shift = 8 * ((size - 1) - i);
        number |= (unsigned char)bytes[i] << shift;
        ++i;
    }
    return (number);
}