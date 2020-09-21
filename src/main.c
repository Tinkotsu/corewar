#include "corewar.h"

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
    endgame(&cw);
    return (0);
}
//todo: флаг -d без аргумента чет не работает