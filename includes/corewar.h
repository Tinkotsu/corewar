#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include "op.h"
# include "libft.h"

typedef struct          s_op
{
    char                *name;
    int                 args_amount;
    int                 args[3];
    int                 id;
    int                 cycles;
    char                *description;
    int                 arg_code;
    int                 dir_size;
}                       t_op;

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
    unsigned char       op_i;
    int                 last_cycle_live;
    int                 cycles_till_op;
    int                 position;
    int                 step;
    int                 reg[REG_NUMBER];
    int                 to_delete;
    t_op                *op;
    struct s_carriage   *next;
}                       t_carriage;

typedef struct          s_cw
{
	int                 players_amount;
	int                 a_flag;
	int                 n_flags;
	int                 d_flag; // 1 = 32 octs; 2 = 64 octs;
	int                 d_cycles;
	int                 cars_amount;
	int                 last_player_alive;
    int                 cycles_to_die;
	int                 game_cycles;
	int                 live_ops;
	int                 checks_performed;
	char                *arena; // to free
	t_player            **players; //to free
	t_carriage          *carriage_list;
}                       t_cw;

extern  t_op            op_tab[17];

int                     main(int argc, char **argv);
int                     get_int(char *bytes, size_t size);
void                    corewar_init(int argc, char **argv, t_cw *cw);
void                    players_init(int argc, char **argv, t_cw *cw);
void                    parse_players(t_cw *cw);
void                    game_init(t_cw *cw);
void	                display_arena(char *arena, int octets_num);
t_carriage              *create_carriage(int id, int pos);
void                    game(t_cw *cw);
void                    delete_carriages(int to_delete, t_cw *cw);
void                    endgame(t_cw *cw);
int                     validate_op(t_cw *cw, t_carriage *car);



void                    error(char *message);

#endif