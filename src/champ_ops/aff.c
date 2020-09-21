#include "game.h"

void            ch_aff(t_carriage *car, t_cw *cw)
{
    char    args[1];

    get_args(args, car, cw);
    if (cw->a_flag)
        ft_putchar((char)car->reg[args[0] - 1]);
}