/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:06:21 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 15:11:54 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	func_arr(t_pf *s)
{
	s->func[0].c = 'o';
	s->func[0].func = &pf_oct;
	s->func[1].c = 'X';
	s->func[1].func = &pf_bhex;
	s->func[2].c = 'x';
	s->func[2].func = &pf_hex;
	s->func[3].c = 'u';
	s->func[3].func = &pf_u;
	s->func[4].c = 'd';
	s->func[4].func = &pf_itoa;
	s->func[5].c = 'i';
	s->func[5].func = &pf_itoa;
	s->func[6].c = 'D';
	s->func[6].func = &pf_u;
	s->func[7].c = 'U';
	s->func[7].func = &pf_u;
	s->func[8].c = 'O';
	s->func[8].func = &pf_oct;
	s->func[9].c = 'p';
	s->func[9].func = &pf_hex;
}
