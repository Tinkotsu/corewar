#include "game.h"

void    ch_ld(t_carriage *car, t_cw *cw)
{
    int     res;
    char    bytes[4];
    char    *pos;

    pos = get_arg_pos(0, car, cw->arena);
    if (car->op->args[0] == 2)
    {
        get_arg_bytes(bytes, car->op->dir_size, pos, 0);
        res = get_int(bytes, car->op->dir_size);
    }
    else
    {
        get_arg_bytes(bytes, IND_SIZE, pos, 0);
        res = get_int(bytes, IND_SIZE);

    }
}
