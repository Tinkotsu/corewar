#include "game.h"

void    ch_ld(t_carriage *car, t_cw *cw)
{
    int     res;
    char    bytes[4];

    get_arg(0, car, cw->arena, bytes);
    if (car->op->args[0] == 2)
        res = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
    else
        res = get_ind_value(car, cw->arena, bytes, 0);
    get_arg(1, car, cw->arena, bytes);
    car->reg[get_int(bytes, 1) - 1] = res;
    car->carry = res ? 0 : 1;
}