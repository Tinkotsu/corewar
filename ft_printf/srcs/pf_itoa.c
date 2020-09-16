/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:18:20 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/07 16:48:02 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa(void *var)
{
	int				len;
	char			*arr;
	long long int	nb;
	int				sign;
	long long int	n;

	n = *(long long int *)var;
	sign = 1;
	len = 1;
	nb = n;
	if (n < 0 && (sign = -sign))
		len++;
	while (nb /= 10)
		len++;
	arr = (char*)malloc(len + 1);
	if (!arr)
		case_of_error();
	arr[len] = '\0';
	if (n < 0)
		arr[0] = '-';
	arr[--len] = (n % 10) * sign + 48;
	while (n /= 10)
		arr[--len] = (n % 10) * sign + 48;
	return (arr);
}
