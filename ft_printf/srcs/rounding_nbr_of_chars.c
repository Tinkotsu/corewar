/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_nbr_of_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:01:38 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:01:39 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		rounding_dec(t_pf *s, size_t *index, char *nbr)
{
	if (s->p_size)
	{
		*index = s->dot_pos + s->p_size + 1;
		*nbr = s->value[*index];
	}
	if (*nbr >= 53 && *nbr < 57)
		*nbr = s->value[--(*index)];
	while (*nbr == 57)
	{
		s->value[*index] = 48;
		*nbr = s->value[--(*index)];
	}
}

void			rounding(t_pf *s, size_t *index)
{
	char	nbr;

	nbr = s->value[*index];
	rounding_dec(s, index, &nbr);
	if (s->value[*index] == '.')
		nbr = s->value[--(*index)];
	while (nbr == 57)
	{
		s->value[*index] = 48;
		nbr = s->value[--(*index)];
	}
	s->value[*index] += 1;
}
