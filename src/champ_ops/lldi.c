#include "game.h"

void            ch_lldi(t_carriage *car, t_cw *cw)
{
    int     args[3];
    char    bytes[4];
    int     pos;
    int     i;

    i = 0;
    while (i < 3)
    {
        get_arg(i, car, cw->arena, bytes);
        if (car->op->args[i] == 1)
            args[i] = car->reg[get_int(bytes, 1) - 1];
        else if (car->op->args[i] == 2)
            args[i] = get_int(bytes, car->op->dir_size);
        else if (car->op->args[i] == 4)
            args[i] = get_ind_value(car, cw->arena, bytes, 0);
        ++i;
    }
    pos = (car->position + args[0] + args[1]) % MEM_SIZE;
    get_arg_bytes(bytes, 4, cw->arena, pos);
    i = get_int(bytes, 4);
    car->reg[args[2] - 1] = i;
    car->carry = i ? 0 : 1;
}