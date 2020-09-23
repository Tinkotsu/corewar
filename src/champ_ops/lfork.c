/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:37:18 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:37:31 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ch_lfork(t_carriage *car, t_cw *cw)
{
	t_carriage		*new;
	int				args[1];
	int				pos;
	int				i;

	get_args(args, car, cw);
	pos = check_pos(car->position + args[0]);
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
