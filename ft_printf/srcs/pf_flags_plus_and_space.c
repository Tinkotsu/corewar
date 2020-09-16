/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:19:13 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/09 14:22:19 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flags_plus_and_space(t_pf *s)
{
	if (s->width_len && !s->flag_minus && !s->flag_zero)
		write(1, s->width, --s->width_len);
	ft_putchar(s->flag_plus | s->flag_space);
	s->len += 1;
	if (s->width_len && s->flag_zero)
		write(1, s->width, --s->width_len);
	s->sign = print_precision(s);
	pf_putvalue(s);
	if (s->width_len && s->flag_minus)
		write(1, s->width, --s->width_len);
}
