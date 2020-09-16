/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:14:40 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 17:14:42 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

static void	float_int_len(t_pf *s)
{
	long double	n;
	int			temp;

	n = s->d.d;
	s->fl_len = 1;
	if (n < 10)
		temp = (int)n;
	while (n >= 10 && s->fl_len++)
	{
		temp = (int)n % 10;
		n /= 10;
	}
	s->even = (temp % 2 == 1) ? 1 : 0;
}

static void	replace_first_zero(t_pf *s)
{
	size_t	index;

	index = 0;
	if (s->sign)
		index++;
	if (s->value[index] == '0' && s->value[index + 1] != '.')
	{
		while ((size_t)index++ < s->strlen)
			s->value[index - 1] = s->value[index];
		s->strlen--;
	}
}

static int	pf_inf(t_pf *s)
{
	if (s->d.d != s->d.d)
	{
		if (!(s->value = ft_strdup("nan")))
			case_of_error();
		s->strlen = 3;
	}
	else if (s->d.d_parts.sign == 0)
	{
		if (!(s->value = ft_strdup("inf")))
			case_of_error();
		s->strlen = 3;
	}
	else if (s->d.d_parts.sign == 1)
	{
		if (!(s->value = ft_strdup("-inf")))
			case_of_error();
		s->strlen = 4;
	}
	return (1);
}

static void	def_sign_and_len(t_pf *s, size_t *index)
{
	s->sign = (s->d.d_parts.sign == 1) ? 1 : 0;
	if (s->sign)
		s->d.d = -s->d.d;
	float_int_len(s);
	s->strlen = s->fl_len + s->p_size + 3 + s->sign;
	if (!(s->value = ft_strnew(s->strlen)))
		case_of_error();
	if (s->sign)
		s->value[(*index)++] = '-';
	s->value[(*index)++] = '0';
}

void		pf_float(t_pf *s, long double n)
{
	size_t				index;
	int					exp;
	char				*mantisa;

	index = 0;
	if (s->p_size == 0 && !s->p_len && (s->p_len = 2))
		s->p_size = 6;
	s->d.d = n;
	if (((s->d.d_parts.exponent == 32767 && s->d.d_parts.mantisa >
			9223372036854775807) || n != n) && pf_inf(s))
		return ;
	def_sign_and_len(s, &index);
	exp = 0;
	if (s->d.d_parts.exponent)
		exp = s->d.d_parts.exponent - 16383;
	mantisa = to_binary(s->d.d_parts.mantisa);
	pf_dtoa(s, &index, exp, mantisa);
	s->strlen--;
	ft_strdel(&mantisa);
	replace_first_zero(s);
}
