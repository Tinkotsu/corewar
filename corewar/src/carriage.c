/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:35:41 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:13:50 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					delete_carriages(int to_delete, t_cw *cw)
{
	t_carriage	*prev;
	t_carriage	*cur;

	prev = NULL;
	cur = cw->carriage_list;
	while (to_delete)
	{
		if (cur->to_delete)
		{
			if (prev)
				prev->next = cur->next;
			else
				cw->carriage_list = cur->next;
			free(cur);
			cur = prev ? prev->next : cw->carriage_list;
			--to_delete;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

t_carriage				*create_carriage(int id, int pos)
{
	t_carriage	*car;
	int			i;

	car = (t_carriage *)malloc(sizeof(t_carriage));
	if (!car)
		error("Memory error");
	car->id = id;
	car->carry = 0;
	car->op_i = -1;
	car->op = NULL;
	car->cycles_till_op = 0;
	car->last_cycle_live = -1;
	car->step = 0;
	car->position = pos;
	car->reg[0] = -id;
	car->to_delete = 0;
	i = 1;
	while (i < REG_NUMBER)
		car->reg[i++] = 0;
	i = 0;
	while (i < 4)
		car->args[i++] = 0;
	return (car);
}
