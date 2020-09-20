#include "game.h"

void            ch_xor(t_carriage *car, t_cw *cw)
{
    int     args[3];
    char    bytes[4];
    int     res;
    int     i;

    i = 0;
    while (i < 3)
    {
        get_arg(i, car, cw->arena, bytes);
        if (car->op->args[i] == 1)
            args[i] = car->reg[get_int(bytes, 1) - 1];
        else if (car->op->args[i] == 2)
            args[i] = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
        else if (car->op->args[i] == 4)
            args[i] = get_ind_value(car, cw->arena, bytes, 0);
        ++i;
    }
    res = args[0] ^ args[1];
    car->reg[args[2] - 1] = res;
    car->carry = res ? 0 : 1;
}