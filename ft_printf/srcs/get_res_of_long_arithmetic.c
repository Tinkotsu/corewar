/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res_of_long_arithmetic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:04:17 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:04:19 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	gain_str(char **arr_mult, t_pf *s)
{
	size_t	i;
	char	*zeroes;
	char	*res;

	zeroes = str_of_chars(s->count_of_0, '0');
	i = 1;
	while (arr_mult[i])
	{
		arr_mult[i] = long_mult(arr_mult[i - 1], arr_mult[i]);
		i++;
	}
	ft_strdel(&s->cur);
	if (!(res = ft_strjoin(arr_mult[i - 1], zeroes)))
		case_of_error();
	if (s->pre && (s->cur = long_add(s->pre, res, &s->oversize)))
		ft_strdel(&s->pre);
	else
		s->cur = ft_strdup(res);
	ft_strdel(&res);
	if (!(s->pre = ft_strdup(s->cur)))
		case_of_error();
	ft_strdel(&zeroes);
	ft_strdel(&arr_mult[i - 1]);
	free(arr_mult);
}
