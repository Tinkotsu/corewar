/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:35:15 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 03:40:44 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	(*g_champ_ops[16])(t_carriage *car, t_cw *cw) = {
	&ch_live,
	&ch_ld,
	&ch_st,
	&ch_add,
	&ch_sub,
	&ch_and,
	&ch_or,
	&ch_xor,
	&ch_zjmp,
	&ch_ldi,
	&ch_sti,
	&ch_fork,
	&ch_lld,
	&ch_lldi,
	&ch_lfork,
	&ch_aff
};
