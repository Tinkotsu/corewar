/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:34:04 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 19:14:55 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	while ((i * i) < nb)
	{
		++i;
		if (i > 46340)
			break ;
	}
	if ((i * i) == nb)
		return (i);
	return (0);
}
