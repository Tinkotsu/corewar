/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:09:04 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 14:09:38 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_precision(t_pf *s)
{
	if (s->t != 's' && s->t != 'c' && s->t != 'C' && *s->value == '-')
	{
		ft_putchar(*s->value);
		write(1, s->p, ft_strlen(s->p));
		return (1);
	}
	if (s->ox == 1)
		write(1, s->p, ft_strlen(s->p) - s->ox);
	else if (s->p)
		write(1, s->p, ft_strlen(s->p));
	if (!s->p || s->ox != 1)
		s->ox = 0;
	return (0);
}
