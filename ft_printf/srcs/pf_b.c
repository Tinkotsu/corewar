/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:12 by ifran             #+#    #+#             */
/*   Updated: 2019/10/21 18:02:38 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_len(unsigned long long n)
{
	size_t	len;

	len = 1;
	while (n >= 2)
	{
		n /= 2;
		++len;
	}
	return (len);
}

char			*pf_b(void *var)
{
	unsigned long long	n;
	size_t				len;
	char				*str;

	n = *(unsigned long long *)var;
	len = count_len(n);
	if (!(str = (char *)malloc(len + 1)))
		case_of_error();
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 2 + 48;
		n /= 2;
		--len;
	}
	return (str);
}
