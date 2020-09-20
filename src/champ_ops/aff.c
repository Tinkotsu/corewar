#include "game.h"

void            ch_aff(t_carriage *car, t_cw *cw)
{
    char    bytes[1];
    int     reg_i;

    if (cw->a_flag)
    {
        get_arg(0, car, cw->arena, bytes);
        reg_i = get_int(bytes, 1);
        ft_putchar((char)car->reg[reg_i - 1]);
    }
}