/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:14:50 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 14:15:37 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flag_zero(t_pf *s)
{
	s->sign = print_precision(s);
	if (s->flag_space)
	{
		ft_putchar(' ');
		s->len++;
		s->width_len--;
	}
	write(1, s->width, s->width_len);
	pf_putvalue(s);
}
