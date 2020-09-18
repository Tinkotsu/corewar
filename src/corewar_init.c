#include "corewar.h"

static int  check_if_flag(char *argv, t_cw *cw)
{
    if (argv[0] == '-')
    {
        if (!cw->d_flag && ft_strequ(&argv[1], "d"))
            cw->d_flag = 2;
        else if (!cw->d_flag && ft_strequ(&argv[1], "dump"))
            cw->d_flag = 1;
        else if (ft_strequ(&argv[1], "n"))
            ++cw->n_flags;
        else
            error("Flag error"); //usage (type flag)
    }
    else
        return (0);
    return (1);
}

static void  parse_input(int argc, char **argv, t_cw *cw)
{
    int amount;
    int len;

    amount = 0;
    while (argc)
    {
        if (!check_if_flag(*argv, cw))
        {
            len = ft_strlen(*argv);
            if (len < 5 || !ft_strequ(&((*argv)[len - 4]), ".cor"))
                error("Wrong filename!");
            ++amount;
        }
        else
        {
            if (!--argc)
                error("Wrong input"); //usage
            ++argv;
        }
        --argc;
        ++argv;
    }
    if (amount > MAX_PLAYERS || !amount)
        error("Wrong players amount");
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
    return (ft_atoi(*argv));
}

void        corewar_init(int argc, char **argv, t_cw *cw)
{
    cw->d_flag = 0;
    cw->n_flags = 0;
    parse_input(argc - 1, argv + 1, cw);
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