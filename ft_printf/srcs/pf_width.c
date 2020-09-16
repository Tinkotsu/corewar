/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:33:31 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 21:02:17 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_width(t_pf *s, int w_len, int width)
{
	s->ret_value += w_len;
	if (*s->value == '0' && s->p_size == 0 && s->p_len)
		w_len = 0;
	else
		w_len = s->strlen + (s->p ? ft_strlen(s->p) : 0);
	if (width > w_len)
	{
		s->width_len = width - w_len;
		s->width = ft_strnew(s->width_len);
		ft_memset(s->width, ' ', s->width_len);
	}
}

void		pf_width(t_pf *s)
{
	size_t	w_len;
	int		width;

	w_len = 0;
	if (*s->str == '*' && (s->str)++ && ++w_len)
	{
		width = va_arg(s->ap, int);
		if (width < 0 && (width = abs(width)))
			if (!s->flag_minus && (s->flag_minus = 45))
				s->flags_count++;
	}
	if (ft_isdigit(*s->str))
		width = 0;
	while (ft_isdigit(*s->str))
	{
		width = width * 10 + *s->str - 48;
		(s->str)++;
		w_len++;
	}
	pf_precision(s);
	if (s->value && w_len)
		do_width(s, w_len, width);
}
