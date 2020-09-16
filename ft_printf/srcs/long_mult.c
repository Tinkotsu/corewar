/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_mult.c.                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:17:17 by ifran             #+#    #+#             */
/*   Updated: 2019/10/18 14:59:05 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	do_multi(char *res, char *num1, char *num2, t_l_ar *d)
{
	long long	i;
	long long	g;
	int			i1;
	int			i2;

	d->carry = 0;
	i = (long long)d->len2 - 1;
	while (i >= 0)
	{
		g = (long long)d->len1 - 1;
		while (g >= 0 || d->carry)
		{
			i1 = (g >= 0) ? num1[g] - 48 : 0;
			i2 = num2[i] - 48;
			d->carry += res[i + g + 1];
			d->nb = i1 * i2;
			d->t = d->nb % 10 + d->carry;
			res[i + g + 1] = (d->t) > '9' ? 48 + (d->t - 48) % 10 : d->t;
			d->carry = d->nb / 10 + (d->t - 48) / 10;
			g--;
		}
		i--;
	}
}

char			*long_mult(char *num1, char *num2)
{
	char	*res;
	char	*t;
	t_l_ar	d;

	d.len1 = num1 ? ft_strlen(num1) : 0;
	d.len2 = num2 ? ft_strlen(num2) : 0;
	d.len = d.len1 + d.len2;
	if (!(res = ft_strnew(d.len)))
		case_of_error();
	ft_memset(res, '0', d.len);
	do_multi(res, num1, num2, &d);
	ft_strdel(&num1);
	ft_strdel(&num2);
	if (res[0] == '0')
	{
		if (!(t = ft_strdup(res + 1)))
			case_of_error();
		ft_strdel(&res);
		res = t;
	}
	return (res);
}
