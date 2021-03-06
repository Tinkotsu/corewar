/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:37:01 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:35:26 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		set_int(char *arena, int start_pos, int num)
{
	start_pos = check_pos(start_pos);
	arena[start_pos] = (num & 0xff000000) >> 24;
	arena[(start_pos + 1) % MEM_SIZE] = (num & 0x00ff0000) >> 16;
	arena[(start_pos + 2) % MEM_SIZE] = (num & 0x0000ff00) >> 8;
	arena[(start_pos + 3) % MEM_SIZE] = (num & 0x000000ff);
}

static int	get_short_int(char *bytes)
{
	short	s_number;
	int		i;

	i = 0;
	s_number = 0;
	while (i < 2)
	{
		s_number |= ((unsigned char)bytes[i]) << 8 * (1 - i);
		++i;
	}
	return (s_number);
}

int			get_int(char *bytes, int size)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	if (size == 2)
		number = get_short_int(bytes);
	else
	{
		while (i < 4)
		{
			number |= ((unsigned char)bytes[i]) << 8 * (3 - i);
			++i;
		}
	}
	return (number);
}
