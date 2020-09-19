#include "game.h"

void    ch_live(t_carriage *car, t_cw *cw)
{
    int arg;
    int dir_size;

    dir_size = op_tab[0].dir_size;
    car->last_cycle_live = cw->game_cycles;
    arg = get_int(&(cw->arena[car->position + 1]), dir_size);
    if (arg == -car->reg[0])
        cw->last_player_alive = car->id; //если id совпадает с id игроком (на данный момент в инициализации каретки она создается с id игрока)
    ++cw->live_ops;
}