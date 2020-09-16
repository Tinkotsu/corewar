/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:17:05 by ifran             #+#    #+#             */
/*   Updated: 2019/10/22 14:58:51 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_str(t_pf *s, const char **start)
{
	size_t	n;
	int		c_res;

	while (*(s->str) == '%' || *(s->str) == '{')
	{
		n = ft_strlen(*start) - ft_strlen(s->str);
		s->len += n;
		write(1, *start, n);
		if (*(s->str) == '%' && *(++s->str))
		{
			pf_flags(s);
			re_initialize(s);
		}
		else if (*(s->str) == '{')
		{
			c_res = pf_colours(s);
			if (!c_res && ++s->len)
				write(1, s->str++, 1);
			s->str += c_res;
		}
		*start = s->str;
	}
}

int				ft_printf(const char *str, ...)
{
	t_pf		*s;
	int			res;
	const char	*start;
	size_t		len;

	s = initialize(str);
	va_start(s->ap, str);
	start = s->str;
	while (1)
	{
		check_str(s, &start);
		if (!(*s->str))
		{
			len = ft_strlen(start);
			write(1, start, len);
			s->len += len;
			break ;
		}
		++s->str;
	}
	va_end(s->ap);
	res = s->len + s->col;
	free(s);
	return (res);
}
