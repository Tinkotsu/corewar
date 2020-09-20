#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    int     arg;
    char    arg_bytes[car->op->dir_size];
    char    *pos;

    car->last_cycle_live = cw->game_cycles;
    pos = get_arg_pos(0, car, cw->arena);
    get_arg_bytes(arg_bytes, car->op->dir_size, pos, car->position);
    arg = get_int(arg_bytes, car->op->dir_size);
    if (-arg > 0 && -arg <= cw->players_amount)
        cw->last_player_alive = -car->reg[0];
    ++cw->live_ops;
}