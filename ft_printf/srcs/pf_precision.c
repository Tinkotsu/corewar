/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:37:35 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 21:03:01 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_precision(t_pf *s)
{
	int sign;

	sign = (*s->value == '-') ? 1 : 0;
	if (s->p_len)
	{
		s->ret_value += s->p_len;
		if (s->t == 's' && s->p_size < s->strlen)
		{
			s->p_len = 0;
			if (!s->negative_p)
				s->strlen = s->p_size;
		}
		else if (ft_strchr("dDioOxXuUp", s->t))
			if (s->strlen - sign < s->p_size)
			{
				if (!(s->p = ft_strnew(s->p_size - s->strlen + sign)))
					case_of_error();
				ft_memset(s->p, '0', s->p_size - s->strlen + sign);
			}
	}
}

void		pf_precision(t_pf *s)
{
	s->p_size = 0;
	if (*s->str == '.' && (s->str)++)
		s->p_len++;
	while (ft_isdigit(*s->str))
	{
		s->p_size = s->p_size * 10 + *(s->str) - 48;
		(s->str)++;
		(s->p_len)++;
	}
	if (*s->str == '*' && (s->str)++ && ++(s->p_len))
	{
		s->p_size = va_arg(s->ap, int);
		if ((int)s->p_size < 0)
		{
			s->p_size = 0;
			s->negative_p = 1;
		}
	}
	pf_modifier(s);
	if (!s->value)
		return ;
	do_precision(s);
}
