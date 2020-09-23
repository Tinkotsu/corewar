/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:40 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:38:40 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void            ch_sti(t_carriage *car, t_cw *cw)
{
    int args[3];
    int values[3];
    int i;
    int pos;

    get_args(args, car, cw);
    i = 0;
    while (i < 3)
    {
        if (car->args[i] == 1)
            values[i] = car->reg[args[i] - 1];
        else if (car->args[i] == 2)
            values[i] = args[i];
        else if (car->args[i] == 4)
            values[i] = get_ind_value(args[i], car->position, cw->arena, 0);
        ++i;
    }
    pos = (values[1] + values[2]) % IDX_MOD + car->position;
    set_int(cw->arena, pos, values[0]);
}