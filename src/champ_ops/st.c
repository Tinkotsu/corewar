#include "game.h"

void            ch_st(t_carriage *car, t_cw *cw)
{
    char    bytes[2];
    int     reg_i;
    int     ind_value;
    int     ind_pos;

    get_arg(0, car, cw->arena, bytes);
    reg_i = get_int(bytes, 2);
    get_arg(1, car, cw->arena, bytes);
    if (car->args[1] == 1)
        car->reg[get_int(bytes, 2) - 1] = car->reg[reg_i - 1];
    else
    {
        ind_value = get_int(bytes, IND_SIZE);
        ind_pos = ((car->position + ind_value) % IDX_MOD) % MEM_SIZE;
        set_int(cw->arena, ind_pos, car->reg[reg_i - 1]);
    }
}