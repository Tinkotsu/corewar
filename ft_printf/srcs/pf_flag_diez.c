/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_diez.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:57:32 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/10 16:59:29 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_diez(t_pf *s)
{
	if (ft_strchr("oOxXp", s->t) && (s->t == 'p' ||
			*s->value != '0') && ++s->len && ++s->ox)
	{
		s->modf[0] = '0';
		if ((s->t == 'x' || s->t == 'p') && ++(s->len) && ++s->ox)
			s->modf[1] = 'x';
		else if (s->t == 'X' && ++(s->len) && ++s->ox)
			s->modf[1] = 'X';
		if (s->t == 'p')
			s->width_len = (s->ox + s->strlen >=
					s->width_len + s->strlen) ? 0 : s->width_len - s->ox;
		else if (s->width_len >= s->ox && s->ox != 1)
			s->width_len -= s->ox;
	}
}

void	pf_flag_diez(t_pf *s)
{
	do_diez(s);
	if (ft_strchr("oO", s->t) && s->width_len)
		if ((s->p_len && !s->p) || (!s->p_len && *s->value != '0'))
			s->width_len--;
	if (!s->flag_minus && !s->flag_zero)
		write(1, s->width, s->width_len);
	if (s->ox > 0)
	{
		ft_putchar(s->modf[0]);
		if (s->ox > 1)
			ft_putchar(s->modf[1]);
	}
	if (s->flag_zero)
		write(1, s->width, s->width_len);
	s->sign = print_precision(s);
	pf_putvalue(s);
	if (s->flag_minus)
		write(1, s->width, s->width_len);
}
