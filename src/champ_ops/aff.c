#include "game.h"

void            ch_aff(t_carriage *car, t_cw *cw)
{
    unsigned char    byte;
    int     reg_i;

    if (cw->a_flag)
    {
        get_arg(0, car, cw->arena, &byte);
        reg_i = get_int(&byte, 1);
        ft_putchar((char)car->reg[reg_i - 1]);
    }
}