/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:45 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:38:46 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void            ch_sub(t_carriage *car, t_cw *cw)
{
    int args[3];
    int res;

    get_args(args, car, cw);
    res = car->reg[args[0] - 1] - car->reg[args[1] - 1];
    car->reg[args[2] - 1] = res;
    car->carry = res ? 0 : 1;
}