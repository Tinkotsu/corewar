/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:57 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:49:51 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ch_zjmp(t_carriage *car, t_cw *cw)
{
	int	args[1];

	if (car->carry)
	{
		get_args(args, car, cw);
		car->position = check_pos(car->position + args[0] % IDX_MOD);
		car->step = 0;
	}
}
