#include "game.h"
//использовал abs

void            ch_zjmp(t_carriage *car, t_cw *cw)
{
    char    bytes[car->op->dir_size == 0 ? 4 : 2];
    int     arg;

    if (car->carry)
    {
        get_arg(0, car, cw->arena, bytes);
        arg = get_int(bytes, car->op->dir_size == 0 ? 4 : 2) % IDX_MOD;
        arg = arg < 0 ? MEM_SIZE - abs(arg) % MEM_SIZE : arg;
        car->position = (car->position + arg) % MEM_SIZE;
        car->step = 0;
    }
}
