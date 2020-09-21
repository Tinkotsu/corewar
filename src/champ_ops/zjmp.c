#include "game.h"

void            ch_zjmp(t_carriage *car, t_cw *cw)
{
    int args[1];

    get_args(args, car, cw);
    if (car->carry)
    {
        car->position = check_pos(car->position + args[0] % IDX_MOD);
        car->step = 0;
    }
}
