/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:14 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:22:42 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void	display_arena(char *arena, int octets_num)
{
	int	counter;
	int	i;

	counter = 0;
	while (counter < MEM_SIZE)
	{
		printf("0x%04x : ", counter);
		i = 0;
		while (i < octets_num)
		{
			printf("%02x ", (unsigned char)*arena);
			arena++;
			i++;
		}
		printf("\n");
		counter += octets_num;
	}
}
