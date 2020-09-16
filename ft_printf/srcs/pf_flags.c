/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:16:08 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/08 17:27:57 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

static void	replace(int *var, t_pf *s)
{
	if (*var)
		s->flags_count--;
	*var = 0;
}

static void	replace_if_not_diez(t_pf *s)
{
	replace(&s->flag_plus, s);
	replace(&s->flag_space, s);
	if (s->t == 'p')
		replace(&s->flag_diez, s);
}

static void	process_flags(t_pf *s)
{
	if (!ft_strchr("xXoOp", s->t))
	{
		if (s->flag_diez)
			s->was_diez = 1;
		replace(&s->flag_diez, s);
	}
	else
		replace_if_not_diez(s);
	if (s->t != 'f' || (s->d.d_parts.exponent == 32767 && s->d.d_parts.mantisa
			> 9223372036854775807) || s->d.d != s->d.d)
		if (s->flag_minus || s->p || !s->width ||
			(!s->p && s->p_len && !s->negative_p))
			replace(&s->flag_zero, s);
	if (!ft_strchr("dif", s->t) || *s->value == '-' || s->d.d != s->d.d)
	{
		replace(&s->flag_plus, s);
		replace(&s->flag_space, s);
	}
	else if (s->flag_plus)
		replace(&s->flag_space, s);
	if (s->flag_zero)
		ft_memset(s->width, '0', s->width_len);
}

static void	do_flags(t_pf *s)
{
	s->sign = 0;
	s->ret_value += s->f_len;
	s->str -= s->ret_value;
	if (s->flags_count > 0 || s->t == 'p')
	{
		if (s->flag_diez || s->t == 'p')
			pf_flag_diez(s);
		else if (s->flag_plus)
			pf_flags_plus_and_space(s);
		else if (s->flag_minus)
			pf_flag_minus(s);
		else if (s->flag_zero && s->p == 0)
			pf_flag_zero(s);
		else if (s->flag_space)
			pf_flags_plus_and_space(s);
	}
	else
		pf_no_flags(s);
	if (s->t != 'f')
		s->len += s->strlen + s->width_len + ft_strlen(s->p) - s->ox;
	else
		s->len += s->strlen + s->width_len - s->ox;
	s->str += s->ret_value;
}

void		pf_flags(t_pf *s)
{
	while (1)
	{
		if (*s->str == '#' && (s->flag_diez || ++s->flags_count))
			s->flag_diez = 35;
		else if (*s->str == '-' && (s->flag_minus || ++s->flags_count))
			s->flag_minus = 45;
		else if (*s->str == '0' && (s->flag_zero || ++s->flags_count))
			s->flag_zero = 48;
		else if (*s->str == '+' && (s->flag_plus || ++s->flags_count))
			s->flag_plus = 43;
		else if (*s->str == ' ' && (s->flag_space || ++s->flags_count))
			s->flag_space = 32;
		else
			break ;
		s->str++;
		s->f_len++;
	}
	pf_width(s);
	if (!s->value)
		return ;
	if (s->flags_count)
		process_flags(s);
	do_flags(s);
}
