#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    int     arg;
    char    arg_bytes[car->op->dir_size];

    get_arg(0, car, cw->arena, arg_bytes);
    car->last_cycle_live = cw->game_cycles;
    arg = get_int(arg_bytes, car->op->dir_size);
    if (-arg > 0 && -arg <= cw->players_amount)
        cw->last_player_alive = -car->reg[0];
    ++cw->live_ops;
}