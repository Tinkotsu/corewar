/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:52 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:49:31 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ch_xor(t_carriage *car, t_cw *cw)
{
	int args[3];
	int values[2];
	int res;
	int i;

	i = 0;
	get_args(args, car, cw);
	while (i < 2)
	{
		if (car->args[i] == 1)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == 2)
			values[i] = args[i];
		else if (car->args[i] == 4)
			values[i] = get_ind_value(args[i], car->position, cw->arena, 0);
		++i;
	}
	res = values[0] ^ values[1];
	car->reg[args[2] - 1] = res;
	car->carry = res ? 0 : 1;
}
