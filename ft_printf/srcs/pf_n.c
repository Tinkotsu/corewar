/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:43:15 by ifran             #+#    #+#             */
/*   Updated: 2020/09/16 21:13:35 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_n(t_pf *s)
{
	if (s->modf[0] == 'l' && ++s->str)
	{
		if (s->modf[1] == 'l' && ++s->str)
			*(va_arg(s->ap, long long *)) = (long long)s->len;
		else
			*(va_arg(s->ap, long *)) = (long)s->len;
	}
	else if (s->modf[0] == 'h' && ++s->str)
	{
		if (s->modf[1] == 'h' && ++s->str)
			*(va_arg(s->ap, signed char *)) = (signed char)s->len;
		else
			*(va_arg(s->ap, short *)) = (short)s->len;
	}
	else
		*(va_arg(s->ap, int *)) = (int)s->len;
}
