/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:42:55 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:55:43 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nullifier(t_pf *s)
{
	s->width_len = 0;
	s->p_len = 0;
	s->flags_count = 0;
	s->flag_zero = 0;
	s->flag_diez = 0;
	s->flag_space = 0;
	s->flag_plus = 0;
	s->flag_minus = 0;
	s->dot_pos = 0;
	s->f_len = 0;
	s->ox = 0;
	s->first_len = -1;
	s->exp = 0;
	s->fl_len = 0;
	s->was_diez = 0;
	s->negative_p = 0;
	s->oversize = 0;
	s->count_of_0 = 0;
	s->b = 0;
	s->col = 0;
}

void		re_initialize(t_pf *s)
{
	int	i;

	nullifier(s);
	s->strlen = 0;
	s->ret_value = 0;
	s->t = '\0';
	i = -1;
	while (++i < 2)
		s->modf[i] = '\0';
	ft_strdel(&s->value);
	ft_strdel(&s->p);
	ft_strdel(&s->width);
	s->pre = NULL;
	s->cur = NULL;
	ft_strdel(&s->pre);
	ft_strdel(&s->cur);
}
