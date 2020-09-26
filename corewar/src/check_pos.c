/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:02 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:17:39 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_pos(int pos)
{
	if (pos < 0)
		return (MEM_SIZE - ((-pos) % MEM_SIZE));
	else if (pos >= MEM_SIZE)
		return (pos % MEM_SIZE);
	return (pos);
}
