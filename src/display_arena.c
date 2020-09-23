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

static void     get_hex(int n, int *len, char *buff, int i)
{
	int c;

	if (n >= 16)
    {
        *len += 1;
		get_hex(n / 16, len, buff, i - 1);
    }
    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	buff[i] = c;
}

static void		print_hex(char *buff, int len, int width)
{
    int i;
    char c;

    i = 0;
	while (i + len < width)
	{
	    ++i;
        ft_putchar('0');
    }
	while (i < width)
	    ft_putchar(buff[i++]);
}

static void		print_octets(char *arena, int octets_num)
{
	int     i;
	int     len;
    char    buff[2];

	i = 0;
	while (i < octets_num)
	{
		len = 1;
		ft_bzero(buff, 2);
		get_hex((unsigned char)*arena, &len, buff, 1);
		print_hex(buff, len, 2);
		ft_putchar(' ');
		++arena;
		++i;
	}
}

void            display_arena(char *arena, int octets_num)
{
	int		counter;
	int     len;
    char	buff[4];

	counter = 0;
	while (counter < MEM_SIZE)
	{
		ft_bzero(buff, 4);
        len = 1;
		ft_putstr("0x");
		get_hex(counter, &len, buff, 3);
		print_hex(buff, len, 4);
        ft_putstr(" : ");
		print_octets(arena, octets_num);
        ft_putchar('\n');
		counter += octets_num;
        arena += octets_num;
	}
}
