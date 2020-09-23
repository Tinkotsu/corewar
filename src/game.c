/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:49 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:06:02 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        if (car->last_cycle_live <= cw->game_cycles - cw->cycles_to_die ||
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

static void     get_op_code(char *arena, t_carriage *car)
{
    car->op_i = arena[car->position];
    if (car->op_i >= 1 && car->op_i <= 0x10)
    {
        car->op = &g_op_tab[car->op_i - 1];
        car->cycles_till_op = car->op->cycles;
    }
    else
        car->cycles_till_op = 0;
}

static void     execute_op(t_cw *cw, t_carriage *car)
{
    ++car->step;
    if (car->op && validate_op(cw, car))
        g_champ_ops[car->op_i - 1](car, cw);
    car->position = check_pos(car->position + car->step);
    car->step = 0;
    car->op = NULL;
 }

static void     main_cycle(t_cw *cw)
{
    t_carriage *car;

    car = cw->carriage_list;
    while (car)
    {
        if (!car->op)
            get_op_code(cw->arena, car);
        if (car->cycles_till_op > 0)
            --car->cycles_till_op;
        if (car->cycles_till_op == 0)
            execute_op(cw, car);
        car = car->next;
    }
}

void            game(t_cw *cw)
{
    int         loop_iter;

    loop_iter = 1;
    cw->game_cycles = 1;
    while (cw->carriage_list)
    {
        main_cycle(cw);
        if (cw->d_flag && cw->game_cycles == cw->d_cycles)
        {
            display_arena(cw->arena, 32 * cw->d_flag);
            return ;
        }
        if (loop_iter == cw->cycles_to_die || cw->cycles_to_die <= 0)
        {
            check(cw);
            loop_iter = 0;
        }
        ++loop_iter;
        ++cw->game_cycles;
    }
}