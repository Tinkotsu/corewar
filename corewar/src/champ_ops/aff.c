/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:35:30 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:10:48 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ch_aff(t_carriage *car, t_cw *cw)
{
	int	args[1];

	get_args(args, car, cw);
	if (cw->a_flag)
		ft_putchar((char)car->reg[args[0] - 1]);
}
