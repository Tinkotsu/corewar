/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:36:44 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 02:36:44 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void         create_arena(t_cw *cw)
{
    int i;
    int s_point;

    i = 0;
    cw->arena = (char *)malloc(MEM_SIZE);
    if (!cw->arena)
        error("Memory error");
    ft_bzero(cw->arena, MEM_SIZE);
    s_point = MEM_SIZE / cw->players_amount;
    while (i < cw->players_amount)
    {
        cw->players[i]->starting_point = s_point * i;
        ft_memcpy(cw->arena + s_point * i,
                  cw->players[i]->exec_code,
                  cw->players[i]->exec_size);
        ++i;
    }
}

static void         champs_introduction(t_cw *cw)
{
    int i;

    i = 0;
    ft_putendl("Introducing contestants...");
    while (i < cw->players_amount)
    {
        ft_putstr("* Player ");
        ft_putnbr(cw->players[i]->id);
        ft_putstr(", weighing ");
        ft_putnbr((int)cw->players[i]->exec_size);
        ft_putstr(" bytes, \"");
        ft_putstr(cw->players[i]->name);
        ft_putstr("\" (\"");
        ft_putstr(cw->players[i]->comment);
        ft_putstr("\") !\n");
        ++i;
    }
}

static void         carriages_init(t_cw *cw)
{
    t_carriage  *new;
    int         i;

    i = 0;
    while (i < cw->players_amount)
    {
        ++cw->cars_amount;
        new = create_carriage(cw->cars_amount, cw->players[i]->starting_point);
        new->next = cw->carriage_list;
        cw->carriage_list = new;
        ++i;
    }
}

void                game_init(t_cw *cw)
{
    create_arena(cw);
    carriages_init(cw);
    champs_introduction(cw);
}
