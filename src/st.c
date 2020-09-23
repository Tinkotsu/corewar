/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:31 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:48:13 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ch_st(t_carriage *car, t_cw *cw)
{
	int args[2];
	int value;

	get_args(args, car, cw);
	value = car->reg[args[0] - 1];
	if (car->args[1] == 1)
		car->reg[args[1] - 1] = value;
	else
		set_int(cw->arena, args[1] % IDX_MOD + car->position, value);
}
