/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_last_symbol_in_string.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:26:54 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/21 13:27:05 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_last(char *str, size_t len, char c)
{
	while (len > 0 && str[len - 1] != c)
		len--;
	return (len);
}
