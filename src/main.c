/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:34:50 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 12:41:42 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** print usage when error
*/

int	main(int argc, char **argv)
{
	t_cw cw;

	if (argc == 1)
		error_usage();
	corewar_init(argc, argv, &cw);
	players_init(argv, &cw);
	parse_players(&cw);
	game_init(&cw);
	game(&cw);
	endgame(&cw);
	return (0);
}
