#include "game.h"

void            ch_sub(t_carriage *car, t_cw *cw)
{
    int     args[3];
    char    bytes[1];
    int     res;
    int     i;

    i = 0;
    while (i < 3)
    {
        get_arg(i, car, cw->arena, bytes);
        args[i] = get_int(bytes, 1);
        ++i;
    }
    res = args[0] - args[1];
    car->reg[args[2] - 1] = res;
    car->carry = res ? 0 : 1;
}