/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:37:28 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:37:29 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void            ch_lld(t_carriage *car, t_cw *cw)
{
    int     args[2];
    int     res;

    get_args(args, car, cw);
    if (car->args[0] == 2)
        res = args[0];
    else
        res = get_ind_value(args[0], car->position, cw->arena, 1);
    car->reg[args[1] - 1] = res;
    car->carry = res ? 0 : 1;
}