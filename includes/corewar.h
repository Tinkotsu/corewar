#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "libft.h"


typedef struct  s_player
{
	int         id;
	char        *filename;
	char        name[PROG_NAME_LENGTH + 1];
	char        comment[COMMENT_LENGTH + 1];
	int         exec_size;
	char        *exec_code; //to free
}               t_player;

typedef struct  s_cw
{
	int         players_amount;
	int         n_flags;
	int         last_player_alive;
    int         cycles_to_die;
	int         game_cycles;
	int         live_operations;
	int         checks_performed;
	t_player    **players; //to free
}               t_cw;

int             main(int argc, char **argv);
void            corewar_init(int argc, char **argv, t_cw *cw);
void            players_init(int argc, char **argv, t_cw *cw);
void            parse_players(t_cw *cw);




void            error(char *message);

#endif