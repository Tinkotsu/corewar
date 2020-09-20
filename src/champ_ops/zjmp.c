#include "game.h"

void            ch_zjmp(t_carriage *car, t_cw *cw)
{
    char    bytes[car->op->dir_size];
    int     arg;

    if (car->carry)
    {
        get_arg(0, car, cw->arena, bytes);
        arg = get_int(bytes, car->op->dir_size);
        car->position = (car->position + (arg % IDX_MOD)) % MEM_SIZE;
    }
}
