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
        ft_putstr(" * Player ");
        ft_putnbr(cw->players[i]->id);
        ft_putstr(", weighing ");
        ft_putnbr((int)cw->players[i]->exec_size);
        ft_putstr(" bytes, \"");
        ft_putstr(cw->players[i]->name);
        ft_putstr("\" (\"");
        ft_putstr(cw->players[i]->comment);
        ft_putstr("\") ! \n");
        ++i;
    }
}

static void	ft_printhex(int n)
{
    int c;

    if (n >= 16)
        ft_printhex(n / 16);
    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
    ft_putchar(c);
}

void	display_memory(char *arena)
{
    int		counter;
    int		i;
    unsigned char c;

    counter = 0;
    while (counter < MEM_SIZE)
    {
        ft_putstr("0x");
        i = 0x1000;
        while (i > counter + 1)
        {
            ft_putchar('0');
            i /= 16;
        }
        ft_printhex(counter);
        ft_putstr(" : ");
        i = 0;
        while (i < 32)
        {
            c = (unsigned char)*arena;
            if (c < 16)
                ft_putchar('0');
            ft_printhex(c);
            ft_putchar(' ');
            arena++;
            i++;
        }
        ft_putchar('\n');
        counter += 32;
    }
}

void        game_init(t_cw *cw)
{
    create_arena(cw);
    champs_introduction(cw);
    display_memory(cw->arena);
}