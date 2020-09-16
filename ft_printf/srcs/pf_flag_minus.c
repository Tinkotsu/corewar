/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:16:29 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 14:17:04 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flag_minus(t_pf *s)
{
	if (s->flag_space)
	{
		ft_putchar(s->flag_space);
		s->len += 1;
		if (s->width_len)
			s->width_len--;
	}
	s->sign = print_precision(s);
	pf_putvalue(s);
	write(1, s->width, s->width_len);
}
