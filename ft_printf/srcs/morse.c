/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:56:37 by ifran             #+#    #+#             */
/*   Updated: 2019/10/22 18:59:53 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*mz_toupper(char *str)
{
	char *start;

	start = str;
	while (*str)
	{
		if ((*str >= 97) && (*str <= 122))
			*str -= 32;
		++str;
	}
	return (start);
}

static char		*morse_arr(int i)
{
	static char morse[43][8] = {".-", "-...", "-.-.", "-..", ".", "..-.", \
	"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", \
	"--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", \
	"--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", \
	"---..", "----.", "-----", "..--..", ".-.-.-", "--..--", "-...-", \
	".-.-.", "......."};

	return (morse[i]);
}

static char		*push_back(char *dest, char *src)
{
	char *temp;

	if (!dest)
		temp = ft_strdup(src);
	else
	{
		temp = ft_strjoin(dest, src);
		ft_strdel(&dest);
	}
	return (temp);
}

static char		*its_error(char *res, char *space, char *str)
{
	ft_strdel(&space);
	ft_strdel(&str);
	if (res)
		ft_strdel(&res);
	return (NULL);
}

char			*morse(char *str)
{
	int		i;
	char	*start;
	char	*res;
	char	*space;

	space = ft_strdup(" ");
	res = NULL;
	str = mz_toupper(str);
	start = str;
	while (*start)
	{
		i = 0;
		while (CHAR_ARR[i] != *start && i < 43)
			++i;
		if (i == 43)
			return (its_error(res, space, str));
		else
			res = push_back(res, (morse_arr(i)));
		if (*(start + 1))
			res = push_back(res, space);
		++start;
	}
	ft_strdel(&space);
	ft_strdel(&str);
	return (res);
}
