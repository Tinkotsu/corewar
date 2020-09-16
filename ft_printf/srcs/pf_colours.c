/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:13:55 by ifran             #+#    #+#             */
/*   Updated: 2019/10/22 15:00:50 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_colours(t_pf *s)
{
	int			ret;
	const char	*str;

	str = s->str;
	ret = 0;
	if ((ft_strnequ(str, "{red}", 5)) && (ret = 5) && (s->col += 5))
		ft_putstr("\x1b[31m");
	else if ((ft_strnequ(str, "{green}", 7)) && (ret = 7) && (s->col += 5))
		ft_putstr("\x1b[32m");
	else if ((ft_strnequ(str, "{yellow}", 8)) && (ret = 8) && (s->col += 5))
		ft_putstr("\x1b[33m");
	else if ((ft_strnequ(str, "{blue}", 6)) && (ret = 6) && (s->col += 5))
		ft_putstr("\x1b[34m");
	else if ((ft_strnequ(str, "{magenta}", 9)) && (ret = 9) && (s->col += 5))
		ft_putstr("\x1b[35m");
	else if ((ft_strnequ(str, "{cyan}", 6)) && (ret = 6) && (s->col += 5))
		ft_putstr("\x1b[36m");
	else if ((ft_strnequ(str, "{eoc}", 5)) && (ret = 5) && (s->col += 4))
		ft_putstr("\x1b[0m");
	return (ret);
}
