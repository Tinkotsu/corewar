#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    car->last_cycle_live = cw->game_cycles;

    ++cw->live_ops;
}