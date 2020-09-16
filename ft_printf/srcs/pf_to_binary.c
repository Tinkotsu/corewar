/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:49:35 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 15:11:40 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_binary(unsigned long int n)
{
	char				*arr;
	int					len;
	unsigned long int	nb;

	len = 1;
	nb = n;
	while (nb /= 2)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = n % 2 + 48;
	while (n /= 2)
		arr[--len] = n % 2 + 48;
	return (arr);
}
