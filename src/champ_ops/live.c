#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    int     arg;
    unsigned char    arg_bytes[car->op->dir_size == 0 ? 4 : 2];

    get_arg(0, car, cw->arena, arg_bytes);
    car->last_cycle_live = cw->game_cycles;
    arg = get_int(arg_bytes, car->op->dir_size == 0 ? 4 : 2);
    if (-arg > 0 && -arg <= cw->players_amount)
        cw->last_player_alive = -car->reg[0];
    ++cw->live_ops;
}