/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:38:20 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 15:23:15 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*initialize(const char *str)
{
	t_pf	*s;

	if (!(s = (t_pf*)ft_memalloc(sizeof(t_pf))))
		case_of_error();
	s->types = "oXxudiDUOpfcCsnb%";
	func_arr(s);
	s->str = str;
	s->len = 0;
	re_initialize(s);
	return (s);
}
