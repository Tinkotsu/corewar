#include "game.h"

static void     check(t_cw *cw)
{
    int         cars_to_delete;
    t_carriage  *car;

    ++cw->checks_performed;
    car = cw->carriage_list;
    cars_to_delete = 0;
    while (car)
    {
        if (car->last_cycle_live >= cw->cycles_to_die ||
            cw->cycles_to_die <= 0)
        {
            ++cars_to_delete;
            car->to_delete = 1;
        }
        car = car->next;
    }
    if (cars_to_delete)
        delete_carriages(cars_to_delete, cw);
    if (cw->live_ops >= NBR_LIVE || cw->checks_performed == MAX_CHECKS)
    {
        cw->checks_performed = 0;
        cw->cycles_to_die -= CYCLE_DELTA;
    }
    cw->live_ops = 0;
}

static void     reduce_carriages_cycles_till_op(t_carriage *car)
{
    while (car)
    {
        if (car->cycles_till_op > 0)
            --car->cycles_till_op;
        car = car->next;
    }
}

static void     get_op_code(char *arena, t_carriage *car)
{
    while (car)
    {
        car->op_i = arena[car->position];
        if (car->op_i >= 0x01 && car->op_i <= 0x10)
        {
            car->op = &op_tab[car->op_i];
            car->cycles_till_op = car->op->cycles;
        }
        else
        {
            car->op = NULL;
            car->cycles_till_op = 0;
        }
        car = car->next;
    }
}

static void     execute_op(t_cw *cw, t_carriage *car)
{
    while (car)
    {
        if (car->cycles_till_op == 0)
        {
            ++car->step;
            if (car->op && validate_op(cw, car))
                champ_ops[car->op_i](car, cw);
            car->position = (car->position + car->step) % MEM_SIZE;
            car->step = 0;
        }
        car = car->next;
    }
}

void            game(t_cw *cw)
{
    int loop_iter;

    while (cw->carriage_list)
    {
        loop_iter = cw->cycles_to_die > 0 ? cw->cycles_to_die : 0;
        while (loop_iter)
        {
            if (cw->d_flag && cw->game_cycles == cw->d_cycles)
            {
                display_arena(cw->arena, 32 * cw->d_flag);
                return ;
            }
            get_op_code(cw->arena, cw->carriage_list);
            reduce_carriages_cycles_till_op(cw->carriage_list);
            execute_op(cw, cw->carriage_list);
            --loop_iter;
            ++cw->game_cycles;
        }
        check(cw);
    }
}