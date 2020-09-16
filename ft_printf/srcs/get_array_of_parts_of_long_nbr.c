/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_of_parts_of_long_nbr.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:08:27 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:08:28 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**gain_array(int exp, int nb, int max_power)
{
	size_t	len;
	char	**arr;
	size_t	nbr;

	if (exp < 0)
		exp = abs(exp);
	len = exp / max_power;
	if (exp % max_power)
		len++;
	if (!(arr = (char**)malloc(sizeof(char*) * (len + 2))))
		case_of_error();
	len += 2;
	while (len > 0)
		arr[--len] = 0;
	nbr = 0;
	while (exp >= max_power)
	{
		if (nbr == 0)
			nbr = ft_recursive_power(nb, max_power);
		arr[len++] = pf_u(&nbr);
		exp -= max_power;
	}
	nbr = ft_recursive_power(nb, exp);
	arr[len] = pf_u(&nbr);
	return (arr);
}
