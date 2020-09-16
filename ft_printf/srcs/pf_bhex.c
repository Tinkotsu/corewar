/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:33:36 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/07 16:46:48 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_bhex(void *var)
{
	int					len;
	char				*arr;
	unsigned long long	nb;
	unsigned long long	n;

	n = *(unsigned long long *)var;
	len = 1;
	nb = n;
	while (nb /= 16)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 55;
	while (n /= 16)
		arr[--len] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 55;
	return (arr);
}
