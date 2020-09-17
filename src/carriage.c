#include "corewar.h"

t_carriage   *create_carriage(int id, char *pos, int player_id)
{
    t_carriage  *car;
    int         i;

    car = (t_carriage *)malloc(sizeof(t_carriage));
    if (!car)
        error("Memory error");
    car->id = id;
    car->carry = 0;
    car->op = -1;
    car->cycles_till_op = -1;
    car->last_cycle_live = -1;
    car->step = -1;
    car->position = pos;
    car->reg[0] = -player_id;
    i = 1;
    while (i < REG_NUMBER)
        car->reg[i++] = 0;
    return (car);
}