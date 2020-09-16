/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:49:33 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 18:24:45 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_modifier(t_pf *s)
{
	if (*s->str == 'l' && s->str++ && ++s->ret_value)
	{
		s->modf[0] = 'l';
		if (*s->str == 'l' && s->str++ && ++s->ret_value)
			s->modf[1] = 'l';
	}
	else if (*s->str == 'h' && s->str++ && ++s->ret_value)
	{
		s->modf[0] = 'h';
		if (*s->str == 'h' && s->str++ && ++s->ret_value)
			s->modf[1] = 'h';
	}
	else if ((*s->str == 'L' || *s->str == 'l') && s->str++)
	{
		s->modf[0] = *(s->str - 1);
		++s->ret_value;
	}
	else if (*s->str == 'm' && s->str++)
	{
		s->modf[0] = *(s->str - 1);
		++s->ret_value;
	}
	pf_type(s);
}
