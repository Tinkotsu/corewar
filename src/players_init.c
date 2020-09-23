/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:38:26 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:38:26 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void player_init(int id, char *filename, t_player *player)
{
    if (!filename)
        error("Wrong input");
    player->id = id;
    player->filename = filename;
    ft_bzero(player->name, PROG_NAME_LENGTH + 1);
    ft_bzero(player->comment, COMMENT_LENGTH + 1);
    player->exec_size = 0;
    player->exec_code = NULL;
    player->starting_point = 0;
}

static int  is_duplicate(int id, t_cw *cw)
{
    int i;

    i = 0;
    while (i < cw->players_amount)
    {
        if (cw->players[i]->id == id)
            return (1);
        ++i;
    }
    return (0);
}

static void manage_n_flags(char **argv, t_cw *cw)
{
    int players_left;
    int id;

    players_left = cw->n_flags;
    while (players_left)
    {
        while (!ft_strequ(*argv, "-n"))
            ++argv;
        ++argv;
        if (!(*argv) || !(ft_isnumber(*argv)))
            error("Wrong usage of '-n'");
        id = ft_atoi(*argv);
        if (id <= 0 || id > cw->players_amount)
            error("Wrong id used with '-n'");
        if (is_duplicate(id, cw))
            error("Duplicate id used with '-n'");
        ++argv;
        player_init(id, *argv, cw->players[id - 1]);
        --players_left;
    }
}

void    manage_remaining(int players_left, char **argv, t_cw *cw)
{
    int id;

    id = 1;
    while (players_left)
    {
        if (*argv[0] == '-')
            argv += 2;
        else
        {
            while (is_duplicate(id, cw))
                ++id;
            player_init(id, *argv, cw->players[id - 1]);
            --players_left;
            ++argv;
        }
    }
}

void    players_init(char **argv, t_cw *cw)
{
    int i;
    int players_left;

    i = 0;
    ++argv;
    players_left = cw->players_amount;
    while (i < cw->players_amount)
        cw->players[i++]->id = 0;
    if (cw->n_flags)
    {
        manage_n_flags(argv, cw);
        players_left -= cw->n_flags;
    }
    if (players_left)
        manage_remaining(players_left, argv, cw);
}