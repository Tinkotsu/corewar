#include "game.h"

void            ch_lld(t_carriage *car, t_cw *cw)
{
    int     args[2];
    int     res;

    get_args(args, car, cw);
    if (car->args[0] == 2)
        res = args[0];
    else
        res = get_ind_value(args[0], car->position, cw->arena, 1);
    car->reg[args[1] - 1] = res;
    car->carry = res ? 0 : 1;
}