/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:07 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:36:10 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int  check_if_flag(char *argv, t_cw *cw)
{
    int ret;

    ret = 2;
    if (argv[0] == '-')
    {
        if (!cw->d_flag && ft_strequ(&argv[1], "d"))
            cw->d_flag = 1;
        else if (!cw->d_flag && ft_strequ(&argv[1], "dump"))
            cw->d_flag = 2;
        else if (ft_strequ(&argv[1], "n"))
            ++cw->n_flags;
        else if (!cw->a_flag && ft_strequ(&argv[1], "a"))
        {
            cw->a_flag = 1;
            ret = 1;
        }
        else
            error("Flag error"); //usage (type flag)
    }
    else
        return (0);
    return (ret);
}

static void  parse_input(int argc, char **argv, t_cw *cw)
{
    int amount;
    int len;
    int ret;

    amount = 0;
    while (argc)
    {
        if ((ret = check_if_flag(*argv, cw)))
        {
            if (ret == 2 && !--argc)
                error("Wrong input"); //usage
            ++argv;
        }
        else
        {
            len = ft_strlen(*argv);
            if (len < 5 || !ft_strequ(&((*argv)[len - 4]), ".cor"))
                error("Wrong filename!");
            ++amount;
        }
        --argc;
        ++argv;
    }
    cw->players_amount = amount;
}

static void mem_players(t_cw *cw)
{
    int i;

    i = 0;
    cw->players = (t_player **)malloc(sizeof(t_player *) * cw->players_amount);
    if (!cw->players)
        error("Memory error!");
    while (i < cw->players_amount)
    {
        cw->players[i] = (t_player *)malloc(sizeof(t_player));
        if (!cw->players[i])
            error("Memory error!");
        ++i;
    }
}

static int  manage_d_flag(char **argv)
{
    while (!ft_strnequ(*argv, "-d", 2))
        ++argv;
    ++argv;
    if (!(*argv) || !ft_isnumber(*argv))
        error("Wrong usage of '-dump' or '-d'"); //usage
    return (ft_atoi(*argv));
}

void        corewar_init(int argc, char **argv, t_cw *cw)
{
    cw->a_flag = 0;
    cw->d_flag = 0;
    cw->n_flags = 0;
    cw->cars_amount = 0;
    parse_input(argc - 1, argv + 1, cw);
    if (cw->players_amount > MAX_PLAYERS || !cw->players_amount)
        error("Wrong players amount");
    cw->last_player_alive = cw->players_amount;
    cw->d_cycles = cw->d_flag ? manage_d_flag(argv) : 0;
    cw->cycles_to_die = CYCLE_TO_DIE;
    cw->game_cycles = 0;
    cw->live_ops = 0;
    cw->checks_performed = 0;
    cw->arena = NULL;
    cw->carriage_list = NULL;
    mem_players(cw);
}