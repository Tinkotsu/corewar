#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include "op.h"
# include "libft.h"


typedef struct          s_player
{
	int                 id;
	char                *filename;
	char                name[PROG_NAME_LENGTH + 1];
	char                comment[COMMENT_LENGTH + 1];
	unsigned int        exec_size;
	char                *exec_code; //to free
	int                 starting_point;
}                       t_player;

typedef struct          s_carriage
{
    int                 id;
    int                 carry;
    int                 op;
    int                 last_cycle_live;
    int                 cycles_till_op;
    char                *position;
    int                 step;
    int                 reg[REG_NUMBER];
    int                 to_delete;
    struct s_carriage   *next;
}                       t_carriage;

typedef struct          s_cw
{
	int                 players_amount;
	int                 n_flags;
	int                 d_flag; // 1 = 32 octs; 2 = 64 octs;
	int                 d_cycles;
	int                 last_player_alive;
    int                 cycles_to_die;
	int                 game_cycles;
	int                 live_ops;
	int                 checks_performed;
	char                *arena; // to free
	t_player            **players; //to free
	t_carriage          *carriage_list;
}                       t_cw;

int                     main(int argc, char **argv);
void                    corewar_init(int argc, char **argv, t_cw *cw);
void                    players_init(int argc, char **argv, t_cw *cw);
void                    parse_players(t_cw *cw);
void                    game_init(t_cw *cw);
void	                display_arena(char *arena, int octets_num);
t_carriage              *create_carriage(int id, char *pos);
void                    game(t_cw *cw);
void                    delete_carriages(int to_delete, t_cw *cw);
void                    endgame(t_cw *cw);


void                    error(char *message);

#endif