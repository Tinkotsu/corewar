#include "corewar.h"


static int  check_if_flag(char *argv)
{
    if (argv[0] == '-')
    {
        return (
                ft_strequ(&argv[1], "d") ||
                ft_strequ(&argv[1], "dump")
                );
    }
    return (0);
}

static void validate_filename(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 5 || !ft_strequ(&filename[len - 4], ".cor"))
        error("Wrong filename!");
}

static void get_players_amount(int argc, char **argv, t_cw *cw)
{
    int amount;
    int i;

    i = 1;
    amount = 0;
    while (i < argc)
    {
        if (ft_strequ(argv[i], "-n"))
        {
            ++i;
            ++cw->n_flags;
        }
        else if (!check_if_flag(argv[i]))
        {
            validate_filename(argv[i]);
            ++amount;
        }
        ++i;
    }
    if (amount > MAX_PLAYERS || !amount)
        error("Wrong players amount");
    cw->players_amount = amount;
    cw->last_player_alive = amount;
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

void        corewar_init(int argc, char **argv, t_cw *cw)
{
    cw->n_flags = 0;
    get_players_amount(argc, argv, cw);
    cw->cycles_to_die = CYCLE_TO_DIE;
    cw->game_cycles = 0;
    cw->live_operations = 0;
    cw->checks_performed = 0;
    cw->carriage_id = 0;
    cw->arena = NULL;
    cw->carriage_list = NULL;
    mem_players(cw);
}