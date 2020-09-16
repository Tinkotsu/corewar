#include "corewar.h"
#include <stdio.h> //to delete

static void create_arena(t_cw *cw)
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

static void champs_introduction(t_cw *cw)
{
    int i;

    i = 0;
    ft_putendl("Introducing contestants...");
    while (i < cw->players_amount)
    {
        printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
                  cw->players[i]->id, cw->players[i]->exec_size,
                  cw->players[i]->name, cw->players[i]->comment);
        ++i;
    }
}

void	display_memory(char *arena) //не мое
{
    int		counter;
    int		i;

    counter = 0;
    while (counter < MEM_SIZE)
    {
        printf("0x%04x : ", counter);
        i = 0;
        while (i < 32)
        {
            printf("%02x ", (unsigned char)*arena);
            arena++;
            i++;
        }
        printf("\n");
        counter += 32;
    }
}

void        game_init(t_cw *cw)
{
    create_arena(cw);
    champs_introduction(cw);
    display_memory(cw->arena);
}