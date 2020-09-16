/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:41:01 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/07 16:46:44 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_oct(void *var)
{
	char				*arr;
	int					len;
	unsigned long long	nb;
	unsigned long long	n;

	n = *(unsigned long long *)var;
	len = 1;
	nb = n;
	while (nb /= 8)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = n % 8 + 48;
	while (n /= 8)
		arr[--len] = n % 8 + 48;
	return (arr);
}
