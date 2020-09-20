#include "game.h"

void            ch_lfork(t_carriage *car, t_cw *cw)
{
    t_carriage  *new;
    char        bytes[4];
    int         pos;
    int         i;

    get_arg(0, car, cw->arena, bytes);
    pos = (car->position + get_int(bytes, car->op->dir_size == 0 ? 4 : 2)) % MEM_SIZE;
    new = create_carriage(++cw->cars_amount, pos);
    i = 0;
    while (i < REG_NUMBER)
    {
        new->reg[i] = car->reg[i];
        ++i;
    }
    new->carry = car->carry;
    new->last_cycle_live = car->last_cycle_live;
    new->next = cw->carriage_list;
    cw->carriage_list = new;
}