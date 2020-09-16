/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_of_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:57:42 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 13:57:43 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*str_of_chars(size_t size, char c)
{
	char	*zeroes;

	if (!(zeroes = (char*)malloc(size + 1)))
		case_of_error();
	zeroes[size] = 0;
	ft_memset(zeroes, c, size);
	return (zeroes);
}
