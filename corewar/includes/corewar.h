/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 02:57:48 by ifran             #+#    #+#             */
/*   Updated: 2020/09/23 12:46:07 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include "op.h"
# include "libft.h"

typedef struct			s_op
{
	char				*name;
	int					args_amount;
	int					args[3];
	int					id;
	int					cycles;
	char				*description;
	int					arg_code;
	int					dir_size;
}						t_op;

typedef struct			s_player
{
	int					id;
	char				*filename;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					exec_size;
	char				*exec_code;
	int					starting_point;
}						t_player;

typedef struct			s_carriage
{
	int					id;
	int					carry;
	unsigned char		op_i;
	int					last_cycle_live;
	int					cycles_till_op;
	int					position;
	int					step;
	int					reg[REG_NUMBER];
	int					to_delete;
	char				args[4];
	t_op				*op;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_cw
{
	int					players_amount;
	int					a_flag;
	int					n_flags;
	int					d_flag;
	int					d_cycles;
	int					cars_amount;
	int					last_player_alive;
	int					cycles_to_die;
	int					game_cycles;
	int					live_ops;
	int					checks_performed;
	char				*arena;
	t_player			**players;
	t_carriage			*carriage_list;
}						t_cw;

extern t_op				g_op_tab[17];

int						main(int argc, char **argv);
int						get_int(char *bytes, int size);
void					set_int(char *arena, int start_pos, int num);
void					corewar_init(int argc, char **argv, t_cw *cw);
void					players_init(char **argv, t_cw *cw);
void					parse_players(t_cw *cw);
void					game_init(t_cw *cw);
void					display_arena(char *arena, int octets_num);
t_carriage				*create_carriage(int id, int pos);
void					game(t_cw *cw);
void					delete_carriages(int to_delete, t_cw *cw);
void					endgame(t_cw *cw);
int						validate_op(t_cw *cw, t_carriage *car);
void					error(char *message);
void					error_usage(void);

#endif
