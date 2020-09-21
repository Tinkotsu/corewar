#include "game.h"

void            ch_ldi(t_carriage *car, t_cw *cw)
{
    int     args[3];
    char    bytes[4];
    int     pos;
    int     i;
    int     res;

    i = 0;
    while (i < 2)
    {
        if (car->args[i] == 1)
            args[i] = car->reg[get_int(bytes, 1) - 1];
        else if (car->args[i] == 2)
            args[i] = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
        else if (car->args[i] == 4)
            args[i] = get_ind_value(car, cw->arena, bytes, 0);
        ++i;
    }
    pos = (car->position + (args[0] + args[1]) % IDX_MOD) % MEM_SIZE;
    get_arg_bytes(bytes, 4, cw->arena, pos);
    res = get_int(bytes, 4);
    get_arg(2, car, cw->arena, bytes);
    car->reg[get_int(bytes, 1) - 1] = res;
}