/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:26 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:24:05 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		announce_winner(t_player *winner)
{
	ft_putstr("Contestant ");
	ft_putnbr(winner->id);
	ft_putstr(", \"");
	ft_putstr(winner->name);
	ft_putstr("\", has won !\n");
}

static void		free_data(t_cw *cw)
{
	t_carriage	*car;
	t_carriage	*next;
	int			i;

	car = cw->carriage_list;
	while (car)
	{
		next = car->next;
		free(car);
		car = next;
	}
	i = 0;
	while (i < cw->players_amount)
	{
		free(cw->players[i]->exec_code);
		free(cw->players[i]);
		++i;
	}
	free(cw->players);
	free(cw->arena);
}

void			endgame(t_cw *cw)
{
	if (!cw->carriage_list)
		announce_winner(cw->players[cw->last_player_alive - 1]);
	free_data(cw);
}
