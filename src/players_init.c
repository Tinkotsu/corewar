#include "corewar.h"

static void player_init(int id, char *filename, t_player *player)
{
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
    while (players_left--)
    {
        while (!ft_strequ(*argv, "-n"))
            ++argv;
        if (!ft_isnumber(*(++argv)))
            error("Wrong usage!");  //print usage (n flag)
        id = ft_atoi(*argv);
        if (id <= 0 || id > cw->players_amount)
            error("Wrong id"); //print usage (n flag)
        if (is_duplicate(id, cw))
            error("Duplicated id!");
        ++argv;
        player_init(id, *argv, cw->players[id - 1]);
    }
}

void    manage_remaining(int players_left, char **argv, t_cw *cw)
{
    int id;

    id = 1;
    while (players_left--)
    {
        if (*argv[0] == '-')
        {
            if (*argv[1] == 'n')
                argv += 2;
            ++argv;
        }
        else
        {
            while (is_duplicate(id, cw))
                ++id;
            player_init(id, *argv, cw->players[id - 1]);
        }
    }
}

void    players_init(int argc, char **argv, t_cw *cw)
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