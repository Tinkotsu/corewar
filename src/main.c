#include "corewar.h"
/*
#include <stdio.h>

static void    check_arena(t_cw *cw)
{
    char *arena = cw->arena;
    int i = 0;
    int false_bytes = 0;

    while (i < cw->players[0]->exec_size)
    {
        if (*arena <= 0x01 || *arena >= 0x10)
            ++false_bytes;
        ++arena;
        ++i;
    }
    printf("exec size = %d\n wrong bytes = %d", cw->players[0]->exec_size, false_bytes);
}
*/

int main(int argc, char **argv)
{
    t_cw cw;

    if (argc == 1)
        error("Wrong usage!"); //print usage
    corewar_init(argc, argv, &cw);
    players_init(argc, argv, &cw);
    parse_players(&cw);
    game_init(&cw);
    game(&cw);
    //display_arena(cw.arena, 32);
    endgame(&cw);
    ft_putendl("Success!");
    return (0);
}
