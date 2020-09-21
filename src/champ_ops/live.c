#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    int     args[1];

    car->last_cycle_live = cw->game_cycles;
    get_args(args, car, cw);
    if (-args[0] > 0 && -args[0] <= cw->players_amount)
        cw->last_player_alive = -car->reg[0];
    ++cw->live_ops;
}