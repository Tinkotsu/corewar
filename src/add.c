#include "game.h"

void            ch_add(t_carriage *car, t_cw *cw)
{
    int args[3];
    int res;

    get_args(args, car, cw);
    res = car->reg[args[0] - 1] + car->reg[args[1] - 1];
    car->reg[args[2] - 1] = res;
    car->carry = res ? 0 : 1;
}