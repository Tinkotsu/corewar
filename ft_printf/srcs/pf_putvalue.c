/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:03:17 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/11 18:22:11 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_is_diez(t_pf *s)
{
	if (s->p_len && !s->p_size && ft_strchr("xX", s->t) && *s->value == '0')
		if (!s->width_len && s->flag_space)
			s->width_len--;
		else
			s->strlen--;
	else
		write(1, s->value + s->sign, s->strlen - s->sign);
}

void		pf_putvalue(t_pf *s)
{
	if (s->flag_diez)
		pf_is_diez(s);
	else
	{
		if (s->p_len && !s->p_size && ft_strchr("xXdDiouUOp", s->t)
				&& *s->value == '0')
		{
			if (!s->width_len && s->flag_space)
				s->width_len--;
			else
				s->strlen--;
		}
		else if (s->t == 'f')
		{
			if ((s->d.d != s->d.d || (s->d.d_parts.exponent == 32767 &&
					s->d.d_parts.mantisa > 9223372036854775807)) || s->p_size)
				s->was_diez = 0;
			s->strlen += s->was_diez;
			write(1, s->value + s->sign, s->strlen - s->sign);
		}
		else
			write(1, s->value + s->sign, s->strlen - s->sign);
	}
}
