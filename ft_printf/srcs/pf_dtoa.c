/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:15:57 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:15:58 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_int_part(t_pf *s, size_t *index)
{
	size_t i;

	i = 0;
	while (s->pre && s->pre[i])
	{
		s->value[*index + i] = s->pre[i];
		i++;
	}
	if (!s->pre)
		s->value[(*index)++] = '0';
	*index += i;
	s->dot_pos = *index;
	s->value[(*index)++] = '.';
	ft_strdel(&s->pre);
}

static void	handle_long_precision(size_t i, t_pf *s, size_t *index)
{
	char	*zeroes;
	char	*res;

	while (i < s->p_size && s->strlen > *index + i)
	{
		if (s->p_size + 1 > 50)
		{
			zeroes = str_of_chars(s->p_size - i, '0');
			res = ft_strjoin(s->value, zeroes);
			ft_strdel(&s->value);
			ft_strdel(&zeroes);
			s->value = res;
			break ;
		}
		s->value[*index + i++] = '0';
	}
}

static void	put_dec_part(t_pf *s, size_t *index)
{
	size_t		i;

	i = 0;
	if (s->first_len >= 0)
		while (i < (size_t)s->first_len && s->strlen > *index + i)
			s->value[*index + i++] = '0';
	*index += i;
	i = 0;
	while (s->pre && s->pre[i] && s->p_size >= i && s->strlen > *index + i)
	{
		s->value[*index + i] = s->pre[i];
		i++;
	}
	if (i > 50)
		i--;
	ft_strdel(&s->pre);
	handle_long_precision(i, s, index);
}

static void	def_dec_part(t_pf *s, char *mantisa, int exp)
{
	while (s->b < 64 && exp < 0 && s->d.d_parts.mantisa)
	{
		if (mantisa[s->b] == '0' && ++s->b && --exp)
			continue ;
		s->count_of_0 = find_last(mantisa, 64, '1') - s->b++;
		gain_str(gain_array(exp, 5, 27), s);
		if (s->first_len == -1)
			s->first_len = abs(exp) - (s->cur ? (int)ft_strlen(s->cur) : 0)
			        + s->count_of_0;
		s->exp = exp--;
	}
}

void		pf_dtoa(t_pf *s, size_t *index, int exp, char *mantisa)
{
	while (s->b < 64 && exp >= 0 && s->d.d_parts.mantisa)
	{
		if (++s->b && mantisa[s->b - 1] == '1')
			gain_str(gain_array(exp, 2, 63), s);
		exp--;
	}
	ft_strdel(&s->cur);
	put_int_part(s, index);
	def_dec_part(s, mantisa, exp);
	s->first_len -= s->oversize;
	ft_strdel(&s->cur);
	put_dec_part(s, index);
	*index = s->strlen - 1;
	if (!s->p_size)
	{
		if ((s->even && s->exp == -1) || s->exp < -1)
			rounding(s, index);
		s->strlen--;
		return ;
	}
	rounding(s, index);
}
