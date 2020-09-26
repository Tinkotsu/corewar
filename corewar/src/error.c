/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:31 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 12:46:01 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(-1);
}

void	error_usage(void)
{
	ft_putstr_fd("Usage:\n  corewar [-n <number> <num_player_file>] ", 2);
	ft_putstr_fd("[-a] [-dump <nbr_cycles>] or [-d <nbr_cycles>] ", 2);
	ft_putstr_fd("<player_file> ... <player_file>\n", 2);
	ft_putstr_fd("  [-n <number> <num_player_file>] : ", 2);
	ft_putstr_fd("to set number for player <num_player_file>\n", 2);
	ft_putstr_fd("  [-dump <nbr_cycles>] : to print the memory ", 2);
	ft_putstr_fd("(64 octets per line) and quit the game at the end ", 2);
	ft_putstr_fd("of nbr_cycles of executions\n", 2);
	ft_putstr_fd("  [-d <nbr_cycles>] : to print the memory (32 ", 2);
	ft_putstr_fd("octets per line) as well as live operations and quit", 2);
	ft_putstr_fd(" the game at the end of nbr_cycles of executions\n", 2);
	ft_putstr_fd("  [-a] : to switch on display of <aff> ", 2);
	ft_putstr_fd("operation output\n", 2);
	ft_putstr_fd("  <player_file> : file name of champion\n", 2);
	exit(-1);
}
