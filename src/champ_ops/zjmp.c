#include "game.h"

void            ch_zjmp(t_carriage *car, t_cw *cw)
{
    unsigned char       bytes[car->op->dir_size == 0 ? 4 : 2];
    int                 arg;

    if (car->carry)
    {
        get_arg(0, car, cw->arena, bytes);
        arg = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
        car->position = (car->position + (arg % IDX_MOD)) % MEM_SIZE;
        car->step = 0;
    }
}
