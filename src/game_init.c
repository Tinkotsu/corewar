#include "corewar.h"

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
        ft_memcpy(cw->arena + s_point * i, cw->players[i]->exec_code,
                  cw->players[i]->exec_size);
        ++i;
    }
}

static void champs_introduction(t_cw *cw)
{
    int i;

    i = 0;
    ft_putendl("Introducing contestants...\n");
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
    champs_introduction(cw);
    create_arena(cw);
    //display_memory(cw->arena);
}