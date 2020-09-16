/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:28:46 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/07 16:46:55 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_u(void *var)
{
	char				*arr;
	int					len;
	unsigned long long	nb;
	unsigned long long	n;

	n = *(unsigned long long *)var;
	len = 1;
	nb = n;
	while (nb /= 10)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = n % 10 + 48;
	while (n /= 10)
		arr[--len] = n % 10 + 48;
	return (arr);
}
