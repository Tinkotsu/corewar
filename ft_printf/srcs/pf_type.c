/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:55:51 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 19:01:46 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pnbp(t_pf *s, size_t i)
{
	if (s->t == 'p')
	{
		s->ta = va_arg(s->ap, unsigned long long);
		s->value = s->func[i].func(&(s->ta));
	}
	else if (s->t == '%')
	{
		if (!(s->value = ft_strnew(1)))
			case_of_error();
		*s->value = '%';
	}
	else if (s->t == 'n')
		pf_n(s);
	else
	{
		s->ta = va_arg(s->ap, unsigned long int);
		s->value = to_binary(s->ta);
	}
}

static void	do_s(t_pf *s)
{
	if (!(s->p = va_arg(s->ap, char *)))
	{
		if (!(s->value = ft_strdup("(null)")))
			case_of_error();
	}
	else
	{
		if (!(s->value = ft_strdup(s->p)))
			case_of_error();
		if (s->modf[0] == 'm' && !s->modf[1])
		{
			if (!(s->value = morse(s->value)))
				case_of_error();
		}
	}
	s->p = NULL;
}

static void	csp(t_pf *s, size_t i)
{
	if (s->t == '%' || s->t == 'n' || s->t == 'p' || s->t == 'b')
		pnbp(s, i);
	else if (s->t == 'c' || s->t == 'C')
	{
		if (!(s->value = ft_strnew(1)))
			case_of_error();
		*s->value = va_arg(s->ap, int);
	}
	else if (s->t == 's')
		do_s(s);
}

static void	do_number(t_pf *s, size_t i)
{
	s->ta = va_arg(s->ap, long long);
	if (!(s->modf[0]))
	{
		if (s->t == 'd' || s->t == 'i')
			s->ta = (int)s->ta;
		else if (s->t == 'U' || s->t == 'O')
			s->ta = (unsigned long long)s->ta;
		else
			s->ta = (unsigned int)s->ta;
	}
	else if (s->modf[0] == 'l' && s->modf[1] == '\0')
	{
		if (s->t == 'd' || s->t == 'i')
			s->ta = (long)s->ta;
		else if (s->t == 'U' || s->t == 'O')
			s->ta = (unsigned long long)s->ta;
		else
			s->ta = (unsigned long)s->ta;
	}
	else if (s->modf[0] == 'h' && s->modf[1] == 'h')
		s->ta = (ft_strchr("di", s->t)) ? (signed char)s->ta
				: (unsigned char)s->ta;
	else if (s->modf[0] == 'h' && s->modf[1] == '\0')
		s->ta = (ft_strchr("di", s->t)) ? (short)s->ta : (unsigned short)s->ta;
	s->value = s->func[i].func(&(s->ta));
}

void		pf_type(t_pf *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s->types))
	{
		if (s->types[i] == *s->str && (s->t = *s->str))
			break ;
		i++;
	}
	if (!s->t)
		return ;
	if (s->t != 'f')
	{
		(!ft_strchr("scCpnb%", s->t)) ? do_number(s, i) : csp(s, i);
		s->strlen = (s->t != 'c') ? ft_strlen(s->value) : 1;
	}
	else
	{
		if (s->modf[0] == 'L' && s->modf[1] == '\0')
			pf_float(s, va_arg(s->ap, long double));
		else
			pf_float(s, va_arg(s->ap, double));
	}
	++(s->ret_value);
	++(s->str);
}
