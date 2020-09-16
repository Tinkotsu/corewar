/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:06:47 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/18 14:06:49 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	def_max_len(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

static void		do_add(char *arr, t_l_ar s, const char *pre, const char *cur)
{
	while (s.len && s.len1 && s.len2)
	{
		s.nb = cur[--s.len2] + pre[--s.len1] - 96 + s.carry;
		s.carry = s.nb / 10;
		arr[--s.len] = s.nb % 10 + 48;
	}
	while (s.len1--)
	{
		s.nb = pre[s.len1] - 48 + s.carry;
		s.carry = s.nb / 10;
		arr[--s.len] = s.nb % 10 + 48;
	}
	while (s.len2--)
	{
		s.nb = cur[s.len2] - 48 + s.carry;
		s.carry = s.nb / 10;
		arr[--s.len] = s.nb % 10 + 48;
	}
	arr[--s.len] = s.carry + 48;
}

char			*long_add(char *pre, char *cur, int *oversize)
{
	char	*arr;
	t_l_ar	s;
	char	*t;

	s.len1 = ft_strlen(pre);
	s.len2 = ft_strlen(cur);
	s.len = def_max_len(s.len1, s.len2) + 1;
	if (!(arr = (char*)malloc(sizeof(char) * (s.len + 1))))
		case_of_error();
	ft_bzero(arr, s.len + 1);
	s.carry = 0;
	do_add(arr, s, pre, cur);
	if (arr[0] == '0')
	{
		if (!(t = ft_strdup(arr + 1)))
			case_of_error();
		ft_strdel(&arr);
		arr = t;
	}
	else
		*oversize = 1;
	return (arr);
}
