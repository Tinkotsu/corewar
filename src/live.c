/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:37:23 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:37:54 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ch_live(t_carriage *car, t_cw *cw)
{
	int	args[1];

	car->last_cycle_live = cw->game_cycles;
	get_args(args, car, cw);
	if (-args[0] > 0 && -args[0] <= cw->players_amount)
		cw->last_player_alive = -args[0];
	++cw->live_ops;
}
